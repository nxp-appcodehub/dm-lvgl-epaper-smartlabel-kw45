/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "lvgl_support.h"
#include "lvgl.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif

#include "board.h"
#include "fsl_gpio.h"
#include "fsl_debug_console.h"
#include "fsl_lpspi.h"
#include "ePaperScreen.h"
#include "fsl_component_mem_manager.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Port Me, Start. */
#define BOARD_TOUCH_I2C           Driver_I2C1
#define BOARD_TOUCH_I2C_IRQ       LPI2C1_IRQn
#define BOARD_TOUCH_I2C_FREQ_FUNC LPI2C1_GetFreq
#define BOARD_TOUCH_I2C_FREQ      CLOCK_GetIpFreq(kCLOCK_Lpi2c1)

//#define BOARD_LCD_SPI           Driver_SPI1
//#define BOARD_LCD_SPI_BAUDRATE  10000000U
#define BOARD_LCD_SPI_IRQ       LPSPI1_IRQn
#define BOARD_LCD_SPI_FREQ_FUNC LPSPI1_GetFreq
#define BOARD_LCD_SPI_FREQ      CLOCK_GetIpFreq(kCLOCK_Lpspi1)
// #define BOARD_LCD_SPI_DMA_IRQ   DMA0_IRQn

#define LPSPI_MASTER_BASEADDR         (LPSPI1)
#define LPSPI_MASTER_IRQN             (LPSPI1_IRQn)
#define LPSPI_MASTER_CLOCK_NAME       (kCLOCK_Lpspi1)
#define LPSPI_MASTER_CLK_FREQ         (CLOCK_GetIpFreq(LPSPI_MASTER_CLOCK_NAME))
#define LPSPI_MASTER_CLOCK_SOURCE     (kCLOCK_IpSrcFro192M)
#define LPSPI_MASTER_PCS_FOR_INIT     (kLPSPI_Pcs3)
#define LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs1)
#define LPSPI_MASTER_IRQHandler       (LPSPI1_IRQHandler)
#define TRANSFER_BAUDRATE 2000000U /*! Transfer baudrate - 2000k */
/* Port Me, End. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_InitLcd(void);
static void DEMO_InitTouch(void);
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data);
static void DEMO_RounderCb(lv_disp_drv_t *disp_drv, lv_area_t *area);
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

/*******************************************************************************
 * Variables
 ******************************************************************************/
SDK_ALIGN(static uint8_t s_frameBuffer[1][LCD_VIRTUAL_BUF_SIZE * LCD_FB_BYTE_PER_PIXEL], 4);

/*******************************************************************************
 * Code
 ******************************************************************************/
void lv_port_pre_init(void)
{
}

uint32_t BOARD_LCD_SPI_FREQ_FUNC(void)
{
    return BOARD_LCD_SPI_FREQ;
}

uint32_t BOARD_TOUCH_I2C_FREQ_FUNC(void)
{
    return BOARD_TOUCH_I2C_FREQ;
}

static void DEMO_InitEPaper(void)
{

    BOARD_InitEPaperPins();
	/*Set clock source for LPSPI and get master clock source*/
	CLOCK_SetIpSrc(LPSPI_MASTER_CLOCK_NAME, LPSPI_MASTER_CLOCK_SOURCE);
	CLOCK_SetIpSrcDiv(LPSPI_MASTER_CLOCK_NAME, kSCG_SysClkDivBy16);

    lpspi_master_config_t masterConfig;

    /* Master config. */
	LPSPI_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate = TRANSFER_BAUDRATE;
	masterConfig.whichPcs = LPSPI_MASTER_PCS_FOR_INIT;
	LPSPI_MasterInit(LPSPI_MASTER_BASEADDR, &masterConfig, LPSPI_MASTER_CLK_FREQ);

    /* Flush FIFO , clear status , disable all the interrupts. */
    LPSPI_FlushFifo(LPSPI_MASTER_BASEADDR, true, true);
    LPSPI_ClearStatusFlags(LPSPI_MASTER_BASEADDR, kLPSPI_AllStatusFlag);
    LPSPI_DisableInterrupts(LPSPI_MASTER_BASEADDR, kLPSPI_AllInterruptEnable);
	ePaperScreen_Init();

}

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;

    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));
    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer[0], NULL, LCD_VIRTUAL_BUF_SIZE);

    /*-------------------------
     * Initialize your display
     * -----------------------*/
    DEMO_InitEPaper();

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);   /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;

    disp_drv.rounder_cb = DEMO_RounderCb;

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

static void DEMO_RounderCb(lv_disp_drv_t *disp_drv, lv_area_t *area)
{
	area->x1 = (area->x1 / 8) * 8;
	area->x2 = ((area->x2 / 8) + 1) * 8 - 1;
	area->y1 = (area->y1 / 8) * 8;
	area->y2 = ((area->y2 / 8) + 1) * 8 - 1;

//for now do nothing

}
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    lv_coord_t x1 = area->x1;
    lv_coord_t y1 = area->y1;
    lv_coord_t x2 = area->x2;
    lv_coord_t y2 = area->y2;
    uint32_t x_size = (x2 - x1 + 1);
    uint8_t* pdata = (uint8_t *)color_p;

#if LCD_HEIGHT > LCD_WIDTH
	for (uint16_t i = 0; i <= y2-y1; i++)
	{

		ePaperScreen_SetCursorPosition(x1/8, y1+i);
		ePaperScreen_SendCommandByte(0x24);   //write RAM for black(0)/white (1)

		for (uint16_t j = 0 ; j <= x2-x1; j+=8)
		{

			ePaperScreen_SendDataByte(
					(pdata[i * x_size + j + 0] & 0x01) << 7 |
					(pdata[i * x_size + j + 1] & 0x01) << 6 |
					(pdata[i * x_size + j + 2] & 0x01) << 5 |
					(pdata[i * x_size + j + 3] & 0x01) << 4 |
					(pdata[i * x_size + j + 4] & 0x01) << 3 |
					(pdata[i * x_size + j + 5] & 0x01) << 2 |
					(pdata[i * x_size + j + 6] & 0x01) << 1 |
					(pdata[i * x_size + j + 7] & 0x01) << 0
					);
		}
	}
#else
	for (uint16_t i = 0; i <= x2-x1; i++)
	{
		ePaperScreen_SetCursorPosition(y1/8, LCD_WIDTH - (x1 + i + 1));
		ePaperScreen_SendCommandByte(0x24);   //write RAM for black(0)/white (1)

		for (uint16_t j = 0 ; j <= y2-y1; j+=8)
		{

			ePaperScreen_SendDataByte(
					(pdata[i + x_size*(j + 0)] & 0x01) << 7 |
					(pdata[i + x_size*(j + 1)] & 0x01) << 6 |
					(pdata[i + x_size*(j + 2)] & 0x01) << 5 |
					(pdata[i + x_size*(j + 3)] & 0x01) << 4 |
					(pdata[i + x_size*(j + 4)] & 0x01) << 3 |
					(pdata[i + x_size*(j + 5)] & 0x01) << 2 |
					(pdata[i + x_size*(j + 6)] & 0x01) << 1 |
					(pdata[i + x_size*(j + 7)] & 0x01) << 0
					);
		}
	}
#endif
    if (lv_disp_flush_is_last(disp_drv))
    {
    	ePaperScreen_RefreshDisplay();
    }

    lv_disp_flush_ready(disp_drv);
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad */
    DEMO_InitTouch();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = DEMO_ReadTouch;
    lv_indev_drv_register(&indev_drv);
}

/*Initialize your touchpad*/
static void DEMO_InitTouch(void)
{
}

/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
}
