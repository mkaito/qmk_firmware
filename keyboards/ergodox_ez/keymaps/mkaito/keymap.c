#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0             // default layer
#define SYMB 1             // symbols
#define MDIA 2             // media keys
#define STAR 3             // sc2 keys
#define STR2 4             // sc2 extra keys
#define _______ KC_TRNS    // unclutter

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  GG,
  GGWP,
  GLHF,
  QUIT,
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Keymap 0: Basic layer
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        MO(MDIA),       KC_1,        KC_2,            KC_3,    KC_4,   KC_5,   _______,
        KC_TAB,         KC_Q,        KC_W,            KC_E,    KC_R,   KC_T,   LCTL(KC_LGUI),
        CTL_T(KC_ESC),  KC_A,        KC_S,            KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,        KC_X,            KC_C,    KC_V,   KC_B,   KC_LGUI,
        LALT(KC_F4),    LALT(KC_F3), LALT(KC_F2),     KC_LALT, TT(SYMB),

                                                      KC_SLCK, KC_PSCR,
                                                               KC_DEL,
                                             KC_BSPC, KC_SPC,  KC_BRK,
        // right hand
        TO(STAR),      KC_6,    KC_7,     KC_8,    KC_9,       KC_0,        KC_BSLASH,
        LSFT(KC_INS),  KC_Y,    KC_U,     KC_I,    KC_O,       KC_P,        KC_MINUS,
                       KC_H,    KC_J,     KC_K,    KC_L,       KC_SCLN,     KC_QUOTE,
        KC_EQL,        KC_N,    KC_M,     KC_COMM, KC_DOT,     KC_SLSH,     KC_RSFT,
                                MO(SYMB), KC_RALT, LALT(KC_P), LALT(KC_F8), LALT(KC_F1),

                       KC_HOME, KC_END,
                       KC_PGUP,
                       KC_PGDN, KC_ENTER, KC_SPACE
    ),
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______,KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PIPE, _______,
       _______,KC_HASH, KC_CIRC, KC_LPRN, KC_RPRN, KC_GRV,
       _______,KC_PERC, KC_DLR,  KC_LCBR, KC_RCBR, KC_TILD, _______,
       RESET  ,EEP_RST, _______, _______, _______,
                                          _______, _______,
                                                   _______,
                                 _______, _______, _______,
       // right hand
       _______, KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_PGUP,   KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_F12,
                KC_PGDOWN, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_F13,
       _______, KC_AMPR,   KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_NLCK,
                           _______, KC_P0,   KC_PDOT, KC_PPLS, KC_PEQL,
                _______,   _______,
                _______,
                _______,   _______,  _______
),
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
       _______,  _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______,
                          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[STAR] = LAYOUT_ergodox(  // layer 3: StarCraft II
        // left hand
        KC_ESC, KC_1,  KC_2,   KC_3,    KC_4,    KC_5,   KC_6,
        KC_TAB, KC_Q,  KC_W,   KC_E,    KC_R,    KC_T,   KC_7,
        KC_LCTL,KC_A,  KC_S,   KC_D,    KC_F,    KC_G,
        KC_LSFT,KC_Z,  KC_X,   KC_C,    KC_V,    KC_B,   KC_8,
        KC_F10, KC_F9, KC_F11, KC_LALT, MO(STR2),

                                        _______, _______,
                                                 _______,
                                KC_SPC, KC_BSPC, _______,
       // right hand
       TO(BASE),  _______, _______, _______, _______, _______, GLHF,
       GGWP,      _______, _______, _______, _______, _______, GG,
                  _______, _______, _______, _______, _______, _______,
       QUIT,      _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______,
       _______,   _______,
       _______,
       _______,   _______, _______
    ),
[STR2] = LAYOUT_ergodox(  // layer 4: StarCraft II extra keys
        // left hand
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        _______, _______, _______, _______, _______, _______, KC_F7,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F8,
        _______, _______, _______, _______, _______,

                                         _______, _______,
                                                  _______,
                                _______,  _______,  _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______,  _______,
       _______,
       _______,   _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case GG:
        SEND_STRING ("\n(gg)(cbquit)\n");
        return false;
      case GLHF:
        SEND_STRING ("\n(glhf)(cbprobe)\n");
        return false;
      case GGWP:
        // F10 w takes you straight from a game into the replay.
        SEND_STRING (SS_TAP(X_F10)"w");
        return false;
      case QUIT:
        // F10 followed by q or n will quit out of replays and surrender current game.
        SEND_STRING (SS_TAP(X_F10)"qn");
        return false;
    }
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) { };

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) { };

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
