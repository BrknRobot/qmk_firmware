#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE   0 // base programmers dvorak
#define SHFT   1 // shift
#define CTRL   2
#define QWERTY 3
#define MDIA   4 // media keys
#define KBRD   5
#define UW     6

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  SH_PERC,
  SH_1,
  SH_2,
  SH_3,
  SH_4,
  SH_5,
  SH_6,
  SH_7,
  SH_8,
  SH_9,
  SH_0,
  SH_GRV,
  MY_LOCK,
  GP_LIKE,
  GP_DLKE,
  GP_LUCK,
  GP_NOTE,
  UT_A,
  UT_B,
  UT_N,
  UW_1,
  UW_2,
  UW_3,
  UW_4,
  UW_5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
       // left hand
       KC_AMPR, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL , _______,
       KC_DLR , KC_SCLN, KC_COMM, KC_DOT , KC_P   , KC_Y   , _______,
       KC_GRV , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
       TT(SHFT), KC_QUOT, KC_Q   , KC_J   , KC_K   , KC_X   , _______,
       TT(CTRL), KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,
                                                    KC_PSCR, KC_INS ,
                                                             TT(UW),
                                           KC_SPC , KC_TAB , TT(MDIA),
       // right hand
       _______, KC_PAST, KC_RPRN, KC_RCBR, KC_RBRC, KC_EXLM, KC_HASH,
       KC_SLSH, KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_AT  ,
                KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_PMNS,
       KC_BSLS, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , TT(SHFT),
                         KC_DOWN, KC_UP  , KC_RALT, KC_RGUI, TT(CTRL),
       KC_ESC , KC_DEL ,
       TT(KBRD),
       TT(MDIA), KC_BSPC, KC_ENT
    ),

[SHFT] = LAYOUT_ergodox(
       // left hand
       SH_PERC, SH_0   , SH_1   , SH_2   , SH_3   , SH_4   , _______,
       KC_TILD, KC_COLN, KC_LABK, KC_RABK, _______, _______, _______,
       KC_AT  , _______, _______, _______, _______, _______,
       _______, KC_DQUO, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______, SH_5   , SH_6   , SH_7   , SH_8   , SH_9   , SH_GRV ,
       KC_QUES, _______, _______, _______, _______, _______, KC_CIRC,
                _______, _______, _______, _______, _______, KC_UNDS,
       KC_PIPE, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[QWERTY] = LAYOUT_ergodox_pretty(
  // left hand
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,              KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,              XXXXXXX,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),         MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                               _______, _______,                _______, _______,
                                                        _______,                _______,
                                      _______, _______, _______,                _______, _______, _______
),

[CTRL] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,
        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
),

// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       // left hand
       XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,
       XXXXXXX, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
       XXXXXXX, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX,
       _______, KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_NUM , XXXXXXX,
       _______, KC_PPLS, KC_KP_0, KC_PDOT, KC_PENT,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
       XXXXXXX, KC_HOME, XXXXXXX, KC_UP  , XXXXXXX, KC_PGUP, XXXXXXX,
                KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
       GP_NOTE, GP_LUCK, KC_MPRV, KC_MPLY, KC_MNXT, GP_LIKE, _______,
                         KC_VOLD, KC_MUTE, KC_VOLU, GP_DLKE, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),

// Keyboard control
[KBRD] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           TG(QWERTY), _______, _______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,
                _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,
       _______, _______, _______, RGB_TOG, RGB_M_P, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, RGB_TOG
),
// UnionWare control
[UW] = LAYOUT_ergodox(
       // left hand
       UW_1, _______, _______, _______, _______, _______, UT_N,
       UW_2, _______, _______, _______, _______, _______, UT_B,
       UW_3, _______, _______, _______, _______, _______,
       UW_4, _______, _______, _______, _______, _______, UT_A,
       UW_5, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SH_PERC:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"%"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_1:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"1"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_2:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"2"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_3:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"3"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_4:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"4"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_5:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"5"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_6:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"6"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_7:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"7"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_8:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"8"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_9:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"9"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_0:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"0"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case SH_GRV:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LEFT_SHIFT)"`"SS_DOWN(X_LEFT_SHIFT));
      }
      return false;
    case GP_LIKE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("u"))));
      }
      return false;
    case GP_DLKE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("d"))));
      }
      return false;
    case GP_LUCK:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("l"))));
      }
      return false;
    case GP_NOTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("\\"))));
      }
      return false;
    case UT_A:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("a"))));
      }
      return false;
    case UT_B:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("b"))));
      }
      return false;
    case UT_N:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("n"))));
      }
      return false;
    case UW_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("reloadct")));
      }
      return false;
    case UW_2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("reloadsec")));
      }
      return false;
    case UW_3:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("uwsql")));
      }
      return false;
    case UW_4:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("uwborderstreet")));
      }
      return false;
    case UW_5:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("uwedit")));
      }
      return false;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  //uint8_t layer = biton32(state);

  if (state & 1<<SHFT) {
    SEND_STRING(SS_DOWN(X_LEFT_SHIFT));
    ergodox_right_led_1_on();
  }
  else {
    SEND_STRING(SS_UP(X_LEFT_SHIFT));
  }

  if (state & 1<<CTRL) {
    SEND_STRING(SS_DOWN(X_LEFT_CTRL));
    ergodox_right_led_2_on();
  }
  else {
    SEND_STRING(SS_UP(X_LEFT_CTRL));
  }

  if (state & 1<<MDIA) {
    ergodox_right_led_3_on();
  }

  if (state & 1<<KBRD) {

  }

  return state;
};
