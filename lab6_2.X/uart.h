#ifndef UART_H
#define UART_H
#include <plib.h>
#include <inttypes.h>

extern void uart1_init(uint32_t baudrate);

extern uint8_t uart1_txrdy();

extern void uart1_txwrite(char c);

extern void uart1_txwrite_str(char *cp);

extern uint8_t uart1_rxrdy();

extern uint8_t uart1_rxread();

 extern uint16_t capture1;

#endif