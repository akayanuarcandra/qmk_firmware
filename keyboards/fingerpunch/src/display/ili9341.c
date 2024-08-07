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
#include "keyboards/fingerpunch/src/display/ili9341.h"

#ifdef QUANTUM_PAINTER_ENABLE
#include "qp.h"

painter_device_t fp_qp_disp_device;

void fp_qp_init_display(void) {
    fp_qp_disp_device = qp_ili9341_make_spi_device(FP_QP_DISPLAY_WIDTH, FP_QP_DISPLAY_HEIGHT, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 0);
}
#endif
