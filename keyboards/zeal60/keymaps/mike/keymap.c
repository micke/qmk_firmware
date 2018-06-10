#include "zeal60.h"
#include "zeal_eeprom.h"

#define ______ KC_TRNS
#define XXXXXX KC_NO

#define _DEFAULT 0
#define _GAMING 1
#define _FUN 2
#define _FUN2 3
#define _SYS  4

enum custom_keycodes {
  KC_CLEP = SAFE_RANGE,
  KC_OSX,
  KC_WIN,
  KC_LIN
};

void non_clearing_layer_state_set(uint32_t state)
{
    dprint("layer_state: ");
    layer_debug(); dprint(" to ");
    layer_state = state;
    layer_debug(); dprintln();
}

void non_clearing_layer_on(uint8_t layer)
{
    non_clearing_layer_state_set(layer_state | (1UL<<layer));
}

void non_clearing_layer_off(uint8_t layer)
{
    non_clearing_layer_state_set(layer_state & ~(1UL<<layer));
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = {
  {KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS},
  {KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC},
  {KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_GRV},
  {KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_FUN)},
  {XXXXXX,   KC_LGUI,  KC_LALT,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  KC_SPC,  XXXXXX,  XXXXXX,   XXXXXX,   KC_RALT,  KC_RGUI,  XXXXXX}
},

[_FUN] = {
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  KC_PSCR,  KC_UP,    ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  KC_LEFT,  KC_RGHT,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   KC_DOWN,  MO(_FUN2),    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   MO(_SYS),  ______}
},

[_FUN2] = {
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  KC_MRWD,  KC_VOLD,  KC_VOLU,  KC_MFFD,  KC_MPLY,  ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,  ______}
},

[_SYS] = {
  {KC_CLEP,  EF_DEC,                EF_INC,              H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  ______,           ______,             ______,  ______,  BR_DEC,  BR_INC,  ______},
  {______,   KC_WIN,                ______,              S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  ______,           ______,             KC_OSX,  ______,  ES_DEC,  ES_INC,  ______},
  {______,   ______,                ______,              ______,  ______,  ______,  ______,  ______,           ______,             KC_LIN,  ______,  ______,  ______,  ______},
  {______,   ______,                ______,              ______,  ______,  ______,  ______,  MAGIC_HOST_NKRO,  MAGIC_UNHOST_NKRO,  ______,  ______,  ______,  ______,  ______},
  {______,   MAGIC_UNSWAP_ALT_GUI,  MAGIC_SWAP_ALT_GUI,  ______,  ______,  ______,  ______,  ______,           ______,             ______,  ______,  ______,  ______,  ______}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t action_layer;

  switch(keycode) {
    case KC_CLEP:
      // Set the Zeal60 specific EEPROM state as invalid.
      eeprom_set_valid(false);
      // Set the TMK/QMK EEPROM state as invalid.
      eeconfig_disable();
      // Jump to bootloader.
      bootloader_jump();
      return false;
    case KC_OSX:
      set_unicode_input_mode(UC_OSX);
      return false;
    case KC_WIN:
      set_unicode_input_mode(UC_WIN);
      return false;
    case KC_LIN:
      set_unicode_input_mode(UC_LNX);
      return false;
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
      action_layer = keycode & 0xFF;

      if (record->event.pressed) {
        non_clearing_layer_on(action_layer);
      } else {
        non_clearing_layer_off(action_layer);
      }

      return false;
  }

  return true;
}

void matrix_init_user(){
  set_unicode_input_mode(UC_OSX);
}
