/* Copyright 2025 the madImpulse */

#pragma once
#include QMK_KEYBOARD_H

/* special keys used in all layouts */

/* other special keys commonly used, but not everywhere in "row" */
#define MADCTL           LCTL_T(KC_ESC)
#define MADRSFT          RSFT_T(KC_SLSH)
#define MADENTRSFT       RSFT_T(KC_ENTER)

#define MADTABRAI        KC_GRV
#define MADCAPSRAI       S(KC_GRV)
#define MADLSFTRAI       KC_PIPE
#define MADRSFTRAI       KC_QUES

#define MADRALTENT       RALT_T(KC_ENTER)
#define MADLALTENT       LALT_T(KC_ENTER)

/* righmost row for narrow layouts e.g. 60% */

#define MADBSPC          KC_BSPC
#define MADDEL           KC_DEL
#define MADQUOT          LCTL_T(KC_QUOT)

#define MADBSPCRAI       _______
#define MADDELRAI        KC_EQL
#define MADQUOTRAI       KC_PLUS

#define MADBSPCLOW       _______
#define MADDELLOW        _______
#define MADQUOTLOW       _______

/* base keys */

/* Qwerty, see "full rows"
 * --------------------------------------  -------------------------------------
 *   |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |
 * --+------+------+------+------+------+  +------+------+------+------+------+-
 *   |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |
 * --+------+------+------+------+-------  -------+------+------+------+------+------|-
 *   |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * --+------+------+------+------+------|  |------+------+------+------+------+------|-
 *   |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |
 * --+------+------+------+------+------+  +------+------+------+------+------+--
 */

#define MADROW12345  KC_1, KC_2, KC_3, KC_4, KC_5
#define MADROWQWERT  KC_Q, KC_W, KC_E, KC_R, KC_T
#define MADROWASDFG  KC_A, KC_S, KC_D, KC_F, KC_G
#define MADROWZXCVB  KC_Z, KC_X, KC_C, KC_V, KC_B

#define MADROW67890  KC_6, KC_7, KC_8, KC_9, KC_0
#define MADROWYUIOP  KC_Y, KC_U, KC_I, KC_O, KC_P
#define MADROWHJKL   KC_H, KC_J, KC_K, KC_L
#define MADROWNM     KC_N, KC_M

#define MADROWSEMICOL LT(MADNAVLAYER, KC_SCLN)
#define MADROWCOMDOT  KC_COMM,  KC_DOT
/* full split */
#define MADROWHJKLSQ MADROWHJKL, MADROWSEMICOL, MADQUOT
#define MADROWNMCDS  MADROWNM, MADROWCOMDOT, KC_SLASH
/* full rows */
#define MADROWNUM     MADROW12345, MADROW67890
#define MADROWQ       MADROWQWERT, MADROWYUIOP
#define MADROWA       MADROWASDFG, MADROWHJKLSQ
#define MADROWZ       MADROWZXCVB, MADROWNMCDS

/* lower layer */
/* layer 3 in elora vial */

/* Lower, F-keys and navigation, see "full rows"
 * --------------------------------------  -------------------------------------
 *   |      |      |      |      |      |  |      |      |      |      |      |
 * --+------+------+------+------+------+  +------+------+------+------+------+-
 *   |  F9  |  F10 |  F11 |  F12 |      |  | PGUP | HOME |  UP  | END  |      |
 * --+------+------+------+------+-------  -------+------+------+------+------+------|-
 *   |  F5  |  F6  |  F7  |  F8  |      |  | PGDN | LEFT | DOWN | RGHT |      |      |
 * --+------+------+------+------+------|  |------+------+------+------+------+------|-
 *   |  F1  |  F2  |  F3  |  F4  |      |  |  BRK |      |      |      |      |
 * --+------+------+------+------+------+  +------+------+------+------+------+--
 */

/* F keys */
#define MADROW12345LOW  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define MADROWQWERTLOW  KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX
#define MADROWASDFGLOW  KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX
#define MADROWZXCVBLOW  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX
/* navigation */
#define MADROW67890LOW  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define MADROWYUIOPLOW  KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX
#define MADROWHJKLLOW   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT
#define MADROWNMLOW     KC_BRK,  XXXXXXX

#define MADROWSEMICOLLOW  XXXXXXX
#define MADROWCOMDOTLOW   XXXXXXX, XXXXXXX
/* full split */
#define MADROWHJKLSQLOW MADROWHJKLLOW, MADROWSEMICOLLOW, MADQUOTLOW
#define MADROWNMCDSLOW  MADROWNMLOW, MADROWCOMDOTLOW, XXXXXXX

/* full rows */
#define MADROWNUMLOW     MADROW12345LOW, MADROW67890LOW
#define MADROWQLOW       MADROWQWERTLOW, MADROWYUIOPLOW
#define MADROWALOW       MADROWASDFGLOW, MADROWHJKLSQLOW
#define MADROWZLOW       MADROWZXCVBLOW, MADROWNMCDSLOW

/* raise layer */
/* layer 4 in elora vial */

/* Lower, F-keys and navigation, see "full rows"
 * --------------------------------------  -------------------------------------
 *   |      |      |      |      |      |  |      |      |      |      |      |
 * --+------+------+------+------+------+  +------+------+------+------+------+-
 *   |  1   |   2  |   3  |   4  |   5  |  |  6   |  7   |  8   |  9   |   0  |
 * --+------+------+------+------+-------  -------+------+------+------+------+------|-
 *   |  !   |   @  |   #  |   $  |   %  |  |  ^   |  &   |  *   |  (   |   )  |  +   |
 * --+------+------+------+------+------|  |------+------+------+------+------+------|-
 *   |  \   |   :  |   ;  |   -  |   [  |  |  ]   |  _   |  ,   |  .   |   /  |
 * --+------+------+------+------+------+  +------+------+------+------+------+--
 */

#define MADROW12345RAI  _______, _______, _______, _______, _______
#define MADROWQWERTRAI  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define MADROWASDFGRAI  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define MADROWZXCVBRAI  KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC

#define MADROW67890RAI  _______, _______, _______, _______, _______
#define MADROWYUIOPRAI  KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define MADROWHJKLRAI   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN
#define MADROWNMRAI     KC_RBRC, KC_UNDS

#define MADROWSEMICOLRAI  KC_RPRN
#define MADROWCOMDOTRAI   KC_COMM,  KC_DOT
/* full split */
#define MADROWHJKLSQRAI MADROWHJKLRAI, MADROWSEMICOLRAI, MADQUOTRAI
#define MADROWNMCDSRAI  MADROWNMRAI, MADROWCOMDOTRAI, KC_SLASH
/* full rows */
#define MADROWNUMRAI     MADROW12345RAI, MADROW67890RAI
#define MADROWQRAI       MADROWQWERTRAI, MADROWYUIOPRAI
#define MADROWARAI       MADROWASDFGRAI, MADROWHJKLSQRAI
#define MADROWZRAI       MADROWZXCVBRAI, MADROWNMCDSRAI
