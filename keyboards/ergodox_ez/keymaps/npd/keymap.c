#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define TAPPING_TOGGLE 1

#define BASE 0 // base programmers dvorak
#define SHFT 1 // shift
#define MDIA  2 // media keys

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
};

#define NK_SFT LM(SHFT, 2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
       // left hand
       KC_AMPR, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL , _______,
       KC_DLR , KC_SCLN, KC_COMM, KC_DOT , KC_P   , KC_Y   , _______,
       KC_TAB , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
       NK_SFT , KC_QUOT, KC_Q   , KC_J   , KC_K   , KC_X   , _______,
       KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,
                                                    _______, KC_INS ,
                                                             KC_LALT,
                                           KC_SPC , KC_TAB , TT(MDIA),
       // right hand
       _______, KC_PAST, KC_RPRN, KC_RCBR, KC_RBRC, KC_EXLM, KC_HASH,
       KC_AT  , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
                KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_PMNS,
       KC_BSLS, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , NK_SFT ,
                         KC_DOWN, KC_UP  , KC_RALT, KC_RGUI, KC_RCTL,
       KC_ESC , KC_DEL ,
       KC_RALT,
       TT(MDIA), KC_BSPC, KC_ENT
    ),

[SHFT] = LAYOUT_ergodox(
       // left hand
       SH_PERC, SH_1   , SH_2   , SH_3   , SH_4   , SH_5   , _______,
       KC_TILD, KC_COLN, KC_LABK, KC_RABK, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, KC_DQUO, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______, SH_6   , SH_7   , SH_8   , SH_9   , SH_0   , SH_GRV ,
       KC_CIRC, _______, _______, _______, _______, _______, KC_QUES,
                _______, _______, _______, _______, _______, KC_UNDS,
       KC_PIPE, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       // left hands
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,
       _______, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
       _______, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, _______,
       _______, KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_NLCK, _______,
       _______, KC_PPLS, KC_KP_0, KC_PDOT, KC_PENT,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
       _______, KC_HOME, _______, KC_UP  , _______, KC_PGUP, _______,
                KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
       _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
                         KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SH_PERC:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"%"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_1:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"1"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_2:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"2"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_3:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"3"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_4:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"4"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_5:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"5"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_6:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"6"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_7:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"7"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_8:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"8"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_9:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"9"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_0:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"0"SS_DOWN(X_LSHIFT));
      }
      return false;
    case SH_GRV:
      if (record->event.pressed) {
        SEND_STRING(SS_UP(X_LSHIFT)"`"SS_DOWN(X_LSHIFT));
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

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

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
