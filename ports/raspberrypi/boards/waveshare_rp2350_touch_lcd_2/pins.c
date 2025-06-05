// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2021 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include "shared-bindings/board/__init__.h"
#include "supervisor/board.h"

static const mp_rom_map_elem_t board_module_globals_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    // Pins from connector
    { MP_ROM_QSTR(MP_QSTR_GP0), MP_ROM_PTR(&pin_GPIO0) }, // Pin 10
    { MP_ROM_QSTR(MP_QSTR_GP1), MP_ROM_PTR(&pin_GPIO1) }, // Pin 8
    { MP_ROM_QSTR(MP_QSTR_GP2), MP_ROM_PTR(&pin_GPIO2) }, // Pin 7
    { MP_ROM_QSTR(MP_QSTR_GP3), MP_ROM_PTR(&pin_GPIO3) }, // Pin 9
    { MP_ROM_QSTR(MP_QSTR_GP4), MP_ROM_PTR(&pin_GPIO4) }, // Pin 11
    { MP_ROM_QSTR(MP_QSTR_GP5), MP_ROM_PTR(&pin_GPIO5) }, // Pin 19
    { MP_ROM_QSTR(MP_QSTR_GP6), MP_ROM_PTR(&pin_GPIO6) }, // Pin 20
    { MP_ROM_QSTR(MP_QSTR_GP7), MP_ROM_PTR(&pin_GPIO7) }, // Pin 28
    { MP_ROM_QSTR(MP_QSTR_GP8), MP_ROM_PTR(&pin_GPIO8) }, // Pin 26
    { MP_ROM_QSTR(MP_QSTR_GP9), MP_ROM_PTR(&pin_GPIO9) }, // Pin 27
    { MP_ROM_QSTR(MP_QSTR_GP10), MP_ROM_PTR(&pin_GPIO10) }, // Pin 12
    { MP_ROM_QSTR(MP_QSTR_GP11), MP_ROM_PTR(&pin_GPIO11) }, // Pin 21

    { MP_ROM_QSTR(MP_QSTR_GP12), MP_ROM_PTR(&pin_GPIO12) }, // Pin 6
    { MP_ROM_QSTR(MP_QSTR_TP_SDA), MP_ROM_PTR(&pin_GPIO12) },
    { MP_ROM_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_GPIO12) }, // Default I2C

    { MP_ROM_QSTR(MP_QSTR_GP13), MP_ROM_PTR(&pin_GPIO13) }, // Pin 5
    { MP_ROM_QSTR(MP_QSTR_TP_SCL), MP_ROM_PTR(&pin_GPIO13) },
    { MP_ROM_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_GPIO13) }, // Default I2C

    // LCD Specific Pins
    { MP_ROM_QSTR(MP_QSTR_GP15), MP_ROM_PTR(&pin_GPIO15) },
    { MP_ROM_QSTR(MP_QSTR_LCD_BL), MP_ROM_PTR(&pin_GPIO15) },
    { MP_ROM_QSTR(MP_QSTR_DISPLAY_BL), MP_ROM_PTR(&pin_GPIO15) },


    { MP_ROM_QSTR(MP_QSTR_GP16), MP_ROM_PTR(&pin_GPIO16) },
    { MP_ROM_QSTR(MP_QSTR_LCD_DC), MP_ROM_PTR(&pin_GPIO16) },
    { MP_ROM_QSTR(MP_QSTR_DISPLAY_DC), MP_ROM_PTR(&pin_GPIO16) },

    { MP_ROM_QSTR(MP_QSTR_GP17), MP_ROM_PTR(&pin_GPIO17) },
    { MP_ROM_QSTR(MP_QSTR_LCD_CS), MP_ROM_PTR(&pin_GPIO17) },
    { MP_ROM_QSTR(MP_QSTR_DISPLAY_CS), MP_ROM_PTR(&pin_GPIO17) },

    { MP_ROM_QSTR(MP_QSTR_GP18), MP_ROM_PTR(&pin_GPIO18) }, // Pin 23
    { MP_ROM_QSTR(MP_QSTR_LCD_CLK), MP_ROM_PTR(&pin_GPIO18) },
    { MP_ROM_QSTR(MP_QSTR_DISPLAY_SCK), MP_ROM_PTR(&pin_GPIO18) },
    { MP_ROM_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_GPIO18) }, // Default SPI

    { MP_ROM_QSTR(MP_QSTR_GP19), MP_ROM_PTR(&pin_GPIO19) }, // Pin 17
    { MP_ROM_QSTR(MP_QSTR_LCD_DIN), MP_ROM_PTR(&pin_GPIO19) },
    { MP_ROM_QSTR(MP_QSTR_DISPLAY_MOSI), MP_ROM_PTR(&pin_GPIO19) },
    { MP_ROM_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_GPIO19) }, // Default SPI

    { MP_ROM_QSTR(MP_QSTR_GP20), MP_ROM_PTR(&pin_GPIO20) }, // Pin 18
    { MP_ROM_QSTR(MP_QSTR_LCD_RST), MP_ROM_PTR(&pin_GPIO20) },
    { MP_ROM_QSTR(MP_QSTR_DISPLAY_RST), MP_ROM_PTR(&pin_GPIO20) },
    { MP_ROM_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_GPIO20) }, // Default SPI

    { MP_ROM_QSTR(MP_QSTR_GP21), MP_ROM_PTR(&pin_GPIO21) }, // Pin 24
    { MP_ROM_QSTR(MP_QSTR_GP22), MP_ROM_PTR(&pin_GPIO22) }, // Pin 25
    { MP_ROM_QSTR(MP_QSTR_GP23), MP_ROM_PTR(&pin_GPIO23) }, // Pin 22

    // ADC Pins & Touch Interrupt
    { MP_ROM_QSTR(MP_QSTR_GP28), MP_ROM_PTR(&pin_GPIO28) }, // Pin 3
    { MP_ROM_QSTR(MP_QSTR_A2), MP_ROM_PTR(&pin_GPIO28) },

    { MP_ROM_QSTR(MP_QSTR_GP29), MP_ROM_PTR(&pin_GPIO29) }, // Pin 4
    { MP_ROM_QSTR(MP_QSTR_TP_INT), MP_ROM_PTR(&pin_GPIO29) },
    { MP_ROM_QSTR(MP_QSTR_TOUCH_INT), MP_ROM_PTR(&pin_GPIO29) },
    { MP_ROM_QSTR(MP_QSTR_A3), MP_ROM_PTR(&pin_GPIO29) },

    // Default I2C0
    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },
    // Default SPI0
    { MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj) },

};
MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);
