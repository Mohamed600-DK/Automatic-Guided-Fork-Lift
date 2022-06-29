
#ifndef FUNCTION_H
#define FUNCTION_H

/*******************************************************************************************/
void 			   Ultasonict_init(void);
float 			   dis_cal_ult(int trig,int echo);
/*******************************************************************************************/
void 			   Motor_init(void);
void 			   Motor_control(int ID,Motor_direction_t Dirdtion,int Speed_persentage);
/*******************************************************************************************/
void 			   IR_voidInti(void);
reflectedlight_t   IR_reflectedlight_tGet_reflectedlight(char Copy_IR_sensor_ID);
/*******************************************************************************************/
void 			   Limit_Switch_init(void);
boolean 		   Limit_Switch_Value(int ID);
/*******************************************************************************************/
#endif