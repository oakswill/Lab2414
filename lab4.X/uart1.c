/* 
 * File:   uart1.c
 * Author: shmuylob
 *
 * Created on September 28, 2021, 1:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <inttypes.h>
#include <plib.h>




/*
 * 
 */

void uart1_init(uint32_t baudrate) {
    
  OpenUART1( UART_EN | UART_NO_PAR_8BIT,UART_TX_ENABLE | UART_RX_ENABLE, (40000000/(16*baudrate))-1);
    
    //ANSELA = 0; //digital
    //TRISA = 0x01; //input
    PPSInput(3,U1RX,RPA2);//U1RXR RXD group 3]
    PPSOutput(1,RPA0,U1TX);//TXD 
}

uint8_t uart1_txrdy() {
    return  !BusyUART1();


}

void uart1_txwrite(char c) {
   int a = c;
    WriteUART1(a);

}

void uart1_txwrite_str(char *cp){
  
    int i;
    for ( i = 0; cp[i] != NULL; i++) {
        while(uart1_txrdy() == 0 ) {
        //do nothing
        }
        uart1_txwrite(*(cp+i));
    }

}

uint8_t uart1_rxrdy(){
    return DataRdyUART1();
}

uint8_t uart1_rxread(){
    uint8_t a = ReadUART1();
    return a;
}

