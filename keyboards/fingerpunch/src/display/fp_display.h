/* Copyright 2023 Sadek Baroudi
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

#include "keyboards/fingerpunch/src/fp.h"

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

// Choose one of QP_ROTATION_0, QP_ROTATION_90, QP_ROTATION_180, QP_ROTATION_270
#ifndef FP_QP_ROTATION
    #define FP_QP_ROTATION QP_ROTATION_0
#endif

#define FP_QP_TOP_LEFT 0
#define FP_QP_TOP_CENTER 1
#define FP_QP_TOP_RIGHT 2
#define FP_QP_MIDDLE_LEFT 3
#define FP_QP_CENTER 4
#define FP_QP_MIDDLE_RIGHT 5
#define FP_QP_BOTTOM_LEFT 6
#define FP_QP_BOTTOM_CENTER 7
#define FP_QP_BOTTOM_RIGHT 8

void fp_post_init_qp(void);
void fp_qp_init_display(void);
void fp_qp_load_initial_screen(void);
