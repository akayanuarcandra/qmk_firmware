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
#include "le_chiffre_democratique.h"

/**
#define LAYOUT_le_chiffre_democratique( \
    K00, K01, K02, K03, K04,           K05, K06, K07, K32, K33, \
    K10, K11, K12, K13, K14,   K47,    K15, K16, K17, K34, K35, \
    K20, K21, K22, K23, K24,           K25, K26, K27, K36, K37, \
                   K41, K42, K43, K44, K45, K46 \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07  }, \
    { K10, K11, K12, K13, K14, K15, K16, K17  }, \
    { K20, K21, K22, K23, K24, K25, K26, K27  }, \
    { ___, ___, K32, K33, K34, K35, K36, K37  }, \
    { ___, K41, K42, K43, K44, K45, K46, K47  } \
}

+ underglow!!
*/

#define NLD NO_LED
/*
TODO: add rgb matrix support
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { K00, K01, K02, K03, K04, K05, K06, K07  },
    { K10, K11, K12, K13, K14, K15, K16, K17  },
    { K20, K21, K22, K23, K24, K25, K26, K27  },
    { NLD, NLD, K32, K33, K34, K35, K36, K37  },
    { NLD, K41, K42, K43, K44, K45, K46, K47  }
}, {
    {7,1},       {21,1},       {36,2},       {51,1},       {65,5},       {79,10},       {93,14},
    {90,21},     {76,20},      {62,16},      {48,12},      {33,12},      {19,12},       {4,10},
    {2,20},      {16,22},      {31,23},      {46,23},      {60,27},      {74,31},       {88,35},
    {87,50},     {71,42},      {57,38},      {43,33},      {28,34},      {14,33},       {0,31},
    {25,46},     {40,48},      {56,51},      {70,56},      {84,63},
    {138,63},    {152,56},     {166,51},     {182,48},     {197,46},     {223,31},      {209,33},
    {200,34},    {179,33},     {165,38},     {151,42},     {135,50},     {134,35},      {148,31},
    {162,27},    {176,23},     {191,23},     {206,22},     {220,20},     {218,9},       {203,12},
    {189,12},    {174,12},     {160,16},     {146,20},     {132,24},     {129,14},      {143,10},
    {157,5},     {171,1},      {186,2},      {201,1},      {215,0}
}, {
    1, 4,  4,  4,  4,  4,  1,   // left half - row 1 - left to right
    1, 4,  4,  4,  4,  4,  1,   // left half - row 2 - right to left
    1, 12, 12, 12, 12, 4,  1,   // left half - row 3 - left to right
    1, 4,  4,  4,  4,  4,  1,   // left half - row 4 - right to left
    1, 1,  1,  9,  1,           // left thumbs - left to right
    1, 9,  1,  1,  1,           // right thumbs - left to right
    1, 4,  4,  4,  4,  4,  1,   // right half - row 4 - right to left
    1, 4,  12, 12, 12, 12, 1,   // right half - row 3 - left to right
    1, 4,  4,  4,  4,  4,  1,   // right half - row 2 - right to left
    1, 4,  4,  4,  4,  4,  1    // right half - row 1 - left to right
} };
#endif
*/