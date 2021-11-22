#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <inttypes.h>
#include <plib.h>
 


static uint16_t capture1, last_capture1, capture_period, max_period, min_period;

void initCapture() {

    OpenTimer3(T3_ON | T3_SOURCE_INT | T3_PS_1_256, 0xffff);
    OpenCapture3( IC_EVERY_RISE_EDGE | IC_INT_1CAPTURE | IC_TIMER3_SRC | IC_ON );
    ConfigIntCapture1(IC_INT_ON | IC_INT_PRIOR_3 | IC_INT_SUB_PRIOR_3 );
    PPSInput(2, IC3, RPB5);          // connect PIN 6 to IC1 capture unit
    mPORTBSetPinsDigitalIn(BIT_2 );  // Set port as input (important!)
    capture1 = 0;
    last_capture1 = 0;
    capture_period = 0;

    



}

// IC1 Interrupt service routine
void __ISR(_INPUT_CAPTURE_1_VECTOR, ipl3) C1Handler(void) {
    capture1 = mIC1ReadCapture();
    capture_period = capture1 - last_capture1;
    // condition on last capture to avoid start up error
    if (capture_period > max_period && last_capture1 > 0) 
        max_period = capture_period;
    if (capture_period < min_period && last_capture1 > 0) 
        min_period = capture_period;
    last_capture1 = capture1;
    mIC1ClearIntFlag();     // clear the interrupt flag!
}
    
    
// return the period measured by IC1
uint16_t ic1_getperiod() {
    return capture_period;
        
}
