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

#define XM AN0
#define YP AN1

int output = 0;
int output1 = 0;
int mv = 0;
int mv1 = 0;
int xPos=0;
int yPos=1;
int button=0;

int sym=0;


int counter =0;
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
   
   
   
   
   
   SYSTEMConfigPerformance(PBCLK);
   tft_init_hw();
   tft_begin();
   tft_setRotation(3);
   tft_fillScreen(ILI9341_BLACK); 
   InitFSM_debounce();
   //initADC();//dac
    ta1 = timer1_read();
    ta3 = timer1_read();
    ta5 = timer1_read();
    while(1){
        struct TSPoint p;
         p.x = 0;
         p.y = 0;
         p.z = 0;
         
         /**
         if(state==2){
            AcquireADC10();
            initADC();//dac
            output = ReadADC10(0);
            output1 = ReadADC10(1);
            
                
            }
        else{
            
            configureADC();
            getPoint(&p);
            
        }
         **/
        configureADC();
        getPoint(&p);
        output = readADC(9);
        output1 = readADC(11);
       /**
        if(counter%2==0){
            initADC();//dac
            output = ReadADC10(0);
            output1 = ReadADC10(1);
            AcquireADC10();
            counter++;
        }
        
        else{
            configureADC();//touchscreen
            //touchscreen stuff
            getPoint(&p);
            counter++;
        }
        **/
        int y1 = 950;
        int x1 = 200;
        int y2 = 320;
        int x2 = 1000;
        xPos = (p.y-y1)*(239-0)/(y2-y1)+0;
        yPos = (p.x-x1)*(319-0)/(x2-x1)+0; 
      
        
        
        
        
        //sensor stuff need to establish which is left and right
        
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
        if (timer1_ms_elapsed(ta3, ta4) > 50) {
            //tickFct_lcd(button,displayable,displayable1);
            tickFct_lcd(button);
            //if reset = 1 then we need to reset both jumpstate FSM's and set reset to 0
           /**
            if(resetJumpFSM=1){
                //rst();
                //rst1();
                resetJumpFSM=0;
            }
            **/
            ta3 = ta4;
        }
        //if statements based on which state the lcd fsm is on and what to print for each one
        
        ta6 = timer1_read();
        if (timer1_ms_elapsed(ta5, ta6) > 50) {
            tickFct_debounce(p.z);
            button=0;
            if(DebouncedKeyPress=1){
                //state1
                //if(state1 and jump selected) button = 1
                
                //state3
                //if(state3 and jump again selected) button = 2
                //if(state3 and menu selected) button = 3
                if(state==1&&xPos<=210&&xPos>=110&&yPos>=70&&yPos<=170){
                    button = 1;
                }
                else if(state==3&&xPos<=319&&xPos>=219&&yPos>=0&&yPos<=50){
                    button = 3;
                }
                else if(state==3&&xPos<=100&&xPos>=0&&yPos>=0&&yPos<=50){
                    //button=2;
                }
            }
            else{button=0;}
            ta5 = ta6;
        }
        
        
        
       /** 
        tft_setCursor(200, 71);
        sprintf(buffer3,"%d",didLand);
        tft_writeString(buffer3);
        
        tft_setCursor(200, 110);
        sprintf(buffer2,"%d",didJump);
        tft_writeString(buffer2);
        
      
        
        tft_setCursor(230, 100);
        sprintf(buffer5,"%d",displayable);
        tft_writeString(buffer5);
        
        tft_setCursor(230, 150);
        sprintf(buffer6,"%d",displayable1);
        tft_writeString(buffer6);
        **/
        if(state==1){
        tft_setTextSize(2);
        tft_drawRoundRect(110,70,100,100,5,ILI9341_WHITE);
        tft_setTextColor(ILI9341_WHITE);
        tft_setCursor(135, 110);
        tft_writeString("Jump");
        tft_setCursor(39, 21);
        tft_writeString("Exercise Selection");
        
        tft_setCursor(20, 200);
        tft_writeString("Not Made for Epileptics");
        
       
    
        }
        else if(state==2){
            //tft_drawRoundRect(0,48,78,46,5,ILI9341_WHITE);
            tft_setTextColor(ILI9341_WHITE);
            tft_setTextSize(2.5);
            tft_setCursor(30, 80);
            tft_writeString("YOU CAN DO IT JUMP");
            tft_setCursor(20, 120);
            tft_writeString("PI PHI GIVES YOU WINGS");
        }
        else if(state==3){
            //tft_drawRoundRect(0,0,100,50,5,ILI9341_WHITE);
            //tft_setTextColor(ILI9341_WHITE);
            tft_setTextSize(2);
            //tft_setCursor(20, 20);
            //tft_writeString("Again");
            
            tft_drawRoundRect(219,0,100,50,5,ILI9341_WHITE);
            tft_setCursor(239, 20);
            tft_writeString("Menu");
            
            //row labels
            tft_setCursor(0, 135);
            tft_writeString("Left");
            
            tft_setCursor(0, 95);
            tft_writeString("Right");
            //col labels
            tft_setCursor(75, 55);
            tft_writeString("Jump");
            
            tft_setCursor(145, 55);
            tft_writeString("AirTime");
            
            tft_setCursor(250, 55);
            tft_writeString("Land");
            
            tft_setCursor(75, 95);
            sprintf(buffer,"%d",maxForceJump);
            tft_writeString(buffer);
            
            tft_setCursor(145, 95);
            sprintf(buffer2,"%d",airTime);
            tft_writeString(buffer2);
            
            tft_setCursor(250, 95);
            sprintf(buffer3,"%d",maxForceLand);
            tft_writeString(buffer3);
            
            tft_setCursor(75, 135);
            sprintf(buffer4,"%d",maxForceJump1);
            tft_writeString(buffer4);
            
            tft_setCursor(145, 135);
            sprintf(buffer5,"%d",airTime1);
            tft_writeString(buffer5);
            
            tft_setCursor(250, 135);
            sprintf(buffer6,"%d",maxForceLand1);
            tft_writeString(buffer6);
            
            tft_setCursor(0, 200);
            tft_writeString("Symmetry Analysis:");
            
            sym = (maxForceJump*1.0/maxForceJump1*1.0 * 100.0 + airTime*1.0/airTime1*1.0 * 100.0 + maxForceLand*1.0/maxForceLand1*1.0 * 100.0)/3.0 ;
            if(sym>100){
                sym=(maxForceJump1*1.0/maxForceJump*1.0 * 100.0 + airTime1*1.0/airTime*1.0 * 100.0 + maxForceLand1*1.0/maxForceLand*1.0 * 100.0)/3.0;
            }
            sprintf(buffer7,"%d",sym);
            tft_writeString(buffer7);
            tft_writeString("%");
            
            
            
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
