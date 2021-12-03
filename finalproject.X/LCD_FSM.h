#ifndef LCD_FSM_H
#define LCD_FSM_H
#include <inttypes.h>
#include <xc.h>

extern void InitFSM_lcd();
extern void tickFct_lcd(int button, int displayable1, int displayable2);

extern int state;
extern int resetJumpFSM;

#endif
