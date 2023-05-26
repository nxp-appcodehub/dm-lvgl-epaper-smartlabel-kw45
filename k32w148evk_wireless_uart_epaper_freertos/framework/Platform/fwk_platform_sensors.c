/*!
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fwk_platform_sensors.h"
#include "fwk_platform_ics.h"
#include "board_utility.h"
#include "fwk_debug.h"

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

/*! Deviation from which the new temperature is sent to the CM3*/
#define PLATFORM_TEMP_SENT_CM3_THRESHOLD 10

static int32_t last_temperature_value = (int32_t)0xFFFFFFFFU;

/************************************************************************************
*************************************************************************************
* Private functions prototype
*************************************************************************************
************************************************************************************/

/*
 * Send temperature value to the CM3.
 */
static void PLATFORM_SendTemperatureValue(uint32_t l_temperature_value);

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
bool PLATFORM_IsAdcInitialized(void)
{
    return BOARD_IsAdcInitialized();
}

void PLATFORM_InitAdc(void)
{
    BOARD_InitAdc();
}

void PLATFORM_DeinitAdc(void)
{
    BOARD_DeinitAdc();
}

void PLATFORM_StartBatteryMonitor(void)
{
    BOARD_AdcSwTrigger(LPADC_BATTERY_MONITOR_CHANNEL);
}

void PLATFORM_GetBatteryLevel(uint8_t *battery_level)
{
    *battery_level = (uint8_t)BOARD_GetBatteryLevel();
}

void PLATFORM_StartTemperatureMonitor(void)
{
    BOARD_AdcSwTrigger(LPADC_TEMPEATURE_SENSOR_CHANNEL);
}

void PLATFORM_GetTemperatureValue(int32_t *temperature_value)
{
    float float_temperature_value;

    float_temperature_value = 10.0f * BOARD_GetTemperature();
    *temperature_value      = (int32_t)(float_temperature_value);
    if ((*temperature_value > (last_temperature_value + PLATFORM_TEMP_SENT_CM3_THRESHOLD)) ||
        (*temperature_value < (last_temperature_value - PLATFORM_TEMP_SENT_CM3_THRESHOLD)))
    {
        /* Send temperature to CM3 */
        PLATFORM_SendTemperatureValue((uint32_t)(*temperature_value));
        last_temperature_value = *temperature_value;
    }
}

void PLATFORM_SaveAdcContext(void)
{
    BOARD_SaveAdcContext();
}

void PLATFORM_RestoreAdcContext(void)
{
    BOARD_RestoreAdcContext();
}

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

static void PLATFORM_SendTemperatureValue(uint32_t l_temperature_value)
{
    int status;
    PWR_DBG_LOG("temperature sent:%d", l_temperature_value);
    status = PLATFORM_FwkSrvSendPacket(gFwkTemperatureIndication_c, &l_temperature_value,
                                       (uint16_t)sizeof(l_temperature_value));
    assert(status == 0);
    (void)status;
}
