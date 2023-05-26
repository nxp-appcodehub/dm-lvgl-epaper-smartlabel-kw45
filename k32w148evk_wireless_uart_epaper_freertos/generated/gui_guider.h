
/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_eanBarcode;
	lv_obj_t *screen_eanLabel;
	lv_obj_t *screen_eanQRCode;
	lv_obj_t *screen_currencyLabel;
	lv_obj_t *screen_priceLabel;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_screen(lv_ui *ui);

LV_FONT_DECLARE(lv_font_montserratMedium_11)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_50)
LV_FONT_DECLARE(lv_customer_font_montserratMedium_50)
LV_FONT_DECLARE(lv_font_montserratMedium_40)


#ifdef __cplusplus
}
#endif
#endif
