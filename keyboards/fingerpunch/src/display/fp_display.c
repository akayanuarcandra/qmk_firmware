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

#include "keyboards/fingerpunch/src/display/fp_display.h"

#ifdef QUANTUM_PAINTER_ENABLE
#include "qp.h"


#ifdef VIK_ILI9341
#include "keyboards/fingerpunch/src/display/ili9341.h"
#endif

#ifdef VIK_WEACT_ST7735
#include "keyboards/fingerpunch/src/display/st7735.h"
#endif

#ifdef VIK_GC9A01
#include "keyboards/fingerpunch/src/display/gc9a01.h"
#endif

#ifdef VIK_WAVESHARE_22224
#include "keyboards/fingerpunch/src/display/waveshare_22224.h"
#endif

extern painter_device_t fp_qp_disp_device;

void fp_post_init_qp(void) {
    // Call the display specific initialization from the appropriate display file
    fp_qp_init_display();

    // Init the device rotation
    qp_init(fp_qp_disp_device, FP_QP_ROTATION);

    // Draw a rectangle of the size of the display
    qp_rect(fp_qp_disp_device, 0, 0, FP_QP_DISPLAY_WIDTH, FP_QP_DISPLAY_HEIGHT, 0, 255, 255, true);

    // Attach and load the initial boot up screen
    if (qp_lvgl_attach(fp_qp_disp_device)) {
        fp_qp_load_initial_screen();
    }
}

/**
 * Display text on the screen in a specified location.
 *
 * @param text The text to display
 * @param location The location to display the text, must use one of the FP_QP_* constants
 */
void fp_qp_display_text(char* text, int location) {
    // Create a label object
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, text);

    // Set the location of the label based on the location variable
    // Note that if you have a round display, top left, top right, bottom left, and bottom right are not displayable
    switch (location) {
        case FP_QP_TOP_LEFT:
            lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
            break;
        case FP_QP_TOP_CENTER:
            lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);
            break;
        case FP_QP_TOP_RIGHT:
            lv_obj_align(label, LV_ALIGN_TOP_RIGHT, 0, 0);
            break;
        case FP_QP_MIDDLE_LEFT:
            lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
            break;
        case FP_QP_CENTER:
            lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
            break;
        case FP_QP_MIDDLE_RIGHT:
            lv_obj_align(label, LV_ALIGN_RIGHT_MID, 0, 0);
            break;
        case FP_QP_BOTTOM_LEFT:
            lv_obj_align(label, LV_ALIGN_BOTTOM_LEFT, 0, 0);
            break;
        case FP_QP_BOTTOM_CENTER:
            lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 0);
            break;
        case FP_QP_BOTTOM_RIGHT:
            lv_obj_align(label, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
            break;
        default:
            break;
    }
}

// Used for test code, found in fp_qp_load_initial_screen
// static void fp_qp_set_arc_angle(void* obj, int32_t v) {
//     lv_arc_set_value(obj, v);
// }

/**
 * Create an arc which acts as a loader.
 */
void fp_qp_load_initial_screen(void) {
    // fp_qp_display_text(PRODUCT, FP_QP_TOP_LEFT);
    // fp_qp_display_text(PRODUCT, FP_QP_TOP_CENTER);
    // fp_qp_display_text(PRODUCT, FP_QP_TOP_RIGHT);
    // fp_qp_display_text(PRODUCT, FP_QP_MIDDLE_LEFT);
    fp_qp_display_text(PRODUCT, FP_QP_CENTER);
    // fp_qp_display_text(PRODUCT, FP_QP_MIDDLE_RIGHT);
    // fp_qp_display_text(PRODUCT, FP_QP_BOTTOM_LEFT);
    // fp_qp_display_text(PRODUCT, FP_QP_BOTTOM_CENTER);
    // fp_qp_display_text(PRODUCT, FP_QP_BOTTOM_RIGHT);

    // Original test code with an arc circling indefinitely
    // /*Create an Arc*/
    // lv_obj_t* arc = lv_arc_create(lv_scr_act());
    // lv_arc_set_rotation(arc, 270);
    // lv_arc_set_bg_angles(arc, 0, 360);
    // lv_obj_remove_style(arc, NULL, LV_PART_KNOB);  /*Be sure the knob is not displayed*/
    // lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    // lv_obj_center(arc);

    // static lv_anim_t a;
    // lv_anim_init(&a);
    // lv_anim_set_var(&a, arc);
    // lv_anim_set_exec_cb(&a, fp_qp_set_arc_angle);
    // lv_anim_set_time(&a, 1000);
    // lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    // lv_anim_set_repeat_delay(&a, 500);
    // lv_anim_set_values(&a, 0, 100);
    // lv_anim_start(&a);
}

#endif
