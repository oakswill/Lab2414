#include <stdint.h>
#include <xc.h>
#include <inttypes.h>

#ifndef TIMER1_H
#define	TIMER1_H

#define CLOCK_FREQ 40000000

#define PRESCALE 256

extern void timer1_init();

extern uint16_t timer1_read();

extern uint16_t timer1_elapsed_ms(uint16_t t1, uint16_t t2 );
