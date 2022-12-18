/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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

// Fillers to make layering more clear
#define ___T___ KC_TRNS

// Layer shorthand
#define _QW 0
#define _LW 1
#define _RS 2
#define _FN 3
#define _ENTFN 4
#define _MEDIA 5
#define _MOUSE 6

enum custom_keycodes {
    M_BACK = SAFE_RANGE,
    M_FWRD,
    M_PTAB,
    M_NTAB,
    M_ZOUT,
    M_ZOIN,
    M_ENTR,
    M_NSPC,
    M_PSPC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
  KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_INSERT,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), LT(_MEDIA, KC_QUOT), LT(_ENTFN, KC_ENT),  LT(_ENTFN, KC_ENT), KC_PGUP,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN,
  KC_LCTL, MO(_FN), KC_LALT, KC_LGUI, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), LT(_ENTFN, KC_ENT), KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
 ),

/* LOWERED
 */

 [_LW] = LAYOUT_ortho_5x15( /* LOWERED */
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, KC_INS,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, ___T___, ___T___, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, KC_PGUP, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
 ),

/* RAISED
 */

 [_RS] = LAYOUT_ortho_5x15( /* RAISED */
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_INS,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, ___T___, ___T___, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, KC_PGUP, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
 ),

/* FUNCTION
 */

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
  RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL,
  KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR,
  KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, _______,
  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,   ___T___, ___T___, KC_PGUP, KC_WH_D,
  _______  , _______, AG_SWAP, AG_NORM, _______, KC_BTN1, KC_BTN1, _______, AG_NORM, AG_SWAP, _______, _______, KC_HOME, KC_PGDN, KC_END
 ),

 [_ENTFN] = LAYOUT_ortho_5x15( /* Enter FN */
  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,
  _______,  M_PTAB,  M_NTAB,  M_PSPC,  M_NSPC, _______,  _______, _______, _______,   M_ZOUT,  M_ZOIN, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______, _______, _______, _______,
  _______,  M_BACK,  M_FWRD, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______
 ),
 [_MEDIA] = LAYOUT_ortho_5x15( /* Media */
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_VOLU, _______, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, _______, _______,
  _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),
 [_MOUSE] = LAYOUT_ortho_5x15( /* Mouse */
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    keyevent_t event = record->event;

    if (!eeconfig_is_enabled()) {
        eeconfig_init();
    }
    bool use_cmd = true; // Use, for example, Cmd-Tab, Cmd-C, Cmd-V, etc.
    // Compare to MAGIC_SWAP_ALT_GUI and MAGIC_UNSWAP_ALT_GUI configs, set in:
    // quantum/quantum.c
    if (keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
        use_cmd = false; // ... or, Alt-Tab, Ctrl-C, Ctrl-V, etc.
    }
    if (event.pressed) {
        switch (keycode) {
            case M_BACK:
                /* Command + [ or previous page */
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_LBRC)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
                }
                break;
            case M_FWRD:
                /* Command + ] or next page */
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_RBRC)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
                }
                break;
            case M_PTAB:
                /* Command + { or prev tab. */
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_RSFT(SS_TAP(X_LBRC))));
                } else {
                    SEND_STRING(SS_LCTRL(SS_RSFT(SS_TAP(X_TAB))));
                }
                break;
            case M_NTAB:
                /* Command + } or next tab*/
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_RSFT(SS_TAP(X_RBRC))));
                } else {
                    SEND_STRING(SS_LCTRL(SS_TAP(X_TAB)));
                }
                break;
            case M_ZOUT:
                /* Command + - or Ctrl + -*/
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_MINS)));
                } else {
                    SEND_STRING(SS_LCTRL(SS_TAP(X_MINS)));
                }
                break;
            case M_ZOIN:
                /* Command + = or Ctrl + =*/
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_EQL)));
                } else {
                    SEND_STRING(SS_LCTRL(SS_TAP(X_EQL)));
                }
                break;
            case M_ENTR:
                /* Command + Enter or Ctrl + Enter*/
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_ENT)));
                } else {
                    SEND_STRING(SS_LCTRL(SS_TAP(X_ENT)));
                }
                break;
            case M_NSPC:
                /* Next space / desktop */
                if (use_cmd) {
                    SEND_STRING(SS_LCTRL(SS_TAP(X_RIGHT)));
                } else {
                    SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
                }
                break;
            case M_PSPC:
                /* Previous space / desktop */
                if (use_cmd) {
                    SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
                } else {
                    SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
                }
                break;
        }
    }
    return true;
};

// Combo definitions

enum combos {
    COMBO_CAPS,
    COMBO_SCROT,
    COMBO_ESC,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM combo_caps[] = {KC_RSFT, KC_LSFT, COMBO_END};
const uint16_t PROGMEM combo_scrot[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  [COMBO_CAPS] = COMBO_ACTION(combo_caps),
  [COMBO_SCROT] = COMBO_ACTION(combo_scrot),
  [COMBO_ESC] = COMBO_ACTION(combo_esc),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_CAPS:
      if (pressed) {
        tap_code16(KC_CAPS);
      }
      break;
    case COMBO_SCROT:
      if (pressed) {
        // Send the keycode for Cmd+Shift+Ctrl+4
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_LCTL);
        tap_code(KC_4);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTL);
      }
      break;
    case COMBO_ESC:
      if (pressed) {
        tap_code(KC_ESC);
      }
      break;
  }
}
