/* Copyright 2022 Jason Wihardja
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
#include "raw_hid.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),

};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  switch(data[0])
  {
    case 1:
      rgblight_sethsv_noeeprom(HSV_ORANGE);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case 2:
      rgblight_sethsv_noeeprom(HSV_GREEN);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case 3:
      rgblight_sethsv_noeeprom(HSV_ORANGE);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
      break;
    case 4:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
      break;
    case 5:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
      break;

    default:
      rgblight_sethsv_noeeprom(HSV_RED);
  }
}
