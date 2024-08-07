#pragma once

#include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

// For VIK SPI
#define SPI_SCK_PIN GP14
#define SPI_MOSI_PIN GP15
#define SPI_MISO_PIN GP12
#define SPI_DRIVER SPID1

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// wiring
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP26, GP22, GP20, GP23, GP21 }
#define MATRIX_COL_PINS { GP4, GP5, GP6, GP7, GP8 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#if defined(FP_WEACT_ST7735)
    // /* LCD config */
    #define DISPLAY_CS_PIN GP13
    #define DISPLAY_RST_PIN GP25 // unused pin, since it's handled with a circuit on the vik module
    #define DISPLAY_DC_PIN GP18

    // To dynamically control the backlight with BL_TOGG keycode
    #define BACKLIGHT_PIN GP24
#endif

#include "keyboards/fingerpunch/src/config_post.h"
