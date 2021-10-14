#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"


uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y);