#include <xc.h>
#include <plib.h>

#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
//need to finish up the ovverflow when inputting nums

#define PERIOD 50

int F; //<- the value of the first number
int OP1; //<- the operation between the first and second number
int S; //<- the value of the second number
int OP2; //<- the operation between the second number and trailing number
int T; //<- hold previous val
int D; //<- what is displayed on the screen; it can be one of F, S, and T

int EqualCounter = 0;

int OVERFLOW=10000;

boolean hasPreviousVal=false;


//button type op = 1 number = 2 clear =3 null = 0
//button value = 0-9 for number 1-4 for op and 1 for clear 1 for equal
// 1 = + 2 = - 3 = * 4 = / 0 =blank 5 = =


static enum CALC_STATES
{Initial,Transition,Equal,TFromInitial,TFromTransition}CALC_state;

void tickFct_Calc(int buttonType, int buttonVal)
{
  //transitions
  switch(CALC_state){
        case Initial://wait for either first number or op if there is a stored val
            if(buttonType==3 && buttonVal==1){//clear
              CALC_state=Initial;
            }
            else if(buttonType==1 && buttonVal==5){//equals
              CALC_state==Initial;
            }
            else if(buttonType==2){//if number
              F=buttonVal;
              CALC_state==TFromInitial;
            }
            else if(buttonType==1 && buttonVal!=5){//any op other then equals
              if(hasPreviousVal){
                F=T;
                CALC_state==Transition;
              }
              else{
                CALC_state==Initial;
              }
            }
            else{
              CALC_state=Initial;
            }
            break;
        case TFromInitial://load in first number
            if(buttonType==3 && buttonVal==1){//clear
              CALC_state=Initial;
            }
            else if(buttonType==1 && buttonVal==5){//equals
              CALC_state==TFromInitial;
            }
            else if(buttonType==2){//if number
              CALC_state==TFromInitial;
            }
            else if(buttonType==1 && buttonVal!=5){//any op other then equals
              CALC_state==Transition;
            }
            else{
              CALC_state=TFromInitial;
            }
            break;
        case Transition://first op
          if(buttonType==3 && buttonVal==1){//clear
            CALC_state=Initial;
          }
          else if(buttonType==1 && buttonVal==5){//equals
            CALC_state==Transition;
          }
          else if(buttonType==2){//if number
            CALC_state==TFromTransition;
          }
          else if(buttonType==1 && buttonVal!=5){//any op other then equals
            CALC_state==Transition;
          }
          else{
            CALC_state=Transition;
          }
            break;
        case TFromTransition://second number
            if(buttonType==3 && buttonVal==1){//clear
              CALC_state=Initial;
            }
            else if(buttonType==1 && buttonVal==5){//equals
              CALC_state==Equal;
            }
            else if(buttonType==2){//if number
              CALC_state==TFromTransition;
            }
            else if(buttonType==1 && buttonVal!=5){//any op other then equals
              CALC_state==TFromTransition;
            }
            else{
              CALC_state=TFromTransition;
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
            break;
        case TFromInitial:
            F=F*10+buttonVal;
            OP1=OP1;
            S=S;
            T=T;
            D=F;
            break;


        case Transition:
            F=F;
            OP1=buttonVal;
            S=F;
            T=T;
            D=F;
            break;
        case TFromTransition:
            F=F;
            OP1=OP1;
            S=S*10+buttonVal;
            T=T;
            D=S;
            break;
        case Equal:
            if(OP1 == 1){
              if(F+S>OVERFLOW){
                D=0;//error message
              }
              else{
                T=F+S;//non overflow
              }
            }
            else if(OP1 == 2){
              T=F-S;
            }
            else if(OP1 == 3){
              if(S==0){
                D = 0;//error message
              }
              else{
                T=F/S;//if no divide by 0
              }
            }
            else if(OP1 == 4){
              if(F*S>OVERFLOW){
                D=0;//error message
              }
              else{
                T=F*S;//if no mulitply
              }
            }
            EqualCounter++;
            break;
        default:
            CALC_state = Initial;
    }

}
