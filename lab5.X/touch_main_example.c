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
   
    ta1 = timer1_read();
    ta3 = timer1_read();
    calculatorDisplay();
    InitFSM_debounce();
    int buttonT;
    int buttonV;
    while(1){
        
        struct TSPoint p;
        p.x = 0;
        p.y = 0;
        p.z = 0;
        getPoint(&p);
        
        //Button determination a mixture of predestination and the desire to calculate
        
        
        ta2 = timer1_read();
        ta4 = timer1_read();
            
       
        //tick functions
        if (timer1_ms_elapsed(ta1, ta2) > 300) {
            tickFct_Calc(buttonT, buttonV);
            tft_setCursor(0, 0);
            tft_setTextColor(ILI9341_WHITE);
            tft_writeString(output);
            ta1 = ta2;
         }
        if (timer1_ms_elapsed(ta3,ta4)>200){
            tickFct_debounce(p.z);
            if(DebouncedKeyPress=1){
                if(p.x<=78&&p.x>=0){
                    if(p.y>=48&&p.y<=94){
                        buttonT=2;
                        buttonV=7;
                    }
                    //the claw tends its way towards entropy
                    else if(p.y>=98&&p.y<=144){
                        buttonT=2;
                        buttonV=4;
                    }
                    else if(p.y>=146&&p.y<=192){
                        buttonT=2;
                        buttonV=1;
                    }
                    else if(p.y>=194&&p.y<=240){
                        buttonT=2;
                        buttonV=0;
                    }
                }
                else if(p.x<=158&&p.x>=80){
                    if(p.y>=48&&p.y<=94){
                        buttonT=2;
                        buttonV=8;
                    }
                    //the claw tends its way towards entropy
                    else if(p.y>=98&&p.y<=144){
                        buttonT=2;
                        buttonV=5;
                    }
                    else if(p.y>=146&&p.y<=192){
                        buttonT=2;
                        buttonV=2;
                    }
                    else if(p.y>=194&&p.y<=240){
                        buttonT=3;
                        buttonV=1;
                    }
                }
                else if(p.x<=238&&p.x>=160){//will is a sabateour
                    if(p.y>=48&&p.y<=94){
                        buttonT=2;
                        buttonV=9;
                    }
                    //the claw tends its way towards entropy
                    else if(p.y>=98&&p.y<=144){
                        buttonT=2;
                        buttonV=6;
                    }
                    else if(p.y>=146&&p.y<=192){
                        buttonT=2;
                        buttonV=3;
                    }
                    else if(p.y>=194&&p.y<=240){
                        buttonT=1;
                        buttonV=5;
                    }
                }
                else if(p.x<=319&&p.x>=240){//will is a sabateour
                    if(p.y>=48&&p.y<=94){
                        buttonT=1;
                        buttonV=1;
                    }
                    //the claw tends its way towards entropy
                    else if(p.y>=98&&p.y<=144){
                        buttonT=1;
                        buttonV=2;
                    }
                    else if(p.y>=146&&p.y<=192){
                        buttonT=1;
                        buttonV=3;
                    }
                    else if(p.y>=194&&p.y<=240){
                        buttonT=1;
                        buttonV=4;
                    }
                }
            }
            
            ta3 = ta4;
        }
        
        if(DebouncedKeyPress==1){
                tft_fillScreen(ILI9341_BLACK);
                //DebouncedKeyPress=0;
            }
        else if(DebouncedKeyPress==0){
            calculatorDisplay();
        }
        //tft_drawRoundRect(0,0,400,400,2,ILI9341_WHITE);
    }
//Lout is our extern from debouncer
    
    
    return (EXIT_SUCCESS);
    
    
    
}

