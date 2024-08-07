// bin/fp_build.sh -k ffkb/lite/v1 -m sadekbaroudi -i -r -e "FP_CONVERT_TO=svlinky_v01 VIK_PMW3360=yes"
#if defined(VIK_TRACKBALL_ENABLE) && defined(FP_CONVERT_TO_SVLINKY_V01)
#define POINTING_DEVICE_INVERT_Y
#endif

// bin/fp_build.sh -k ffkb/lite/v1 -m sadekbaroudi -i -r -e "FP_CONVERT_TO=svlinky_v01 VIK_PER56_CIRQUE_LEDS=yes"
#if defined(VIK_PER56_CIRQUE_LEDS) && defined(FP_CONVERT_TO_SVLINKY_V01)
#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_ROTATION_90
#endif

// bin/fp_build.sh -k ffkb/lite/v1 -m sadekbaroudi -i -r -e "FP_CONVERT_TO=svlinky_v01 VIK_EC11_EVQWGD001=yes VIK_RGB_ONLY=yes RGBLIGHT_ENABLE=yes"

// 15mm thumb trackball build
// bin/fp_build.sh -k ffkb/lite/v1 -m sadekbaroudi -i -r -e "FP_CONVERT_TO=svlinky_v02 VIK_PMW3360=yes"
#if defined(VIK_TRACKBALL_ENABLE) && defined(FP_CONVERT_TO_SVLINKY_V02)
#define POINTING_DEVICE_INVERT_X
#endif

// ffkb lite solenoid edition
// bin/fp_build.sh -k ffkb/lite/v1 -m sadekbaroudi -i -r -e "FFKB_LITE_SOLENOID=yes"
#if defined(FFKB_LITE_SOLENOID)
#define SOLENOID_PIN F0
#define RP2040_FLASH_GENERIC_03H
#endif