#ifndef JUMPSTATE1_H
#define JUMPSTATE1_H
#include <inttypes.h>
#include <xc.h>
#include "ztimer.h"
extern void InitFSM_jump1();
extern void rst1();
extern void tickFct_jump1(int sensor);
extern int didJump1;
extern int airTime1;
extern int maxForceLand1;
extern int maxForceJump1;
extern int didLand1;
extern int displayable1;
#endif