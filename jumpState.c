#include <xc.h>
#include "ztimer.h"

extern int didJump;
extern int airTime;
extern int maxForceLand;
extern int maxForceJump;
extern int didLand;
int threshhold = 20;

uint32_t t1, t2;
#define DEBOUNCE_PERIOD 50


static enum debounce_States { debounce_NOTJUMP, debounce_MAYBEJUMP, debounce_INAIR, debounce_MAYBELAND, debounce_LAND } debounce_State;


void InitFSM_jump() {
    debounce_State = debounce_NOTJUMP;
    didJump = 0;
    airTime = 0;
    maxForceLand = 0;
    maxForceJump = 0;
    didLand = 0;
    zTimerOn();
}

void tickFct_jump(uint8_t sensor)
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
                debounce_State = debounce_JUMP;
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
