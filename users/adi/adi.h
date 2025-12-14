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

/* This sets the type of tap keys to hold on other keys. This is explained in:
 * https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes */
#define HOLD_ON_OTHER_KEY_PRESS

#define MEDIA_KEY_DELAY 10

// Keycodes and layers and stuff

#define F_ENTFN LT(_ENTFN, KC_ENT)
#define F_MOUSE LT(_MOUSE, KC_SCLN)
#define F_QUOTE LT(_MEDIA, KC_QUOT)
#define F_ESCFN LT(_ESCFN, KC_ESC)

enum adi_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ENTFN,
    _MEDIA,
    _MOUSE,
    _NUMPAD,
    _ESCFN,
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
    M_UUML,
    M_AUML,
    M_OUML,
    M_IUML,
    M_EUML,
    M_SZET,
};

void adi_umlaut_macro(uint16_t keycode, keyrecord_t *record) {
    /* Ü or ü (depending on shift) on macOS
    This is done by reading the state of either right or left shift. If shift is pressed, unregister shift first, send alt+u, then register shift again. If shift is not pressed, just send alt+u. */
    if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_RSFT)) {
            unregister_code(KC_RSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_U)));
            register_code(KC_RSFT);
        } else if (get_mods() & MOD_BIT(KC_LSFT)) {
            unregister_code(KC_LSFT);
            SEND_STRING(SS_LALT(SS_TAP(X_U)));
            register_code(KC_LSFT);
        } else {
            SEND_STRING(SS_LALT(SS_TAP(X_U)));
        }
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
}

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

        case M_OUML:
            adi_umlaut_macro(KC_O, record);
            break;

        case M_AUML:
            adi_umlaut_macro(KC_A, record);
            break;

        case M_UUML:
            adi_umlaut_macro(KC_U, record);
            break;

        case M_IUML:
            adi_umlaut_macro(KC_I, record);
            break;

        case M_EUML:
            adi_umlaut_macro(KC_E, record);
            break;

        case M_SZET:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_S);
            } else {
                unregister_code(KC_S);
                unregister_code(KC_LALT);
            }
            break;
    }
    return true;
};

// Combo definitions

#ifdef COMBO_ENABLE
enum combos {
    COMBO_CAPS,
    COMBO_SCROT,
    COMBO_SCROT_SAVE,
    COMBO_ESC,
    COMBO_COPY,
    COMBO_PASTE,
    COMBO_CUT,
    COMBO_BSPC,
    COMBO_ALT_BSPC,
    COMBO_UNDO,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM combo_caps[] = {KC_RSFT, KC_LSFT, COMBO_END};
const uint16_t PROGMEM combo_scrot[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_scrot_save[] = {KC_DOT, KC_COMM, KC_SLASH, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_cut[] = {KC_U, KC_J, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_alt_bspc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_undo[] = {KC_K, KC_I, COMBO_END};

combo_t key_combos[] = {
  [COMBO_CAPS] = COMBO(combo_caps, CW_TOGG),
  [COMBO_SCROT] = COMBO(combo_scrot, LGUI(LSFT(LCTL(KC_4)))),
  [COMBO_SCROT_SAVE] = COMBO(combo_scrot_save, LGUI(LSFT(KC_4))),
  [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
  [COMBO_COPY] = COMBO(combo_copy, LGUI(KC_C)),
  [COMBO_PASTE] = COMBO(combo_paste, LGUI(KC_V)),
  [COMBO_CUT] = COMBO(combo_cut, LGUI(KC_X)),
  [COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC),
  [COMBO_ALT_BSPC] = COMBO(combo_alt_bspc, LALT(KC_BSPC)),
  [COMBO_UNDO] = COMBO(combo_undo, LGUI(KC_Z)),
};

#ifdef COMBO_TERM_PER_COMBO
#define COMBO_TERM_SHORT 30

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_BSPC:
            return COMBO_TERM_SHORT;
        default:
            return COMBO_TERM;
    }
}
#endif

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
                    tap_code(MS_DOWN);
                    tap_code(MS_DOWN);
                } else {
                    tap_code(MS_UP);
                    tap_code(MS_UP);
                }
            } else {
                if (clockwise) {
                    tap_code(MS_RGHT);
                    tap_code(MS_RGHT);
                } else {
                    tap_code(MS_LEFT);
                    tap_code(MS_LEFT);
                }
            }
            break;

        case _ENTFN:
            if (clockwise) {
                SEND_STRING(SS_LGUI(SS_RSFT("]")));
            } else {
                SEND_STRING(SS_LGUI(SS_RSFT("[")));
            }
            break;
    }

    return false;
}
#endif
