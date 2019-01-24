#include "tv44.h"
#include "action_layer.h"
#include "eeconfig.h"

#define QWERTY 0
#define RAISE 1
#define ENTFN 2
#define UTILS 3
#define MOUSE 4
#define RAISX 5
#define ADJUST 6
#define GAMES 7

#define M_BACK 0
#define M_FWRD 1
#define M_PTAB 2
#define M_NTAB 3
#define M_ZOUT 4
#define M_ZOIN 5
#define M_ENTR 6
#define M_SCRN 7
#define M_NSPC 8
#define M_PSPC 9

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = {
        {KC_FN5,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC},
        {KC_TAB,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,  KC_FN4,KC_FN2},
        {KC_LSPO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM,KC_DOT,KC_SLSH,KC_RSPC},
        {KC_LCTL,  KC_LALT,  KC_LGUI, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX,    KC_FN0, KC_FN1, KC_RGUI, XXXXXXX, KC_RCTL}
    },
    [RAISE] = {
        {KC_CAPS,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,KC_7,KC_8,KC_9,KC_0,  KC_DEL},
        {KC_ESC, KC_F1,KC_F2,KC_F3, KC_F4,KC_F5,KC_F6, KC_MINS,KC_EQL,KC_LBRC,KC_RBRC,  KC_BSLS},
        {KC_TRNS, KC_F7,KC_F8,KC_F9, KC_F10,KC_F11,KC_F12,KC_NUHS,KC_NUBS,KC_PGDN,KC_PGUP, KC_TRNS},
        {KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,    KC_TRNS,     KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS}
    },
    [ENTFN] = {
        {KC_TRNS,  M(M_PTAB), M(M_NTAB), M(M_PSPC), M(M_NSPC), KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,M(M_ZOUT),M(M_ZOIN),  KC_DEL},
        {KC_ESC, KC_TRNS, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,  M(M_ENTR)},
        {KC_TRNS, M(M_BACK),M(M_FWRD),KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_FN3, KC_TRNS, XXXXXXX, KC_TRNS}
    },
    [UTILS] = {
        {KC_TRNS,  KC_SLCK,   KC_PAUS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS},
        {KC_TRNS,   KC_VOLU,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, KC_TRNS, KC_TRNS},
        {KC_TRNS,   KC_VOLD,   BL_TOGG,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
        {KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS}
    },
    [MOUSE] = {
        {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_BTN1,   KC_BTN2,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS},
        {KC_TRNS,  KC_TRNS, KC_MS_WH_LEFT, KC_MS_WH_UP ,KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,KC_TRNS},
        {KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
        {KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,    KC_TRNS,     KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS}
    },
    [RAISX] = {
        {KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN, KC_TRNS},
        {KC_TRNS, KC_F13,KC_F14,KC_F15, KC_F16,KC_F17,KC_F18, KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR, LALT(KC_PIPE)},
        {KC_TRNS, KC_F19,KC_F20,KC_F21, KC_F22,KC_F23,KC_F24,KC_NUHS,KC_NUBS,KC_HOME,KC_END, KC_TRNS},
        {KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,    KC_TRNS,     KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS}
    },
    [ADJUST] = {
        {KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, M(M_SCRN), XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, AG_NORM, XXXXXXX, AG_SWAP}
    }
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(ENTFN, KC_ENT), // ENTFN
    [1] = ACTION_LAYER_TAP_TOGGLE(RAISE), // RAISE
    [2] = ACTION_LAYER_TAP_KEY(UTILS, KC_QUOT), // UTILS
    [3] = ACTION_LAYER_MOMENTARY(ADJUST), // Backlight toggle
    [4] = ACTION_LAYER_TAP_KEY(MOUSE, KC_SCLN),
    [5] = ACTION_LAYER_TAP_KEY(RAISX, KC_GRV),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    bool use_cmd = true;    // Use, for example, Cmd-Tab, Cmd-C, Cmd-V, etc.
    // Compare to MAGIC_SWAP_ALT_GUI and MAGIC_UNSWAP_ALT_GUI configs, set in:
    // quantum/quantum.c
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      use_cmd = false;      // ... or, Alt-Tab, Ctrl-C, Ctrl-V, etc.
    }
    switch (id) {
        case M_BACK:
            /* Command + [ or previous page */
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(LBRC), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LALT), T(LEFT), U(LALT), END ) : MACRO(END));
            }
            break;
        case M_FWRD:
            /* Command + ] or next page */
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(RBRC), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LALT), T(RIGHT), U(LALT), END ) : MACRO(END));
            }
            break;
        case M_PTAB:
            /* Command + { or prev tab. */
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), D(RSFT), T(LBRC), U(RSFT), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), D(RSFT), T(TAB), U(RSFT), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case M_NTAB:
            /* Command + } or next tab*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), D(RSFT), T(RBRC), U(RSFT), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(TAB), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case M_ZOUT:
            /* Command + - or Ctrl + -*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(MINS), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(MINS), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case M_ZOIN:
            /* Command + = or Ctrl + =*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(EQL), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(EQL), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case M_ENTR:
            /* Command + Enter or Ctrl + Enter*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(ENT), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(ENT), U(LCTRL), END ) : MACRO(END));
            }
        case M_SCRN:
            /* Command + Enter or Ctrl + Enter*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), D(LCTRL), D(LSFT), T(4), U(LSFT), U(LGUI), U(LCTRL), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( T(PSCR) ) : MACRO(END));
            }
        case M_NSPC:
          /* Next space / desktop */
          if (use_cmd) {
            return (event.pressed ? MACRO( D(LCTRL), T(RIGHT), U(LCTRL), END ) : MACRO(END));
          } else {
            return (event.pressed ? MACRO( D(LGUI), T(RIGHT), U(LGUI), END ) : MACRO(END));
          }
        case M_PSPC:
          /* Previous space / desktop */
          if (use_cmd) {
            return (event.pressed ? MACRO( D(LCTRL), T(LEFT), U(LCTRL), END ) : MACRO(END));
          } else {
            return (event.pressed ? MACRO( D(LGUI), T(LEFT), U(LGUI), END ) : MACRO(END));
          }
        default:
            break;
    }
    return MACRO_NONE;
}

bool backlightOn = false;

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// Backlight.
	if (record->event.pressed && keycode == BL_TOGG) {
		// Set B2 to output.
		DDRB |= (1 << 2);

		// Toggle backlight variable.
		if ( (backlightOn = !backlightOn) ) {
			// Turn backlight on.
			PORTB |= (1 << 2);
		} else {
			// Turn backlight off.
			PORTB &= ~(1 << 2);
		}

		// Disable the actual keycode.
		return false;
	}

	return true;
}


