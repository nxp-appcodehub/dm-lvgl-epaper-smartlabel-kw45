/* -------------------------------------------------------------------------- */
/*                           Copyright 2020-2022 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "board.h"
#include "board_lp.h"
#include "fsl_spc.h"
#include "fsl_port.h"
#include "fwk_platform.h"
#include "fwk_platform_lowpower.h"
#include "fsl_pm_core.h"
#include "fwk_debug.h"

#if ((defined(gAppButtonCnt_c) && (gAppButtonCnt_c > 0)) ||               \
     (defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0)) || \
     (defined(gAppLedCnt_c) && (gAppLedCnt_c > 0)))
/* board_comp.h only required for above services   */
#include "board_comp.h"
#include "app.h"
#endif

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
#include "fwk_platform_sensors.h"
#endif

#if (defined(gDebugConsoleEnable_d) && (gDebugConsoleEnable_d == 1))
#include "fsl_debug_console.h"
#endif

#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
#include "fwk_sfc.h"
#endif

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Callback registered to SDK Power Manager to get notified of entry/exit of low power modes
 *
 * \param[in] eventType event specifying if we entered or exited from low power mode
 * \param[in] powerState low power mode used during low power period
 * \param[in] data Optional data passed when the callback got registered (not used currently)
 * \return status_t
 */
static status_t BOARD_LowpowerCb(pm_event_type_t eventType, uint8_t powerState, void *data);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static pm_notify_element_t boardLpNotifyGroup = {
    .notifyCallback = BOARD_LowpowerCb,
    .data           = NULL,
};

#if defined(gBoard_ManageSwdPinsInLowPower_d) && (gBoard_ManageSwdPinsInLowPower_d > 0)
/* Variables to store the PCR register value for SWD_DIO and SWD_CLK pins */
static uint32_t mSWDIO_PCR_Save;
static uint32_t mSWDCLK_PCR_Save;
#endif

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

#if defined(gBoard_ManageSwdPinsInLowPower_d) && (gBoard_ManageSwdPinsInLowPower_d > 0)
static void BOARD_SetSWDPinsLowPower(bool_t isLowPower)
{
    bool_t   clock_portA        = FALSE;
    uint32_t clock_porta_config = (*(volatile uint32_t *)kCLOCK_PortA);

    /* Activate PORTA clock if disabled */
    if ((clock_porta_config & MRCC_CC_MASK) == 0U)
    {
        clock_portA = TRUE;
        CLOCK_EnableClock(kCLOCK_PortA);
    }

    if (isLowPower)
    {
        /* Store SWDIO PCR value */
        mSWDIO_PCR_Save = PORTA->PCR[0];
        /* Store SWDCLK PCR value */
        mSWDCLK_PCR_Save = PORTA->PCR[1];
        /* Disable SWDIO pin */
        PORT_SetPinMux(PORTA, 0, kPORT_PinDisabledOrAnalog);
        /* Disable SWDCLK pin */
        PORT_SetPinMux(PORTA, 1, kPORT_PinDisabledOrAnalog);
    }
    else
    {
        /* Enable SWDIO pin */
        PORTA->PCR[0] = mSWDIO_PCR_Save;
        /* Disable SWDIO pin */
        PORTA->PCR[1] = mSWDCLK_PCR_Save;
    }

    /* Restore PORTA clock settings */
    if (clock_portA)
    {
        *(volatile uint32_t *)kCLOCK_PortA = clock_porta_config;
    }
}
#endif

/*!
 * @brief Basic lowpower entry call to flush serial transaction and disable peripherals pin to avoid leakage in lowpower
 *    typically called from wakeup from deep sleep
 */
static void BOARD_EnterLowPowerCb(void)
{
    uint8_t bank_mask;

#if defined(gDebugConsoleEnable_d) && (gDebugConsoleEnable_d == 1)
    BOARD_UninitDebugConsole();
#endif

#if defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0)
#if (DEFAULT_APP_UART == 1)
    /* Disable properly UART1, this peripheral will enter low power without wakeup capabilities */
    BOARD_UninitSerialManager();
#else

    /* UART 0 is located in wakeup domain and should remain initialized in low power mode to allow wakeup */

#if !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d == 0)
    /* Disable UART if not used as wakeup source,  this will save significant amount of current */
    BOARD_UninitSerialManager();
#endif /* defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0) */
#endif /* DEFAULT_APP_UART==1 */
#endif /* !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d==0) */

#if defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 1)
#if !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d == 0) || (DEFAULT_APP_UART == 0)
    BOARD_UninitSerialManager2();
#endif /* defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 1) */
#endif /* !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d==0) || (DEFAULT_APP_UART==0) \
        */

#if defined(gAppButtonCnt_c) && (gAppButtonCnt_c > 1)
    BUTTON_EnterLowpower((button_handle_t)g_buttonHandle[1]);
#endif

#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
    SFC_EnterLowPower();
#endif

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    PLATFORM_SaveAdcContext();
#endif
    /* In order to optimize the consumption in lowpower we do not retain all RAM banks.
     * We obtain the banks that need to be retained by the application thanks to
     * PLATFORM_GetDefaultRamBanksRetained but this function is linker script dependant.
     * If you change the linker script you can implement you GetRamBanksRetained or give
     * directly a mask to PLATFORM_SetRamBanksRetained. */
    bank_mask = PLATFORM_GetDefaultRamBanksRetained();
    PLATFORM_SetRamBanksRetained(bank_mask);
    return;
}

