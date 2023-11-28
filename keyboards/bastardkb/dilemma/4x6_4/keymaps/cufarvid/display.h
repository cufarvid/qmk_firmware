#include "qp.h"
#include "print.h"
#include "os_detection.h"
#include "cufarvid.h"
#include "generated/fira-code-nerd.qff.h"

#define LCD_RST_PIN GP13
#define LCD_DC_PIN GP11
#define LCD_CS_PIN GP12

typedef struct {
    char *name;
    char *icon;
} os_info_t;