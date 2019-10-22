#include QMK_KEYBOARD_H
#include "keyboards/wilba_tech/zeal60/zeal60.h"

#define _______ KC_TRNS
#define XXXXXX_ KC_NO

#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_SPCOF LT(_FUN,  KC_SPC)

#define _DEFAULT 0
#define _GAMING 1
#define _FUN 2
#define _FUN2 3
#define _SYS  4

extern void eeprom_reset(void);

enum {
  TD_FUN_OR_SWITCH_DEFAULT  = 0
};

#define KC_FUN_OR_SWITCH_DEFAULT TD(TD_FUN_OR_SWITCH_DEFAULT)

enum custom_keycodes {
  KC_CLEP = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Default layer
  [_DEFAULT] = LAYOUT_all(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,            KC_UP,   KC_FUN_OR_SWITCH_DEFAULT,
    MO(1),   KC_LGUI, KC_LALT,                            KC_SPCOF,                           KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

  [_GAMING] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_RSFT, _______,
    _______, _______, _______,                            KC_SPC,                                      _______,          _______, _______, _______),

  // Fn1 Layer
  [_FUN] = LAYOUT_all(
    KC_CAD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,                   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
    _______, _______, _______,                            _______,                                     _______,          _______, _______, _______),

  // Fn3 Layer
  [_FUN2] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, _______, _______,                   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
    _______, _______, _______,                            _______,                                     MO(_SYS),         _______, _______, _______),

  // Fn3 Layer
  [_SYS] = LAYOUT_all(
    KC_CLEP,                      EF_DEC,               EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  _______, _______, _______, _______, BR_DEC,  BR_INC,  _______, _______, _______,
    _______,                      _______,              _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, ES_DEC,  ES_INC,  _______,          _______,
    _______,                      _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    _______,                      _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
    _______,                      MAGIC_UNSWAP_ALT_GUI, MAGIC_SWAP_ALT_GUI,                          _______,                                     _______,          _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_CLEP:
      eeprom_reset();
      bootloader_jump();
      return false;
  }

  return true;
}

void dance_switch_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (IS_LAYER_ON(_GAMING)) {
      layer_on(_FUN);
    } else {
      layer_on(_FUN2);
    }
  } else {
    if (IS_LAYER_ON(_GAMING)) {
      layer_off(_GAMING);
    } else {
      layer_on(_GAMING);
    }
  }
}

void dance_switch_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (IS_LAYER_ON(_GAMING)) {
      layer_off(_FUN);
    } else {
      layer_off(_FUN2);
    }
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_FUN_OR_SWITCH_DEFAULT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_switch_finished, dance_switch_reset)
};
