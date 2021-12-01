/* 
 * File:   main.c
 * Author: oakesw
 *
 * Created on November 30, 2021, 7:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "DAC.h"
#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"

int output = 0;
/*
 * 
 */
float v;
char buffer[50];
char buffer2[50];

 

int main() {
   
   configureADC();
   SYSTEMConfigPerformance(PBCLK);
   tft_init_hw();
   tft_begin();
   tft_setRotation(3);
   tft_fillScreen(ILI9341_BLACK); 
   //initADC();
   
   
    while(1){
        //output = ReadADC10(0);
        //AcquireADC10();
        tft_fillScreen(ILI9341_BLACK); 
       /* 
        tft_setCursor(0,100);
        tft_setTextColor(ILI9341_WHITE);
        tft_setTextSize(2);
        v=(float)output*3.3/1023.0;
        sprintf(buffer,"%d",output);
        tft_writeString(buffer);
        */
        //tft_setCursor(0,150);
        //fprintf(buffer2,"%f",v);
        //tft_writeString(buffer2);
    }
   
}

