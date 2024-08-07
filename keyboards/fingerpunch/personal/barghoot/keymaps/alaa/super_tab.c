#include "super_tab.h"

uint16_t super_tab_timer = 0;
bool is_super_tab_active = false;

void press_super_tab(bool shift, uint16_t mod) {
    if (shift) {
        register_code(KC_LSFT);
    } else {
        unregister_code(KC_LSFT);
    }
    if (!is_super_tab_active) {
        is_super_tab_active = true;
        register_code(mod);
    }

    super_tab_timer = timer_read();
    tap_code(KC_TAB);
}

void unregister_super_tab(uint16_t mod) {
    if (is_super_tab_active) {
        if (timer_elapsed(super_tab_timer) > 800 ) {
            unregister_code(mod);
            is_super_tab_active = false;

            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
    }
}

void update_super_tab(uint16_t mod, uint16_t keycode) {
    if (is_super_tab_active) {
        if (is_super_tab_cancel_key(keycode)) {
            unregister_code(mod);
            is_super_tab_active = false;

            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
    }
}
