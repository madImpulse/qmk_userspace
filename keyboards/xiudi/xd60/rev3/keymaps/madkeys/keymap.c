// Copyright 2025 the madImpulse
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "madkeys.h"

#define LAYOUT_wrapper(...)  LAYOUT_60_ansi_split_bs_rshift_space (__VA_ARGS__)

enum madddz64_layers {
  _MADBASE,
  _MADLOWER,
  _MADRAISE,
  _MADSET
};

#define MADNAVLAYER _MADLOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Mad Base Layer - Default Layer
     * ,--------------------------------------------------------------------,
     * |` ~ |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Del |Bksp      |
     * |--------------------------------------------------------------------+
     * |Tab   |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[ {|] }|\ |          |
     * |--------------------------------------------------------------------+
     * |Ctl/Esc|A  |S  |D  |F  |G  |H  |J  |K  |L  |; :|' "|    Enter       |
     * |--------------------------------------------------------------------+
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |, <|. >|/ ?|Shift | Up |RShift |
     * |--------------------------------------------------------------------+
     * |Ctrl|Win |Alt |  Lower/Space  |  Raise/Space |Alt |Ctl|Left|Down|Rgt|
     * `--------------------------------------------------------------------'
     */
    [_MADBASE] = LAYOUT_wrapper(
        KC_GRV,         MADROWNUM,                                                                                                  KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,         MADROWQ,                                                                                                             KC_LBRC, KC_RBRC, KC_BSLS,
        MADCTL,         MADROWA,                                                                                                             KC_NO,            KC_ENT,
        KC_LSFT, _______, MADROWZ,                                                                                                           MADRSFT,  KC_UP,  MADRSFT,
        KC_LCTL, KC_LGUI, MADLALTENT,                   LT(_MADLOWER, KC_SPC), LT(_MADRAISE, KC_SPC),         KC_SPC, MADRALTENT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    /* Mad Lower Layer - Navigation & Function Keys
     * ,---------------------------------------------------------------------,
     * |~ ~ |F9 |F10|F11|F12|   |   |   |   |   |   |   |   |    |           |
     * |---------------------------------------------------------------------+
     * |`    |F5 |F6 |F7 |F8 |   |PgUp|Home|Up |End|   |   |   |             |
     * |---------------------------------------------------------------------+
     * |Del   |F1 |F2 |F3 |F4 |   |PgDn|Left|Down|Rght|   |   |              |
     * |---------------------------------------------------------------------+
     * |       |   |   |   |   |Brk|   |   |   |   |   |      |   |          |
     * |---------------------------------------------------------------------+
     * |    |    |    |    Space      |   Set   |     |   |   |   |   |      |
     * `---------------------------------------------------------------------'
     */
    [_MADLOWER] = LAYOUT_wrapper(
        KC_TILD,        MADROWNUMLOW,                                                                                              _______, _______,  _______, _______,
        KC_TILD,        MADROWQLOW,                                                                                                          _______, _______, _______,
        KC_DEL ,        MADROWALOW,                                                                                                                   _______, _______,
        _______, _______, MADROWZLOW,                                                                                                       _______,  _______, _______,
        _______, _______, _______,                   _______, MO(_MADSET), _______,                                        _______, _______, _______, _______, _______
    ),

    /* Mad Raise Layer - Symbols & Numbers
     * ,--------------------------------------------------------------------,
     * |    |1! |2@ |3# |4$ |5% |6^ |7& |8* |9( |0) |   |   |    |Power     |
     * |--------------------------------------------------------------------+
     * |`    |!  |@  |#  |$  |%  |^  |&  |*  |(  |)  |   |   |              |
     * |--------------------------------------------------------------------+
     * |~     |\ ||: |; |- |[ |] |_ |+ |{ |} |   |                          |
     * |--------------------------------------------------------------------+
     * |   ~   || |: |; |- |[ |] |_ |< |> |? |      |    |   |              |
     * |--------------------------------------------------------------------+
     * |    |    |    |     Set     |           |     |   |   |   |   |     |
     * `--------------------------------------------------------------------'
     */
    [_MADRAISE] = LAYOUT_wrapper(
        _______,      MADROWNUMRAI,                                                                                                   _______, _______,  _______,  KC_SYSTEM_POWER,
        MADTABRAI,    MADROWQRAI,                                                                                                              _______,  _______,  _______,
        MADCAPSRAI,   MADROWARAI,                                                                                                                        _______,  _______,
        MADLSFTRAI,   _______,  MADROWZRAI,                                                                                                    _______, _______, _______,
        _______,      _______, _______,                   MO(_MADSET),  _______,  _______,                                     _______, _______, _______, _______, _______
    ),

    /* Mad Settings Layer - RGB & System Controls
     * ,---------------------------------------------------------------------,
     * |XXX |RGB |Brth|Rain|Swrl|Snke|Kngt|Xmas|Grad|Test|   |   |   |Boot|  |
     * |---------------------------------------------------------------------+
     * |Make |Tog|Next|Hue+|Sat+|Val+|Spd+|   |   |   |   |   |   |Boot      |
     * |---------------------------------------------------------------------+
     * |Boot  |   |Prev|Hue-|Sat-|Val-|Spd-|   |   |   |   |   |             |
     * |---------------------------------------------------------------------+
     * |       |   |   |   |   |BL- |BL |BL+ |Step|   |   |    |   |         |
     * |---------------------------------------------------------------------+
     * |    |    |    |              |           |     |   |   |   |   |     |
     * `---------------------------------------------------------------------'
     */
    [_MADSET] = LAYOUT_wrapper(
        XXXXXXX, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, _______, _______, _______, QK_BOOTLOADER, _______,
        QK_MAKE, UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, _______, _______, _______, _______, _______, _______, QK_BOOT,
        QK_BOOT, _______, UG_PREV, UG_HUED, UG_SATD, UG_VALD, UG_SPDD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
