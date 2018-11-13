#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // base programmers dvorak
#define SHFT 1 // shift
#define CTRL 2
#define MDIA 3 // media keys
#define KBRD 4

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
  MY_LOCK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
       // left hand
       KC_AMPR, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL , _______,
       KC_DLR , KC_SCLN, KC_COMM, KC_DOT , KC_P   , KC_Y   , _______,
       KC_TAB , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
       TT(SHFT), KC_QUOT, KC_Q   , KC_J   , KC_K   , KC_X   , _______,
       TT(CTRL), KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,
                                                    MY_LOCK, KC_INS ,
                                                             TT(KBRD),
                                           KC_SPC , KC_TAB , TT(MDIA),
       // right hand
       _______, KC_PAST, KC_RPRN, KC_RCBR, KC_RBRC, KC_EXLM, KC_HASH,
       KC_AT  , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
                KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_PMNS,
       KC_BSLS, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , TT(SHFT),
                         KC_DOWN, KC_UP  , KC_RALT, KC_RGUI, TT(CTRL),
       KC_ESC , KC_DEL ,
       TT(KBRD),
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
       _______, KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_NLCK, XXXXXXX,
       _______, KC_PPLS, KC_KP_0, KC_PDOT, KC_PENT,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
       XXXXXXX, KC_HOME, XXXXXXX, KC_UP  , XXXXXXX, KC_PGUP, XXXXXXX,
                KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
       XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
                         KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
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
                                           _______, _______, _______,
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

  //uint8_t layer = biton32(state);

  if (state & 1<<SHFT) {
    SEND_STRING(SS_DOWN(X_LSHIFT));
    ergodox_right_led_1_on();
  }
  else {
    SEND_STRING(SS_UP(X_LSHIFT));
  }

  if (state & 1<<CTRL) {
    SEND_STRING(SS_DOWN(X_LCTRL));
    ergodox_right_led_2_on();
  }
  else {
    SEND_STRING(SS_UP(X_LCTRL));
  }

  if (state & 1<<MDIA) {
    ergodox_right_led_3_on();
  }

  if (state & 1<<KBRD) {

  }

  return state;
};
