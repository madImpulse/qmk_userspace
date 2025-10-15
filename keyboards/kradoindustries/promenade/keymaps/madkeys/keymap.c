/*
Copyright 2025 the madImpulse
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

// Layer shorthand
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LAYOUT_promenade_grid_wrapper(...) LAYOUT_all(__VA_ARGS__)

#define MADNAVLAYER _LOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |CTRL/ESC| A      | S      | D      | F      | G      |        |        | H      | J      | K      | L      | ;/LOWER| CTL '  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | PG UP  | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | FN(ADJ)| LGUI   | LALT   | SP(LO) | SPACE           | SP(RAI)         | ENTER  | LEFT   | DOWN   | UP     | RIGHT  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_promenade_grid_wrapper(
        KC_GRV,  MADROW12345,                                       KC_MINS, KC_EQL,   MADROW67890,                                      MADBSPC,
        KC_TAB,  MADROWQWERT,                                       KC_LBRC, KC_RBRC,  MADROWYUIOP,                                      MADDEL,
        MADCTL,  MADROWASDFG,                                       _______, _______,  MADROWHJKL, MADROWSEMICOL,                        MADQUOT,
        KC_LSFT, MADROWZXCVB,                                       KC_PGUP,  KC_PGDN, MADROWNMCDS,                                      KC_RSFT,
        KC_LCTL, MO(_ADJUST), KC_LGUI, MADLALTENT, LT(_LOWER, KC_SPC), KC_SPC,  KC_SPC,  LT(_RAISE, KC_SPC),  MADRALTENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    [_LOWER] = LAYOUT_promenade_grid_wrapper(
        _______,  MADROW12345LOW,                                   _______, _______,  MADROW67890LOW,                                   MADBSPCLOW,
        _______,  MADROWQWERTLOW,                                   _______, _______,  MADROWYUIOPLOW,                                   MADDELLOW,
        _______,  MADROWASDFGLOW,                                   _______, _______,  MADROWHJKLLOW, MADROWSEMICOLLOW,                 MADQUOTLOW,
        _______,  MADROWZXCVBLOW,                                   _______, _______,  MADROWNMCDSLOW,                                  _______,
        _______,  _______, _______, _______, _______,  _______,      _______,      MO(_ADJUST),  _______, _______, _______,   _______, _______
    ),

    [_RAISE] = LAYOUT_promenade_grid_wrapper(
        _______,  MADROW12345RAI,                                   _______, _______,  MADROW67890RAI,                                   MADBSPCRAI,
        MADTABRAI,  MADROWQWERTRAI,                                 KC_LPRN, KC_RPRN,  MADROWYUIOPRAI,                                   MADDELRAI,
        MADCAPSRAI,  MADROWASDFGRAI,                                _______, _______,  MADROWHJKLRAI, MADROWSEMICOLRAI,                  MADQUOTRAI,
        MADLSFTRAI,  MADROWZXCVBRAI,                                KC_HOME,  KC_END,  MADROWNMCDSRAI,                                   _______,
        _______,  _______, _______, _______, MO(_ADJUST), _______,       _______,      _______,  _______, _______, _______,   _______, _______
    ),

    [_ADJUST] = LAYOUT_all(
        XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        QK_MAKE, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_MPLY, KC_MSTP, UG_TOGG, UG_NEXT, UG_SPDD, UG_SPDU, KC_PSCR, _______,
        QK_BOOT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, UG_HUEU, UG_SATU, UG_VALU, RGB_M_P, RGB_M_G, QK_BOOT,
        _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______, QK_BOOT
    )
};
