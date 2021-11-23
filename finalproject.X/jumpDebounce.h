#ifndef JUMPDEBOUNCE_H
#define JUMPDEBOUNCE_H
#include <inttypes.h>
extern void InitFSM_debounce();
extern void tickFct_debounce(uint8_t sensor);
extern int didJump;
extern int airTime;
extern int maxForceLand;
extern int maxForceJump;
extern int didLand;
#endif