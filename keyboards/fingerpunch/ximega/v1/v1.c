/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "v1.h"

#define NLD NO_LED

#ifdef RGB_MATRIX_ENABLE

// Layout
//
//┌────────────────────────┐                 ┌────────────────────────┐
//│ 25  24  17  16  09  08 │                 │ 37  38  45  46  53  54 │
//│────────────────────────┤                 ├────────────────────────│
//│ 26  23  18  15  10  07 │                 │ 36  39  44  47  52  55 │
//│────────────────────────┤                 ├────────────────────────│
//│ 27  22  19  14  11  06 │                 │ 35  40  43  48  51  56 │
//├────────────────────────┤                 ├────────────────────────┤
//│ 28  21  20  13  12  05 │                 │ 34  41  42  49  50  57 │
//└───────────┬────────────┴───────┐ ┌───────┴────────────┬───────────┘
//            │ 04  03  02  01  00 │ │ 29  30  31  32  33 │
//            └────────────────────┘ └────────────────────┘
//
//

led_config_t g_led_config = { {
//COL   00     01     02     03     04     05     06      07       ROW
    {   25,    24,    17,    16,    9,     8,     3,      4      },//00
    {   26,    23,    18,    15,    10,    7,     2,      NO_LED },//01
    {   27,    22,    19,    14,    11,    6,     1,      NO_LED },//02
    {   28,    21,    20,    13,    12,    5,     0,      NO_LED },//03
    {   54,    53,    46,    45,    38,    37,    32,     33     },//00
    {   55,    52,    47,    44,    39,    36,    31,     NO_LED },//01
    {   56,    51,    48,    43,    40,    35,    30,     NO_LED },//02
    {   57,    50,    49,    42,    41,    34,    29,     NO_LED },//03
}, {
    // Left
    {86 , 0},   // Thumb reachy
    {71 , 3},   // Thumb homing
    {55 , 4},   // Thumb tucky
    {41 , 4},   // Thumb tucky 2
    {27 , 4},   // Thumb tucky 3
    {69 , 19},  // C5 R3
    {69 , 32},  // C5 R2
    {69 , 44},  // C5 R1
    {69 , 57},  // C5 R0
    {55 , 59},  // C4 R0
    {55 , 46},  // C4 R1
    {55 , 33},  // C4 R2
    {55 , 20},  // C4 R3
    {41 , 24},  // C3 R3
    {41 , 37},  // C3 R2
    {41 , 50},  // C3 R1
    {41 , 63},  // C3 R0
    {27 , 59},  // C2 R0
    {27 , 46},  // C2 R1
    {27 , 33},  // C2 R2
    {27 , 20},  // C2 R3
    {13 , 12},  // C1 R3
    {13 , 25},  // C1 R2
    {13 , 38},  // C1 R1
    {13 , 51},  // C1 R0
    {0 , 46},   // C0 R0
    {0 , 33},   // C0 R1
    {0 , 20},   // C0 R2
    {0 , 7},    // C0 R3
    // Right
    {136 , 0},  // Thumb reachy
    {151 , 3},  // Thumb homing
    {167 , 4},  // Thumb tucky
    {181 , 4},  // Thumb tucky 2
    {195 , 4},  // Thumb tucky 3
    {153 , 19}, // C6 R3 (or C5)
    {153 , 32}, // C6 R2 (or C5)
    {153 , 44}, // C6 R1 (or C5)
    {153 , 57}, // C6 R0 (or C5)
    {167 , 59}, // C7 R0 (or C4)
    {167 , 46}, // C7 R1 (or C4)
    {167 , 33}, // C7 R2 (or C4)
    {167 , 20}, // C7 R3 (or C4)
    {181 , 24}, // C8 R3 (or C3)
    {181 , 37}, // C8 R2 (or C3)
    {181 , 50}, // C8 R1 (or C3)
    {181 , 63}, // C8 R0 (or C3)
    {195 , 59}, // C9 R0 (or C2)
    {195 , 46},  // C9 R1 (or C2)
    {195 , 33}, // C9 R2 (or C2)
    {195 , 20}, // C9 R3 (or C2)
    {209 , 12}, // C10 R3 (or C1)
    {209 , 25}, // C10 R2 (or C1)
    {209 , 38}, // C10 R1 (or C1)
    {209 , 51}, // C10 R0 (or C1)
    {223 , 46}, // C11 R0 (or C0)
    {223 , 33}, // C11 R1 (or C0)
    {223 , 20}, // C11 R2 (or C0)
    {223 , 7}   // C11 R3 (or C0)
}, {
    //LEFT
    1, 1,   1, 1, 1, // 1, 9,   1, 1, 1 // change to this if you want the thumb home key to be highlighted as a home row key color
    4, 4,   4, 4,
    4, 4,  12, 4,
    4, 12,  4, 4,
    4,  4, 12, 4,
    4, 12,  4, 4,
    1, 1,   1, 1,
    //RIGHT
    1, 1,  1, 1, 1, // 1, 9,   1, 1, 1 // change to this if you want the thumb home key to be highlighted as a home row key color
    4, 4,   4, 4,
    4, 4,  12, 4,
    4, 12,  4, 4,
    4,  4, 12, 4,
    4, 12,  4, 4,
    1, 1,   1, 1
} };

#endif
