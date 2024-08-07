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

/*
//                             LED series physical key order
    2, 3, 8, 9,  14, 15,                                         29, 30, 35, 36, 41, 42,
    1, 4, 7, 10, 13, 16,                                         28, 31, 34, 37, 40, 43,
    0, 5, 6, 11, 12, 17,                                         27, 32, 33, 38, 39, 44,
                        18, 19, 20,    21, 22, 23,    24, 25, 26,
         NLD,           NLD, NLD, NLD,                NLD, NLD, NLD,        NLD,
    NLD, NLD, NLD,                                                     NLD, NLD, NLD,
         NLD,                                                               NLD
*/

#ifdef RGB_MATRIX_ENABLE

#define NLD NO_LED

// 6 column and 3 center key rgb config
led_config_t g_led_config = { {
    { 2,   3,   8,   9,   14,  15,  18,  NLD },
    { 1,   4,   7,   10,  13,  16,  19,  NLD },
    { 0,   5,   6,   11,  12,  17,  20,  NLD },
    { 42,  41,  36,  35,  30,  29,  26,  NLD },
    { 43,  40,  37,  34,  31,  28,  25,  NLD },
    { 44,  39,  38,  33,  32,  27,  24,  NLD },
    { NLD, NLD, 21,  22,  23,  NLD, NLD, NLD },
    { NLD, NLD, NLD, NLD, NLD, NLD, NLD, NLD },
    { NLD, NLD, NLD, NLD, NLD, NLD, NLD, NLD }
}, {
    {0,36},   {1,22},   {4,9},     // col 1
    {19,7},   {16,20},  {14,33},   // col 2
    {29,27},  {31,13},  {34,0},    // col 3
    {48,0},   {45,12},  {43,26},   // col 4
    {56,31},  {58,18},  {60,5},    // col 5
    {73,9},   {71,22},  {69,36},   // col 6
    {53,48},  {67,52},  {81,58},   // left thumbs
    {97,63},  {111,63}, {125,63},  // center keys
    {141,58}, {155,52}, {169,48},  // right thumbs
    {153,36}, {151,22}, {149,9},   // col 7
    {162,5},  {164,18}, {166,31},  // col 8
    {179,26}, {177,12}, {175,0},   // col 9
    {189,0},  {191,13}, {194,27},  // col 10
    {208,33}, {206,20}, {204,7},   // col 11
    {218,9},  {221,22}, {223,36}   // col 12
}, {
    1, 1, 1,   // col 1
    4, 12, 4,  // col 2
    4, 12, 4,  // col 3
    4, 12, 4,  // col 4
    4, 12, 4,  // col 5
    4, 4, 4,   // col 6
    1, 1, 1,   // left thumbs
    9, 9, 9,   // center 3 keys
    1, 1, 1,   // right thumbs
    4, 4, 4,   // col 7
    4, 12, 4,  // col 8
    4, 12, 4,  // col 9
    4, 12, 4,  // col 10
    4, 12, 4,  // col 11
    1, 1, 1    // col 12
} };

#endif