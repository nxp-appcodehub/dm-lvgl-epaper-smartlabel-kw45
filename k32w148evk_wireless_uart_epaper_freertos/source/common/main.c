/*! *********************************************************************************
 * \addtogroup Main
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright 2021-2022 NXP
* All rights reserved.
*
* \file
*
* This is the source file for the main entry point for a FreeRTOS application.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

/************************************************************************************
 *************************************************************************************
 * Include
 *************************************************************************************
 ************************************************************************************/
#include "app.h"
#include "app_conn.h"
#include "fsl_os_abstraction.h"
#include "wireless_uart.h"
#include "lvgl.h"
#include "gui_guider.h"


/************************************************************************************
 *************************************************************************************
 * Private functions prototypes
 *************************************************************************************
 ************************************************************************************/
static void start_task(void *argument);
static void price_task(void *argument);
lv_ui gui_guider;
static volatile bool s_lvgl_initialized = false;


/************************************************************************************
 *************************************************************************************
 * Private memory declarations
 *************************************************************************************
 ************************************************************************************/
static OSA_TASK_HANDLE_DEFINE(s_startTaskHandle);
static OSA_TASK_HANDLE_DEFINE(s_priceTaskHandle);
static OSA_TASK_DEFINE(start_task, gMainThreadPriority_c, 1, gMainThreadStackSize_c, 0);
static OSA_TASK_DEFINE(price_task, gMainThreadPriority_c, 1, 20*configMINIMAL_STACK_SIZE, 0);

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

static void start_task(void *argument)
{
    /* Start BLE Platform related ressources such as clocks, Link layer and HCI transport to Link Layer */
    (void)APP_InitBle();

    /* Start Application services (timers, serial manager, low power, led, button, etc..) */
    APP_InitServices();

    /* Start Host stack */
    BluetoothLEHost_AppInit();

    while(TRUE)
    {
        BluetoothLEHost_HandleMessages();
    }
}


/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

static void updatePriceTag(lv_ui *ui, appPriceInformation_t *pInformation)
{
	char sPrice[] = "00.00";
	char sBarecode[] = "0000000000000";
	sPrice[0] = pInformation->tens + 48;
	sPrice[1] = pInformation->units + 48;
	sPrice[3] = pInformation->tenths + 48;
	sPrice[4] = pInformation->cents + 48;
	for(uint8_t i = 0; i < 13; i++){
		sBarecode[i] = pInformation->ean[i] + 48;
	}
	switch(pInformation->currency){
		case 0:
			lv_label_set_text(ui->screen_currencyLabel, "$");
			break;
		case 1:
			lv_label_set_text(ui->screen_currencyLabel, "£");
			break;
		case 2:
			lv_label_set_text(ui->screen_currencyLabel, "€");
			break;
		case 3:
			lv_label_set_text(ui->screen_currencyLabel, "¥");
			break;
		default:
			break;
	}
	lv_qrcode_update(ui->screen_eanQRCode, sBarecode, 13);
	lv_barcode_update(ui->screen_eanBarcode, sBarecode);
	lv_label_set_text(ui->screen_eanLabel, sBarecode);
	lv_label_set_text(ui->screen_priceLabel, sPrice);
}

static void price_task(void *argument)
{
    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
    //lv_port_indev_init();
    s_lvgl_initialized = true;
    setup_ui(&gui_guider);
    while(TRUE)
    {
#ifdef SDK_OS_FREE_RTOS
			lv_task_handler();
			osa_event_flags_t event = 0U;
			(void)OSA_EventWait((osa_event_handle_t)mNewPriceEvent,
								osaEventFlagsAll_c,
								FALSE,
								10,//gAppTaskWaitTimeout_ms_c ,
								&event);
#endif /* SDK_OS_FREE_RTOS */

			/* Check for existing messages in queue */
			if (MSG_QueueGetHead(&mPriceInputQueue) != NULL)
			{
				/* Pointer for storing the messages from host. */
				appPriceInformation_t *pNewPrice= MSG_QueueRemoveHead(&mPriceInputQueue);

				if (pNewPrice != NULL)
				{
					updatePriceTag(&gui_guider, pNewPrice);
					/* Messages must always be freed. */
					(void)MSG_Free(pNewPrice);
				}
			}

#ifdef SDK_OS_FREE_RTOS
			/* Signal the main_thread again if there are more messages pending */
			event = (MSG_QueueGetHead(&mPriceInputQueue) != NULL) ? 1 : 0U;
			if (event != 0U)
			{
				(void)OSA_EventSet((osa_event_handle_t)mNewPriceEvent, gAppEvtAppCallback_c);
			}
#endif /* SDK_OS_FREE_RTOS */
    }
}
/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
int main(void)
{
    /* Init OSA: should be called before any other OSA API */
    OSA_Init();

    BOARD_InitHardware();

    (void)OSA_TaskCreate((osa_task_handle_t)s_startTaskHandle, OSA_TASK(start_task), NULL);
    (void)OSA_TaskCreate((osa_task_handle_t)s_priceTaskHandle, OSA_TASK(price_task), NULL);

    /* Start scheduler*/
    OSA_Start();

    /*won't run here*/
    assert(0);
    return 0;
}

/*! *********************************************************************************
 * @}
 ********************************************************************************** */
