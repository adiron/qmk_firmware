/* Copyright 2020 yushakobo
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

enum macro_names {
    M_BACK = 0,
    M_FWRD,
    M_PTAB,
    M_NTAB,
    M_ZOUT,
    M_ZOIN,
    M_ENTR,
    M_NSPC,
    M_PSPC,
    M_APPN,
    M_APPP,
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ENTFN,
  _MEDIA,
  _MOUSE
};


#define F_ENTFN LT(_ENTFN, KC_ENT)
#define F_MOUSE LT(_MOUSE, KC_SCLN)
#define F_QUOTE LT(_MEDIA, KC_QUOT)
#define F_RAISE MO(_RAISE)
#define F_LOWER MO(_LOWER)
#define F_ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | PgUp |A-Tab |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |Adjust| Alt  | GUI  |Lower |Space | PgDn |AS-Tab|Space |Raise |EntFn | GUI  | Alt  | Ctrl |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_GRV,  KC_1,        KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      KC_LCTL, KC_A,        KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,   KC_J,    KC_K,    KC_L,    F_MOUSE, F_QUOTE,
      KC_LSFT, KC_Z,        KC_X,    KC_C,    KC_V,    KC_B, KC_PGUP, M_APPN, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL, F_ADJUST, KC_LALT, KC_LGUI, F_LOWER, KC_SPC,  KC_PGDN, M_APPP, KC_SPC, F_RAISE, F_ENTFN, KC_RGUI, KC_RALT, KC_RCTL
    ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_HOME, _______, KC_F12,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,  KC_END, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_HOME, _______, KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______,
      _______, _______, _______, _______, _______, _______,  KC_END, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Adjust
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|DEBUG |      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |Win   | Mac  |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______,   RESET,   DEBUG, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, AG_NORM,                   AG_SWAP, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
      _______, _______, AG_SWAP, AG_NORM, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
      ),
  /* EnterFn layer
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | PTab | NTab | NSpc | PSpc |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | Left | Down |  Up  | Right|      | CEnt |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | Back | Fwrd |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ENTFN] =  LAYOUT(
      _______, _______, _______, _______, _______,_______ ,                   _______, _______, _______, _______,  _______, _______,
      _______,  M_PTAB,  M_NTAB,  M_PSPC,  M_NSPC, _______,                   _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______,  M_ENTR,
      _______,  M_BACK,  M_FWRD, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
      ),
  /* EnterFn layer
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Brt- | Brt+ |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Vol+ |      |      |      |      |             |      | Rewd | Play | FFwd |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | Vol- |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_MEDIA] =  LAYOUT(
      _______, _______, _______, _______, _______,_______ ,                   _______, _______, _______, _______, _______, _______,
      _______, KC_SLCK, KC_PAUS, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, KC_VOLU, _______, _______, _______, _______,                   _______, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, _______, _______,
      _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
  /* EnterFn layer
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      | LBtn | RBtn |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | MsL  | MsD  | MsU  | MsR  |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_MOUSE] =  LAYOUT(
      _______, _______, _______, _______, _______,_______ ,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, KC_BTN1, KC_BTN2, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }


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
    if (record->event.pressed) {
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
            case M_APPN:
                /* Next app */
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_GRV)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                }
                break;
            case M_APPP:
                /* Previous app */
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_GRV))));
                } else {
                    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_TAB))));
                }
                break;
        }
    }
    return true;
};
