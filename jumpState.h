#ifndef JUMPSTATE_H
#define JUMPSTATE_H
#include <inttypes.h>
extern void InitFSM_jump();
extern void tickFct_jump(uint8_t sensor);
extern int didJump;
extern int airTime;
extern int maxForceLand;
extern int maxForceJump;
extern int didLand;
#endif
