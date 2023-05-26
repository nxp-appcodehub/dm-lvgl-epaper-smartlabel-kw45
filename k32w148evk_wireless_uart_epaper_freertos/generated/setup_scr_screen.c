/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"




void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 296, 128);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_eanBarcode
	ui->screen_eanBarcode = lv_barcode_create(ui->screen);
	lv_obj_set_height(ui->screen_eanBarcode, 40);
	lv_barcode_set_scale(ui->screen_eanBarcode, 1);
	lv_barcode_set_dark_color(ui->screen_eanBarcode, lv_color_hex(0x000000));
	lv_barcode_set_light_color(ui->screen_eanBarcode, lv_color_hex(0xffffff));
	const char * screen_eanBarcode_data = "0000000000000";
	lv_barcode_update(ui->screen_eanBarcode, screen_eanBarcode_data);
	lv_obj_set_pos(ui->screen_eanBarcode, 148, 67);

	//Write codes screen_eanLabel
	ui->screen_eanLabel = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_eanLabel, "0000000000000");
	lv_label_set_long_mode(ui->screen_eanLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_eanLabel, 150, 110);
	lv_obj_set_size(ui->screen_eanLabel, 139, 12);
	lv_obj_set_scrollbar_mode(ui->screen_eanLabel, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_eanLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_eanLabel, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_eanLabel, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_eanLabel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_eanLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_eanLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_eanLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_eanQRCode
	ui->screen_eanQRCode = lv_qrcode_create(ui->screen, 50, lv_color_hex(0x2C3224), lv_color_hex(0xffffff));
	const char * screen_eanQRCode_data = "0000000000000";
	lv_qrcode_update(ui->screen_eanQRCode, screen_eanQRCode_data, strlen(screen_eanQRCode_data));
	lv_obj_set_pos(ui->screen_eanQRCode, 231, 14);
	lv_obj_set_size(ui->screen_eanQRCode, 50, 50);

	//Write codes screen_currencyLabel
	ui->screen_currencyLabel = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_currencyLabel, "£");
	lv_label_set_long_mode(ui->screen_currencyLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_currencyLabel, 12, 14);
	lv_obj_set_size(ui->screen_currencyLabel, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_currencyLabel, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_currencyLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_currencyLabel, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_currencyLabel, &lv_customer_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_currencyLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_currencyLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_currencyLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_currencyLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_currencyLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_priceLabel
	ui->screen_priceLabel = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_priceLabel, "99.99");
	lv_label_set_long_mode(ui->screen_priceLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_priceLabel, 62, 14);
	lv_obj_set_size(ui->screen_priceLabel, 150, 50);
	lv_obj_set_scrollbar_mode(ui->screen_priceLabel, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_priceLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_priceLabel, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_priceLabel, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_priceLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_priceLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_priceLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_priceLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_priceLabel, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_priceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	
}
