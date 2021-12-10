#include <xc.h>
#include "ztimer.h"
#include <inttypes.h>

extern int didJump1=0;
extern int airTime1=0;
extern int maxForceLand1=0;
extern int maxForceJump1=0;
extern int didLand1=0;
extern int displayable1=0;
int threshhold = 100;

uint32_t t1, t2;


static enum debounce_States { debounce_NOTJUMP, debounce_MAYBEJUMP, debounce_INAIR, debounce_MAYBELAND, debounce_LAND } debounce_State;


void InitFSM_jump1() {
    debounce_State = debounce_NOTJUMP;
    didJump1 = 0;
    airTime1 = 0;
    maxForceLand1 = 0;
    maxForceJump1 = 0;
    didLand1 = 0;
    displayable1=0;
    zTimerOn();
}

void rst1() {
    debounce_State = debounce_NOTJUMP;
    didJump1 = 0;
    airTime1 = 0;
    maxForceLand1 = 0;
    maxForceJump1 = 0;
    didLand1 = 0;
    displayable1=0;
}

void tickFct_jump1(int sensor)
{



    switch (debounce_State) {
        case debounce_NOTJUMP:
            if(sensor>maxForceJump1){
                maxForceJump1=sensor;
            }
            if(sensor<threshhold){
                debounce_State = debounce_MAYBEJUMP;
            }
            else{
                debounce_State = debounce_NOTJUMP;
            }
            break;
        case debounce_MAYBEJUMP:
            if(sensor>maxForceJump1){
                maxForceJump1=sensor;
            }
            if(sensor<threshhold){
                debounce_State = debounce_INAIR;
                t1 = zTimerReadms();
                didJump1=1;
            }
            else{
                debounce_State = debounce_NOTJUMP;
            }
            break;
        case debounce_INAIR:
            if(sensor>threshhold){
                debounce_State = debounce_MAYBELAND;
            }
            else{
                debounce_State = debounce_INAIR;
            }
            break;
        case debounce_MAYBELAND:
            if(sensor>threshhold){
                debounce_State = debounce_LAND;
                airTime1 = zTimerReadms()-t1;
                t2=zTimerReadms();
                didLand1=1;
                if(sensor>maxForceLand1){
                    maxForceLand1=sensor;
                }
            }
            else{
                debounce_State = debounce_INAIR;
            }
            break;
        case debounce_LAND:
            if(zTimerReadms()-t2<1000){
                debounce_State = debounce_LAND;
                if(sensor>maxForceLand1){
                    maxForceLand1=sensor;
                }
            }
            else{
                debounce_State = debounce_LAND;
                displayable1=1;//when we get main working we need to only reset when given input so 
                //stay displayinf as opposed to notjump ie stay in land until its reset then reset all the values
                //cant do yet becuase do not have main module FSM for the lcd built up yet
            }
            break;
    }
    switch (debounce_State) {
            case debounce_NOTJUMP:

                break;
            case debounce_MAYBEJUMP:

                break;
            case debounce_INAIR:

                break;
             case debounce_MAYBELAND:

                break;
             case debounce_LAND:

                break;
        }
}

