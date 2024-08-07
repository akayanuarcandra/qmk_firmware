#include "quantum.h"
#include "barghoot.h"
#include "display.h"
#include "qp.h"
#include "qp_lvgl.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {

    { 38, 39, 40, 41, 1,  2,  3,  4  },
    { 37, 36, 35, 34, 8,  7,  6,  5  },
    { 28, 29, 30, 31, 11, 12, 13, 14 },
    { 27, 26, 25, 24, 18, 17, 16, 15 },
    { 42, 33, 32, 23, 19, 10, 9,  0  },
    { NO_LED, NO_LED, NO_LED, 22, 21, 20, NO_LED, NO_LED }
}, {
    {78,14},  {61,14},   {43,14},   {27,14},  {10,14},  // left row 0
    {10,25},  {27,25},   {43,25},   {61,25},  {78,25},  // left row 1
    {78,37},  {61,37},   {43,37},   {27,37},  {10,37},  // left row 2
    {10,51},  {27,51},   {43,51},   {61,51},  {78,51},  // left row 3

    {94,55},  {111,55},  {129,55}, // mouse keys

    {145,51}, {162,51},  {179,51},  {196,51}, {212,51}, // right row 0
    {212,37}, {196,37},  {179,37},  {162,37}, {145,37}, // right row 1
    {145,25}, {162,25},  {179,25},  {196,25}, {212,25}, // right row 2
    {212,14}, {196,14},  {179,14},  {162,14}, {145,14}, // right row 3

    {132,1},  {161,1},   {180,1},   {216,1},                                          // underglow top right
    {216,23}, {216,35},                                                               // underglow mid right
    {218,47}, {184,47},  {160,47},  {138,55}, {87,55},  {62,47},  {34,47},  {4,47},   // underglow bottom
    {2,36},   {2,24},                                                                 // underglow mid left
    {5,5},    {38,1},    {59,1},    {94,1}                                            // underglow top left
}, {
    4, 4, 4, 4, 4,  // row 0 left
    4, 4, 4, 4, 4,  // row 1 left
    4, 4, 4, 4, 4,  // row 2 left
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // row 3
    4, 4, 4, 4, 4,  // row 0 right
    4, 4, 4, 4, 4,  // row 1 right
    4, 4, 4, 4, 4,  // row 2 right
    2, 2, 2, 2,     // underglow top right
    2, 2,           // underglow right
    2, 2, 2, 2, 2, 2, 2, 2, // underglow bottom
    2, 2,           // underglow left
    2, 2, 2, 2      // underglow top left
} };

#endif

kb_runtime_config kb_state;

static painter_device_t display;

void keyboard_post_init_keymap(void) {
  /* debug_enable=true; */
  /* debug_matrix=false; */
  /* debug_keyboard=false; */
  /* debug_mouse=true; */

  display = qp_st7789_make_spi_device(200, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 3);
  qp_set_viewport_offsets(display, 0, 34);
  qp_init(display, QP_ROTATION_270); // Initialise the display
  qp_power(display, true);
  qp_rect(display, 0, 0, 319, 171, 0, 0, 0, true);

  if (qp_lvgl_attach(display)) {     // Attach LVGL to the display
    wait_ms(50);
    display_init();
  }
  rgblight_enable();
  // backlight_enable();
}

void suspend_power_down_keymap(void) {
  #ifdef BACKLIGHT_ENABLE
    backlight_level_noeeprom(0);
  #endif // ifdef BACKLIGHT_ENABLE
}

void suspend_wakeup_init_keymap(void) {
  #ifdef BACKLIGHT_ENABLE
    backlight_level_noeeprom(1);
  #endif // ifdef BACKLIGHT_ENABLE
}

void housekeeping_task_keymap(void) {
  lvgl_event_triggers();
}

void board_init(void) {}
