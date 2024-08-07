/*
 * Copyright 2024 Sadek Baroudi <sadekbaroudi@gmail.com> (@sadekbaroudi)
 */

#pragma once

#if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS)
#define HAL_USE_PWM    TRUE
#define HAL_USE_I2C    TRUE
#define HAL_USE_PAL    TRUE
#define HAL_USE_SPI    TRUE
#endif // CONVERT_TO_(any_rp2040)

#ifdef CONVERT_TO_STEMCELL
#define HAL_USE_PWM    TRUE
#define HAL_USE_GPT    TRUE
#define HAL_USE_SERIAL TRUE
#define HAL_USE_SPI    TRUE
#define SPI_USE_WAIT   TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
#endif

#include_next <halconf.h>
