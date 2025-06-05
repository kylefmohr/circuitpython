// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2021 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include "supervisor/board.h"
#include "mpconfigboard.h"
#include "shared-bindings/displayio/__init__.h"
#include "shared-module/displayio/FourWire.h"
#include "shared-bindings/busio/SPI.h"
#include "shared-bindings/microcontroller/Pin.h"

// Generic ST7789 init sequence
uint8_t display_init_sequence[] = {
    0x01, 0x80, 0x96, // Software reset with 150ms delay
    0x11, 0x80, 0xff, // Sleep out with 255ms delay
    0x3A, 0x01, 0x55, // COLMOD: Interface Pixel Format, 16bits/pixel
    0x36, 0x01, 0x00, // MADCTL: Memory Data Access Control, Page/Column Address Order, MX, MY, MV, ML, BGR, MH
                      // Row Address Order (MY) = 0 (Top to Bottom)
                      // Column Address Order (MX) = 0 (Left to Right)
                      // Page/Column Order (MV) = 0 (Normal)
                      // Line Address Order (ML) = 0 (Top to Bottom)
                      // Color Order (BGR) = 0 (RGB)
                      // Display Data Latch Order (MH) = 0 (Left to Right)
    0x21, 0x00,       // INVON: Display Inversion On (typically off for ST7789, but some modules need it)
    // 0x20, 0x00,    // INVOFF: Display Inversion Off
    0x13, 0x00,       // NORON: Normal Display Mode On
    0x29, 0x80, 0xff, // DISPON: Display On with 255ms delay
};

// This is for the display bus
displayio_fourwire_obj_t board_display_obj;

void board_init(void) {
    // Display
    busio_spi_obj_t *spi = common_hal_board_get_spi();
    displayio_fourwire_obj_t *bus = &board_display_obj;
    bus->base.type = &displayio_fourwire_type;

    common_hal_displayio_fourwire_construct(
        bus,
        spi,
        CIRCUITPY_DISPLAY_SCK,    // CLK
        CIRCUITPY_DISPLAY_MOSI,   // MOSI
        NULL,                     // MISO (not used by display typically)
        CIRCUITPY_DISPLAY_DC,     // DC
        CIRCUITPY_DISPLAY_CS,     // CS
        CIRCUITPY_DISPLAY_RST,    // RST
        CIRCUITPY_DISPLAY_BL,     // BL, can be NULL if not used or controlled differently
        60000000,                 // Baudrate (RP2040/RP2350 can often go this high for ST7789)
        0,                        // Polarity
        0                         // Phase
        );

    // This is the display object
    displayio_display_obj_t *display = common_hal_displayio_allocate_display(bus, display_init_sequence, sizeof(display_init_sequence));

    common_hal_displayio_display_construct(
        display,
        bus,
        CIRCUITPY_DISPLAY_WIDTH,  // Width
        CIRCUITPY_DISPLAY_HEIGHT, // Height
        0,                        // column_offset
        0,                        // row_offset
        CIRCUITPY_DISPLAY_ROTATION, // rotation
        16,                       // color_depth
        false,                    // grayscale
        false,                    // pixels_in_byte_share_row
        1,                        // bytes_per_cell
        false,                    // reverse_pixels_in_byte
        true,                     // reverse_pixels_in_word
        0x2A,                     // set_column_command
        0x2B,                     // set_row_command
        0x2C,                     // write_ram_command
        NULL,                     // set_vertical_scroll_command
        NULL,                     // set_vertical_scroll_start_command
        false,                    // backbuffer
        true                      // auto_refresh
        );
}

// Use the MP_WEAK supervisor/shared/board.c versions of routines not defined here.
// If board_reset is not defined here, the common one will be used.
// void board_reset(void) {
//    // Reset code.
// }

// Before the display is used, `common_hal_displayio_release_displays()` will be called to free the display object.
// After a soft reset, this `board_init` will be called again.
