# bin/fp_build.sh -k ximi -m sadekbaroudi -i -r -e "XIMI_TRACKPOINT_BUILD=yes"
ifeq ($(strip $(XIMI_TRACKPOINT_BUILD)), yes)
    PS2_MOUSE_ENABLE = yes
    PS2_ENABLE = yes
    PS2_DRIVER = vendor
    OPT_DEFS += -DXIMI_TRACKPOINT_BUILD
endif
