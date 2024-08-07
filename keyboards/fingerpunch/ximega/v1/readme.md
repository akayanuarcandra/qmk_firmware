# ximega

* Keyboard Maintainer: sadekbaroudi
* Hardware Supported: ximega PCB

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/ximega:default RGB_MATRIX_ENABLE=yes FP_CIRQUE_BOTH=yes HAPTIC_ENABLE=yes
```

Options are:
```
    RGB_MATRIX_ENABLE=yes
    RGBLIGHT_ENABLE=yes
    AUDIO_ENABLE=yes
    // for the options below, select only one, or none
    FP_TRACKBALL_BOTH=yes
    FP_CIRQUE_BOTH=yes
    FP_TRACKBALL_LEFT_ONLY=yes
    FP_TRACKBALL_RIGHT_ONLY=yes
    FP_CIRQUE_LEFT_ONLY=yes
    FP_CIRQUE_RIGHT_ONLY=yes
    FP_TRACKBALL_LEFT_CIRQUE_RIGHT=yes
    FP_CIRQUE_LEFT_TRACKBALL_RIGHT=yes
    FP_SPLIT_LEFT=yes     # only applicable if doing a mixed pointing device build (e.g. trackpad left, trackball right)
    FP_SPLIT_RIGHT=yes     # only applicable if doing a mixed pointing device build (e.g. trackpad left, trackball right)
```

**IMPORTANT NOTES:**
* Pick one (or none) of FP_TRACKBALL_* or FP_CIRQUE_* only.
* If you are building a ximega with a trackpad on one side, and a trackball on the other, you will need to build two firmware files. Once with FP_SPLIT_LEFT=yes, and once with FP_SPLIT_RIGHT=yes - then you'll need to unplug the trrs and flash the left firmware on the left half, and the right firmware on the right half

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Build Guide

See the ximi build guide, which shares the same process for overlapping features:
https://github.com/sadekbaroudi/fingerpunch/blob/master/ximi/
