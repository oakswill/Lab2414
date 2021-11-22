#ifndef INPUTCAPTURE_H
#define INPUTCAPTURE_H

#include <inttypes.h>
#include <plib.h>

extern void initCapture();
extern void __ISR();
extern uint16_t ic1_getperiod();

#endif