#include "../default/keymap.c"

bool spongebob_mode = false;
bool spongebob_case = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (spongebob_mode) {
    switch(keycode) {
      case KC_A...KC_Z:
        if (record->event.pressed) {
          (spongebob_case ^= 1) == 0 ? tap_code16(S(keycode)) : tap_code(keycode);
          return false; break;
        }
    }
  }
  switch(keycode) {
    case KC_F24:
      if (record->event.pressed) {
        spongebob_mode ^= 1;
      }
      return false; break;
  }
  return true;
}
