#include <xc.h>
#include "ztimer.h"
#include <inttypes.h>

extern int didJump=0;
extern int airTime=0;
extern int maxForceLand=0;
extern int maxForceJump=0;
extern int didLand=0;
extern int displayable=0;
int threshhold = 80;

uint32_t t1, t2;


static enum debounce_States { debounce_NOTJUMP, debounce_MAYBEJUMP, debounce_INAIR, debounce_MAYBELAND, debounce_LAND } debounce_State;


void InitFSM_jump() {
    debounce_State = debounce_NOTJUMP;
    didJump = 0;
    airTime = 0;
    maxForceLand = 0;
    maxForceJump = 0;
    didLand = 0;
    displayable=0;
    zTimerOn();
}

void rst() {
    debounce_State = debounce_NOTJUMP;
    didJump = 0;
    airTime = 0;
    maxForceLand = 0;
    maxForceJump = 0;
    didLand = 0;
    displayable=0;
}

void tickFct_jump(int sensor)
{



    switch (debounce_State) {
        case debounce_NOTJUMP:
            if(sensor>maxForceJump){
                maxForceJump=sensor;
            }
            if(sensor<threshhold){
                debounce_State = debounce_MAYBEJUMP;
            }
            else{
                debounce_State = debounce_NOTJUMP;
            }
            break;
        case debounce_MAYBEJUMP:
            if(sensor>maxForceJump){
                maxForceJump=sensor;
            }
            if(sensor<threshhold){
                debounce_State = debounce_INAIR;
                t1 = zTimerReadms();
                didJump=1;
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
                airTime = zTimerReadms()-t1;
                t2=zTimerReadms();
                didLand=1;
                if(sensor>maxForceLand){
                    maxForceLand=sensor;
                }
            }
            else{
                debounce_State = debounce_INAIR;
            }
            break;
        case debounce_LAND:
            if(zTimerReadms()-t2<1000){
                debounce_State = debounce_LAND;
                if(sensor>maxForceLand){
                    maxForceLand=sensor;
                }
            }
            else{
                debounce_State = debounce_NOTJUMP;
                displayable=1;//when we get main working we need to only reset when given input so 
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
