#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"


#define PERIOD 50ms

static enum CALC_STATES
{Clear,ReadInput,Display,Error}CALC_state;
int firstVal=0;
int secondVal=0;
int numsBeingInputted1 = 0;
int numsBeingInputted2 = 0;
int firstValEmpty=1;
int secondValEmpty=1;
int op=0; // 1 = + 2 = - 3 = * 4 = / 0 =blank 5 = =
int op2 =0;

int result=0;//dont clear this gets overridden 
int displayNum=0;

int previousResult=0;//0 if this result has been cleared 1 if this is holding a value

int displayed = 0;
//need error vals to keep track

int isCleared = 0;
int isError = 0;
int errorType = 0;
//button type op = 1 number = 2 clear =3 null = 0
//button value = 0-9 for number 1-4 for op and 0-1 for clear
void tickFct_Calc(int buttonType, int buttonVal)
{
    switch(CALC_state){
        case Clear:
            if(isCleared==1){CALC_state = ReadInput;}
            break;
        case ReadInput:
            if(buttonType==0){CALC_state = ReadInput;}
            else if(buttonType==1&&numsBeingInputted2==1&&buttonVal!=5){CALC_state = Error;}
            else if(buttonType==3){CALC_state = Clear;}
            else if(buttonType==1){
                if(previousResult==0){CALC_state = ReadInput;}
                else {CALC_state = Display;}
                }//do not take as input it is op we are looking for num
            else if(buttonType==2){CALC_state = Display;}
            break;
        case Display:
            if(displayed==0){CALC_state = Display;}
            else {CALC_state = ReadInput;}
            break;
        case Error:
            if(isError==0){CALC_state = Error;}
            else {CALC_state = ReadInput;}
            break;
        default:
            CALC_state = Clear;
    }
    switch(CALC_state){
        case Clear:
            firstVal=0;
            secondVal=0;
            op=0; // 1 = + 2 = - 3 = * 4 = / 0 =blank 5 = =
            op2=0;
            //int result=0;//dont clear this gets overridden 
            numsBeingInputted1 = 0;
            numsBeingInputted2 = 0;
            displayNum=0;
            previousResult=0;//0 if this result has been cleared 1 if this is holding a value
            displayed = 0;
            //need error vals to keep track
            isError = 0;
            errorType=0;
            firstValEmpty=1;
            secondValEmpty=1;
            isCleared = 1;
            break;
        case ReadInput:
            if(buttonType==1&&numsBeingInputted1==1){
                op = buttonVal;
                firstValEmpty=0;
                numsBeingInputted1==0;
                isCleared = 0;
                isError = 0;
            }
            //deal with second operand
            //inputting numbers
            else if(buttonType==1&&numsBeingInputted2==1){
                op2 = buttonVal;
                secondValEmpty=0;
                numsBeingInputted2==0;
                isCleared = 0;
                isError = 0;
            }
            else if(buttonType==2 && firstValEmpty==1){
                firstVal*=10;
                firstVal+=buttonVal;
                numsBeingInputted1==1;
                isCleared = 0;
                isError = 0;
            }
            else if(buttonType==2 && secondValEmpty==1){
                secondVal*=10;
                secondVal+=buttonVal;
                numsBeingInputted2==1;
                isCleared = 0;
                isError = 0;
            }
            break;
        case Display:
            if(errorType!=0){
                if(errorType==1){char output[] = "dont divide by zero asshole";}
                else if(errorType==2){char output[] = "why you need so many numbers";}
            }
            else if (numsBeingInputted1||!firstValEmpty){char output[] = firstVal;}
            else if (numsBeingInputted2){char output[] = secondVal;}
            else if (!secondValEmpty){char output[] = displayNum;}
            
            break;
        case Error:
            //divide by 0
            if(op==4 && secondVal == 0 && op2==5){errorType=1;}
            //overflows
            else if(op==1 && op2==5){//addition
                if(firstVal+secondVal>2^16-1){errorType=2;}
            }
            else if(op==2 && op2==5){//subtraction
                if(firstVal+-secondVal<-1*2^16){errorType=2;}
            }
            else if(op==3 && op2==5){//multiplication
                if(firstVal*secondVal>2^16-1){errorType=2;}
            }
            //deal with if second operand is not equals
            else if (op2!=5){
                if(op==4 ){
                    if(secondVal == 0){errorType=1;}
                    else{firstVal = firstVal/secondVal; op = op2; op2=0; secondVal=0;}
                }
                //overflows
                else if(op==1){//addition
                    if(firstVal+secondVal>2^16-1){errorType=2;}
                    else{firstVal = firstVal+secondVal; op = op2; op2=0; secondVal=0;}
                }
                else if(op==2 ){//subtraction
                    if(firstVal+-secondVal<-1*2^16){errorType=2;}
                    else{firstVal = firstVal-secondVal; op = op2; op2=0; secondVal=0;}

                }
                else if(op==3){//multiplication
                    if(firstVal*secondVal>2^16-1){errorType=2;}
                    else{firstVal = firstVal*secondVal; op = op2; op2=0; secondVal=0;}
                }
            }
            isError = 1;
            break;
    }
}