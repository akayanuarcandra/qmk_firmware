#pragma once

#include QMK_KEYBOARD_H

void press_super_tab(bool shift, uint16_t mod);
void unregister_super_tab(uint16_t mod);
bool is_super_tab_cancel_key(uint16_t keycode);
void update_super_tab(uint16_t mod, uint16_t );
