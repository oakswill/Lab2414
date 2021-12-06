#ifndef DEBOUNCE_H
#define DEBOUNCE_H
#include <inttypes.h>
extern void InitFSM_debounce();
extern void tickFct_debounce(uint8_t btn);
extern uint8_t DebouncedKeyPress;
extern uint8_t statename;
extern int state;
#endif