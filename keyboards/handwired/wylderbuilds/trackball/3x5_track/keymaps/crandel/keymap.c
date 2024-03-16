#include QMK_KEYBOARD_H
#include "3x5_track.h"

#include "crandel.h"

#ifdef LEADER_ENABLE
#  include "crd_leader.c"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "crd_tapdance.c"
#endif


void set_lang(bool lng){
  if (lng) {
    tap_code(KC_CAPS);
  } else {
    tap_code16(S(KC_CAPS));
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case V_US:
    if (record->event.pressed) {
      set_lang(true);
    }
    break;
  case V_UK:
    if (record->event.pressed) {
      set_lang(false);
    }
    break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  #ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
  #endif
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_3x5_wrapper(
    //--------------------      ,------------------.
      ____COLEMAK_L11____,      ____COLEMAK_L12____,
    //-------+-------+----      |------+-------+---|
      ____COLEMAK_L21____,      ____COLEMAK_L22____,
    //-------+-------+----      |------+-------+---|
      ____COLEMAK_L31____,      ____COLEMAK_L32____,
    //-------+-------+----      |------+-------+---|
          KC_LGUI, KC_SPC,                   KC_ENT,
       //--------+-------|       |------+----------|
          QK_LEAD,  TD(0),                  KC_BSPC,
       //--------+-------|       |------+----------|
          QK_GESC, KC_DEL,          TD(2),   KC_TAB
       //--------+-------|       |------+----------|
  ),
  [NUM_L] = LAYOUT_3x5_wrapper(
  //--------------------.    ,------------------.
     ____NUMBERS_L11____,    ____NUMBERS_L12____,
  //--------------------|    |-----+-------+----|
     ____NUMBERS_L21____,    ____NUMBERS_L22____,
  //--------------------|    |-----+-------+----|
     ____NUMBERS_L31____,    ____NUMBERS_L32____,
  //--------------------|    |-----+-------+----|
         KC_LGUI, KC_SPC,            KC_ENT,
    // ---------+-------|    |-----+-------|
         QK_LEAD,  TD(0),           KC_BSPC,
    // ---------+-------|    |-----+-------|
          KC_DEL,  KC_F1,     TD(2), KC_TAB
    // ---------+-------|    |-----+-------|
  ),
  [CHARS_L] = LAYOUT_3x5_wrapper(
  //-----------------------.    ,------------------.
        ____CHARCTS_L11____,    ____CHARCTS_L12____,
  //--------+-----+--------|    |------+-------+---|
        ____CHARCTS_L21____,    ____CHARCTS_L22____,
  //--------+-----+--------|    |------+-------+---|
        ____CHARCTS_L31____,    ____CHARCTS_L32____,
  //--------+-----+--------|    |------+-------+---|
           KC_LGUI,  KC_SPC,             KC_ENT,
           //-----+--------|    |------+-------|
           KC_LALT,  TD(0),             KC_BSPC,
           //-----+--------|    |------+-------|
            KC_DEL, QK_GESC,      TD(2), KC_TAB
           //-----+--------|    |------+-------|
  ),
  [MOUSE_L] = LAYOUT_3x5_wrapper(
  //,----------------------.    ,------------------.
        ____MOUSESS_L11____,    ____MOUSESS_L12____,
  //|-------+-------+------|    |------+-------+---|
        ____MOUSESS_L21____,    ____MOUSESS_L22____,
  //|-------+-------+------|    |------+-------+---|
        ____MOUSESS_L31____,    ____MOUSESS_L32____,
  //|-------+-------+------|    |------+-------+---|
           KC_LGUI,  KC_SPC,               KC_ENT,
         //--------+-------|    |--------+-------|
              TD(1),  TD(0),              KC_BSPC,
         //--------+-------|    |--------+-------|
            QK_BOOT, TO_GAM,     QK_BOOT,  KC_TAB
         //--------+-------|    |--------+-------|
  ),

  [GAME_L] = LAYOUT_3x5(
  //,-------------------------------------.    ,-------------------------------------------.
        KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
                            KC_ENT, KC_SPC,               KC_ENT,
                          //------+-------|    |- -----+--------|
                            KC_TAB,  TD(0),              KC_BSPC,
                          //------+-------|    |-------+--------|
                           KC_LALT, TO_GAM,     XXXXXXX,  KC_TAB
                          // -----+-------|    |-------+--------|
  )
};
