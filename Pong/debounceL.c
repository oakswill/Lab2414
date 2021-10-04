#include <inttypes.h>


enum Left_States {notPressed, maybePressed, buttonPressed, buttonMaybeNotPressed} Left_State;
extern int Lout;
void buttondebounceL(uint8_t b){
    uint8_t btn;
    if((b&0x1)==0){
     btn=1;
    }
    else {btn=0;
    }
    int btnp;
switch (Left_State){

case notPressed:
	if(!btn){
        Lout=0;
	Left_State=notPressed;
}
    else{
    Left_State=maybePressed;
}
    break;
case maybePressed:
	if(!btn){
	Left_State=notPressed;
}
	else{
     Lout=2;
	Left_State=buttonPressed;
}
	break;


case buttonPressed:
	if(!btn){
	Left_State=buttonMaybeNotPressed;
}
	else {
	Left_State=buttonPressed;
}
break;
case buttonMaybeNotPressed:
	if(!btn){

	Left_State=notPressed;
}
	else {
	Left_State=buttonPressed;
}
break;
default:
	Left_State = notPressed;
	break;
}
}
