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
#include "kucheza.h"

#define NLD NO_LED

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 6,   5,   4,   3,   2,   1,   0,   NLD },
    { 7,   8,   9,   10,  11,  12,  13,  NLD },
    { 20,  19,  18,  17,  16,  15,  14,  NLD },
    { 21,  22,  23,  24,  25,  26,  NLD, NLD },
    { 32,  31,  30,  29,  28,  27,  NLD, NLD },
    { NLD, NLD, NLD, NLD, NLD, NLD, NLD, NLD }
}, {
    // This section is complete, see google doc
    {223, 11}, {187, 4},  {152, 3},  {116, 0},  {80, 3},   {45, 4}, {9, 4}, 
    {9, 18},   {45, 18},  {80, 16},  {116, 12}, {152, 16}, {187, 18}, {223, 24}, 
    {223, 38}, {187, 31}, {152, 29}, {116, 26}, {80, 29},  {45, 31}, {9, 31}, 
    {9, 44},   {4, 44},   {80, 43},  {116, 39}, {152, 43}, {187, 44}, 
    {212, 59}, {173, 58}, {137, 58}, {80, 58},  {45, 58},  {9, 58},
    {0, 68},   {10, 68},  {22, 68},  {33, 68},  {45, 68},  {56, 68}, {68, 68}, {79, 68}, {91, 68} // accent lights
}, {
    1, 4,  4,  4,  4,  4,  1,          // row 1 - right to left
    1, 4,  4,  4,  4,  4,  1,          // row 2 - left to right
    1, 4,  12, 12, 12, 12, 1,          // row 3 - right to left
    1, 4,  4,  4,  4,  4,              // row 4 - left to right
    1, 1,  1,  1,  1,  1,              // row 5 - right to left
    1, 1,  1,  1,  1,  1,  1,  1,  1   // accent lights - left to right
} };
#endif
