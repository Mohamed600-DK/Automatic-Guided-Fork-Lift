#include "Arduino.h"
#include "DATA_TYPE.h"
#include "Config.h"
#include "Function.h"




APP_FUNs_Initlization(void)
{
	/*Make inilization for all Functions in our project here*/
	
 //Ultasonict_init();
   Motor_init();
   IR_voidInti();
   Limit_Switch_init();
}

/****************************************************************************************************************************************************************************************************
	Motion Code										
*****************************************************************************************************************************************************************************************************/



void APP_Automatic_Control(void)
{
	
    /*Make sure that the robot alwasy in the center of the balck line*/
/****************************************************************************************************************************************************************************/  

		if  (IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==White && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==Black && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==White)
			{
				
				Motor_control(ID_Right_Motor,Forword,100);
				Motor_control(ID_Left_Motor,Forword,100);
				Serial.println("Forword");
			}
    else if (IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==Black  && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==White &&
			 IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==White)

			{				
				Motor_control(ID_Right_Motor,BackWord,0);
				Motor_control(ID_Left_Motor,Forword,100);
				Serial.println("Right");
			}
	else if (IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==Black  && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==Black &&
			 IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==White)

			{				
				Motor_control(ID_Right_Motor,BackWord,0);
				Motor_control(ID_Left_Motor,Forword,100);
				Serial.println("Right");
			}
    else if (IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==White  && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==White && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==Black)

			{		
				Motor_control(ID_Right_Motor,BackWord,0);
				Motor_control(ID_Left_Motor,Forword,100);
				Serial.println("Left");
			}  
    else if (IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==White  && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==Black && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==Black)

			{		
				Motor_control(ID_Right_Motor,BackWord,0);
				Motor_control(ID_Left_Motor,Forword,100);
				Serial.println("Left");
			}			
    else if (IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==White  && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==White && 
			 IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==White)

			{
				Motor_control(ID_Right_Motor,BackWord,25);
				Motor_control(ID_Left_Motor,BackWord,25);
				Serial.println("Back");
				if(IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==Black)
				{
					Motor_control(ID_Right_Motor,BackWord,0);
					Motor_control(ID_Left_Motor,Forword,100);
					Serial.println("Left");				
				}
				else if(IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==Black)
				{				
					Motor_control(ID_Right_Motor,BackWord,0);
					Motor_control(ID_Left_Motor,Forword,100);
					Serial.println("Right");
				}
				while(IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==White&&(IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==White||IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==White));
			}  
    else
			{ 		
			   Motor_control(ID_Right_Motor,Stop,0);
			   Motor_control(ID_Left_Motor,Stop,0);
			   Serial.println("Error");
			}  
/****************************************************************************************************************************************************************************************************
	lifting code										
*****************************************************************************************************************************************************************************************************/

	
	if(IR_reflectedlight_tGet_reflectedlight(ID_Right_IR)==Black  && 
	   IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)==Black && 
	   IR_reflectedlight_tGet_reflectedlight(ID_Left_IR)==Black)
		{
			    /**UP Section**/
			if(Limit_Switch_Value(ID_Upper_Limit_Switch)==0 &&Limit_Switch_Value(ID_Down_Limit_Switch)==1)
			{
				Motor_control(ID_Right_Motor,Forword,25);Motor_control(ID_Left_Motor,Forword,25);
				
				delay(1000);
				
				Motor_control(ID_Right_Motor,Stop,0);Motor_control(ID_Left_Motor,Stop,0);
				
				Motor_control(ID_Lift_Motor,Up,100);
				while( Limit_Switch_Value(ID_Upper_Limit_Switch)==0);
				Motor_control(ID_Lift_Motor,Stop,0);
				
				Motor_control(ID_Left_Motor,BackWord,50);Motor_control(ID_Right_Motor,Forword,100);
				while(IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)!=Black);
				Motor_control(ID_Right_Motor,Stop,0);Motor_control(ID_Left_Motor,Stop,0);
				
				Motor_control(ID_Right_Motor,Forword,50);Motor_control(ID_Left_Motor,Forword,50);	

				Serial.println("Fork_UP");
			}
				/**Down Section**/
			else if (Limit_Switch_Value(ID_Upper_Limit_Switch)==1 &&Limit_Switch_Value(ID_Down_Limit_Switch)==0)
			{
				
				Motor_control(ID_Right_Motor,Forword,25);Motor_control(ID_Left_Motor,Forword,25);
				
				delay(1000);
				
				Motor_control(ID_Right_Motor,Stop,0);Motor_control(ID_Left_Motor,Stop,0);
				
				Motor_control(ID_Lift_Motor,Down,100);
				while( Limit_Switch_Value(ID_Down_Limit_Switch)==0);
				Motor_control(ID_Lift_Motor,Stop,0);
				
				Motor_control(ID_Left_Motor,BackWord,50);Motor_control(ID_Right_Motor,Forword,100);
				while(IR_reflectedlight_tGet_reflectedlight(ID_Center_IR)!=Black);
				Motor_control(ID_Right_Motor,Stop,0);Motor_control(ID_Left_Motor,Stop,0);
				
				Motor_control(ID_Right_Motor,Forword,50);Motor_control(ID_Left_Motor,Forword,50);
				Serial.println("Fork_DOWN");
			}
			else
			{
				Motor_control(ID_Lift_Motor,Down,100);
				while(Limit_Switch_Value(ID_Down_Limit_Switch)==0);
				Motor_control(ID_Lift_Motor,Stop,0);					
			}
	
		}
	else
		{
			Serial.println("Error in rotate and lifting");
			Motor_control(ID_Right_Motor,Stop,0);Motor_control(ID_Left_Motor,Stop,0);Motor_control(ID_Lift_Motor,Stop,0);	
		}	





	
	
}

APP_Manual_Control(int WIFI_Command)
{
	
	static Motor_direction_t lifting_motor_statuse;
	boolean Upper_Switch;
	boolean Lower_Switch;
	Upper_Switch=Limit_Switch_Value(ID_Upper_Limit_Switch);
	Lower_Switch=Limit_Switch_Value(ID_Down_Limit_Switch);
	
	switch (WIFI_Command) 
            {
            case 'F':Motor_control(ID_Right_Motor,Forword,50);Motor_control(ID_Left_Motor,Forword,50);Serial.println('F');break;
            case 'B':Motor_control(ID_Right_Motor,BackWord,50);Motor_control(ID_Left_Motor,BackWord,50);Serial.println('B');break;
            case 'L':Motor_control(ID_Left_Motor,BackWord,0);Motor_control(ID_Right_Motor,Forword,100);Serial.println('L');break;
            case 'R':Motor_control(ID_Right_Motor,BackWord,0);Motor_control(ID_Left_Motor,Forword,100);Serial.println('R');break;
            case 'U':if(Upper_Switch==0){Motor_control(ID_Lift_Motor,Up,100);lifting_motor_statuse=Up;}Serial.println('U');break;
            case 'D':if(Lower_Switch==0){Motor_control(ID_Lift_Motor,Down,100);lifting_motor_statuse=Down;}Serial.println('D');break;
            case 'S':Motor_control(ID_Right_Motor,Stop,0);Motor_control(ID_Left_Motor,Stop,0);break;  
			case 'O':Motor_control(ID_Lift_Motor,Stop,0);break;  
			default :
					if(Upper_Switch==1 &&lifting_motor_statuse==Up){Motor_control(ID_Lift_Motor,Stop,0);}
					else if(Lower_Switch==1 &&lifting_motor_statuse==Down){Motor_control(ID_Lift_Motor,Stop,0);}	
					break;					
             }
}
