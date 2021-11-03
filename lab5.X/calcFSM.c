#include <xc.h>
#include <plib.h>

#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
//need to finish up the ovverflow when inputting nums
//check during the transitions set the display to error
//go to init

#define PERIOD 50

int F=0; //<- the value of the first number
int OP1; //<- the operation between the first and second number
int S; //<- the value of the second number
int T; //<- hold previous val
extern int D=0;
extern int state=0;//<- what is displayed on the screen; it can be one of F, S, and T

int EqualCounter = 0;

int OVERFLOW=65535;
//error messages will be int values abovce overflow
//65536 = overflow
//65537 = divide by zero
int hasPreviousVal=0;


//button type op = 1 number = 2 clear =3 null = 0
//button value = 0-9 for number 1-4 for op and 1 for clear 1 for equal
// 1 = + 2 = - 3 = * 4 = / 0 =blank 5 = =


static enum CALC_STATES
{Initial,Transition,Equal,FirstNum,SecondNum}CALC_state;

void InitFSM_Calc() {
    CALC_state=FirstNum;
    
    state = 0;
}

void tickFct_Calc(int buttonType, int buttonVal)
{
  //transitions
  switch(CALC_state){
        case Initial://wait for either first number or op if there is a stored val
            if(buttonType==2){//if number
              //F=buttonVal;
              F=F*10+buttonVal;
              CALC_state=FirstNum;
            }
            else if(buttonType==3 && buttonVal==1){//clear
              T=0;D=0;
              CALC_state=Initial;
            }
            else if(buttonType==1 && buttonVal==5){//equals
              CALC_state=Initial;
            }
            
            else if(buttonType==1 && buttonVal!=5){//any op other then equals
              if(hasPreviousVal){
                F=T;
                OP1 = buttonVal;
                CALC_state=SecondNum;
              }
              else{
                CALC_state=Initial;
              }
            }
            else{
              CALC_state=Initial;
            }
            break;
        case FirstNum://load in first number
            if(buttonType==2){//if number
              if(F*10+buttonVal>OVERFLOW){
                D=65536;//eror mesage
                CALC_state=Initial;
                F=0;
              }
              else{
                F=F*10+buttonVal;
                CALC_state=FirstNum;
              }
           // F=F*10+buttonVal;
            //CALC_state==FirstNum; 
            }
            else if(buttonType==3 && buttonVal==1){//clear works praise the lord allmight ahlllowed by thy name thy kingdom come thy will be done on earth as it is in heaven
                
              CALC_state=Initial;
            }
            else if(buttonType==1 && buttonVal==5){//equals
               
              CALC_state=FirstNum;
            }
            
            else if(buttonType==1 && buttonVal!=5){//any op other then equals
                OP1 = buttonVal;
                D = 0;
              CALC_state=SecondNum;
            }
            
            else{
              F=F;  
              CALC_state=FirstNum;
            }
            break;
        case Transition://first op
          if(buttonType==3 && buttonVal==1){//clear
            CALC_state=Initial;
          }
          else if(buttonType==1 && buttonVal==5){//equals
            CALC_state=Transition;
          }
          else if(buttonType==2){//if number
            CALC_state=SecondNum;
          }
          else if(buttonType==1 && buttonVal!=5){//any op other then equals
              OP1 = buttonVal;
            CALC_state=Transition;
          }
          else{
            CALC_state=Transition;
          }
            break;
        case SecondNum://second number
            if(buttonType==3 && buttonVal==1){//clear
              CALC_state=Initial;
            }
            else if(buttonType==1 && buttonVal==5){//equals
              CALC_state=Equal;
            }
            else if(buttonType==2){//if number
              if(S*10+buttonVal>OVERFLOW){
                D=65536;//eror mesage
                CALC_state=Initial;
              }
              else{
                S=S*10+buttonVal;
                CALC_state=SecondNum;
              }
             //S=S*10+buttonVal;
             //CALC_state=SecondNum;   
            }
            else if(buttonType==1 && buttonVal!=5){//any op other then equals
              CALC_state=SecondNum;
            }
            else{
              S=S;
              CALC_state=SecondNum;
            }
            break;
        case Equal://calculations
          if(EqualCounter==0){
              CALC_state=Equal;
            }
            else{
              EqualCounter==0;
              CALC_state=Initial;//non overflow
            }
              break;
        default:
            CALC_state = Initial;
    }
    //outputs and calculations
  switch(CALC_state){
        case Initial:
            F = 0;
            OP1 =  1;//+
            S = 0;
            //T = 0;
            D = T;
            state = 0;
            break;
        case FirstNum:
            //F=F*10+buttonVal;
            OP1=OP1;
            S=S;
            T=T;
            D=F;
            state = 1;
            break;
        case Transition:
            F=F;
           // OP1=buttonVal;
            S=S;
            T=T;
            D=F;//keep showing first number when pressing the operanbd
            state = 2;
            break;
        case SecondNum:
            F=F;
            OP1=OP1;
            //S=S*10+buttonVal;
            T=T;
            D=S;
            state = 3;
            break;
        case Equal:
            D = OP1;
            state = 4;
            if(OP1 == 1){
              if(F+S>OVERFLOW){
                D=65536;//error message
                //D=F+S;
              }
              else{
                //D=F+S;//non overflow
                T=F+S;
                hasPreviousVal=1;
              }
            }
            else if(OP1 == 2){
              if(F-S<(-1*OVERFLOW-1)){
                D=65536;//error message
              }
              else{
                T=F-S;//if no mulitply
                hasPreviousVal=1;
              }
              
            }
            else if(OP1 == 4){
              if(S==0){
                D = 65537;//error message divide by zero
              }
              else{
                T=F/S;//if no divide by 0
                hasPreviousVal=1;
              }
            }
            else if(OP1 == 3){
              if(F*S>OVERFLOW || F*S<(-1*OVERFLOW-1)){
                D=65536;//error message
              }
              else{
                T=F*S;//if no mulitply
                hasPreviousVal=1;
              }
            }
            
            EqualCounter++;
            break;
        default:
            CALC_state = Initial;
    }

}