//#include "oc1.h"
#include <xc.h>
#include <plib.h>

    // initialize output compare using timer3 

void oc1_init_plib(uint16_t duty) {
        OpenTimer3(T3_ON | T3_SOURCE_INT | T3_PS_1_1, 0xffff);
        OpenOC1(OC_ON | OC_TIMER_MODE16| OC_TIMER3_SRC | 
                OC_PWM_FAULT_PIN_DISABLE, duty, duty);  
        PPSOutput(1, RPB7, OC1);
    }    
    
    void oc1_setduty_plib(uint16_t duty) {
        SetDCOC1PWM(duty);
    }

