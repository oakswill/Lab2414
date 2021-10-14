#include <xc.h>
#include <inttypes.h>                                                                                   
#include <stdio.h> // for sprintf
#include "uart1.h"


#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

// Module includes here
// Number of iterations for testing. You may need to play with this
// number. If it is too short, you may not get a very accurate measure
// of performance. Too long and you will have to wait forever.
#define NUM_ITERATIONS 1000
// This is the number of times you repeat the operation within the
// loop. You want to repeat enough times that the loop overhead is
// small for the simplest operations.
#define NUM_REPS 10
uint8_t buffer[64];
void test_uint8_mult()
{
 uint32_t i;
 uint32_t i1, i2, i3;
 i1 = 15;
 i2 = 26;
 for (i=0; i<NUM_ITERATIONS; i++)
 {
 // Make sure NUM_REPS is the same as the number
 // of repeated lines here.
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 i3 = i1+i2;
 }
}
void main()
{
 zTimerOn();
 uart1_init(9600);
 uint32_t t1, t2;
 // !!! Add code: Initialize modules and turn on interrupts
 uart1_txwrite_str("Performance Summary: Time per operation statistics\r\n");
 // Test multiplying bytes
 t1 = zTimerReadms();
 test_uint8_mult();
 t2 = zTimerReadms();
 uart1_txwrite_str("Warm tidings from the desk of Boris and Will, Happy Hannukah\r\nWarm tidings from the desk of Boris and Will, Happy Hannukah\r\nWarm tidings from the desk of Boris and Will, Happy Hannukah\r\nWarm tidings from the desk of Boris and Will, Happy Hannukah\r\nWarm tidings from the desk of Boris and Will, Happy Hannukah\r\n");
 //uart1_txwrite('a');
 // uart1_rxrdy();
 // Print timing result. Doubles OK here. Not time critical code.
 
 sprintf(buffer, "UINT8 MULT: %.06f us per operation\r\n",
 (double)(t2-t1)/
 (double)NUM_ITERATIONS /(double)NUM_REPS*1000.0);
 uart1_txwrite_str(buffer);
 // Add code to test other sizes and operators
 // ...

//uart1_txwrite_str('The quick brown fox preffered christmas!');
     
 
 while (1){
     uint8_t a;
     if (uart1_rxrdy()) {
        a = uart1_rxread();
        if(a>='a'&&a<='z'){uart1_txwrite(a-'a'+'A');}
        else if(a>='A'&&a<='Z'){uart1_txwrite(a-'A'+'a');}
        else{uart1_txwrite(a);}
     }

 } // When done, wait forever.
}
