#include "keymap.h"
#define RAISE 1
#define LOWER 2
#define SPACE 3
#define SPCLK 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = { /* Qwerty */
 //                                      HOMING F                      HOMING J
 { KC_GRV,   KC_Q,     KC_W,    KC_E,        KC_R,        KC_T,        KC_Y,   KC_U,        KC_I,    KC_O,    KC_P, KC_BSPC},
 { KC_TAB,   KC_A,     KC_S,    KC_D,        KC_F,        KC_G,        KC_H,   KC_J,        KC_K,    KC_L, KC_SCLN, KC_QUOT},
 {KC_LSFT,   KC_Z,     KC_X,    KC_C,        KC_V,        KC_B,        KC_N,   KC_M,     KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT},
 {FUNC(7), KC_LCTL, KC_LALT, KC_LGUI, FUNC(RAISE), FUNC(SPACE), FUNC(SPACE), KC_ENT, FUNC(LOWER), KC_RGUI, KC_RALT, KC_RCTL}
 // Space is repeated to accommadate for both spacebar wiring positions
},
[1] = { /* Numpad layer */
 //                                   HOMING F                   HOMING J
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[2] = { /* RAISE */
 {KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DELETE},
 {FUNC(6), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS  },
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS  },
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  }
},
[3] = { /* LOWER */
 //                                            HOMING F                         HOMING J
 {  KC_F1,   KC_F2,   KC_F3,        KC_F4,        KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12},
 {KC_TRNS, KC_VOLU,   BL_INC, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_VOLD,   BL_DEC,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,  MU_TOG,  AU_TOG, KC_TRNS, KC_TRNS, KC_TRNS},
 {  RESET, KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[4] = { /* Spacefn */
 {KC_CAPS, KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_BTN1, KC_BTN2,  KC_TRNS,  KC_TRNS, KC_TRNS},
 {KC_ESC , KC_TRNS, KC_WH_L, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_WH_R, KC_LEFT,     KC_DOWN,   KC_UP, KC_RIGHT, KC_MINUS, KC_EQUAL},
 {KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS, KC_PGDN,     KC_PGUP, KC_HOME,   KC_END,  KC_TRNS, KC_TRNS},
 {FUNC(4), KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, FUNC(SPCLK), KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS}
},
[5] = { /* Mousekeys */
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
 {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[6] = { /* Plover */
 { KC_1,    KC_1,  KC_1, KC_1, KC_1,  KC_1,  KC_1, KC_1, KC_1,  KC_1,    KC_1, KC_1   },
 {KC_NO,    KC_Q,  KC_W, KC_E, KC_R,  KC_T,  KC_Y, KC_U, KC_I,  KC_O,    KC_P, KC_LBRC},
 {KC_NO,    KC_A,  KC_S, KC_D, KC_F,  KC_G,  KC_H, KC_J, KC_K,  KC_L, KC_SCLN, KC_QUOT},
 {FUNC(8), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO,   KC_NO, KC_NO  }
},
};

const uint16_t PROGMEM fn_actions[] = {
 [1] = ACTION_LAYER_MOMENTARY(2), // to RAISE
 [2] = ACTION_LAYER_MOMENTARY(3), // to LOWER

 [3] = ACTION_LAYER_TAP_KEY(4, KC_SPC), // SpaceFN
 [4] = ACTION_DEFAULT_LAYER_SET(6), // Plover layer
 [5] = ACTION_LAYER_TOGGLE(4), // SpaceFN toggle
 [6] = ACTION_LAYER_TOGGLE(1), // Numpad toggle
 [7] = ACTION_LAYER_TAP_TOGGLE(5), // Mouse keys tap-toggle
 [8] = ACTION_DEFAULT_LAYER_SET(0),
};
