		
#include "DATA_TYPE.h"
#include "Config.h"



const ultrasonic_t ultrasonic_array[]={
							  /*{ID,echo_pin,Triger_pin}*/
  /*0*/                         {ID_UlterSonic,9,8}
        
									  };


/*****************************************************/                             

const IR_sensor_t IR_sensor_array[]={
							/*{ID,digital_pin,analog_pin}*/
  /*0*/                       {ID_Right_IR , 47 ,NULL},
  /*1*/                       {ID_Center_IR, 49 ,NULL},
  /*2*/                       {ID_Left_IR  , 51 ,NULL},
  /*3*/						  {ID_Right_Stop_IR  , 53 ,NULL},
  /*4*/						  {ID_Left_Stop_IR  , 50 ,NULL}
									};
/*****************************************************/
                      
 const Motor_t motor_array[]={
					/*{motor_driner_name,motor_ID,Right_pin,left_pin,pwm_pin}*/
  /*0*/               {Driver_Relay,ID_Right_Motor,4,2,NULL},
  /*1*/               {Driver_Relay,ID_Left_Motor,3,5,NULL},
  /*2*/				  {Driver_Relay,ID_Lift_Motor,10,11,NULL}
							 };
/*****************************************************/

const limit_switch_sensor_t  limit_switch_array[]={
	
				    /*{ID,digital_pin}*/
  /*0*/               {ID_Upper_Limit_Switch,42},
  /*1*/               {ID_Down_Limit_Switch,44}
	
	
	
	
};