/*******************************************************************************
 * Size: 50 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef LV_CUSTOMER_FONT_MONTSERRATMEDIUM_50
#define LV_CUSTOMER_FONT_MONTSERRATMEDIUM_50 1
#endif

#if LV_CUSTOMER_FONT_MONTSERRATMEDIUM_50

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0024 "$" */
    0x0, 0xe, 0x0, 0x0, 0x1, 0xc0, 0x0, 0x0,
    0x38, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0xe0,
    0x0, 0x0, 0x1c, 0x0, 0x0, 0x3, 0x80, 0x0,
    0x3, 0xff, 0x80, 0x3, 0xff, 0xfe, 0x0, 0xff,
    0xff, 0xf0, 0x7f, 0xff, 0xfe, 0xf, 0xe7, 0xf,
    0xc3, 0xf0, 0xe0, 0x30, 0x7c, 0x1c, 0x0, 0x1f,
    0x3, 0x80, 0x3, 0xe0, 0x70, 0x0, 0x7c, 0xe,
    0x0, 0xf, 0x81, 0xc0, 0x1, 0xf0, 0x38, 0x0,
    0x3f, 0x7, 0x0, 0x3, 0xf8, 0xe0, 0x0, 0x7f,
    0xdc, 0x0, 0x7, 0xff, 0x80, 0x0, 0x7f, 0xff,
    0x0, 0x3, 0xff, 0xfc, 0x0, 0x1f, 0xff, 0xc0,
    0x0, 0x3f, 0xfe, 0x0, 0x7, 0x7f, 0xe0, 0x0,
    0xe1, 0xfc, 0x0, 0x1c, 0x1f, 0xc0, 0x3, 0x81,
    0xf8, 0x0, 0x70, 0x1f, 0x0, 0xe, 0x3, 0xe0,
    0x1, 0xc0, 0x7c, 0x0, 0x38, 0xf, 0xb8, 0x7,
    0x3, 0xe7, 0xc0, 0xe0, 0xfd, 0xfe, 0x1c, 0x7f,
    0x1f, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xf0, 0xf,
    0xff, 0xfc, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x38,
    0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0xe0, 0x0,
    0x0, 0x1c, 0x0, 0x0, 0x3, 0x80, 0x0, 0x0,
    0x70, 0x0,

    /* U+00A3 "£" */
    0x0, 0x1, 0xff, 0x80, 0x0, 0x3f, 0xff, 0xc0,
    0x3, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xfe, 0x0,
    0xfe, 0x0, 0xf8, 0x7, 0xe0, 0x0, 0x40, 0x3f,
    0x0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x7, 0xe0,
    0x0, 0x0, 0x1f, 0x0, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0x1, 0xf0, 0x0, 0x0, 0x7, 0xc0, 0x0,
    0x0, 0x1f, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x3,
    0xff, 0xff, 0xfc, 0xf, 0xff, 0xff, 0xf0, 0x1,
    0xf0, 0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x1f,
    0x0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x1, 0xf0,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0x0, 0x7c, 0x0, 0x0, 0x1, 0xf0, 0x0,
    0x0, 0x7, 0xc0, 0x0, 0x0, 0x1f, 0x0, 0x0,
    0x0, 0x7c, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xfe,
    0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xef,
    0xff, 0xff, 0xff, 0x80,

    /* U+00A5 "¥" */
    0x7c, 0x0, 0x0, 0x3, 0xe7, 0xe0, 0x0, 0x0,
    0x3e, 0x3e, 0x0, 0x0, 0x7, 0xc1, 0xf0, 0x0,
    0x0, 0xf8, 0xf, 0x80, 0x0, 0xf, 0x80, 0xfc,
    0x0, 0x1, 0xf0, 0x7, 0xc0, 0x0, 0x3e, 0x0,
    0x3e, 0x0, 0x7, 0xe0, 0x1, 0xf0, 0x0, 0x7c,
    0x0, 0x1f, 0x80, 0xf, 0x80, 0x0, 0xf8, 0x1,
    0xf0, 0x0, 0x7, 0xc0, 0x1f, 0x0, 0x0, 0x3e,
    0x3, 0xe0, 0x0, 0x3, 0xf0, 0x7c, 0x0, 0x0,
    0x1f, 0x7, 0xc0, 0x0, 0x0, 0xf8, 0xf8, 0x0,
    0x0, 0x7, 0xdf, 0x0, 0x0, 0x0, 0x7f, 0xf0,
    0x0, 0x0, 0x3, 0xfe, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xe0, 0x7, 0xff, 0xff, 0xfe, 0x0, 0x7f,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0xf8, 0x0, 0x0,
    0x0, 0xf, 0x80, 0x0, 0x0, 0x0, 0xf8, 0x0,
    0x0, 0x0, 0xf, 0x80, 0x0, 0x7, 0xff, 0xff,
    0xfe, 0x0, 0x7f, 0xff, 0xff, 0xe0, 0x7, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0xf, 0x80, 0x0, 0x0,
    0x0, 0xf8, 0x0, 0x0, 0x0, 0xf, 0x80, 0x0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0xf, 0x80,
    0x0, 0x0, 0x0, 0xf8, 0x0, 0x0,

    /* U+20AC "€" */
    0x0, 0x0, 0x1f, 0xf8, 0x0, 0x0, 0x7, 0xff,
    0xf8, 0x0, 0x1, 0xff, 0xff, 0xf0, 0x0, 0x1f,
    0xff, 0xff, 0xc0, 0x3, 0xff, 0x0, 0xff, 0x80,
    0x3f, 0xc0, 0x0, 0xfc, 0x1, 0xf8, 0x0, 0x3,
    0x80, 0x1f, 0x80, 0x0, 0x8, 0x1, 0xf8, 0x0,
    0x0, 0x0, 0xf, 0x80, 0x0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xfe, 0x0, 0x7f, 0xff, 0xff, 0xf0,
    0x3, 0xff, 0xff, 0xff, 0x80, 0x0, 0xf8, 0x0,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x0, 0x3e,
    0x0, 0x0, 0x0, 0x1, 0xf0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0xff, 0xc0, 0xf, 0xff, 0xff, 0xfe,
    0x0, 0x7f, 0xff, 0xff, 0xf0, 0x0, 0xf, 0x80,
    0x0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x0, 0x3,
    0xf0, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x0, 0x1, 0xf8, 0x0,
    0x0, 0xc0, 0x7, 0xf0, 0x0, 0xf, 0x0, 0x1f,
    0xc0, 0x1, 0xfc, 0x0, 0x7f, 0xc0, 0x3f, 0xc0,
    0x1, 0xff, 0xff, 0xfc, 0x0, 0x3, 0xff, 0xff,
    0xc0, 0x0, 0x7, 0xff, 0xf8, 0x0, 0x0, 0x7,
    0xfc, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 497, .box_w = 27, .box_h = 48, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 162, .adv_w = 517, .box_w = 30, .box_h = 35, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 566, .box_w = 36, .box_h = 35, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 646, .box_w = 37, .box_h = 35, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x7f, 0x81, 0x2088
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 36, .range_length = 8329, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 1,
    4, 1
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -8, -2
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 2,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_customer_font_montserratMedium_50 = {
#else
lv_font_t lv_customer_font_montserratMedium_50 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 48,          /*The maximum line height required by the font*/
    .base_line = 6,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -4,
    .underline_thickness = 3,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_CUSTOMER_FONT_MONTSERRATMEDIUM_50*/
