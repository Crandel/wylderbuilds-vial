MCU = RP2040
SPLIT_KEYBOARD = yes
BOOTLOADER = rp2040
SERIAL_DRIVER = vendor
RGBLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
#COMMAND_ENABLE = yes
BOOTMAGIC_ENABLE = yes
NKRO_ENABLE = yes           # Enable N-Key Rollover

OLED_ENABLE = yes
#OLED_DRIVER = SSD1306
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control

ENCODER_ENABLE = no
ENCODER_MAP_ENABLE = no

OPT_DEFS += -DHAL_USE_I2C=TRUE