# MCU name
MCU = RP2040
BOOTLOADER = rp2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no           # USB Nkey Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no           # MIDI support
UNICODE_ENABLE = no        # Unicode
BLUETOOTH_ENABLE = no      # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no          # Audio output on port C6
SPLIT_KEYBOARD = no       # Split common
LTO_ENABLE = yes

ENCODER_ENABLE = no       # Enables the use of one or more encoders
SPLIT_KEYBOARD = no

FP_WEACT_ST7735 ?= no

ifeq ($(strip $(FP_WEACT_ST7735)), yes)
   # For LCD backlight toggling
   BACKLIGHT_ENABLE = yes
   BACKLIGHT_DRIVER = software

   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += st7735_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += fonts/urbanist24.qff.c fonts/urbanist36.qff.c 
   SRC += fonts/roboto12.qff.c fonts/roboto18.qff.c fonts/roboto14.qff.c
   SRC += display.c
   WPM_ENABLE = yes
   OPT_DEFS += -DFP_WEACT_ST7735
endif

include keyboards/fingerpunch/src/rules.mk
