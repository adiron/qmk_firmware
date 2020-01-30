#include QMK_KEYBOARD_H
#include "action_layer.h"

#include "../../backlight_staryu.h"

bool has_layer_changed = false;
static uint8_t current_layer;

enum custom_keycodes {
  EXCUSE1 = SAFE_RANGE,
  EXCUSE2,
  EXCUSE3,
  EXCUSE4,
  EXCUSE5,
  EXCUSE6,
  EXCUSE7,
  EXCUSE8,
  EXCUSE9,
  EXCUSE10,
  EXCUSE11,
  EXCUSE12,
  //   EXCUSE13,
  //   EXCUSE14,
  //   EXCUSE15,
  //   EXCUSE16,
};

enum layers {
  _LAYER0,
  _LAYER1,
  _LAYER2,
};


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  LAYOUT(
    /* EMPTY  */ EXCUSE1, EXCUSE2,
    TO(_LAYER1), EXCUSE3, EXCUSE4
  ),
  LAYOUT(
    /* EMPTY  */ EXCUSE5, EXCUSE6,
    TO(_LAYER2), EXCUSE7, EXCUSE8
  ),
  LAYOUT(
    /* EMPTY  */ EXCUSE9, EXCUSE10,
    TO(_LAYER0), EXCUSE11, EXCUSE12
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EXCUSE1:
      if (record->event.pressed) {
        SEND_STRING("thzv pruhey bjns ungbhhi' tck pauy frdg tbjbu kt kuejho pruheyho c,juo vzv");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE2:
      if (record->event.pressed) {
        SEND_STRING("anjbu kanug gk vpruhey akfo! neuuho a,nmtu xyushu thbyrteyhc ahhej tu,u");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE3:
      if (record->event.pressed) {
        SEND_STRING("tbjbu kt kuejho pruhey cachk pju, nnkhui sukr xurh");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE4:
      if (record->event.pressed) {
        SEND_STRING("tbjbu frdg guaho re prhby tz brtv kh pju, n,tho");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE5:
      if (record->event.pressed) {
        SEND_STRING("scru th,bu cxcc vdhux vct akfo");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE6:
      if (record->event.pressed) {
        SEND_STRING("zv nuako ffv' tbjbu hfukho re kvrux kfo! tk ,abu scr! chh");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE7:
      if (record->event.pressed) {
        SEND_STRING("tbjbu cshue gucsho go jcrv tjr, aguav t, tu,u vscr at,o guaho re hu,r yuc uzv hvhv bhdus gbhhbho///");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE8:
      if (record->event.pressed) {
        SEND_STRING("tbjbu cab, ac,ui go zdnhhxyr b,rtv tjrh zv");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE9:
      if (record->event.pressed) {
        SEND_STRING("kmgrbu kt bufk kej, pruheyho fk fl xjhho gnfo vxkhjv");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE10:
      if (record->event.pressed) {
        SEND_STRING("tbjbu kt gucsho go kpkpho fnufo");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE11:
      if (record->event.pressed) {
        SEND_STRING("nv zv?? kt ang,h?? tbh bfbx knbvrv uthi ekhyv!!!!");
      } else {
        // when keycode is released
      }
      break;

    case EXCUSE12:
      if (record->event.pressed) {
        SEND_STRING("vvmgv vzt, ngkhcv t, vhfuku, akbu ftnbh hu-thex utbjbu nxrcho cfk ,ue;!");
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

