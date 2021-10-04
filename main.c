#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"
#include "porta_in.h"
#include "PONGLED_FSM.h"
#include "timer1.h"

int period = 300;
int Lout;
int Rout;
int main() {
	porta_in_init();
	uint16_t ta1, ta2, ta3, ta4;
	portb_out_init();
	timer1_init();
	ta1 = timer1_read();
    ta3 = timer1_read();
	while (1) {
		ta2 = timer1_read();
        ta4 = timer1_read();
        if (timer1_ms_elapsed(ta1, ta2) > period) {
            //buttondebounceR(porta_in_read());
            //buttondebounceL(porta_in_read());
            tickFct_PONG(Rout,Lout);//changed
            ta1 = ta2;
         }
        if (timer1_ms_elapsed(ta3,ta4)>50){
            buttondebounceR(porta_in_read());
            buttondebounceL(porta_in_read());
        }
    }
}
