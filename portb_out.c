#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"

void portb_out_init(){
    ANSELB = 0;
    TRISB = 0x0000;
    LATB = 0x0000;
}

void portb_out_write(uint16_t v){
    LATB = v&0x003F| v&0x07C0 | outval&0x1C00;
}
