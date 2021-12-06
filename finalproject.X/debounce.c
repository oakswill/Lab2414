#include <xc.h>
#include "debounce.h"


#define DEBOUNCE_PERIOD 50
//need to take external function from porta in to get the input
static enum debounce_States { debounce_NOPUSH, debounce_MAYBEPUSH, debounce_PUSHED, debounce_MAYBENOPUSH } debounce_State;

extern uint8_t DebouncedKeyPress = 0;
extern uint8_t statename = 0;

//int counter = 0;

void InitFSM_debounce() {
    debounce_State = debounce_NOPUSH;
    DebouncedKeyPress = 0;
    statename = 0;
}

void tickFct_debounce(uint8_t btn)
{



    switch (debounce_State) {
        case debounce_NOPUSH:
            if (btn>60){debounce_State = debounce_MAYBEPUSH;}
            else {debounce_State = debounce_NOPUSH;}
            break;
        case debounce_MAYBEPUSH:
            if (btn>60){DebouncedKeyPress=1;debounce_State = debounce_PUSHED;}
            else {debounce_State = debounce_NOPUSH;}
            break;
        case debounce_PUSHED:
            if (btn>60){debounce_State = debounce_PUSHED;}
            else {debounce_State = debounce_MAYBENOPUSH;}
            break;
        case debounce_MAYBENOPUSH:
            if (btn>60){debounce_State = debounce_PUSHED;}
            else {debounce_State = debounce_NOPUSH;}
            break;
    }
    switch (debounce_State) {
            case debounce_NOPUSH:
               // DebouncedKeyPress = 0;
                 //statename = 0;
                //counter = 0;
                //DebouncedKeyPress=btn;
                break;
            case debounce_MAYBEPUSH:
               // DebouncedKeyPress = 0; 
                //statename = 1;
                //counter = 0;
                //DebouncedKeyPress=btn;
                break;
            case debounce_PUSHED:
               // DebouncedKeyPress=0; 
                //statename = 2;
                break;
            case debounce_MAYBENOPUSH:
                //DebouncedKeyPress = btn;
                //DebouncedKeyPress = 0; 
                //statename = 3;
               // counter = 0;
                break;
        }
}
