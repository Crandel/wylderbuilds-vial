#pragma once
void shifted_letters(uint8_t code){
  register_code(KC_LSFT);
  tap_code16(C(code));
  unregister_code(KC_LSFT);
}
