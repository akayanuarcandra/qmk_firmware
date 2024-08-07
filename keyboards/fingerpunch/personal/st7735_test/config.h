/*
Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>

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

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 2
#define MATRIX_COLS 2

// wiring
#define MATRIX_ROW_PINS { D3, D1 }
#define MATRIX_COL_PINS { D2, D0 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* spi config for display*/
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B1
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN B2
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN B3
#define SPI_MISO_PAL_MODE 5

// /* LCD config */
// Cut slope
#define DISPLAY_CS_PIN F5
#define DISPLAY_RST_PIN B6
#define DISPLAY_DC_PIN F6

// To dynamically control the backlight with BL_TOGG keycode
#define BACKLIGHT_PIN F4

// Stront
// #define LCD_DC_PIN F6
// #define LCD_CS_PIN F5
// #define LCD_RST_PIN B6
// #define LCD_SPI_DIVISOR 8
// #define LCD_SPI_MODE 3

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
