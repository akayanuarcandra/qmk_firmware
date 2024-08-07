# testamatta

An ergonomic 50% keyboard

* Keyboard Maintainer: [hide-key](https://github.com/hide-key)

# Descripiton

This firmware comes originally from:  
https://github.com/hide-key/testamatta/tree/main/keyboard/011/  

I have modified it to include my personal fingerpunch code and VIK support for the xivik controller:  
https://fingerpunch.xyz/product/xivik  

To be clear, this firmware **only** works with the xivik controller

# Firmware

To build the firmware for this keyboard (after setting up your build environment):
```
    make fingerpunch/personal/testamatta:default
```

Options are:
```
    // for the options below, select only one, or none, used for testing [VIK modules](https://github.com/sadekbaroudi/vik#known-list-of-vik-certifications)
    VIK_PER56_CIRQUE_LEDS=yes
    VIK_PER56_PMW3360_LEDS=yes
    VIK_PMW3360=yes
    VIK_WEACT_ST7735=yes
    VIK_GC9A01=yes
    VIK_WAVESHARE_22224=yes
    VIK_HAPTIC=yes
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).