# MCU name
MCU = RP2040
BOOTLOADER = rp2040

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
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no      # not supported yet, but will add
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
EXTRAFLAGS     += -flto     # macros enable or disable
MOUSEKEY_ENABLE = yes

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor


#HAPTIC FEEDBACK
HAPTIC_ENABLE ?= no
HAPTIC_DRIVER = drv2605l

# Audio doesn't work with RP2040 yet :(
# Pending https://github.com/qmk/qmk_firmware/pull/17723 and https://github.com/qmk/qmk_firmware/pull/17706
AUDIO_ENABLE ?= no

CIRQUE_ENABLE = no           # Don't set this one, gets set automatically by FP_CIRQUE_*
PMW3360_ENABLE = no          # Don't set this one, gets set automatically by FP_TRACKBALL_*

# Choose only one (or none) of the 8 options below
FP_TRACKBALL_BOTH ?= no
FP_CIRQUE_BOTH ?= no
FP_TRACKBALL_LEFT_ONLY ?= no
FP_TRACKBALL_RIGHT_ONLY ?= no
FP_CIRQUE_LEFT_ONLY ?= no
FP_CIRQUE_RIGHT_ONLY ?= no
FP_TRACKBALL_LEFT_CIRQUE_RIGHT ?= no
FP_CIRQUE_LEFT_TRACKBALL_RIGHT ?= no

# When qmk supports multiple types of pointing devices, can remove this line below
# Also, can remove the question from fp_build.json
FP_SPLIT_LEFT ?= no
FP_SPLIT_RIGHT ?= no

ifeq ($(strip $(FP_TRACKBALL_BOTH)), yes)
   PMW3360_ENABLE := yes
   OPT_DEFS += -DFP_TRACKBALL_BOTH
endif

ifeq ($(strip $(FP_TRACKBALL_LEFT_ONLY)), yes)
   PMW3360_ENABLE := yes
   OPT_DEFS += -DFP_TRACKBALL_LEFT_ONLY
endif

ifeq ($(strip $(FP_TRACKBALL_RIGHT_ONLY)), yes)
   PMW3360_ENABLE := yes
   OPT_DEFS += -DFP_TRACKBALL_RIGHT_ONLY
endif

ifeq ($(strip $(FP_TRACKBALL_LEFT_CIRQUE_RIGHT)), yes)
   PMW3360_ENABLE := yes
   OPT_DEFS += -DFP_TRACKBALL_LEFT_CIRQUE_RIGHT
endif

ifeq ($(strip $(FP_CIRQUE_LEFT_TRACKBALL_RIGHT)), yes)
   PMW3360_ENABLE := yes
   OPT_DEFS += -DFP_CIRQUE_LEFT_TRACKBALL_RIGHT
endif

ifeq ($(strip $(FP_CIRQUE_BOTH)), yes)
   CIRQUE_ENABLE := yes
   OPT_DEFS += -DFP_CIRQUE_BOTH
endif

ifeq ($(strip $(FP_CIRQUE_LEFT_ONLY)), yes)
   CIRQUE_ENABLE := yes
   OPT_DEFS += -DFP_CIRQUE_LEFT_ONLY
endif

ifeq ($(strip $(FP_CIRQUE_RIGHT_ONLY)), yes)
   CIRQUE_ENABLE := yes
   OPT_DEFS += -DFP_CIRQUE_RIGHT_ONLY
endif

ifeq ($(strip $(FP_TRACKBALL_LEFT_CIRQUE_RIGHT)), yes)
   # When qmk supports multiple types of pointing devices, change to something like the commented code below
   # PMW3360_ENABLE = yes
   # CIRQUE_ENABLE = yes
   ifeq ($(strip $(FP_SPLIT_LEFT)), yes)
      PMW3360_ENABLE = yes
   endif
   ifeq ($(strip $(FP_SPLIT_RIGHT)), yes)
      CIRQUE_ENABLE = yes
   endif
   OPT_DEFS += -DFP_TRACKBALL_LEFT_CIRQUE_RIGHT
endif

ifeq ($(strip $(FP_CIRQUE_LEFT_TRACKBALL_RIGHT)), yes)
   # When qmk supports multiple types of pointing devices, change to something like the commented code below
   # PMW3360_ENABLE = yes
   # CIRQUE_ENABLE = yes
   ifeq ($(strip $(FP_SPLIT_LEFT)), yes)
      CIRQUE_ENABLE = yes
   endif
   ifeq ($(strip $(FP_SPLIT_RIGHT)), yes)
      PMW3360_ENABLE = yes
   endif
   OPT_DEFS += -DFP_CIRQUE_LEFT_TRACKBALL_RIGHT
endif

# When qmk supports multiple types of pointing devices, can remove the FP_SPLIT_* blocks below
ifeq ($(strip $(FP_SPLIT_LEFT)), yes)
   OPT_DEFS += -DFP_SPLIT_LEFT
endif

ifeq ($(strip $(FP_SPLIT_RIGHT)), yes)
   OPT_DEFS += -DFP_SPLIT_RIGHT
endif

ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := cirque_pinnacle_i2c
   OPT_DEFS += -DCIRQUE_ENABLE
endif

ifeq ($(strip $(PMW3360_ENABLE)), yes)
   AUDIO_ENABLE := no
   RGBLIGHT_ENABLE := no
   RGB_MATRIX_ENABLE := no
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := pmw3360
   QUANTUM_LIB_SRC += spi_master.c
   OPT_DEFS += -DFP_TRACKBALL_ENABLE
endif

include keyboards/fingerpunch/src/rules.mk

SRC += matrix_74hc595_spi.c
QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite
