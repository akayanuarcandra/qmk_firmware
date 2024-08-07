# This file intentionally left blank
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = no            # USB Nkey Rollover

HAPTIC_DRIVER += drv2605l

QUANTUM_PAINTER_DRIVERS += st7789_spi

# Either do RGBLIGHT_ENABLE or RGB_MATRIX_ENABLE and RGB_MATRIX_DRIVER
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = ws2812  # RGB matrix driver support
WS2812_DRIVER = vendor

# SADEK: DISPLAY: COMMENT OUT FOR NOW
# QUANTUM_PAINTER_DRIVERS += st7789_spi
# QUANTUM_PAINTER_LVGL_INTEGRATION = yes

# SRC += assets/rb_24.c \
#        assets/rb_18.c \
#        assets/window.c \
# 			 assets/tools.c \
# 			 assets/hash.c \
# 			 assets/apple.c \
# 			 assets/cmd.c \
# 			 assets/shift.c \
# 			 assets/caret.c \
# 			 assets/alt.c

# SRC += display.c

SRC += keyboards/fingerpunch/src/fp_matrix_74hc595_spi.c
QUANTUM_LIB_SRC += spi_master.c
CUSTOM_MATRIX = lite

HAPTIC_ENABLE ?= no
HAPTIC_DRIVER = drv2605l

ifeq ($(strip $(FP_TRACKBALL_ENABLE)), yes)
   MOUSEKEY_ENABLE := yes  # not required, but enabling for mouse button keys
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := pmw3360
   QUANTUM_LIB_SRC += spi_master.c
   OPT_DEFS += -DFP_TRACKBALL_ENABLE
endif

include keyboards/fingerpunch/src/rules.mk
