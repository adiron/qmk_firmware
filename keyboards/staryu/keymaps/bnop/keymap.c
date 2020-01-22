#include QMK_KEYBOARD_H
#include "action_layer.h"

#include "../../backlight_staryu.h"

bool has_layer_changed = false;
static uint8_t current_layer;

enum custom_keycodes {
  DANI = SAFE_RANGE,
  BACON,
  HOVAV,
  OPPENHEIM,
  EXCUSE1,
  EXCUSE2,
  EXCUSE3,
  EXCUSE4,
};

enum layers {
  _LAYER0,
  _LAYER1,
  _LAYER2,
};


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  LAYOUT(
    /* EMPTY  */ KC_B,  KC_N,
    TO(_LAYER1), KC_O, KC_P
  ),
  LAYOUT(
    /* EMPTY  */ DANI,  BACON,
    TO(_LAYER2), HOVAV, OPPENHEIM
  ),
  LAYOUT(
    /* EMPTY  */ EXCUSE1, EXCUSE2,
    TO(_LAYER0), EXCUSE3, EXCUSE4
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DANI:
      if (record->event.pressed) {
        SEND_STRING("Dani ");
      } else {
        // when keycode is released
      }
      break;

    case BACON:
      if (record->event.pressed) {
        SEND_STRING("Bacon ");
      } else {
        // when keycode is released
      }
      break;

    case HOVAV:
      if (record->event.pressed) {
        SEND_STRING("Hovav ");
      } else {
        // when keycode is released
      }
      break;

    case OPPENHEIM:
      if (record->event.pressed) {
        SEND_STRING("Oppenheim ");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE1:
      if (record->event.pressed) {
        SEND_STRING("Unfortunately I can't make it, so you'll have to do it without me");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE2:
      if (record->event.pressed) {
        SEND_STRING("Thanks for the invitation, but I forgot to update my calendar and it clashes with something else I have.");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE3:
      if (record->event.pressed) {
        SEND_STRING("Oh no, is it this week? This week's no good, I think I'll sit this one out");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE4:
      if (record->event.pressed) {
        SEND_STRING("I will definitely come to this if I have time from the other meeting that I have that's at exactly the same time");
      } else {
        // when keycode is released
      }
      break;

  }
  return true;
};


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

