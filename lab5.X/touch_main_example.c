/* 
 * File:   touch_main.c
 * Author: watkinma
 *
 * Description: Prints out the detected position (x, y) of a press on the
 * touchscreen as well as the pressure (z).
 * 
 * IMPORTANT: For this example to work, you need to make the following 
 * connections from the touchpad to the PIC32:
 *  Y+ => AN1 (Pin 3)
 *  Y- => RA3 (Pin 10)
 *  X+ => RA4 (Pin 12)
 *  X- => AN0 (Pin 2)
 * 
 */

#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "calc_display.h"
#include "debounce.h"
#include "timer1.h"
#include "calcFSM.h"


#define XM AN0
#define YP AN1

/*
 * 
 */






int main(int argc, char** argv) {
    char buffer[30];

    uint16_t ta1, ta2, ta3, ta4;
    
    timer1_init();
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    tft_setTextSize(2);//TEXTSIZE LOOK AT ME I AM MPORTANT JK I AM VERY IMPORTANT 
       int xPos;
    int yPos;
    int size = 20;
    
    ta1 = timer1_read();
    ta3 = timer1_read();
    calculatorDisplay();
    InitFSM_debounce();
    InitFSM_Calc();
    int buttonT;
    int buttonV;
    char str[30];
    char str1[30];
    char str2[30];
    while(1){
        
        struct TSPoint p;
        p.x = 0;
        p.y = 0;
        p.z = 0;
        getPoint(&p);
        
        
       // tft_drawLine(xPos-size,yPos,xPos+size,yPos,ILI9341_BLACK);
       // tft_drawLine(xPos,yPos-size,xPos,yPos+size,ILI9341_BLACK);
        
        int y1 = 950;
        int x1 = 200;
        int y2 = 320;
        int x2 = 1000;
        xPos = (p.y-y1)*(239-0)/(y2-y1)+0;
        yPos = (p.x-x1)*(319-0)/(x2-x1)+0; 
        
      //  tft_drawLine(xPos-size,yPos,xPos+size,yPos,ILI9341_WHITE);
       // tft_drawLine(xPos,yPos-size,xPos,yPos+size,ILI9341_WHITE);
        
        
        
        //Button determination a mixture of predestination and the desire to calculate
        
        
        ta2 = timer1_read();
        ta4 = timer1_read();
            
       //error messages will be int values abovce overflow
        //65536 = overflow
        //65537 = divide by zero
        //tick functions
        if (timer1_ms_elapsed(ta1, ta2) > 300) {
            tickFct_Calc(buttonT, buttonV);
            //tft_fillRoundRect(0,0,400,45,1,ILI9341_BLACK);
            //tft_setCursor(0, 10);
            //tft_setTextColor(ILI9341_WHITE);
            //sprintf(str, "%d", buttonV);
            //tft_setCursor(30, 10);
            //sprintf(str1, "%d", buttonT);
            //tft_writeString(str1);
            buttonT=0;
            buttonV=0;
            ta1 = ta2;
         }
        tft_setTextSize(4);
        tft_fillRoundRect(0,0,400,45,1,ILI9341_BLACK);
        if(D<65536){
            sprintf(str, "%d", D);
            tft_setTextColor(ILI9341_WHITE);
            tft_setCursor(0, 10);
            tft_writeString(str);
        }
        else if(D==65536){
            char error1[30] = "ERROR";
            tft_setTextColor(ILI9341_WHITE);
            tft_setCursor(0, 10);
            tft_writeString(error1);
        }
        else if(D==65537){
            char error2[30] = "DIV0";
            tft_setTextColor(ILI9341_WHITE);
            tft_setCursor(0, 10);
            tft_writeString(error2);
        }
        
        
         //sprintf(str2, "%d", state);
         //tft_setTextColor(ILI9341_WHITE);
         //tft_setCursor(0, 30);
         //tft_writeString(str2);
        
        if (timer1_ms_elapsed(ta3,ta4)>200){
            tickFct_debounce(p.z);
            if(DebouncedKeyPress=1){
                if(xPos<=78&&xPos>=0){
                    if(yPos>=48&&yPos<=94){
                        buttonT=2;
                        buttonV=7;
                    }
                    //the claw tends its way towards entropy
                    else if(yPos>=98&&yPos<=144){
                        buttonT=2;
                        buttonV=4;
                    }
                    else if(yPos>=146&&yPos<=192){
                        buttonT=2;
                        buttonV=1;
                    }
                    else if(yPos>=194&&yPos<=240){
                        buttonT=2;
                        buttonV=0;
                    }
                }
                else if(xPos<=158&&xPos>=80){
                    if(yPos>=48&&yPos<=94){
                        buttonT=2;
                        buttonV=8;
                    }
                    //the claw tends its way towards entropy
                    else if(yPos>=98&&yPos<=144){
                        buttonT=2;
                        buttonV=5;
                    }
                    else if(yPos>=146&&yPos<=192){
                        buttonT=2;
                        buttonV=2;
                    }
                    else if(yPos>=194&&yPos<=240){
                        buttonT=3;
                        buttonV=1;
                    }
                }
                else if(xPos<=238&&xPos>=160){//will is a sabateour
                    if(yPos>=48&&yPos<=94){
                        buttonT=2;
                        buttonV=9;
                    }
                    //the claw tends its way towards entropy
                    else if(yPos>=98&&yPos<=144){
                        buttonT=2;
                        buttonV=6;
                    }
                    else if(yPos>=146&&yPos<=192){
                        buttonT=2;
                        buttonV=3;
                    }
                    else if(yPos>=194&&yPos<=240){
                        buttonT=1;
                        buttonV=5;
                    }
                }
                else if(xPos<=319&&xPos>=240){//will is a sabateour
                    if(yPos>=48&&yPos<=94){
                        buttonT=1;
                        buttonV=1;
                    }
                    //the claw tends its way towards entropy
                    else if(yPos>=98&&yPos<=144){
                        buttonT=1;
                        buttonV=2;
                    }
                    else if(yPos>=146&&yPos<=192){
                        buttonT=1;
                        buttonV=3;
                    }
                    else if(yPos>=194&&yPos<=240){
                        buttonT=1;
                        buttonV=4;
                    }
                }
            }
            
            ta3 = ta4;
        }
       
      
    }
//Lout is our extern from debouncer
    
    
    return (EXIT_SUCCESS);
    
    
    
}

