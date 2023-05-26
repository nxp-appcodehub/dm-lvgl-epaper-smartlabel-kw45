#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include "fsl_gpio.h"
#include "fsl_lpspi.h"
#include "pin_mux.h"
#include "fsl_os_abstraction.h"
#include "lvgl_support.h"

void ePaperScreen_Init(void);
void ePaperScreen_SendCommandByte(uint8_t cmd);
void ePaperScreen_SendDataByte(uint8_t data);
void ePaperScreen_SetCursorPosition(uint16_t x, uint16_t y);
void ePaperScreen_RefreshDisplay(void);

#endif

