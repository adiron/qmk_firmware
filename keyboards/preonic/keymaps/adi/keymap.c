/* Copyright 2015-2017 Jack Humbert
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

#define MEDIA_KEY_DELAY 10

#define F_ENTFN LT(_ENTFN, KC_ENT)
#define F_MOUSE LT(_MOUSE, KC_SCLN)
#define F_QUOTE LT(_MEDIA, KC_QUOT)

enum preonic_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ENTFN,
    _MEDIA,
    _MOUSE
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    BACKLIT,
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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | A-Tab|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  M_APPN,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    F_MOUSE, F_QUOTE, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_GRV, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   F_ENTFN, KC_RGUI, KC_RALT, KC_RCTRL \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_DEL,  _______, _______, _______, _______, _______, _______,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bspc |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_BSPC, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_F11,  KC_F12, \
  _______,   RESET,   DEBUG, _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______,  KC_DEL, \
  _______, _______,  MU_MOD,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, _______,  _______, _______, _______, _______, \
  _______,  MUV_DE,  MUV_IN,   MU_ON,  MU_OFF,   MI_ON,  MI_OFF, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_ENTFN] = LAYOUT_preonic_grid( \
  _______, _______,       _______,     _______,       _______,        _______, _______, _______, _______, _______, _______, _______, \
  _______,  M_PTAB,        M_NTAB,     M_PSPC ,        M_NSPC,        _______, _______, KC_BTN1, KC_BTN2, M_ZOUT,   M_ZOIN, _______, \
  KC_ESC,  _______, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______, M_ENTR, \
  _______,  M_BACK,        M_FWRD,     _______,       _______,        _______, _______, _______, _______, _______, _______, _______, \
  _______, _______,       _______,     _______,       _______,        _______, _______, _______, _______, _______, _______, _______ \
),

[_MEDIA] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_VOLU, _______, _______, _______, _______, _______, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, _______, _______, \
  _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_MOUSE] = LAYOUT_preonic_grid( \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, \
 KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, \
 KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),



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
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
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
};

bool encoder_update_user(uint8_t index, bool counter_clockwise) {
    bool clockwise = !counter_clockwise;
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            // No layer is on
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;

        case _MEDIA:
            if (clockwise) {
                tap_code_delay(KC_VOLU, MEDIA_KEY_DELAY);
            } else {
                tap_code_delay(KC_VOLD, MEDIA_KEY_DELAY);
            }
            break;

        case _LOWER:
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
            break;

        case _RAISE:
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
            break;

        case _MOUSE:
            if (get_mods() & (MOD_BIT(KC_RGUI) | MOD_BIT(KC_LGUI))) {
                if (clockwise) {
                    tap_code(KC_MS_D);
                    tap_code(KC_MS_D);
                } else {
                    tap_code(KC_MS_U);
                    tap_code(KC_MS_U);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_MS_R);
                    tap_code(KC_MS_R);
                } else {
                    tap_code(KC_MS_L);
                    tap_code(KC_MS_L);
                }
            }
            break;

        case _ENTFN:
            if (clockwise) {
                register_code(KC_LGUI);
                register_code(KC_RSFT);
                register_code(KC_RBRC);
                unregister_code(KC_RBRC);
                unregister_code(KC_RSFT);
                unregister_code(KC_LGUI);
            } else {
                register_code(KC_LGUI);
                register_code(KC_RSFT);
                register_code(KC_LBRC);
                unregister_code(KC_LBRC);
                unregister_code(KC_RSFT);
                unregister_code(KC_LGUI);
            }
            break;
    }

    return false;
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
