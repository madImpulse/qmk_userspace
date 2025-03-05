/*
Copyright 2021 keebnewb

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "madkeys.h"

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /*
//      * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
//      * │ Esc │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
//      * ├─────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
//      * │  Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
//      * ├───────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
//      * │  Caps  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
//      * ├────────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
//      * │   Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
//      * ├─────┬────┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
//      * │Ctrl │ GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
//      * └─────┴─────┴────┴────────────────────────┴────┴────┴────┴────┘
//      */
//     [0] = LAYOUT_60_utilitarian_iso_split(
//         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
//         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,
//         KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUBS,
//         KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP, KC_RSFT,
//         KC_LCTL, KC_LGUI, KC_LALT,       MO(1),             KC_SPC,         MO(1),                              MO(1), KC_RCTL, KC_LEFT,   KC_DOWN,  MO(1)
//     ),

//     [1] = LAYOUT_60_utilitarian_iso_split(
//         QK_BOOT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
//         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,
//         KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUBS,
//         KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP, KC_RSFT,
//         KC_LCTL, KC_LGUI, KC_LALT,      KC_SPC,             KC_SPC,        KC_SPC,                              KC_RALT, KC_RCTL, KC_LEFT,   KC_DOWN, KC_RIGHT
//     ),
// };

#define LAYOUT_wrapper(...)  LAYOUT_60_utilitarian_iso_split(__VA_ARGS__)

enum saturn60_layers {
  _MADBASE,
  _MADLOWER,
  _MADRAISE,
  _MADSET
};

#define MADNAVLAYER _MADLOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MADBASE] = LAYOUT_wrapper(
        KC_GRV,         MADROWNUM,                                                                                                  KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,         MADROWQ,                                                                                                             KC_LBRC, KC_RBRC, KC_BSLS,
        MADCTL,         MADROWA,                                                                                                                               KC_ENT,
        KC_LSFT,        MADROWZ,                                                                                                             KC_RSFT, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, MADLALTENT,             LT(_MADLOWER, KC_SPC),  KC_SPC,  LT(_MADRAISE, KC_SPC),               MADRALTENT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_MADLOWER] = LAYOUT_wrapper(
        KC_TILD,        MADROWNUMLOW,                                                                                              _______, _______,  _______, _______,
        KC_TILD,        MADROWQLOW,                                                                                                          _______, _______, _______,
        KC_DEL ,        MADROWALOW,                                                                                                                            _______,
        _______,        MADROWZLOW,                                                                                                          _______, _______, _______,
        _______, _______, _______,                   _______,  _______,  MO(_MADSET),                                      _______, _______, _______, _______, _______
    ),

    [_MADRAISE] = LAYOUT_wrapper(
        _______,    MADROWNUMRAI,                                                                                                   _______, _______,  _______,  KC_SYSTEM_POWER,
        MADTABRAI,  MADROWQRAI,                                                                                                              _______,  _______,  _______,
        MADCAPSRAI, MADROWARAI,                                                                                                                                  _______,
        MADLSFTRAI, MADROWZRAI,                                                                                                           MADRSFTRAI, _______, _______,
        _______,  _______, _______,                   MO(_MADSET),  _______,  _______,                                     _______, _______, _______, _______, _______
    ),

    [_MADSET] = LAYOUT_wrapper(
        _______, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, _______, _______, _______, QK_BOOTLOADER, QK_BOOTLOADER,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
