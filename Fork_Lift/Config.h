#ifndef CONFIG_H
#define CONFIG_H

#ifndef NULL
#define NULL   0
#endif

#define ultrasonic_Sensors_Numbers		1
#define IR_Sensors_Numbers				5
#define Motor_Numbers					3
#define limit_switch_Numbers			2

#define ID_UlterSonic           0


#define ID_Right_IR            0
#define ID_Center_IR           1
#define ID_Left_IR             2
#define ID_Right_Stop_IR       3
#define ID_Left_Stop_IR        4

#define ID_Upper_Limit_Switch	0
#define ID_Down_Limit_Switch	1


#define Driver_L293N        	0
#define Driver_BTS7960          1
#define Driver_Relay 	        2

#define ID_Right_Motor        0
#define ID_Left_Motor         1
#define ID_Lift_Motor         2

#define Timer_time_US		  1000000
#define Encoder_Pin			2
#define DPP					18			/* Degree Per Pluse*/
#define DPR					360			/* Degree Per Revolution*/



/*****************************************************/
/*****************************************************/
/*****************************************************/

extern const ultrasonic_t           ultrasonic_array[ultrasonic_Sensors_Numbers];                          

extern const limit_switch_sensor_t  limit_switch_array[limit_switch_Numbers];  

extern const IR_sensor_t            IR_sensor_array[IR_Sensors_Numbers];

extern const Motor_t                motor_array[Motor_Numbers];






#endif