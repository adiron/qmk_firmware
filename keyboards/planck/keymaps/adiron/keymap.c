#include "keymap.h"

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif


// Layer names start with an underscore.
#define _QWERTY 0
#define _NUMPAD 1
#define _RAISE  2
#define _LOWER  3
#define _ENTFN  4
#define _MOUSE  5
#define _PLOVER 6

// FN key names do not.
#define RAISE 1
#define LOWER 2
#define ENTFN 3
#define SPCLK 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = { /* Qwerty */
 //                                      HOMING F                      HOMING J
 { KC_GRV,   KC_Q,     KC_W,    KC_E,        KC_R,   KC_T,   KC_Y,        KC_U,        KC_I,    KC_O,    KC_P, KC_BSPC},
 { KC_TAB,   KC_A,     KC_S,    KC_D,        KC_F,   KC_G,   KC_H,        KC_J,        KC_K,    KC_L, KC_SCLN, KC_QUOT},
 {KC_LSFT,   KC_Z,     KC_X,    KC_C,        KC_V,   KC_B,   KC_N,        KC_M,     KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT},
 {FUNC(7), KC_LCTL, KC_LALT, KC_LGUI, FUNC(RAISE), KC_SPC, KC_SPC, FUNC(ENTFN), FUNC(LOWER), KC_RGUI, KC_RALT, KC_RCTL}
 // Space is repeated to accommadate for both spacebar wiring positions
},
[_NUMPAD] = { /* Numpad layer */
 //                                   HOMING F                   HOMING J
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[_RAISE] = { /* RAISE */
 {KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DELETE},
 {FUNC(6), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS  },
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS  },
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(10), FUNC(10), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  }
},
[_LOWER] = { /* LOWER */
 //                                            HOMING F                         HOMING J
 {  KC_F1,   KC_F2,   KC_F3,        KC_F4,        KC_F5,        KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12},
 {KC_TRNS, KC_VOLU,   BL_INC, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2,    M(0),    M(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_VOLD,   BL_DEC,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,  MU_TOG,  AU_TOG, KC_TRNS, KC_TRNS, KC_TRNS},
 {  RESET, KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,      FUNC(9), FUNC(9), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[_ENTFN] = { /* Enter-FN */
 {KC_CAPS, KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS, KC_BTN1, KC_BTN2,  KC_TRNS, KC_MINUS, KC_EQUAL},
 {KC_ESC , KC_TRNS, KC_WH_L, KC_MS_WH_UP, KC_MS_WH_DOWN,     KC_WH_R,     KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,     M(2), M(3)},
 {KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_PGDN, KC_PGUP, KC_HOME,   KC_END,  KC_TRNS, KC_TRNS},
 {FUNC(4), KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS, FUNC(SPCLK), FUNC(SPCLK), KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS}
},
[_MOUSE] = { /* Mousekeys */
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[_PLOVER] = { /* Plover */
 { KC_1,    KC_1,  KC_1, KC_1, KC_1,  KC_1,  KC_1, KC_1, KC_1,  KC_1,    KC_1, KC_1   },
 {KC_NO,    KC_Q,  KC_W, KC_E, KC_R,  KC_T,  KC_Y, KC_U, KC_I,  KC_O,    KC_P, KC_LBRC},
 {KC_NO,    KC_A,  KC_S, KC_D, KC_F,  KC_G,  KC_H, KC_J, KC_K,  KC_L, KC_SCLN, KC_QUOT},
 {FUNC(8), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO,   KC_NO, KC_NO  }
},
};

const uint16_t PROGMEM fn_actions[] = {
 [1] = ACTION_LAYER_MOMENTARY(_RAISE), // to RAISE
 [2] = ACTION_LAYER_MOMENTARY(_LOWER), // to LOWER

 [3] = ACTION_LAYER_TAP_KEY(_ENTFN, KC_ENT), // Enter-FN
 [4] = ACTION_DEFAULT_LAYER_SET(_PLOVER), // Plover layer
 [5] = ACTION_LAYER_TOGGLE(_ENTFN), // Enter-FN toggle
 [6] = ACTION_LAYER_TOGGLE(_NUMPAD), // Numpad toggle
 [7] = ACTION_LAYER_TAP_TOGGLE(_MOUSE), // Mouse keys tap-toggle
 [8] = ACTION_DEFAULT_LAYER_SET(_QWERTY),
 [9] = ACTION_LAYER_TOGGLE(_LOWER),
 [10] = ACTION_LAYER_TOGGLE(_RAISE),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
      if (record->event.pressed) {
        return MACRO( I(1), T(A), T(D), T(I), D(RSFT), T(2), U(RSFT),
            T(A), T(D), T(I),  T(R), T(O), T(N), END  );
      }
      break;
    case 1:
      if (record->event.pressed) {
        return MACRO( I(1), T(J), T(J), T(J), END  );
      }
      break;
    case 2:
      if (record->event.pressed) {
        return MACRO( I(1), D(RGUI), T(MINUS), U(RGUI), END  );
      }
      break;
    case 3:
      if (record->event.pressed) {
        return MACRO( I(1), D(RGUI), T(EQUAL), U(RGUI), END  );
      }
      break;

  }
  return MACRO_NONE;
};


void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);


void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
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
