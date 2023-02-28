
MCU = RP2040
# Bootloader selection
BOOTLOADER = rp2040


BOARD = GENERIC_RP_RP2040

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
OPT_DEFS += -DHAL_USE_I2C=TRUE
