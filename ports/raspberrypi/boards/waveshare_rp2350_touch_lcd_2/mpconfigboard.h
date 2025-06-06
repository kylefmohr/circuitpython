// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2021 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#pragma once

#define MICROPY_HW_BOARD_NAME "Waveshare RP2350-Touch-LCD-2"
#define MICROPY_HW_MCU_NAME "rp2350"

// Display Pins (SPI0)
#define CIRCUITPY_DISPLAY_BL (&pin_GPIO15)
#define CIRCUITPY_DISPLAY_DC (&pin_GPIO16)
#define CIRCUITPY_DISPLAY_CS (&pin_GPIO17)
#define CIRCUITPY_DISPLAY_SCK (&pin_GPIO18) // SPI0 SCK
#define CIRCUITPY_DISPLAY_MOSI (&pin_GPIO19) // SPI0 TX
#define CIRCUITPY_DISPLAY_RST (&pin_GPIO20)

#define CIRCUITPY_DISPLAY_WIDTH 320
#define CIRCUITPY_DISPLAY_HEIGHT 240
#define CIRCUITPY_DISPLAY_ROTATION 0 // Default rotation

// Touch Pins (I2C0)
#define CIRCUITPY_BOARD_HAS_TOUCH 1
#define CIRCUITPY_TOUCH_INT (&pin_GPIO29)
#define CIRCUITPY_TOUCH_SDA (&pin_GPIO12) // I2C0 SDA
#define CIRCUITPY_TOUCH_SCL (&pin_GPIO13) // I2C0 SCL

#define DEFAULT_I2C_BUS_SCL (&pin_GPIO13)
#define DEFAULT_I2C_BUS_SDA (&pin_GPIO12)

#define DEFAULT_SPI_BUS_SCK (&pin_GPIO18)
#define DEFAULT_SPI_BUS_MOSI (&pin_GPIO19)
#define DEFAULT_SPI_BUS_MISO (&pin_GPIO20) // Using GPIO20 as SPI0 RX
