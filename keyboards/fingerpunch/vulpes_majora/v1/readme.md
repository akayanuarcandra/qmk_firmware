# vulpes majora 

An ergonomic 40% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

Vulpes Majora

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/vulpes_majora/v1:default RGBLIGHT_ENABLE=yes
```

Options are:
```
CIRQUE_ENABLE=yes
FP_TRACKBALL_ENABLE=yes
RGBLIGHT_ENABLE=yes
RGB_MATRIX_ENABLE=yes
ENCODER_ENABLE=yes
AUDIO_ENABLE=yes
HAPTIC_ENABLE=yes
FP_VM_RGB_6COL_WITH_CENTER=yes
FP_VM_RGB_5COL=yes
FP_VM_RGB_5COL_WITH_CENTER=yes
FP_VM_RGB_CENTER_ONLY=yes
```

## Parameters

* CIRQUE_ENABLE - enable if you have a cirque trackpad installed
* FP_TRACKBALL_ENABLE - enable if you have a trackball installed
* RGBLIGHT_ENABLE - enable if you are using leds and want to use qmk rgblight, required if you are using the trackball leds in the center, do not use rgb matrix if using this
* RGB_MATRIX_ENABLE - enable if you are using leds and want to use qmk rgb matrix, don't use if you have the trackball leds in the center, as they won't light up
* ENCODER_ENABLE - enable if you are using the vik center scroll ring (PER56)
* AUDIO_ENABLE - installed on the pcb by default. If you don't like the audio feature, don't enable this
* HAPTIC_ENABLE - enable if you installed the pimoroni haptic feedback module
* FP_VM_RGB_6COL_WITH_CENTER - enable if you have a 6 col build with rgb and the 4 leds in the center
* FP_VM_RGB_5COL - enable if you have a 5 col build with no leds in the center
* FP_VM_RGB_5COL_WITH_CENTER - enable if you have a 5 col build with leds in the center
* FP_VM_RGB_CENTER_ONLY - enable if you have no per key leds, but installed the 4 in the center

## Build Guide

See:
https://github.com/sadekbaroudi/fingerpunch/blob/master/keyboards/vulpes-majora/