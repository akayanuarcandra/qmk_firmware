# bin/fp_build.sh -k ffkb/rp/v1 -m sadekbaroudi -i -r -e "FFKB_TRACKPOINT_BUILD=yes"
ifeq ($(strip $(FFKB_TRACKPOINT_BUILD)), yes)
    PS2_MOUSE_ENABLE = yes
    PS2_ENABLE = yes
    PS2_DRIVER = vendor
    OPT_DEFS += -DFFKB_TRACKPOINT_BUILD
endif
