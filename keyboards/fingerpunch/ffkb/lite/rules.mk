# If using svlinky, uncomment the first 2 lines, comment the "Other" MCU and BOOTLOADER and use FP_CONVERT_TO=svlinky

# svlinky
# MCU = RP2040
# BOOTLOADER = rp2040
# WS2812_DRIVER = vendor

# Other
MCU = atmega32u4
BOOTLOADER = atmel-dfu

## Moved to keyboards/fingerpunch/src/rules.mk
# ifeq ($(strip $(FP_CONVERT_TO)), svlinky_v01)
#    VIK_ENABLE = yes
#    OPT_DEFS += -DFP_CONVERT_TO_SVLINKY_V01
# endif

# ifeq ($(strip $(FP_CONVERT_TO)), svlinky_v02)
#    VIK_ENABLE = yes
#    OPT_DEFS += -DFP_CONVERT_TO_SVLINKY_V02
# endif

# $(info $(MCU))
# $(info $(BOOTLOADER))

PIN_COMPATIBLE=elite_c

include keyboards/fingerpunch/src/rules.mk