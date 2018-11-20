// M60-A layout
#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define XXXXXX KC_NO

#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_SPCOF LT(_FUN,  KC_SPC)

#define _DEFAULT 0
#define _GAMING 1
#define _FUN 2
#define _FUN2 3
#define _SYS  4

enum {
  TD_FUN_OR_SWITCH_DEFAULT  = 0
};

#define KC_FUN_OR_SWITCH_DEFAULT TD(TD_FUN_OR_SWITCH_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layer
[_DEFAULT] = LAYOUT_60_hhkb(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_FUN_OR_SWITCH_DEFAULT,
           KC_LGUI, KC_LALT,                            KC_SPCOF,                           KC_RALT, KC_RGUI),

[_GAMING] = LAYOUT_60_hhkb(
  ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______, ______, ______,
  ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______, ______,
  ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  ______,
  KC_LSFT, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_RSFT, ______,
           ______, ______,                            KC_SPC,                              ______, ______),

// Fn1 Layer
[_FUN] = LAYOUT_60_hhkb(
  KC_CAD, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11, KC_F12, ______, ______,
  ______, ______, ______, ______, ______, ______, ______,  ______,  ______, ______,  KC_PSCR, ______, ______, ______,
  ______, ______, ______, ______, ______, ______, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, ______,  ______, ______,
  ______, ______, ______, ______, ______, ______, ______,  ______,  ______, ______,  ______,  ______, ______,
          ______, ______,                            ______,                                  ______, ______),

// Fn2 Layer
[_FUN2] = LAYOUT_60_hhkb(
  ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______, ______, ______,
  ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______, ______,
  ______, ______, ______, ______, ______, ______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, ______, ______,
  ______, ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______,
          ______, ______,                            ______,                                   ______, MO(_SYS)),

// Fn3 Layer (zeal60 Configuration)
[_SYS] = LAYOUT_60_hhkb(
  ______,                       EF_DEC,             EF_INC, H1_DEC, H1_INC,  H2_DEC, H2_INC, ______,          ______,            ______, ______, BR_DEC, BR_INC, ______, ______,
  ______,                       ______,             ______, S1_DEC, S1_INC,  S2_DEC, S2_INC, ______,          ______,            ______, ______, ES_DEC, ES_INC, ______,
  ______,                       ______,             ______, ______, ______,  ______, ______, ______,          ______,            ______, ______, ______, ______,
  ______,                       ______,             ______, ______, ______,  ______, ______, MAGIC_HOST_NKRO, MAGIC_UNHOST_NKRO, ______, ______, ______, ______,
          MAGIC_UNSWAP_ALT_GUI, MAGIC_SWAP_ALT_GUI, ______, ______, ______),

};

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
