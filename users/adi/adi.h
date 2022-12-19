/* Copyright 2019 Adi Ron <adi@adiron.me>
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

/* This file includes all the different base settings for my usual keyboard
 * layout. */

#define MEDIA_KEY_DELAY 10

// Keycodes and layers and stuff

#define F_ENTFN LT(_ENTFN, KC_ENT)
#define F_MOUSE LT(_MOUSE, KC_SCLN)
#define F_QUOTE LT(_MEDIA, KC_QUOT)

enum adi_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ENTFN,
    _MEDIA,
    _MOUSE,
    _NUMPAD,
};

enum adi_keycodes {
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
    M_APPP,
};

// Macro definitions

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
                    SEND_STRING(SS_LCTL(SS_RSFT(SS_TAP(X_TAB))));
                }
            }
            break;
        case M_NTAB:
            /* Command + } or next tab*/
            if (record->event.pressed) {
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_RSFT(SS_TAP(X_RBRC))));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
                }
            }
            break;
        case M_ZOUT:
            /* Command + - or Ctrl + -*/
            if (record->event.pressed) {
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_MINS)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_MINS)));
                }
            }
            break;
        case M_ZOIN:
            /* Command + = or Ctrl + =*/
            if (record->event.pressed) {
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_EQL)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_EQL)));
                }
            }
            break;
        case M_ENTR:
            /* Command + Enter or Ctrl + Enter*/
            if (record->event.pressed) {
                if (use_cmd) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_ENT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_ENT)));
                }
            }
            break;
        case M_NSPC:
            /* Next space / desktop */
            if (record->event.pressed) {
                if (use_cmd) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
                } else {
                    SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
                }
            }
            break;
        case M_PSPC:
            /* Previous space / desktop */
            if (record->event.pressed) {
                if (use_cmd) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
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
        case M_APPP:
            /* Next or previous app (reverse) */
            if (record->event.pressed) {
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

// Combo definitions

#ifdef COMBO_ENABLE
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

__attribute__ ((weak))
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_CAPS:
      if (pressed) {
        #ifdef CAPS_WORD_ENABLE
        caps_word_toggle();
        #else
        tap_code16(KC_CAPS);
        #endif
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

#endif

// Encoder definitions
#ifdef ENCODER_ENABLE
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
#endif
