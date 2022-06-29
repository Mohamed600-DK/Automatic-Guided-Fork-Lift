#include "APP.h"

/*************************************************************************************/
/*************************************************************************************/
void  setup () {
Serial.begin(115200);
Serial1.begin(115200);

APP_FUNs_Initlization();
Serial.println("finish_inilization");
delay(100);
}

void  loop() {
  
int command=0;

if (Serial1.available() > 0) {
  command = Serial1.read(); 
}

  if(command=='A')
    {
      while(1){APP_Automatic_Control();if (Serial1.available() > 0) {command = Serial1.read();}if(command =='S'){break;}}
      
    }
  else
    {
      APP_Manual_Control(command);
        
    }
      
/****************************************************************************************************************************************************************************/  
}
