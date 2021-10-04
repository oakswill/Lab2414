#include <inttypes.h>


enum Right_States {notPressed, maybePressed, pressed, maybeNotPressed} Right_State;
extern int Rout;
void buttondebounceR(uint8_t b){
  uint8_t btn;
  if((b&0x2)==0){
    btn=1;
  }
  else {btn=0;
  }
  int btnp;
  switch (Right_State){

    case notPressed:
    if(!btn){
      Rout=0;
      Right_State=notPressed;
    }
    else{
      Right_State=maybePressed;
    }
    break;
    case maybePressed:
    if(!btn){
      Right_State=notPressed;
    }
    else{
      Rout=1;
      Right_State=pressed;
    }
    break;


    case pressed:
    if(!btn){
      Right_State=maybeNotPressed;
    }
    else {
      Right_State=pressed;
    }
    break;
    case maybeNotPressed:
    if(!btn){

      Right_State=notPressed;
    }
    else {
      Right_State=pressed;
    }
    break;
    default:
    Right_State = notPressed;
    break;
  }
}
