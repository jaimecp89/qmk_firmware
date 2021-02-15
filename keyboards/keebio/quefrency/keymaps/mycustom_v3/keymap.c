#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
    KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC, KC_PSCREEN, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_END, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_FN1),         KC_SPC,  _______, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, KC_TAB,  KC_DQT,  KC_MINS, KC_GRV,  KC_EQL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,  _______, _______, _______, _______, \
    _______, KC_ESC,  KC_QUOT, KC_LBRC, KC_BSLS, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______, _______, _______, \
    _______, KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, KC_RALT, KC_RGUI, KC_RCTL, _______, _______, _______, \
    _______, _______, _______, _______, _______,          MO(_FN2),_______, _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_65( /* NUMBERS EASY ACCESS */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, \
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};
