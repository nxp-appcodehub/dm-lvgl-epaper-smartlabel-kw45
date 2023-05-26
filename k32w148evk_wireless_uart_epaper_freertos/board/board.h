/*
 * Copyright 2019-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"
#include "fsl_gpio.h"

/*!
 * @addtogroup FWK_Board_module
 * The FWK_Board module
 *
 * FWK_Board module provides APIs to config platform functionalities and peripherals.
 * @{
 */
/*!
 * @addtogroup FWK_Board
 * The FWK_Board main module
 *
 * FWK_Board main module provides APIs to initialise hardware and manage serial consoles.
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME        "KW45_K32W1"
#define MANUFACTURER_NAME "NXP"

/* @brief Change Default trimming value for 32MHz crystal,
      will be used by fwk_platform.c file during initialization */
//#define BOARD_32MHZ_XTAL_TRIM_DEFAULT           12U

/* @brief Change Default load capacitance config for 32KHz crystal,
      will be used by fwk_platform.c file during initialization */
//#define BOARD_32KHZ_XTAL_CLOAD_DEFAULT          (CCM32K_OSC32K_CTRL_XTAL_CAP_SEL(8U) |
// CCM32K_OSC32K_CTRL_EXTAL_CAP_SEL(8U))

/* Number of LEDs supported on the board
 * Note: If an application requires more or less LED, then change the gAppLedCnt_c flag in app_preinclude.h
 */
#define gBoardLedCnt_c 2

/* Number of Buttons supported on the board
 * Note: If an application requires more or less button, then change the gAppButtonCnt_c flag in app_preinclude.h
 */
#define gBoardButtonCnt_c 2

#ifndef DEFAULT_APP_UART
/* Use LPUART1 as default UART for Applicative serial console on new EVK rev A1-B1*/
#define DEFAULT_APP_UART 1
#endif

#if (defined(HAL_UART_DMA_ENABLE) && (HAL_UART_DMA_ENABLE > 0U))
#define BOARD_APP_UART_TYPE (kSerialPort_UartDma)
#else
#define BOARD_APP_UART_TYPE (kSerialPort_Uart)
#endif
#if (DEFAULT_APP_UART == 0)
#define BOARD_APP_UART_BASEADDR     (uint32_t) LPUART0 /*set lpuart0 as the default*/
#define BOARD_APP_UART_INSTANCE     0U                 /*set lpuart0 as the default*/
#define BOARD_APP_UART_CLK          kCLOCK_Lpuart0     /*set lpuart0 as the default*/
#define BOARD_APP_UART_CLKSRC       kCLOCK_IpSrcFro6M  /* LPUART0 and FRO6M are in same power domain */
#define BOARD_APP_UART_DMAREQ_TX    kDmaRequestLPUART0Tx
#define BOARD_APP_UART_DMAREQ_RX    kDmaRequestLPUART0Rx
#define BOARD_APP_UART_DMAREQMUX_TX kDmaRequestMuxLPUART0Tx
#define BOARD_APP_UART_DMAREQMUX_RX kDmaRequestMuxLPUART0Rx

#define BOARD_APP2_UART_BASEADDR     (uint32_t) LPUART1 /*set lpuart1 as the default*/
#define BOARD_APP2_UART_INSTANCE     1U                 /*set lpuart1 as the default*/
#define BOARD_APP2_UART_CLK          kCLOCK_Lpuart1     /*set lpuart1 as the default*/
#define BOARD_APP2_UART_CLKSRC       kCLOCK_IpSrcFro192M
#define BOARD_APP2_UART_DMAREQ_TX    kDmaRequestLPUART1Tx
#define BOARD_APP2_UART_DMAREQ_RX    kDmaRequestLPUART1Rx
#define BOARD_APP2_UART_DMAREQMUX_TX kDmaRequestMuxLPUART1Tx
#define BOARD_APP2_UART_DMAREQMUX_RX kDmaRequestMuxLPUART1Rx
#else
#define BOARD_APP_UART_BASEADDR     (uint32_t) LPUART1 /*set lpuart1 as the default*/
#define BOARD_APP_UART_INSTANCE     1U                 /*set lpuart1 as the default*/
#define BOARD_APP_UART_CLK          kCLOCK_Lpuart1     /*set lpuart1 as the default*/
#define BOARD_APP_UART_CLKSRC       kCLOCK_IpSrcFro192M
#define BOARD_APP_UART_DMAREQ_TX    kDmaRequestLPUART1Tx
#define BOARD_APP_UART_DMAREQ_RX    kDmaRequestLPUART1Rx
#define BOARD_APP_UART_DMAREQMUX_TX kDmaRequestMuxLPUART1Tx
#define BOARD_APP_UART_DMAREQMUX_RX kDmaRequestMuxLPUART1Rx