static void BOARD_EnterPowerDownCb(void)
{
#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    PLATFORM_DeinitAdc();
#endif
    return;
}
/*!
 * @brief Basic lowpower exit callback to reinitialize clock and pin mux configuration,
 *    typically called from wakeup from deep sleep and other lowest power mode
 */
static void BOARD_ExitLowPowerCb(void)
{
#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
    SFC_ExitLowPower();
#endif

#if defined(gAppButtonCnt_c) && (gAppButtonCnt_c > 1)
    BUTTON_ExitLowpower((button_handle_t)g_buttonHandle[1]);
#endif

#if defined(gDebugConsoleEnable_d) && (gDebugConsoleEnable_d == 1)
    BOARD_ReinitDebugConsole();
#endif

#if defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0)
#if (DEFAULT_APP_UART == 1)
    /* Re enable properly UART1, this peripheral exits low power */
    BOARD_ReinitSerialManager((serial_handle_t)gSerMgrIf);
#else

    /* UART 0 is located in wakeup domain and remains initialized in low power mode to allow wakeup */
#if !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d == 0)
    BOARD_ReinitSerialManager((serial_handle_t)gSerMgrIf);
#endif /* defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 0) */
#endif /* (DEFAULT_APP_UART==1) */
#endif /* !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d==0) */

#if defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 1)
#if !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d == 0) || (DEFAULT_APP_UART == 0)
    BOARD_ReinitSerialManager2((serial_handle_t)gSerMgrIf2);
#endif /* defined(gAppUseSerialManager_c) && (gAppUseSerialManager_c > 1) */
#endif /* !defined(gAppLpuart0WakeUpSourceEnable_d) || (gAppLpuart0WakeUpSourceEnable_d==0) || (DEFAULT_APP_UART==0)*/

#if defined(gAppUseSensors_d) && (gAppUseSensors_d > 0)
    PLATFORM_RestoreAdcContext();
#endif

#if defined(DBG_PWR) && (DBG_PWR == 1)
    /* Debug purpose only */
    static int nb = 0;
    PWR_DBG_LOG("%d", nb++);
#endif
    return;
}

/*!
 * \brief This function called after exiting Power Down mode on main domain. It should be used to
 *        restore peripherals in main domain used by the application that need specific restore
 *        procedure such as LPUART1, etc..
 * \note  Peripherals in wakeup domain are not concerned. Wakeup domain always remains in Deep Sleep, Sleep,
 *        or Active mode so the HW registers are always retained.
 */
static void BOARD_ExitPowerDownCb(void)
{
#if (defined(gAppButtonCnt_c) && (gAppButtonCnt_c > 1))
    BOARD_ReinitButton1((button_handle_t)g_buttonHandle[1]);
#endif
    return;
}

/* -------------------------------------------------------------------------- */
/*                              Lowpower callbacks                             */
/* -------------------------------------------------------------------------- */

static status_t BOARD_LowpowerCb(pm_event_type_t eventType, uint8_t powerState, void *data)
{
    status_t ret = kStatus_Success;
    if (powerState < PLATFORM_DEEP_SLEEP_STATE)
    {
        /* Nothing to do when entering WFI or Sleep low power state
            NVIC fully functionnal to trigger upcoming interrupts */
    }
    else
    {
        if (eventType == kPM_EventEnteringSleep)
        {
            BOARD_EnterLowPowerCb();

            if (powerState >= PLATFORM_POWER_DOWN_STATE)
            {
                /* Power gated low power modes often require extra specific
                 * entry/exit low power procedures, those should be implemented
                 * in the following BOARD API */
                BOARD_EnterPowerDownCb();
            }
        }
        else
        {
            /* Check if Main power domain domain really went to Power down,
             *   powerState variable is just an indication, Lowpower mode could have been skipped by an immediate wakeup
             */
            PLATFORM_PowerDomainState_t main_pd_state = PLATFORM_NO_LOWPOWER;
            PLATFORM_status_t           status;

            status = PLATFORM_GetLowpowerMode(PLATFORM_MainDomain, &main_pd_state);
            assert(status == PLATFORM_Successful);
            (void)status;

            if (main_pd_state == PLATFORM_POWER_DOWN_MODE)
            {
                /* Process wake up from power down mode on Main domain
                 *  Note that Wake up domain has not been in power down mode */
                BOARD_ExitPowerDownCb();
            }

            BOARD_ExitLowPowerCb();
        }
    }
    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void BOARD_LowPowerInit(void)
{
    status_t status;

    status = PM_RegisterNotify(kPM_NotifyGroup2, &boardLpNotifyGroup);
    assert(status == kStatus_Success);
    (void)status;
}
