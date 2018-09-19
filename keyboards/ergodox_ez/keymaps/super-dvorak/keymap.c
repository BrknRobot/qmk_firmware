#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ergodox(
    KC_DLR, KC_AMPR, KC_LBRC, KC_LCBR, KC_LCBR, KC_LPRN, KC_EQL ,
    KC_TAB, KC_SCLN, k12, k13, k14, k15, k16,
    k20, k21, k22, k23, k24, k25,
    k30, k31, k32, k33, k34, k35, k36,
    k40, k41, k42, k43, k44,
                            k55, k56,
                                k54,
                        k53, k52, k51,

        k07, k08, k09, k0A, k0B, k0C, k0D,
        k17, k18, k19, k1A, k1B, k1C, k1D,
            k28, k29, k2A, k2B, k2C, k2D,
        k37, k38, k39, k3A, k3B, k3C, k3D,
                k49, k4A, k4B, k4C, k4D,
    k57, k58,
    k59,
    k5C, k5B, k5A
  )
    KC_DLR,            KC_AMPR,   KC_LBRACKET, C_LCBR, C_RCBR, C_LPRN, C_EQUAL,
    C_TAB,             C_SCOLON,  C_COMMA,     C_DOT,  C_P,    C_Y,    C_TRANSPARENT,
    C_BSPACE,          C_A,       C_O,         C_E,    C_U,    C_I,
    FT_T(KC_KP_SLASH), C_QUOTE,   C_Q,         C_J,    C_K,    C_X,    C_TRANSPARENT,
    C_LCTRL,           C_LGUI,    C_LALT,      C_LEFT, C_RIGHT,

                         O(2), C_TRANSPARENT,
                               C_LALT,        C_SPACE, O(1), C_LCTRL, C_ASTR, C_RPRN, C_PLUS, C_RBRACKET, C_EXLM, C_HASH, C_BSPACE, C_BSLASH, C_F, C_G, C_C, C_R, C_L, C_AT, C_D, C_H, C_T, C_N, C_S, C_MINUS, C_SLASH, C_B, C_M, C_W, C_V, C_Z, SFT_T(KC_BSLASH), C_DOWN, C_UP, C_RALT, C_RGUI, C_RCTRL, C_ESCAPE, O(2), C_RALT, C_RCTRL, O(1), C_ENTER),

  [1] = LAYOUT_ergodox(KC_TILD, C_PERC, C_0, C_1, C_2, C_3, C_4, SFT(KC_TAB), C_COLN, C_LABK, C_RABK, SFT(KC_P), SFT(KC_Y), C_TRANSPARENT, SFT(KC_CAPSLOCK), SFT(KC_A), SFT(KC_O), SFT(KC_E), SFT(KC_U), SFT(KC_I), C_TRANSPARENT, C_DQUO, SFT(KC_Q), SFT(KC_J), SFT(KC_K), SFT(KC_X), C_TRANSPARENT, C_MEDIA_PREV_TRACK, C_MEDIA_PLAY_PAUSE, C_MEDIA_NEXT_TRACK, C_AUDIO_VOL_DOWN, C_AUDIO_VOL_UP, C_TRANSPARENT, C_TRANSPARENT, SFT(KC_LALT), SFT(KC_SPACE), C_TRANSPARENT, SFT(KC_LCTRL), C_5, C_6, C_7, C_8, C_9, C_GRAVE, C_CIRC, C_TRANSPARENT, SFT(KC_F), SFT(KC_G), SFT(KC_C), SFT(KC_R), SFT(KC_L), C_QUES, SFT(KC_D), SFT(KC_H), SFT(KC_T), SFT(KC_N), SFT(KC_S), C_UNDS, C_TRANSPARENT, SFT(KC_B), SFT(KC_M), SFT(KC_W), SFT(KC_V), SFT(KC_Z), C_PIPE, C_PGDOWN, C_PGUP, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, SFT(KC_RALT), SFT(KC_RCTRL), C_TRANSPARENT, SFT(KC_ENTER)),

  [2] = LAYOUT_ergodox(KC_TRANSPARENT, C_F1, C_F2, C_F3, C_F4, C_F5, C_F6, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_MS_UP, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_MS_LEFT, C_MS_DOWN, C_MS_RIGHT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_MS_BTN1, C_MS_BTN2, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_F7, C_F8, C_F9, C_F10, C_F11, C_F12, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_UP, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_LEFT, C_DOWN, C_RIGHT, C_TRANSPARENT, C_MEDIA_PLAY_PAUSE, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_MEDIA_PREV_TRACK, C_MEDIA_NEXT_TRACK, C_TRANSPARENT, C_TRANSPARENT, C_AUDIO_VOL_UP, C_AUDIO_VOL_DOWN, C_AUDIO_MUTE, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_TRANSPARENT, C_WWW_BACK),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
