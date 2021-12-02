/* 
 * File:   main.c
 * Author: oakesw
 *
 * Created on November 30, 2021, 7:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "DAC.h"
#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "timer1.h"
#include "jumpState.h"

int output = 0;
int output1 = 0;
int mv = 0;
int mv1 = 0;
/*
 * 
 */
float v;
float v1;
char buffer[50];
char buffer2[50];
char buffer3[50];
char buffer4[50];
char buffer5[50];
char buffer6[50];
char buffer7[50];
char buffer8[50];
char buffer9[50];
uint16_t ta1, ta2;
 

int main() {
   
   timer1_init();
   InitFSM_jump();
   
   configureADC();
   SYSTEMConfigPerformance(PBCLK);
   tft_init_hw();
   tft_begin();
   tft_setRotation(3);
   tft_fillScreen(ILI9341_BLACK); 
   initADC();
   
    ta1 = timer1_read();
    while(1){
        output = ReadADC10(0);
        output1 = ReadADC10(1);
        AcquireADC10();
        tft_fillScreen(ILI9341_BLACK); 
        
        tft_setCursor(0,100);
        tft_setTextColor(ILI9341_WHITE);
        tft_setTextSize(2);
        v=(float)output*3.3/1023.0*1000.0;//output in mv
        sprintf(buffer,"%d",output);
        tft_writeString(buffer);
        
        tft_setCursor(0,150);
        sprintf(buffer2,"%f",v);
        tft_writeString(buffer2);
        
        mv=(int)v;
        tft_setCursor(0,200);
        sprintf(buffer3,"%d",mv);
        tft_writeString(buffer3);
        
        tft_setCursor(100,100);
        sprintf(buffer9,"%d",output1);
        tft_writeString(buffer9);
        
        ta2 = timer1_read();
        if (timer1_ms_elapsed(ta1, ta2) > 50) {
            tickFct_jump(mv);
            ta1 = ta2;
        }
        
        /**
        tft_setCursor(120,100);
        sprintf(buffer4,"%d",didJump);
        tft_writeString(buffer4);
        
        tft_setCursor(120,150);
        sprintf(buffer5,"%d",didLand);
        tft_writeString(buffer5);
        
        tft_setCursor(200,100);
        sprintf(buffer6,"%d",maxForceJump);
        tft_writeString(buffer6);
        
        tft_setCursor(200,150);
        sprintf(buffer7,"%d",airTime);
        tft_writeString(buffer7);
        
        tft_setCursor(200,200);
        sprintf(buffer8,"%d",maxForceLand);
        tft_writeString(buffer8);
        */
    }
   
}
