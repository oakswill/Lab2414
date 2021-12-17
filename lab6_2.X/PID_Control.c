
#include <xc.h>
#include <inttypes.h>


static enum PID_States { INIT,CONTROL } PID_State;
int Actuator;
int ActualPrev;
int Integ;
int Error;
int Deriv;
int IntegMax;
int IntegMin;

int Kp;
int Kd;
int Ki;


void InitFSM_Control() {
    PID_State=INIT;
    Actuator=0;
    ActualPrev=0;
    Integ=0;
    IntegMax=0;
    IntegMin=10000000;
}

void tickFct_Control(int Actual, int Desired)
{
    switch (PID_State) {
        case(INIT):
            PID_State = CONTROL;
        break;
        case(CONTROL):
            PID_State = CONTROL;
        break;
    }
    switch (PID_State) {
        case(INIT):
            Actuator=0;
            ActualPrev=0;
            Integ=0;
        break;
        case(CONTROL):
            Error=Desired-Actual;
            Deriv = Actual - ActualPrev;
            Integ=Integ+Error;
            if(Integ<IntegMin){IntegMin=Integ;}
            if(Integ>IntegMax){IntegMax=Integ;}
            Actuator =Kp*Error + Ki*Integ - Kd*Deriv;
            ActualPrev=Actual;
        break;
        }
}
