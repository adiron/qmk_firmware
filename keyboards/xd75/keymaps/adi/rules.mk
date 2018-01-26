NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
TAP_DANCE_ENABLE = no
MIDI_ENABLE = yes
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
BLUETOOTH_ENABLE = no
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
RGBLIGHT_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
