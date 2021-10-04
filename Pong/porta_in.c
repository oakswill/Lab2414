#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"

void porta_in_init(){
    ANSELA = 0;
    TRISA = 0x1F;
}

uint8_t porta_in_read(){
    uint8_t data;
    data = PORTA;
    return data;
}
