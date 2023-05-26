
# Copyright 2023 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

lv.init()
SDL.init(w=296,h=128)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(296*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 296
disp_drv.ver_res = 128
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init()
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, show_second, use_ampm):
    datetime = time.localtime()
    hour = datetime[3]
    ampm = 'AM'
    if use_ampm:
        if hour > 12:
            hour = hour % 12
            ampm = 'PM'
        if show_second:
            obj.set_text("%02d:%02d:%02d %s" %(hour, datetime[4], datetime[5], ampm))
        else:
            obj.set_text("%02d:%02d %s" %(hour, datetime[4], ampm))
    else:
        if show_second:
            obj.set_text("%02d:%02d:%02d" %(hour, datetime[4], datetime[5]))
        else:
            obj.set_text("%02d:%02d" %(hour, datetime[4]))

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def screen_ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)

# Create screen
screen = lv.obj()
screen.set_size(296, 128)
screen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_eanBarcode
screen_eanBarcode = lv.barcode(screen)
screen_eanBarcode.set_height(40)
screen_eanBarcode.set_scale(1)
screen_eanBarcode.set_dark_color(lv.color_hex(0x000000))
screen_eanBarcode.set_light_color(lv.color_hex(0xffffff))
screen_eanBarcode.update("0000000000000")
screen_eanBarcode.set_pos(158, 67)

# Create screen_eanLabel
screen_eanLabel = lv.label(screen)
screen_eanLabel.set_text("0000000000000")
screen_eanLabel.set_long_mode(lv.label.LONG.WRAP)
screen_eanLabel.set_pos(158, 107)
screen_eanLabel.set_size(123, 10)
screen_eanLabel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_eanLabel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_eanLabel.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_text_font(test_font("Abel_regular", 11), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_text_letter_space(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_pad_left(3, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_eanLabel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_eanQRCode
screen_eanQRCode = lv.qrcode(screen, 50, lv.color_hex(0x2C3224), lv.color_hex(0xffffff))
screen_eanQRCode_data = "0000000000000"
screen_eanQRCode.update(screen_eanQRCode_data, len(screen_eanQRCode_data))
screen_eanQRCode.set_pos(231, 14)
screen_eanQRCode.set_size(50, 50)

# Create screen_currencyLabel
screen_currencyLabel = lv.label(screen)
screen_currencyLabel.set_text("€")
screen_currencyLabel.set_long_mode(lv.label.LONG.WRAP)
screen_currencyLabel.set_pos(12, 14)
screen_currencyLabel.set_size(50, 50)
screen_currencyLabel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_currencyLabel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_currencyLabel.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_border_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_text_font(test_font("montserratMedium", 50), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_currencyLabel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_priceLabel
screen_priceLabel = lv.label(screen)
screen_priceLabel.set_text("99.99")
screen_priceLabel.set_long_mode(lv.label.LONG.WRAP)
screen_priceLabel.set_pos(62, 14)
screen_priceLabel.set_size(150, 50)
screen_priceLabel.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_priceLabel, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_priceLabel.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_text_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_text_font(test_font("montserratMedium", 40), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_pad_top(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_priceLabel.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# content from custom.py

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)

