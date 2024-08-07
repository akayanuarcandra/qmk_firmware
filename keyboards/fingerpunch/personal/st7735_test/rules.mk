# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

PIN_COMPATIBLE=elite_c

## During compile, you should be doing a CONVERT_TO=stemcell to test. You can use other controllers, but you may need to update mcuconf and halconf

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = yes       # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

RGBLIGHT_ENABLE = no
RGBLIGHT_DRIVER = ws2812
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = ws2812

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
OLED_ENABLE = no
# EXTRAFLAGS     += -flto     # macros disabled, if you need the extra space
MOUSEKEY_ENABLE = no

# For LCD backlight toggling
BACKLIGHT_ENABLE = yes
BACKLIGHT_DRIVER = software

# Cut slope
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7735_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
SRC += fonts/urbanist24.qff.c fonts/urbanist36.qff.c 
SRC += fonts/roboto12.qff.c fonts/roboto18.qff.c fonts/roboto14.qff.c
SRC += display.c
WPM_ENABLE 					= yes

# Stront
# QUANTUM_PAINTER_ENABLE = yes
# QUANTUM_PAINTER_LVGL_INTEGRATION = yes
# QUANTUM_PAINTER_DRIVERS += st7735_spi
# SRC += lvgl_helpers.c \
# 	   display.c