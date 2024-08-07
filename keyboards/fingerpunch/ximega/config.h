/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// For General SPI pins and VIK
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

#define MASTER_LEFT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_POINTING_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_HAPTIC_ENABLE
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin

#ifdef FP_VIK2_RGB
#define WS2812_DI_PIN GP8
#else
#define WS2812_DI_PIN GP25
#endif
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SPLIT
    #define RGBLED_SPLIT { 29, 29 }
    #define RGBLIGHT_LED_COUNT 58
    #define RGBLIGHT_HUE_STEP 16
    #define RGBLIGHT_SAT_STEP 16
    #define RGBLIGHT_VAL_STEP 16
    #define RGBLIGHT_LIMIT_VAL 130 /* The maximum brightness level for RGBLIGHT_ENABLE */
    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef RGB_MATRIX_ENABLE
    #define SPLIT_TRANSPORT_MIRROR
    #define RGB_MATRIX_LED_COUNT 58 // Number of LEDs
    #define RGB_MATRIX_SPLIT { 29, 29 }
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 130
    #define RGB_MATRIX_STARTUP_HUE 35
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_SLEEP
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYREACTIVE_ENABLED
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#ifdef AUDIO_ENABLE
    #define AUDIO_VOICES
    #define AUDIO_PIN GP18
    #define AUDIO_PWM_DRIVER PWMD1
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
    #define AUDIO_ENABLE_TONE_MULTIPLEXING
    #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
    #define FP_AUDIO_MOUSE_BUTTONS
    #define FP_AUDIO_CUT_COPY_PASTE
    #define FP_AUDIO_SAVE
    #define FP_STARTUP_XIMEGA WHOLE_NOTE(_FS5), QUARTER_NOTE(_A5), HALF_DOT_NOTE(_B5), WHOLE_NOTE(_D6), QUARTER_NOTE(_REST), HALF_DOT_NOTE(_B5), HALF_DOT_NOTE(_FS5), HALF_DOT_NOTE(_D5), HALF_DOT_NOTE(_E5), HALF_NOTE(_REST), HALF_DOT_NOTE(_D5), HALF_DOT_NOTE(_B4),
    #define STARTUP_SONG SONG(FP_STARTUP_XIMEGA)
    #define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// All the possible configurations of pointing devices
#if defined(VIK_CIRQUE) || defined(VIK_PER56_CIRQUE_LEDS)
    #define POINTING_DEVICE_ROTATION_90
#endif

#if defined(VIK_CIRQUE_RIGHT) || defined(VIK_PER56_CIRQUE_LEDS_RIGHT)
    #ifdef POINTING_DEVICE_COMBINED
        #define POINTING_DEVICE_ROTATION_90_RIGHT
    #else
        #define POINTING_DEVICE_ROTATION_90
    #endif
#endif

#if defined(VIK_PMW3360) || defined(VIK_PER56_PMW3360_LEDS)
    #define POINTING_DEVICE_INVERT_X
#endif

#if defined(VIK_PMW3360_RIGHT) || defined(VIK_PER56_PMW3360_LEDS_RIGHT)
    #ifdef POINTING_DEVICE_COMBINED
        #define POINTING_DEVICE_INVERT_X_RIGHT
    #else
        #define POINTING_DEVICE_INVERT_X
    #endif
#endif

#if defined(VIK_AZOTEQ)
    #define AZOTEQ_IQS5XX_TPS65
    #define POINTING_DEVICE_ROTATION_270
#endif

#if defined(VIK_AZOTEQ_RIGHT)
    #define AZOTEQ_IQS5XX_TPS65
    #ifdef POINTING_DEVICE_COMBINED
        #define POINTING_DEVICE_ROTATION_270_RIGHT
    #else
        #define POINTING_DEVICE_ROTATION_270
    #endif
#endif

// Display rotations
#if defined(VIK_WEACT_ST7735)
    #define FP_QP_ROTATION QP_ROTATION_180
#endif

// Encoder configuration from VIK is in version specific config, e.g. ximega/v1/config.h
