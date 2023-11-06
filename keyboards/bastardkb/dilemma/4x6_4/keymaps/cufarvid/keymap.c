/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 * Copyright 2023 cufarvid <vid@cufar.dev> (@cufarvid)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    _BASE = 0,
    _NAV,
    _NUM,
    _MOUSE,
    _SYM,
    _MEDIA,
    _FUN,
    _MISC
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

// Layer toggles
#define SPC_NAV   LT(_NAV,   KC_SPC)
#define BSPC_NUM  LT(_NUM,   KC_BSPC)
#define TAB_MOUSE LT(_MOUSE, KC_TAB)
#define ENT_SYM   LT(_SYM,   KC_ENT)
#define ESC_MEDIA LT(_MEDIA, KC_ESC)
#define DEL_FUN   LT(_FUN,   KC_DEL)
#define PT_Z      LT(_MISC,  KC_Z)
#define PT_SLSH   LT(_MISC,  KC_SLSH)

// Clipboard shortcuts
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

// Left-hand home row mods
#define GUI_A  LGUI_T(KC_A)
#define ALT_R  LALT_T(KC_R)
#define SFT_S  LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)

// Right-hand home row mods
#define CTRL_N RCTL_T(KC_N)
#define SFT_E  RSFT_T(KC_E)
#define ALT_I  LALT_T(KC_I)
#define GUI_O  RGUI_T(KC_O)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,  KC_2,    KC_3,      KC_4,    KC_5,      KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q,  KC_W,    KC_F,      KC_P,    KC_B,      KC_J,    KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_BSLS,
        KC_LSFT, GUI_A, ALT_R,   SFT_S,     CTRL_T,  KC_G,      KC_M,    CTRL_N,   SFT_E,   ALT_I,  GUI_O,   KC_QUOT,
        KC_LCTL, PT_Z,  KC_X,    KC_C,      KC_D,    KC_V,      KC_K,    KC_H,     KC_COMM, KC_DOT, PT_SLSH, KC_RALT,
                        KC_LALT, ESC_MEDIA, SPC_NAV, TAB_MOUSE, ENT_SYM, BSPC_NUM, DEL_FUN, KC_MUTE
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, U_RDO,   U_PST,    U_CPY,   U_CUT,   U_UND,   XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
                          XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_ENT,  KC_BSPC,  KC_DEL,  XXXXXXX
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
        XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, KC_DOT,  KC_0,    KC_MINS, XXXXXXX, _______, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,     XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, U_RDO,   U_PST,      U_CPY,      U_CUT,    U_UND,       XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    SNIPING,    DRGSCRL,  XXXXXXX,     XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN3, KC_BTN1,    KC_BTN2,    XXXXXXX
    ),

    [_SYM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
        XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, KC_LPRN, KC_GRV,  KC_UNDS, XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),

    [_MEDIA] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV,  KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
    ),

    [_FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
        XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),

    [_MISC] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX
    ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_NAV]        = {ENCODER_CCW_CW(  KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [_NUM]        = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_MOUSE]      = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_SYM]        = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_MEDIA]      = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_FUN]        = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_MISC]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

void shutdown_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_sethsv_noeeprom(HSV_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}
