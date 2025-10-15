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
    [_MADBASE] = LAYOUT_wrapper(
        KC_GRV,         MADROWNUM,                                                                                                  KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,         MADROWQ,                                                                                                             KC_LBRC, KC_RBRC, KC_BSLS,
        MADCTL,         MADROWA,                                                                                                             KC_NO,            KC_ENT,
        KC_LSFT, _______, MADROWZ,                                                                                                           MADRSFT,  KC_UP,  MADRSFT,
        KC_LCTL, KC_LGUI, MADLALTENT,                   LT(_MADLOWER, KC_SPC), LT(_MADRAISE, KC_SPC),         KC_SPC, MADRALTENT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_MADLOWER] = LAYOUT_wrapper(
        KC_TILD,        MADROWNUMLOW,                                                                                              _______, _______,  _______, _______,
        KC_TILD,        MADROWQLOW,                                                                                                          _______, _______, _______,
        KC_DEL ,        MADROWALOW,                                                                                                                   _______, _______,
        _______, _______, MADROWZLOW,                                                                                                       _______,  _______, _______,
        _______, _______, _______,                   _______, MO(_MADSET), _______,                                        _______, _______, _______, _______, _______
    ),

    [_MADRAISE] = LAYOUT_wrapper(
        _______,      MADROWNUMRAI,                                                                                                   _______, _______,  _______,  KC_SYSTEM_POWER,
        MADTABRAI,    MADROWQRAI,                                                                                                              _______,  _______,  _______,
        MADCAPSRAI,   MADROWARAI,                                                                                                                        _______,  _______,
        MADLSFTRAI,   _______,  MADROWZRAI,                                                                                                    _______, _______, _______,
        _______,      _______, _______,                   MO(_MADSET),  _______,  _______,                                     _______, _______, _______, _______, _______
    ),

    [_MADSET] = LAYOUT_wrapper(
        XXXXXXX, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, _______, _______, _______, QK_BOOTLOADER, _______,
        QK_MAKE, RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, _______, _______, _______, _______, _______, _______, QK_BOOT,
        QK_BOOT, _______, RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
