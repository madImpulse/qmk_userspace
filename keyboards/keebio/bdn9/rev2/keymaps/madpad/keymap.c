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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum madbdn9pad_leyers {
    _MADMEDIA,
    _MADRGB,
    _MADARROWS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        various F-Keys to be used as shortcuts
        and normal media keys in lower row
     */
    [_MADMEDIA] = LAYOUT(
        RALT(KC_F13), RALT(KC_F15), RALT(KC_F17),
        MO(1), RCTL(KC_F15), MO(2),
        KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK
    ),
    /*
        rgb control
        | val         | hue          | sat         |
        | n/a         | rgb spd inc  | rgb next    |
        | rgb toggle  | rgb spd dec  | rgb prev    |
     */
    [_MADRGB] = LAYOUT(
        _______,   _______, _______,
        _______, RM_SPDU, RM_NEXT,
        RM_TOGG, RM_SPDD, RM_PREV
    ),
    /*
        emergency arrow mode
        | n/a         | n/a         | bootloader   |
        | enter       | up          | n/a          |
        | left        | down        | right        |
     */
    [_MADARROWS] = LAYOUT(
        _______, _______, QK_BOOTLOADER,
        KC_ENTER, KC_UP, _______,
        KC_LEFT, KC_DOWN, KC_RIGHT
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    /* somehow clock orientation is mixed up */
    if (layer_state_is(_MADMEDIA))
    {
        if (index == _LEFT)
        {
            if (clockwise) {
                tap_code(KC_F13);
            } else {
                tap_code(KC_F14);
            }
        }
        else if (index == _MIDDLE)
        {
            if (clockwise) {
                tap_code(KC_F15);
            } else {
                tap_code(KC_F16);
            }
        }
        else if (index == _RIGHT)
        {
            if (clockwise) {
                tap_code(KC_F17);
            } else {
                tap_code(KC_F18);
            }
        }
    }
    else
    {
        if (index == _LEFT)
        {
            if (!clockwise) {
                rgblight_increase_val_noeeprom();
            } else {
                rgblight_decrease_val_noeeprom();
            }
        }
        else if (index == _MIDDLE)
        {
            if (!clockwise) {
                rgblight_increase_hue_noeeprom();
            } else {
                rgblight_decrease_hue_noeeprom();
            }
        }
        else if (index == _RIGHT)
        {
            if (!clockwise) {
                rgblight_increase_sat_noeeprom();
            } else {
                rgblight_decrease_sat_noeeprom();
            }
        }
    }
    return false;
}
