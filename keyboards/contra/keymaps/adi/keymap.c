#include "contra.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "adi.h"

extern keymap_config_t keymap_config;

#define F_ENTFN LT(_ENTFN, KC_ENT)
#define F_MOUSE LT(_MOUSE, KC_SCLN)
#define F_QUOTE LT(_MEDIA, KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    F_MOUSE, F_QUOTE},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, MO(_NUMPAD), KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   F_ENTFN, KC_RGUI, KC_RALT, KC_RCTL}
},

[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  { KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, LALT(KC_PIPE)},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

[_RAISE] = {
  { KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
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
  {_______, QK_BOOT, _______, _______, _______, _______  , _______  , _______, _______, _______, _______, KC_DEL },
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
  {_______, KC_SCRL, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_VOLU, _______, _______, _______, _______, _______, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, _______, _______},
  {_______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
