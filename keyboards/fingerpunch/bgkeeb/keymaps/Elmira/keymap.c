#include QMK_KEYBOARD_H
#include "accordion/accordion.h"

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "color.h"
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _MEDIA,
    _ARROW,
    _MOUSE,
    _NUMBER,
    _SYMBOL,
    _FUNC,
    _GAME
};

enum custom_keycodes {
    DDOT = SAFE_RANGE,
};

#define GAME TO(_GAME)
#define NORM TO(_QWERTY)

bool is_caps_lock_on;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x5_4(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,             KC_Y,           KC_U,         KC_I,         KC_O,         KC_P,
  KC_A,         LCTL_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,             KC_H,           LSFT_T(KC_J), LALT_T(KC_K), LCTL_T(KC_L), LGUI_T(KC_QUOT),
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,             KC_N,           KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                XXXXXXX,      LT(1,KC_ESC), LT(2,KC_TAB), LT(3,KC_ENT),     LT(4,KC_SPC),   LT(5,KC_BSPC),LT(6,KC_DEL), XXXXXXX
),

[_MEDIA] = LAYOUT_split_3x5_4(
  QK_BOOT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,        KC_MUTE,      XXXXXXX,      XXXXXXX,      GAME,
  KC_LGUI,      KC_LCTL,      KC_LALT,      KC_LSFT,      XXXXXXX,          KC_BRIU,        KC_VOLU,      KC_MPLY,      KC_MPRV,      KC_MNXT,
  XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          KC_BRID,        KC_VOLD,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                XXXXXXX,      XXXXXXX,      KC_TAB,       KC_ENT,           KC_SPC,         KC_BSPC,      KC_DEL,       XXXXXXX
),

[_ARROW] = LAYOUT_split_3x5_4(
  XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          KC_PSCR,        KC_INS,       KC_CAPS,      KC_BSLS,      XXXXXXX,
  KC_LGUI,      KC_LCTL,      KC_LALT,      KC_LSFT,      XXXXXXX,          KC_LEFT,        KC_DOWN,      KC_UP,        KC_RGHT,      KC_BRIU,
  XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          KC_HOME,        KC_PGDN,      KC_PGUP,      KC_END,       KC_BRID,
                XXXXXXX,      KC_ESC,       XXXXXXX,      KC_ENT,           KC_SPC,         KC_BSPC,      KC_DEL,       XXXXXXX
),

[_MOUSE] = LAYOUT_split_3x5_4(
  XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  KC_LGUI,      KC_LCTL,      KC_LALT,      KC_LSFT,      XXXXXXX,          KC_MS_L,        KC_MS_D,      KC_MS_U,      KC_MS_R,      KC_WFWD,
  XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_ACL1,      KC_ACL0,          KC_WH_L,        KC_WH_D,      KC_WH_U,      KC_WH_R,      KC_WBAK,
                XXXXXXX,      KC_ESC,       KC_TAB,       XXXXXXX,          KC_BTN1,        KC_BTN2,      KC_BTN3,      XXXXXXX
),

[_NUMBER] = LAYOUT_split_3x5_4(
  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,             XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  KC_6,         KC_7,         KC_8,         KC_9,         KC_0,             XXXXXXX,        KC_LSFT,      KC_LALT,      KC_LCTL,      KC_LGUI,
  KC_SCLN,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                XXXXXXX,      XXXXXXX,      KC_LPRN,      KC_RPRN,          XXXXXXX,        KC_BSPC,      KC_DEL,       XXXXXXX   
),

[_SYMBOL] = LAYOUT_split_3x5_4(
  KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_MINS,      KC_PLUS,          XXXXXXX,        KC_LSFT,      KC_LALT,      KC_LCTL,      KC_LGUI,
  DDOT,         KC_TILD,      KC_GRV,       KC_UNDS,      KC_EQL,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                XXXXXXX,      XXXXXXX,      KC_LCBR,      KC_RCBR,          KC_SPC,         XXXXXXX,      KC_DEL,       XXXXXXX   
),

[_FUNC] = LAYOUT_split_3x5_4(
  KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,            XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,           XXXXXXX,        KC_LSFT,      KC_LALT,      KC_LCTL,      KC_LGUI,
  XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_F11,       KC_F12,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                XXXXXXX,      XXXXXXX,      KC_LBRC,      KC_RBRC,          KC_SPC,         KC_BSPC,      XXXXXXX,      XXXXXXX   
),

[_GAME] = LAYOUT_split_3x5_4(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,             KC_Y,           KC_U,         KC_I,         KC_O,         KC_P,
  KC_A,         KC_S,         KC_D,         KC_F,         KC_G,             KC_H,           KC_J,         KC_K,         KC_L,         KC_QUOT,
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,             KC_N,           KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                XXXXXXX,      KC_ESC,       KC_TAB,       KC_SPC,           KC_ENT,         KC_BSPC,      NORM,         XXXXXXX
)
};


void keyboard_post_init_user(void) {
    is_caps_lock_on = false;
    #ifdef PIMORONI_TRACKBALL_ENABLE
    pimoroni_trackball_set_rgbw(RGB_BLUE, 0x00);
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS_LOCK:
            if (record->event.pressed) {
                if (is_caps_lock_on) {
                    is_caps_lock_on = false;
                } else {
                    is_caps_lock_on = true;
                }
            }
            break;
        case DDOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(";"));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        default:
            break;
    }

    return true;
}
