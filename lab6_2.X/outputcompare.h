#ifndef OUTPUTCOMPARE_H
#define OUTPUTCOMPARE_H



#ifdef	__cplusplus
extern "C" {
#endif
    
#include <inttypes.h>

    // initialize output compare using timer3
    extern void oc1_init_plib(uint16_t duty);
    
    // set duty cycle 0x0000-0xffff
    extern void oc1_setduty_plib(uint16_t duty);




#ifdef	__cplusplus
}
#endif

#endif	/* OC1_H */

