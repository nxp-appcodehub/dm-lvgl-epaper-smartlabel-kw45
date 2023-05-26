/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LVGL_SUPPORT_H
#define LVGL_SUPPORT_H

#include <stdint.h>
#include "lv_conf.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LCD_WIDTH             LV_HOR_RES_MAX
#define LCD_HEIGHT            LV_VER_RES_MAX
#define LCD_FB_BYTE_PER_PIXEL 1
#define LCD_VIRTUAL_BUF_SIZE (LCD_WIDTH * LCD_HEIGHT / 10)

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void lv_port_pre_init(void);
void lv_port_disp_init(void);
void lv_port_indev_init(void);

#if defined(__cplusplus)
}
#endif

#endif /*LVGL_SUPPORT_H */
