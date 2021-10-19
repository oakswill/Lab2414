#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"


#define XM AN0
#define YP AN1

void calculatorDisplay(){
//first column
tft_drawRoundRect(0,48,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(39, 71);
tft_write('7');

tft_drawRoundRect(0,98,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(39, 122);
tft_write('4');

tft_drawRoundRect(0,146,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(39, 169);
tft_write('1');


tft_drawRoundRect(0,194,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(39, 217);
tft_write('0');
//second column
tft_drawRoundRect(80,48,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(119, 71);
tft_write('8');

tft_drawRoundRect(80,98,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(119, 122);
tft_write('5');

tft_drawRoundRect(80,146,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(119, 169);
tft_write('2');


tft_drawRoundRect(80,194,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(119, 217);
tft_write('C');
//third column
tft_drawRoundRect(160,48,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(199, 71);
tft_write('9');

tft_drawRoundRect(160,98,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(199, 122);
tft_write('6');

tft_drawRoundRect(160,146,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(199, 169);
tft_write('3');


tft_drawRoundRect(160,194,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(199, 217);
tft_write('=');
//fourth column
tft_drawRoundRect(240,48,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(279, 71);
tft_write('+');

tft_drawRoundRect(240,98,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(279, 122);
tft_write('-');

tft_drawRoundRect(240,146,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(279, 169);
tft_write('x');


tft_drawRoundRect(240,194,78,46,2,ILI9341_WHITE);
tft_setTextColor(ILI9341_BLACK);
tft_setCursor(279, 217);
tft_write('/');




}