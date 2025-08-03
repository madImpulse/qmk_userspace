/* Copyright 2025 the madImpulse
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
#include "madkeys.h"

#define LAYOUT_wrapper(...)  LAYOUT_ansi_82 (__VA_ARGS__)

enum layers{
    STANDARD_LAYOUT,
    STANDARD_FN,
    MAD_BASE,
    MAD_LOWER,
    MAD_RAISE,
    MAD_FN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define MADNAVLAYER MAD_LOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [STANDARD_LAYOUT] = LAYOUT_ansi_82(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_PGUP,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 MO(MAD_FN), KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [STANDARD_FN] = LAYOUT_ansi_82(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  KC_SYSTEM_POWER,
        _______,  RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT,  _______,  _______,  _______,  _______,  _______,           _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

    [MAD_BASE] = LAYOUT_wrapper(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_PGUP,
        KC_GRV,   MADROWNUM,                                                                                          KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        KC_TAB,   MADROWQ,                                                                                            KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        MADCTL,   MADROWA,                                                                                                                RCTL_T(KC_ENTER),   KC_END,
        KC_LSFT,  MADROWZ,                                                                                                                KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LWIN,  LT(MAD_LOWER, KC_LALT),                            LT(MAD_RAISE, KC_SPC),               MADRALTENT, KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAD_LOWER] = LAYOUT_wrapper(
        _______,           _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   MADROWNUMLOW,                                                                                     _______,  _______,  _______,            _______,
        _______,   MADROWQLOW,                                                                                       _______,  _______,  _______,            _______,
        _______,   MADROWALOW,                                                                                                           _______,            _______,
        _______,   MADROWZLOW,                                                                                                           _______,  _______,
        _______,   _______,  MO(MAD_FN),                          _______,                              MO(MAD_FN),  _______,  _______,  _______,  _______,  _______),

    [MAD_RAISE] = LAYOUT_wrapper(
        _______,           _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SYSTEM_POWER,
        _______,      MADROWNUMRAI,                                                                                     _______,  _______,  _______,            _______,
        MADTABRAI,    MADROWQRAI,                                                                                       _______,  _______,  _______,            _______,
        MADCAPSRAI,   MADROWARAI,                                                                                                           _______,            _______,
        MADLSFTRAI,   MADROWZRAI,                                                                                                           _______,  _______,
        _______,         _______,  _______,                                _______,                        MO(MAD_FN),  _______,  _______,  _______,  _______,  _______),

    [MAD_FN] = LAYOUT_ansi_82(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  QK_BOOTLOADER,  _______,
        QK_MAKE,  RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT,  _______,  _______,  _______,  _______,  _______,           _______,
        QK_BOOTLOADER,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};
