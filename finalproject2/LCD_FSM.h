#ifndef LCD_FSM_H
#define LCD_FSM_H
#include <inttypes.h>
#include <xc.h>
#include "jumpState.h"
#include "jumpState1.h"

extern void InitFSM_lcd();
extern void tickFct_lcd(int button);

extern int state;
extern int resetJumpFSM;
extern int updateScreen;

#endif