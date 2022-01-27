SRC += joachimmathes.c

KEY_OVERRIDE_ENABLE = yes

# https://docs.qmk.fm/#/squeezing_avr
AUDIO_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = no
GRAVE_ESC_ENABLE = no
LTO_ENABLE = yes # reduces compiled size by about 4k.
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no

ifneq ($(filter $(strip $(KEYBOARD)),keebio/levinson/rev3 keebio/nyquist/rev3),)
	RGBLIGHT_ENABLE = yes
	BACKLIGHT_ENABLE = yes
endif

ifneq ($(filter $(strip $(KEYBOARD)),crkbd/rev1),)
	BOOTLOADER = atmel-dfu
	RGB_MATRIX_ENABLE = yes
	OLED_ENABLE = yes
	OLED_DRIVER = SSD1306
	WPM_ENABLE = yes
	SRC += oled.c
endif
