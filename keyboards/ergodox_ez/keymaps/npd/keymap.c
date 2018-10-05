#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // base programmers dvorak
#define SHFT 1 // shift
#define MDIA 2 // media keys

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
       KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL , _______,
       KC_DLR , KC_SCLN, KC_COMM, KC_DOT , KC_P   , KC_Y   , _______,
       KC_TAB , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
       NK_SFT , KC_QUOT, KC_Q   , KC_J   , KC_K   , KC_X   , _______,
       KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,
                                                    _______, _______,
                                                             KC_LALT,
                                           KC_SPC , KC_TAB , KC_LCTL,
       // right hand
       _______, KC_PAST, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH,
       KC_AT  , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
                KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_PMNS,
       KC_BSLS, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , NK_SFT ,
                         KC_DOWN, KC_UP  , KC_RALT, KC_RGUI, KC_RCTL,
       KC_ESC , _______,
       KC_RALT,
       KC_RCTL, KC_BSPC, KC_ENT
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
       SH_GRV , _______, _______, _______, _______, _______, KC_QUES,
                _______, _______, _______, _______, _______, KC_UNDS,
       KC_PIPE, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
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
