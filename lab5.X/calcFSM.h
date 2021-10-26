
#include <xc.h>
#include <plib.h>

#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"


#define PERIOD 50ms

extern void tickFct_Calc(int buttonType, int buttonVal);

extern char output[50];