#define BOARD_APP2_UART_BASEADDR     (uint32_t) LPUART0 /*set lpuart0 as the default*/
#define BOARD_APP2_UART_INSTANCE     0U                 /*set lpuart0 as the default*/
#define BOARD_APP2_UART_CLK          kCLOCK_Lpuart0     /*set lpuart0 as the default*/
#define BOARD_APP2_UART_CLKSRC       kCLOCK_IpSrcFro6M  /* LPUART0 and FRO6M are in same power domain */
#define BOARD_APP2_UART_DMAREQ_TX    kDmaRequestLPUART0Tx
#define BOARD_APP2_UART_DMAREQ_RX    kDmaRequestLPUART0Rx
#define BOARD_APP2_UART_DMAREQMUX_TX kDmaRequestMuxLPUART0Tx
#define BOARD_APP2_UART_DMAREQMUX_RX kDmaRequestMuxLPUART0Rx
#endif

#define BOARD_APP_UART_BAUDRATE  115200
#define BOARD_APP2_UART_BAUDRATE 115200

/*! @brief The UART to use for debug messages. */
#if !defined DebugConsole_c
#define DebugConsole_c 0
#endif

#define BOARD_DEBUG_UART_TYPE kSerialPort_Uart
#if (DebugConsole_c == 1)
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) LPUART1
#define BOARD_DEBUG_UART_INSTANCE 1U
#define BOARD_DEBUG_UART_CLK      kCLOCK_Lpuart1
#elif (DebugConsole_c == 0)
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) LPUART0
#define BOARD_DEBUG_UART_INSTANCE 0U
#define BOARD_DEBUG_UART_CLK      kCLOCK_Lpuart0
#endif
#define BOARD_DEBUG_UART_CLKSRC   kCLOCK_IpSrcFro6M // kCLOCK_IpSrcFro192M
#define BOARD_DEBUG_UART_CLK_FREQ 6000000U          // 192000000U could be used as well

#ifndef BOARD_DEBUG_UART_BAUDRATE
#define BOARD_DEBUG_UART_BAUDRATE 115200
#endif /* BOARD_DEBUG_UART_BAUDRATE */

#define BOARD_SERIAL_MGR_IF_INVALID 0xFFu

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * \brief Initializes hardware
 *
 */
void BOARD_InitHardware(void);

/*!
 * \brief Initializes 1st application console instance
 *
 */
void BOARD_InitAppConsole(void);

/*!
 * \brief Deinitializes 1st application console instance
 *
 */
void BOARD_UninitAppConsole(void);

/*!
 * \brief Initializes 2nd application console instance
 *
 */
void BOARD_InitApp2Console(void);

/*!
 * \brief Deinitializes 2nd application console instance
 *
 */
void BOARD_UninitApp2Console(void);

/*!
 * \brief Initializes debug console
 *
 */
void BOARD_InitDebugConsole(void);

/*!
 * \brief Deinitializes debug console
 *
 */
void BOARD_UninitDebugConsole(void);

/*!
 * \brief Re-initializes debug console
 *
 */
void BOARD_ReinitDebugConsole(void);

/*!
 * @}  end of FWK_Board addtogroup
 */
/*!
 * @}  end of FWK_Board_module addtogroup
 */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
