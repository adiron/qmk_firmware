// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "contra.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _PLOVER 5
#define _ENTFN 6
#define _MEDIA 7
#define _MOUSE 8
#define _ADJUST 16
#define _NUMPAD 9

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

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  LOWER,
  RAISE,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | `    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | Cmd  |Lower |    Space    |Raise | Enter| Cmd  |  Alt |Ctrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FUNC(3), FUNC(4)},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, FUNC(2), KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   FUNC(1), KC_RGUI, KC_RALT, KC_RCTRL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, LALT(KC_PIPE)},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  { KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

[_ENTFN] = {
  {_______, M(M_PTAB), M(M_NTAB), M(M_PSPC), M(M_NSPC),  _______, _______, KC_BTN1, KC_BTN2, M(M_ZOUT), M(M_ZOIN), _______},
  { KC_ESC, _______, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, M(M_ENTR)},
  {_______, M(M_BACK),  M(M_FWRD), _______, _______, _______, _______, _______, _______, _______,  _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______}
},
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______  , _______  , _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  _______  , _______  , _______, _______, _______,  PLOVER, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON    , MI_OFF   , _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, M(M_SCRN), M(M_SCRN), _______, _______, _______, AG_NORM, AG_SWAP}
},

[_MOUSE] = { /* Mousekeys */
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

[_NUMPAD] = { /* Numpad */
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

[_MEDIA] = {
  {_______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_VOLU, _______, _______, _______, _______, _______, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, _______, _______},
  {_______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

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
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
