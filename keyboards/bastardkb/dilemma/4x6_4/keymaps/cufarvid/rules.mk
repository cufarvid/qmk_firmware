VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
CAPS_WORD_ENABLE = yes
OS_DETECTION_ENABLE = yes
WPM_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += gc9a01_spi

SRC += cufarvid.c \
       display.c \
       generated/fira-code-nerd.qff.c
