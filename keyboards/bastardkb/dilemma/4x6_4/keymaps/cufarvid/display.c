#include "display.h"

static painter_device_t      lcd;
static painter_font_handle_t font;

const os_info_t os_info(void) {
    os_info_t    result;
    os_variant_t detected_os = detected_host_os();

    switch (detected_os) {
        case OS_LINUX:
            result.name = "Linux";
            result.icon = "\uF303";
            break;
        case OS_WINDOWS:
            result.name = "Windows";
            result.icon = "\uE62A";
            break;
        case OS_MACOS:
            result.name = "MacOS";
            result.icon = "\uF302";
            break;
        case OS_IOS:
            result.name = "iOS";
            result.icon = "\uF302";
            break;
        case OS_UNSURE:
        default:
            result.name = "Unknown";
            result.icon = "\uF128";
            break;
    }

    return result;
}

const char *layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            return "Colemak DH";
        case _NAV:
            return "Nav";
        case _NUM:
            return "Num";
        case _MOUSE:
            return "Mouse";
        case _SYM:
            return "Sym";
        case _MEDIA:
            return "Media";
        case _FUN:
            return "Fun";
        case _MISC:
            return "Misc";
        case _UTF:
            return "Unicode";
        default:
            return "Unknown";
    }
}

void keyboard_post_init_kb(void) {
    lcd = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);
    qp_init(lcd, QP_ROTATION_0);
    qp_clear(lcd);

    font = qp_load_font_mem(font_fira_code_nerd);

    // Draw the background
    qp_rect(lcd, 0, 0, 240, 240, 0, 0, 0, true);

    // OS name
    qp_drawtext(lcd, 50, (240 / 2) + (font->line_height * 1), font, os_info().icon);
}

void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;

    // Throttle to 30fps
    if (timer_elapsed32(last_draw) > 33) {
        int  fixedLength = 16;
        char paddedStr[fixedLength + 1];

        // Layer name
        snprintf(paddedStr, sizeof(paddedStr), "%-*s", fixedLength, layer_name());
        qp_drawtext(lcd, 50, (240 / 2) + (font->line_height * 2), font, paddedStr);

        // WPM
        snprintf(paddedStr, sizeof(paddedStr), "%-*d", fixedLength, get_current_wpm());
        qp_drawtext(lcd, 50, (240 / 2) + (font->line_height * 3), font, paddedStr);

        // Led state
        static led_t last_led_state = {0};
        if (last_led_state.raw != host_keyboard_led_state().raw) {
            last_led_state.raw = host_keyboard_led_state().raw;

            // Caps lock
            snprintf(paddedStr, sizeof(paddedStr), "%-*s", fixedLength, last_led_state.caps_lock ? "Caps Lock" : "");
            qp_drawtext(lcd, 50, (240 / 2) + (font->line_height * 4), font, paddedStr);
        }

        qp_flush(lcd);
        last_draw = timer_read32();
    }
}
