# pinkiesout

An ergonomic 65% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

To build the firmware for this keyboard (after setting up your build environment):
```
    make fingerpunch/pinkiesout/v2_ext:default RGB_MATRIX_ENABLE=yes AUDIO_ENABLE=yes CIRQUE_ENABLE=yes ENCODER_ENABLE=yes CONVERT_TO=stemcell
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

Options are:
```
    CIRQUE_ENABLE=yes
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=yes
    ENCODER_ENABLE=yes
    AUDIO_ENABLE=yes
    HAPTIC_ENABLE=yes
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
