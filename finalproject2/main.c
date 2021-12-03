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
#include "jumpState1.h"
#include "LCD_FSM.h"
#include "debounce.h"

int output = 0;
int output1 = 0;
int mv = 0;
int mv1 = 0;
int xPos=0;
int yPos=1;
int button=0;
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
uint16_t ta1, ta2,ta3,ta4,ta5,ta6;
 

int main() {
   
   timer1_init();
   InitFSM_jump();
   InitFSM_jump1();
   InitFSM_lcd();
   
   configureADC();
   SYSTEMConfigPerformance(PBCLK);
   tft_init_hw();
   tft_begin();
   tft_setRotation(3);
   tft_fillScreen(ILI9341_BLACK); 
   initADC();
   
    ta1 = timer1_read();
    ta3 = timer1_read();
    ta5 = timer1_read();
    while(1){
        //touchscreen stuff
        struct TSPoint p;
        p.x = 0;
        p.y = 0;
        p.z = 0;
        getPoint(&p);
        int y1 = 950;
        int x1 = 200;
        int y2 = 320;
        int x2 = 1000;
        xPos = (p.y-y1)*(239-0)/(y2-y1)+0;
        yPos = (p.x-x1)*(319-0)/(x2-x1)+0; 
        
        //sensor stuff need to establish which is left and right
        output = ReadADC10(0);
        output1 = ReadADC10(1);
        AcquireADC10();
        v=(float)output*3.3/1023.0*1000.0;//output in mv
        mv=(int)v;
        v1=(float)output1*3.3/1023.0*1000.0;//output in mv
        mv1=(int)v1;
        tft_fillScreen(ILI9341_BLACK); 
        /**
        tft_setCursor(0,100);
        tft_setTextColor(ILI9341_WHITE);
        tft_setTextSize(2);
        
        sprintf(buffer,"%d",output);
        tft_writeString(buffer);
        
        tft_setCursor(0,150);
        sprintf(buffer2,"%f",v);
        tft_writeString(buffer2);
        
       // m
        tft_setCursor(0,200);
        sprintf(buffer3,"%d",mv);
        tft_writeString(buffer3);
        
        tft_setCursor(100,100);
        sprintf(buffer9,"%d",output1);
        tft_writeString(buffer9);
        **/
        ta2 = timer1_read();
        if (timer1_ms_elapsed(ta1, ta2) > 50) {
            tickFct_jump(mv);
            tickFct_jump1(mv1);
            ta1 = ta2;
        }
        ta4 = timer1_read();
        if (timer1_ms_elapsed(ta3, ta4) > 200) {
            tickFct_lcd(button,displayable,displayable1);
            //if reset = 1 then we need to reset both jumpstate FSM's and set reset to 0 
            ta3 = ta4;
        }
        //if statements based on which state the lcd fsm is on and what to print for each one
        
        ta6 = timer1_read();
        if (timer1_ms_elapsed(ta5, ta6) > 200) {
            tickFct_debounce(p.z);
            if(DebouncedKeyPress=1){
                //state1
                //if(state1 and jump selected) button = 1
                
                //state3
                //if(state3 and jump again selected) button = 2
                //if(state3 and menu selected) button = 3
            }
            ta5 = ta6;
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
