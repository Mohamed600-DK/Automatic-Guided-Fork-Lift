#ifndef DATA_TYPE_H
#define DATA_TYPE_H

typedef struct 
{
  int ID;
  int echo_pin;
  int Triger_pin;
  
}ultrasonic_t;

typedef struct 
{
  int ID;
  int digital_pin;
  int analog_pin;
  
}IR_sensor_t;

typedef struct 
{
  int ID;
  int digital_pin;
  
}limit_switch_sensor_t;

typedef enum{
  
  White=0,
  Black=1

}reflectedlight_t;


typedef struct 
{
  char motor_driver_name;
  int ID;
  int Right_pin;
  int left_pin;
  int pwm_pin;
  
}Motor_t;

typedef enum
{
  Forword=0,
  BackWord=1,
  Stop=2,
  Up=3,
  Down=4
}Motor_direction_t;




#endif