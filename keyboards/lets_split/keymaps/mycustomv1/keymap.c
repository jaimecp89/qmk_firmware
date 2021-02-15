#include QMK_KEYBOARD_H

// Layer shorthand
#define _QW 0
#define _FN 1
#define _FN2 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_ortho_4x12( /* QWERTY */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN), MO(_FN), KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_FN] = LAYOUT_ortho_4x12( /* FUNCTION */
    _______, KC_TAB,  KC_DQT,  KC_MINS, KC_GRV,  KC_EQL,  KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   KC_BSPC, KC_DEL,
    _______, KC_ESC,  KC_QUOT, KC_LBRC, KC_BSLS, KC_RBRC, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  KC_ENT,  _______,
    _______, KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______,  _______,  KC_RALT,  KC_RGUI, KC_RCTL, _______,
    _______, _______, KC_CAPS,   RESET, MO(_FN), MO(_FN), MO(_FN2), MO(_FN2), MO(_FN2), _______, _______, _______
  ),

  [_FN2] = LAYOUT_ortho_4x12( /* NUMBERS EASY ACCESS */
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
