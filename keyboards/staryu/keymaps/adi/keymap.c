/*
Copyright 2018 Kenneth Aloysius

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
#include "action_layer.h"

#include "../../backlight_staryu.h"

bool has_layer_changed = false;
static uint8_t current_layer;

enum layers {
  _LAYER0,
  _LAYER1,
  _LAYER2,
};


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  LAYOUT( KC_UP,  TO(_LAYER1), KC_LEFT,KC_DOWN,KC_RIGHT ),
  LAYOUT( S(KC_UP),  TO(_LAYER2), S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT) ),
  LAYOUT( LALT(LGUI(KC_UP)),  TO(_LAYER0), LCAG(KC_UP), LALT(LGUI(KC_DOWN)), LCAG(KC_DOWN) ),
  // LAYOUT( RGB_VAI, TO(_LAYER0), RGB_SAD, RGB_VAD, RGB_SAI )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (current_layer == layer) {
    has_layer_changed = false;
  } else {
    has_layer_changed = true;
    current_layer = layer;
  }

  if (has_layer_changed) {
    switch (layer) {
      case 0:
        rgblight_sethsv(0, 255, 64);
        break;
      case 1:
        rgblight_sethsv(255/3 * 1, 255, 64);
        break;
      case 2:
        rgblight_sethsv(255/3 * 2, 255, 64);
        break;
    }
  }
}

void led_set_user(uint8_t usb_led) {
}

void matrix_init_user(void) {
  rgblight_enable();
  rgblight_sethsv(0, 255, 64);
  rgblight_mode(1);
}

