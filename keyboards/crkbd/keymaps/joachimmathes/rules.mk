BOOTLOADER = atmel-dfu

# enable linking time optimization
# final compile step takes longer but reduces compiled size by about 4k.
LTO_ENABLE = yes

RGB_MATRIX_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

WPM_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes

# https://docs.qmk.fm/#/squeezing_avr
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
