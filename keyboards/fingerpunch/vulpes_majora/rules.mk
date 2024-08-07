# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

# Either do RGBLIGHT_ENABLE or RGB_MATRIX_ENABLE and RGB_MATRIX_DRIVER
RGBLIGHT_ENABLE ?= no
RGB_MATRIX_ENABLE ?= no
RGB_MATRIX_DRIVER = ws2812

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
OLED_ENABLE = no            # this can be yes or no depending on if you have an OLED
EXTRAFLAGS     += -flto     # needed for LVGL, can disable if you want, if not using display

VIK_ENABLE = yes

##### Disabled EXTRAFLAGS line above, as it was causing the error below when compiling with rgb matrix enabled
# Linking: .build/fingerpunch_vulpes_majora_v1_sadekbaroudi.elf                                       [ERRORS]
#  |
#  | quantum/rgb_matrix/rgb_matrix_drivers.c: In function 'flush':
#  | platforms/chibios/drivers/vendor/RP/RP2040/ws2812_vendor.c:277:26: error: iteration 4 invokes undefined behavior [-Werror=aggressive-loop-optimizations]
#  |   277 |         WS2812_BUFFER[i] = rgbw8888_to_u32(ledarray[i].r, ledarray[i].g, ledarray[i].b, 0);
#  |       |                          ^
#  | platforms/chibios/drivers/vendor/RP/RP2040/ws2812_vendor.c:273:5: note: within this loop
#  |   273 |     for (int i = 0; i < leds; i++) {
#  |       |     ^
#  | lto1: all warnings being treated as errors
#  | lto-wrapper: fatal error: arm-none-eabi-gcc returned 1 exit status
#  | compilation terminated.
#  | /usr/lib/gcc/arm-none-eabi/9.2.1/../../../arm-none-eabi/bin/ld: error: lto-wrapper failed
#  | collect2: error: ld returned 1 exit status

SRC += keyboards/fingerpunch/src/fp_matrix_74hc595_spi.c
QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite

# default is 6 column, specify if building a 6 col with center rgb on vik
ifeq ($(strip $(FP_VM_RGB_6COL_WITH_CENTER)), yes)
   OPT_DEFS += -DFP_VM_RGB_6COL_WITH_CENTER
endif

# default is 6 column, specify if building a 5 col
ifeq ($(strip $(FP_VM_RGB_5COL)), yes)
   OPT_DEFS += -DFP_VM_RGB_5COL
endif

# default is 6 column, specify if building a 5 col with center rgb on vik
ifeq ($(strip $(FP_VM_RGB_5COL_WITH_CENTER)), yes)
   OPT_DEFS += -DFP_VM_RGB_5COL_WITH_CENTER
endif

# default is 6 column, specify if building with center vik leds only
ifeq ($(strip $(FP_VM_RGB_CENTER_ONLY)), yes)
   OPT_DEFS += -DFP_VM_RGB_CENTER_ONLY
endif


ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   RGB_MATRIX_CUSTOM_KB = yes
   OPT_DEFS += -DRGB_MATRIX_CUSTOM_KB
endif

include keyboards/fingerpunch/src/rules.mk
