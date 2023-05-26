/*
 * Copyright 2021 - 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*${header:start}*/
#include "board.h"
#include "board_dcdc.h"
#include "clock_config.h"
#include "fwk_platform.h"
#include "fwk_debug.h"

#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
#include "fwk_sfc.h"
#endif
/*${header:end}*/

#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
static sfc_config_t sfcConfig;
#endif

/*${function:start}*/
void BOARD_InitHardware(void)
{
    BOARD_DBGCONFIGINIT(TRUE); // internal debug

#if defined(gAppHighSystemClockFrequency_d) && (gAppHighSystemClockFrequency_d > 0)
    /* Set Core frequency to 96Mhz , core voltage to 1.1v */
    BOARD_BootClockHSRUN();
#else
    /* Set Core frequency to 48Mhz , core voltage to 1.0v */
    BOARD_BootClockRUN();
#endif

#if defined(gBoardUseFro32k_d) && (gBoardUseFro32k_d > 0)
    SFC_GetDefaultConfig(&sfcConfig);
    SFC_Init(&sfcConfig);
#else
    /* Initialize and start osc32k
     * Note: osc32k is not yet selected as 32k clock source, the switch is done
     * when calling PLATFORM_SwitchToOsc32k a bit later.
     * This allows to perform other initialization task before the 32k clock is
     * actually needed */
    (void)PLATFORM_InitOsc32K();
#endif

    /* Initialize DCDC and apply optimized configuration */
    BOARD_InitDcdc();

#if defined(gDebugConsoleEnable_d) && (gDebugConsoleEnable_d == 1)
    BOARD_InitDebugConsole();
#endif

    /* Pins and clocks for serial, timers, ... are initialized in board_comp.c api
     * see BOARD_InitSerialManager() for example */
}
/*${function:end}*/
