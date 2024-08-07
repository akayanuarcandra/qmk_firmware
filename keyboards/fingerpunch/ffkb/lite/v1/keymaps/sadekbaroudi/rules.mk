# bin/fp_build.sh -k ffkb/lite/v1 -m sadekbaroudi -i -r -e "FFKB_LITE_SOLENOID=yes"
ifeq ($(strip $(FFKB_LITE_SOLENOID)), yes)
    HAPTIC_ENABLE = yes
    HAPTIC_DRIVER = solenoid
    OPT_DEFS += -DFFKB_LITE_SOLENOID
	CONVERT_TO=rp2040_ce
endif
