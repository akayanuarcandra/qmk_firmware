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
#include "vulpes_minora.h"

#ifdef RGB_MATRIX_ENABLE

#define NLD NO_LED

// Layout
// 2          1           0           6           7           8
//  ┌────────────────────┐             ┌────────────────────┐
//  │ XX  XX  XX  XX  XX │             │ XX  XX  XX  XX  XX │
//  │────────────────────┤             ├────────────────────│
//  │ XX  XX  XX  XX  XX │             │ XX  XX  XX  XX  XX │
//  ├────────────────────┤             ├────────────────────┤
//  │ XX  XX  XX  XX  XX │             │ XX  XX  XX  XX  XX │
//  └─────────────┬──────┴─────┐ ┌─────┴──────┬─────────────┘
// 3              │ XX  XX  XX │ │ XX  XX  XX │              9
//                └────────────┘ └────────────┘
//            4           5           11         10
//

led_config_t g_led_config = { {
//COL   00     01      02       03      04      ROW 
    {    2,     2,      1,       1,      0  },//00
    {    2,     2,      1,       1,      0  },//01
    {    3,     3,      4,       4,      5  },//02
    {  NLD,   NLD,      4,       5,      5  },//03
    {    8,     8,      7,       7,      6  },//04
    {    8,     8,      7,       7,      6  },//05
    {    9,     9,     10,      10,     11  },//06
    {  NLD,   NLD,     10,      11,     11  } //07
}, {
    // { 112, 32 } is the center
    {90	, 0},  // 0
    {45	, 0},  // 1
    {0	, 0},  // 2
    {0	, 64}, // 3
    {45	, 64}, // 4
    {90 , 64}, // 5
    {134, 0},  // 6
    {179, 0},  // 7
    {224, 0},  // 8
    {224, 64}, // 9
    {179, 64}, // 10
    {134, 0}   // 11
}, {       
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
} };
#endif
