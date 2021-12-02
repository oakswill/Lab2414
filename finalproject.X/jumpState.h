#ifndef JUMPSTATE_H
#define JUMPSTATE_H
#include <inttypes.h>
#include <xc.h>
#include "ztimer.h"
extern void InitFSM_jump();
extern void tickFct_jump(int sensor);
extern int didJump;
extern int airTime;
extern int maxForceLand;
extern int maxForceJump;
extern int didLand;
#endif