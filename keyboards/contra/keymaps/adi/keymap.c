#include "contra.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ENTFN,
    _MEDIA,
    _MOUSE,
    _NUMPAD
};

#define F_ENTFN LT(_ENTFN, KC_ENT)
#define F_MOUSE LT(_MOUSE, KC_SCLN)
#define F_QUOTE LT(_MEDIA, KC_QUOT)
#define F_NUMPAD MO(_NUMPAD)

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  M_BACK,
  M_FWRD,
  M_PTAB,
  M_NTAB,
  M_ZOUT,
  M_ZOIN,
  M_ENTR,
  M_NSPC,
  M_PSPC,
  M_APPN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = {
  {KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    F_MOUSE, F_QUOTE},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, F_NUMPAD, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   F_ENTFN, KC_RGUI, KC_RALT, KC_RCTRL}
},

[_LOWER] = {
  {KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, LALT(KC_PIPE)},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

[_RAISE] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  { KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

[_ENTFN] = {
  {_______, M_PTAB, M_NTAB, M_PSPC, M_NSPC,  _______, _______, KC_BTN1, KC_BTN2, M_ZOUT, M_ZOIN, _______},
  { KC_ESC, _______, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, M_ENTR},
  {_______, M_BACK,  M_FWRD, _______, _______, _______, _______, _______, _______, _______,  _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______}
},

[_ADJUST] = {
  {_______, RESET  , _______, _______, _______, _______  , _______  , _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______, _______, _______, _______  , _______  , _______, _______, _______,  _______, _______},
  {_______, _______, _______, _______, _______, _______  , _______  , _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AG_NORM, AG_SWAP}
},

[_MOUSE] = { /* Mousekeys */
 {_______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______},
 {_______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______},
 {_______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______},
 {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_NUMPAD] = { /* Numpad */
 {_______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______},
 {_______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______},
 {_______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______},
 {_______, _______, _______, _______, _______, _______, _______, KC_KP_0, _______, _______, _______, _______}
},

[_MEDIA] = {
  {_______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_VOLU, _______, _______, _______, _______, _______, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, _______, _______},
  {_______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const uint16_t PROGMEM fn_actions[] = {
 [1] = ACTION_LAYER_TAP_KEY(_ENTFN, KC_ENT), // Enter-FN
 [2] = ACTION_LAYER_MOMENTARY(_NUMPAD),
 [3] = ACTION_LAYER_TAP_KEY(_MOUSE, KC_SCLN), // Enter-FN
 [4] = ACTION_LAYER_TAP_KEY(_MEDIA, KC_QUOT), // Enter-FN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!eeconfig_is_enabled()) {
        eeconfig_init();
    }
    bool use_cmd = true; // Use, for example, Cmd-Tab, Cmd-C, Cmd-V, etc.
    // Compare to MAGIC_SWAP_ALT_GUI and MAGIC_UNSWAP_ALT_GUI configs, set in:
    // quantum/quantum.c
    if (keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
        use_cmd = false; // ... or, Alt-Tab, Ctrl-C, Ctrl-V, etc.
    }

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case M_BACK:
        /* Command + [ or previous page */
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_TAP(X_LBRC)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
            }
        }
        break;
    case M_FWRD:
        /* Command + ] or next page */
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_TAP(X_RBRC)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
            }
        }
        break;
    case M_PTAB:
        /* Command + { or prev tab. */
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_RSFT(SS_TAP(X_LBRC))));
            } else {
                SEND_STRING(SS_LCTRL(SS_RSFT(SS_TAP(X_TAB))));
            }
        }
        break;
    case M_NTAB:
        /* Command + } or next tab*/
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_RSFT(SS_TAP(X_RBRC))));
            } else {
                SEND_STRING(SS_LCTRL(SS_TAP(X_TAB)));
            }
        }
        break;
    case M_ZOUT:
        /* Command + - or Ctrl + -*/
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_TAP(X_MINS)));
            } else {
                SEND_STRING(SS_LCTRL(SS_TAP(X_MINS)));
            }
        }
        break;
    case M_ZOIN:
        /* Command + = or Ctrl + =*/
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_TAP(X_EQL)));
            } else {
                SEND_STRING(SS_LCTRL(SS_TAP(X_EQL)));
            }
        }
        break;
    case M_ENTR:
        /* Command + Enter or Ctrl + Enter*/
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_TAP(X_ENT)));
            } else {
                SEND_STRING(SS_LCTRL(SS_TAP(X_ENT)));
            }
        }
        break;
    case M_NSPC:
        /* Next space / desktop */
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_RIGHT)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
            }
        }
        break;
    case M_PSPC:
        /* Previous space / desktop */
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
            }
        }
        break;
    case M_APPN:
        /* Next or previous app */
        if (record->event.pressed) {
            if (use_cmd) {
                SEND_STRING(SS_LGUI(SS_TAP(X_GRV)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
            }
            break;
        }
}
return true;
}
