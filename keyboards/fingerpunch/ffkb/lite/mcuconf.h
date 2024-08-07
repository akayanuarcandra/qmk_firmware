#pragma once

#include_next "mcuconf.h"

#if defined(FP_CONVERT_TO_SVLINKY_V01) || defined(FP_CONVERT_TO_SVLINKY_V02)
#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE
#endif