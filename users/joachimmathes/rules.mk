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
	OLED_LOGO = OLED_LOGO_SPLIT1
	WPM_ENABLE = yes
	SRC += oled.c
endif

ifneq ($(filter $(strip $(KEYBOARD)),splitkb/aurora/sweep),)
	BOOTLOADER = rp2040
	RGB_MATRIX_ENABLE = yes
	OLED_ENABLE = yes
	OLED_DRIVER = SSD1306
	OLED_LOGO = OLED_LOGO_SPLIT2
	WPM_ENABLE = yes
	SRC += oled.c
endif

ifneq ($(filter $(OLED_LOGO),OLED_LOGO_SPLIT1 OLED_LOGO_SPLIT2 OLED_LOGO_SPLIT3),)
    OPT_DEFS += -D$OLED_LOGO
endif
