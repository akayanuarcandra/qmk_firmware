# pinkiesout

An ergonomic 65% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

To build the firmware for this keyboard (after setting up your build environment):
```
make fingerpunch/pinkiesout/v3_1:default RGB_MATRIX_ENABLE=yes AUDIO_ENABLE=yes
```

Look at the file `fp_build.json` for all the possible build parameters, or use the `fp_build.sh` script to interactively build (requires bash)
```
bin/fp_build.sh -k pinkiesout/v3_1 -m default -i -r
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
