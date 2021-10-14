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


#define XM AN0
#define YP AN1

/*
 * 
 */






int main(int argc, char** argv) {
    char buffer[30];
    int xPos;
    int yPos;
    int size = 10;
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
   
    
    while(1){
        //tft_fillScreen(ILI9341_BLACK);
        tft_setCursor(20, 100);
        tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);

        //erase old text
        tft_setTextColor(ILI9341_BLACK);
        tft_writeString(buffer);
        
        //erase old crosshair
        tft_drawLine(xPos-size,yPos,xPos+size,yPos,ILI9341_BLACK);
        tft_drawLine(xPos,yPos-size,xPos,yPos+size,ILI9341_BLACK);
        
        struct TSPoint p;
        p.x = 0;
        p.y = 0;
        p.z = 0;
        getPoint(&p);
        tft_setCursor(20, 100);
        tft_setTextColor(ILI9341_WHITE);
        sprintf(buffer,"x: %d, y: %d, z: %d", p.x, p.y, p.z);
        tft_writeString(buffer);
        
        //tft_drawLine(p.x-size,p.y,p.x+size,p.y,ILI9341_WHITE);
        //tft_drawLine(p.x,p.y-size,p.x,p.y+size,ILI9341_WHITE);
        
        int y1 = 950;
        int x1 = 200;
        int y2 = 320;
        int x2 = 850;
        xPos = (p.y-y1)*(239-0)/(y2-y1)+0;
        yPos = (p.x-x1)*(319-0)/(x2-x1)+0;
        
        tft_drawLine(xPos-size,yPos,xPos+size,yPos,ILI9341_WHITE);
        tft_drawLine(xPos,yPos-size,xPos,yPos+size,ILI9341_WHITE);
       
         uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y) {
            uint8_t returnable = 0;
            if(p.z>0){
            *y=yPos;
            *x=xPos;
            returnable = 1;
            }
            return returnable;
         }
    
        delay_ms(100);
    }

    
    
    return (EXIT_SUCCESS);
    
    
    
}

