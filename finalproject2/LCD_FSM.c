#include <xc.h>
#include <inttypes.h>
#include "jumpState.h"
#include "jumpState1.h"

extern int state=0;
extern int resetJumpFSM=0;

static enum lcd_States { lcd_Select, lcd_Excercising, lcd_DisplayResults} lcd_State;

void InitFSM_lcd() {
  lcd_State=lcd_Select;
  resetJumpFSM=0;
  state=1;
}
//button 0 = empty
//button 1 = jump
//button 2 = jump again
//button 3 = back to menu

//displayable will be 1 when the jumping is done
//should take the displayable of both shoes and them together
void tickFct_lcd(int button){
  switch(lcd_State){
    case lcd_Select:
      if(button==1){
        state =2;
        //resetJumpFSM=1;
        rst();
        rst1();
        lcd_State=lcd_Excercising;
      }
      else{
        lcd_State=lcd_Select;
      }
      break;
    case lcd_Excercising:
      if(displayable1&&displayable){
        state=3;
        lcd_State=lcd_DisplayResults;
      }
      else{
        lcd_State=lcd_Excercising;
      }
      break;
    case lcd_DisplayResults:
      if(button==2){
        state = 2;
        //resetJumpFSM=1;
        rst();
        rst1();
        lcd_State=lcd_Excercising;
      }
      else if(button==3){
        state =1;
        rst();
        rst1();
        lcd_State=lcd_Select;
      }
      else{
        lcd_State=lcd_DisplayResults;
      }
      break;
  }
  switch(lcd_State){
    case lcd_Select:
      break;
    case lcd_Excercising:
      break;
    case lcd_DisplayResults:
      break;
  }


}
