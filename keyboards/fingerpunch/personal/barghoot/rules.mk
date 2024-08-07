# This file intentionally left blank
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = yes

SRC += keyboards/fingerpunch/src/fp_matrix_74hc595_spi.c
QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
OPT_DEFS += -DFP_TRACKBALL_ENABLE

HAPTIC_DRIVER += drv2605l

QUANTUM_PAINTER_DRIVERS += st7789_spi

#PER KEY RGB
RGB_MATRIX_DRIVER = ws2812  # RGB matrix driver support
WS2812_DRIVER = vendor

QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

ifeq ($(strip $(MCU_HELIOS)), yes)
   OPT_DEFS += -DMCU_HELIOS
endif

SRC += assets/rb_24.c \
       assets/rb_18.c \
       assets/window.c \
			 assets/tools.c \
			 assets/hash.c \
			 assets/apple.c \
			 assets/cmd.c \
			 assets/shift.c \
			 assets/caret.c \
			 assets/alt.c

SRC += display.c

include keyboards/fingerpunch/src/rules.mk
