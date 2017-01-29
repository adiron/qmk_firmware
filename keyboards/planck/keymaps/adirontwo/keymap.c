// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
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

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
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
  {KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
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
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

[_ENTFN] = {
  {_______, M(2)   ,     M(3)     ,       _______,      _______,        _______, _______, KC_BTN1, KC_BTN2,    M(4),     M(5), _______},
  { KC_ESC, _______, KC_MS_WH_LEFT, KC_MS_WH_UP  ,KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______,    M(6)},
  {_______, M(0)   ,  M(1)        ,       _______,      _______,        _______, _______, _______, _______, _______,  _______, _______},
  {_______, _______,       _______,       _______,      _______,        _______, _______, _______, _______, _______,  _______, _______}
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
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, AG_NORM, AG_SWAP}
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
        case 0:
            /* Command + [ or previous page */
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(LBRC), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LALT), T(LEFT), U(LALT), END ) : MACRO(END));
            }
            break;
        case 1:
            /* Command + ] or next page */
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(RBRC), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LALT), T(RIGHT), U(LALT), END ) : MACRO(END));
            }
            break;
        case 2:
            /* Command + { or prev tab. */
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), D(RSFT), T(LBRC), U(RSFT), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), D(RSFT), T(TAB), U(RSFT), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case 3:
            /* Command + } or next tab*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), D(RSFT), T(RBRC), U(RSFT), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(TAB), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case 4:
            /* Command + - or Ctrl + -*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(MINS), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(MINS), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case 5:
            /* Command + = or Ctrl + =*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(EQL), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(EQL), U(LCTRL), END ) : MACRO(END));
            }
            break;
        case 6:
            /* Command + Enter or Ctrl + Enter*/
            if (use_cmd) {
                return (event.pressed ? MACRO( D(LGUI), T(ENT), U(LGUI), END ) : MACRO(END));
            } else {
                return (event.pressed ? MACRO( D(LCTRL), T(ENT), U(LCTRL), END ) : MACRO(END));
            }
        default:
            break;
    }
    return MACRO_NONE;
}

#ifdef AUDIO_ENABLE

#define MARIO                                          \
    Q__NOTE(_E4), Q__NOTE(_E4), Q__NOTE(_REST), Q__NOTE(_E4), \
    Q__NOTE(_REST), Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_REST), \
    Q__NOTE(_G4),
#define RAISE_SOUND                                          \
    Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_C5),
#define RAISE_GB_SOUND                                          \
    Q__NOTE(_C5), Q__NOTE(_E4), Q__NOTE(_C4),

#define LOWER_SOUND                                          \
    Q__NOTE(_A4), Q__NOTE(_C4), Q__NOTE(_A5),
#define LOWER_GB_SOUND                                          \
    Q__NOTE(_A5), Q__NOTE(_C4), Q__NOTE(_A4),

#define MAC_SOUND                                          \
    W__NOTE(_C4),
#define WIN_SOUND                                          \
    Q__NOTE(_A3), Q__NOTE(_A2),
float tone_startup[][2]    = SONG(MARIO);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_caps_on[][2]    = SONG(SCROLL_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(CAPS_LOCK_OFF_SOUND);

// float tone_raise_on[][2]    = SONG(RAISE_SOUND);
// float tone_raise_off[][2]   = SONG(RAISE_GB_SOUND);
// float tone_lower_on[][2]    = SONG(LOWER_SOUND);
// float tone_lower_off[][2]   = SONG(LOWER_GB_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float tone_mac[][2] = SONG(MAC_SOUND);
float tone_win[][2] = SONG(WIN_SOUND);
#endif


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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
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
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;

    case AG_NORM:
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_mac,  false, LEGATO);
      }
        return true;
        break;

    case AG_SWAP:
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_win,  false, LEGATO);
      }
        return true;
        break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void led_set_user(uint8_t usb_led) {
    static uint8_t old_usb_led = 0;

    _delay_ms(10); // gets rid of tick

    if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK)))
    {
            // If CAPS LK LED is turning on...
            PLAY_NOTE_ARRAY(tone_caps_on,  false, LEGATO);
    }
    else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK)))
    {
            // If CAPS LK LED is turning off...
            PLAY_NOTE_ARRAY(tone_caps_off, false, LEGATO);
    }
    old_usb_led = usb_led;
}

void startup_user()
{
    _delay_ms(30); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, STACCATO);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
