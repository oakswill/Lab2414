/* 
 * File:   main.c
 * Author: oakesw
 *
 * Created on November 16, 2021, 1:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <inttypes.h>
#include "outputcompare.h"
#include "uart.h"
#include "tft_master.h"
#include "tft_gfx.h"

/*
 * 
 */



#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF


int main(int argc, char** argv) {
     uart1_init(9600);
      initCapture();
        uint16_t a;      
   oc1_init_plib(1000);
   while(1) {
    a = ic1_getperiod();
   
    tft_fillScreen(ILI9341_BLACK);  
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(0, 10);
    tft_writeString(a);

}


}