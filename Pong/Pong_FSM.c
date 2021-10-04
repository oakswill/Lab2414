#include "porta_in.h"
#include "portb_out.h"
#include "PONG_FSM.h"
#include <inttypes.h>
#include <stdio.h>
#include<stdlib.h>
#include "timer1.h"

static enum PONG_States
{PONG_SMStart, PONG_Initial, PONG_Wait, PONG_RightB, PONG_LeftB, PONG_MissL, PONG_MissR} PONG_State;
extern int period;
int gamesPlayed = 0;
int r;
int pos;
static uint16_t output=0x10;

void tickFct_PONG(int Right,int Left)
{

    int rbtn = Right;
    int lbtn = Left;
	switch (PONG_State) {
		case PONG_SMStart: //starts the fsm
			PONG_State = PONG_Initial;
			break;
		case PONG_Initial: //initial state
			PONG_State = PONG_Wait;
			break;
		case PONG_Wait: //waiting for someone to start
			if(lbtn==2&&output==0x01){
				PONG_State = PONG_RightB;
			}
			else if(rbtn==1&&output==0x100){
				PONG_State = PONG_LeftB;
			}
            else{
                PONG_State = PONG_Wait;
            }
			break;
		case PONG_RightB:
            if(output==0x100 && rbtn==1 && period>100){
              period = period-25;
				PONG_State = PONG_LeftB;
			}
			else if((output!=0x100 && rbtn==1)  ||  (output>0x100)){
				PONG_State = PONG_MissR;
			}
            else{
                PONG_State = PONG_RightB;
            }
			break;
case PONG_LeftB:
            if(output==0x01 && lbtn==2){
                if(period>100){
                period = period-50;
                }
				PONG_State = PONG_RightB;
			}
			else if((output!=0x01 && lbtn==2)  ||  (output<0x01)){
				PONG_State = PONG_MissL;
			}
            else{
                PONG_State = PONG_LeftB;
            }
			break;
		case PONG_MissL:
			break;
        case PONG_MissR:
			break;

		default:
			PONG_State = PONG_Initial;
			break;
	}

	switch (PONG_State) {
		case PONG_Initial:
            r = timer1_read()&0x01;
            if(r==0){
              output=0x01;
            }
			else{
                output=0x100;
            }
            gamesPlayed = 0;
			portb_out_write(output);
			break;
		case PONG_Wait:
            portb_out_write(output);
            break;
		case PONG_RightB:
            if(output==0x00){
               output = 0x01;
               pos = 0;
            }
            else{
                if(pos++==3)
                {
                    if(output==0x20){
                        output= output << 2;
                        pos = 0;
                    }
                    else{
                        output = output << 1;
                        pos = 0;
                    }

                }
            }
			portb_out_write(output);
			break;
		case PONG_LeftB:
            if(output==0x00){
               output = 0x100;
               pos = 0 ;
            }
            else{
                if(pos++==3)
                {
                    if(output==0x80){
                    output=output>>2;
                    pos = 0;
                    }
                    else{
                    output = output >> 1;
                    pos = 0;
                    }
                }
			}
			portb_out_write(output);
			break;
		case PONG_MissL:
			output = (gamesPlayed&0x80);
			portb_out_write(output);
			break;
        case PONG_MissR:
			output = gamesPlayed&0x01;
			portb_out_write(output);
			break;
		default:
			output = 0x00;
			break;
	}
}
