#include "zeal60.h"
#include "zeal_eeprom.h"

#define ______ KC_TRNS
#define XXXXXX KC_NO

#define _DEFAULT 0
#define _GAMING 1
#define _FUN 2
#define _FUN2 3
#define _SYS  4

#define M_CLEP 0

#define KC_CLEP M(M_CLEP)

#define KC_SPC_OR_FUN LT(_FUN,  KC_SPC)

enum {
  TD_FUN2_OR_SWITCH_DEFAULT  = 0
};

#define KC_FUN2_OR_SWITCH_DEFAULT TD(TD_FUN2_OR_SWITCH_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = {
  {KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,           KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSLS},
  {KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,           KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC},
  {KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,           KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,    KC_GRV },
  {KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,           KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   KC_FUN2_OR_SWITCH_DEFAULT},
  {XXXXXX,   KC_LGUI,  KC_LALT,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  KC_SPC_OR_FUN,  XXXXXX,  XXXXXX,   XXXXXX,   KC_RALT,  KC_RGUI,   XXXXXX}
},

[_GAMING] = {
  {KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSLS},
  {KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC},
  {KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  KC_SCLN,  KC_QUOT,  KC_ENT,    KC_GRV },
  {KC_LSFT,  XXXXXX,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   KC_FUN2_OR_SWITCH_DEFAULT},
  {XXXXXX,   KC_LGUI,  KC_LALT,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,   KC_SPC,   XXXXXX,  XXXXXX,   XXXXXX,   KC_RALT,  KC_RGUI,   XXXXXX}
},

[_FUN] = {
  {KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  ______},
  {______,   KC_HOME,  KC_PGUP,  ______,   ______,  ______,  ______,   ______,   ______,  ______,   KC_PSCR,  ______,  ______,  KC_DEL},
  {______,   KC_END,   KC_PGDN,  KC_RGHT,  ______,  ______,  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  ______,   ______,  ______,  ______},
  {______,   ______,   ______,   ______,   ______,  ______,  ______,   ______,   ______,  ______,   ______,   ______,  ______,  ______},
  {______,   ______,   ______,   ______,   ______,  ______,  ______,   ______,   ______,  ______,   ______,   ______,  ______,  ______}
},

[_FUN2] = {
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  KC_MRWD,  KC_VOLD,  KC_VOLU,  KC_MFFD,  KC_MPLY,  ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  ______,    ______},
  {______,  ______,  ______,  ______,  ______,  ______,  ______,   ______,   ______,   ______,   ______,   ______,  MO(_SYS),  ______}
},

[_SYS] = {
  {KC_CLEP,  EF_DEC,                EF_INC,              H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  ______,           ______,             ______,  ______,  BR_DEC,  BR_INC,  ______},
  {______,   ______,                ______,              S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  ______,           ______,             ______,  ______,  ES_DEC,  ES_INC,  ______},
  {______,   ______,                ______,              ______,  ______,  ______,  ______,  ______,           ______,             ______,  ______,  ______,  ______,  ______},
  {______,   ______,                ______,              ______,  ______,  ______,  ______,  MAGIC_HOST_NKRO,  MAGIC_UNHOST_NKRO,  ______,  ______,  ______,  ______,  ______},
  {______,   MAGIC_UNSWAP_ALT_GUI,  MAGIC_SWAP_ALT_GUI,  ______,  ______,  ______,  ______,  ______,           ______,             ______,  ______,  ______,  ______,  ______}
}

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case M_CLEP:
        // Set the Zeal60 specific EEPROM state as invalid.
        eeprom_set_valid(false);
        // Set the TMK/QMK EEPROM state as invalid.
        eeconfig_disable();
        // Jump to bootloader.
        bootloader_jump();
        break;
      /* case M_LBRCA: */
      /*   if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) { */
      /*     register_code(UC(0xE5)); */
      /*     unregister_code(UC(0xE5)); */
      /*   } else { */
      /*     SEND_STRING(SS_TAP(X_LBRC)); */
      /*   } */
      /*   break; */
    }
  }
  return MACRO_NONE;
};

void dance_switch_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_on(_FUN2);
  } else {
    uint8_t deflayer = biton32(default_layer_state);

    if (deflayer == _DEFAULT) {
      default_layer_set(1UL<<_GAMING);
    } else {
      default_layer_set(1UL<<_DEFAULT);
    }
  }
}

void dance_switch_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_off(_FUN2);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_FUN2_OR_SWITCH_DEFAULT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_switch_finished, dance_switch_reset)
};
