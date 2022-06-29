#include <Arduino.h>
#include<TimerOne.h>
#include "DATA_TYPE.h"
#include "Config.h"
#include "Function.h"

/*--------------------- Encoder Functions---------------------------------------*/

volatile unsigned int Pluse_count=0;
volatile unsigned int pps=0;



static void counting_pulse(void)
{
	Pluse_count++;	
}

static void Speed_calcualte_PPS(void)
{
    noInterrupts();
    pps = ((Pluse_count *1000000)/(Timer_time_US*1.0));
    //Serial.print("Speed (PPS): ");
    //Serial.println(pps);
    Pluse_count = 0;
    interrupts();

}


int Speed_calcualte_RPM(void)
{
	
	int RPM=0;
	
	RPM=(pps)*(DPP/DPR)*(60);
	
	
	
	return RPM;
}

void Encoder_init(void)
{

   attachInterrupt(digitalPinToInterrupt(Encoder_Pin), counting_pulse, RISING);
   Timer1.initialize(Timer_time_US);
   Timer1.attachInterrupt(Speed_calcualte_PPS);	
	
}





/*************************************************************************************/


/*--------------------- Limit Switch Functions---------------------------------------*/

void Limit_Switch_init(void)
{
	int Array_lengh;
  Array_lengh=(sizeof(limit_switch_array)/sizeof(limit_switch_sensor_t));

  for(int count=0;count<Array_lengh;count++)
  {
    pinMode(limit_switch_array[count].digital_pin,INPUT);   
  }
	
	
}

boolean Limit_Switch_Value(int ID)
{
	boolean result;
	
	result=digitalRead(limit_switch_array[ID].digital_pin);
	
	return result;
	
	
}

/*************************************************************************************/

/*--------------------- UltraSoinc Functions---------------------------------------*/
void Ultasonict_init(void)
{
  int Array_lengh;
  Array_lengh=(sizeof(ultrasonic_array)/sizeof(ultrasonic_t));

  for(int count=0;count<Array_lengh;count++)
  {
    pinMode(ultrasonic_array[count].echo_pin,INPUT);
    pinMode(ultrasonic_array[count].Triger_pin,OUTPUT);    
  }

}


/*************************************************************************************/

float dis_cal_ult(int trig,int echo)
{
  
   float time_signal ,time_travel,distance_cm;
   /**********************************/
    digitalWrite(trig,0);
    delayMicroseconds(5);
    digitalWrite(trig,1);
    delayMicroseconds(10);
    digitalWrite(trig,0);
    delayMicroseconds(10);
   /**********************************/
   
   /**********************************/
    time_signal=pulseIn(echo,1);
    /**********************************/
    
   // time_travel=time_signal/2.0;
    distance_cm=time_signal/58.0;
    

    
      return distance_cm;
}
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/


/*--------------------- Motor Functions---------------------------------------*/

void Motor_init(void)
{
  int Array_lengh;
  Array_lengh=(sizeof(motor_array)/sizeof(Motor_t));
  for(int count=0;count<Array_lengh;count++)
  {
    pinMode(motor_array[count].Right_pin,OUTPUT);
    pinMode(motor_array[count].left_pin,OUTPUT);
    pinMode(motor_array[count].pwm_pin,OUTPUT);
  }
Serial.println("finish_moter");

}

void Motor_control(int ID,Motor_direction_t Dirdtion,int Speed_persentage)
{
  if(Speed_persentage==0)
   {
	  Dirdtion=Stop;	   
   }
   int motor_speed=map(Speed_persentage,0,100,0,255);

    switch (Dirdtion)
    {
      case Forword :
			if(motor_array[ID].motor_driver_name==Driver_L293N)
			{
				
			  digitalWrite(motor_array[ID].Right_pin,HIGH);
			  digitalWrite(motor_array[ID].left_pin,LOW);
			  analogWrite(motor_array[ID].pwm_pin,motor_speed);	
			}
			else if(motor_array[ID].motor_driver_name==Driver_BTS7960)
			{
			  analogWrite(motor_array[ID].Right_pin,motor_speed);
			  analogWrite(motor_array[ID].left_pin,LOW);				
			}
			else if(motor_array[ID].motor_driver_name==Driver_Relay)
			{
			digitalWrite(motor_array[ID].left_pin,LOW);
			digitalWrite(motor_array[ID].Right_pin,HIGH);
			}
          break;  
      case BackWord:
 			if(motor_array[ID].motor_driver_name==Driver_L293N)
			{
				digitalWrite(motor_array[ID].Right_pin,LOW);
				digitalWrite(motor_array[ID].left_pin,HIGH);
				analogWrite(motor_array[ID].pwm_pin,motor_speed);
				
			}
			else if(motor_array[ID].motor_driver_name==Driver_BTS7960)
			{
				analogWrite(motor_array[ID].Right_pin,LOW);
			  analogWrite(motor_array[ID].left_pin,motor_speed);
			}
			else if(motor_array[ID].motor_driver_name==Driver_Relay)
			{
			  digitalWrite(motor_array[ID].Right_pin,LOW);
			  digitalWrite(motor_array[ID].left_pin,HIGH);
			}
          break;
      case Stop:
			if(motor_array[ID].motor_driver_name==Driver_L293N)
			{
				digitalWrite(motor_array[ID].Right_pin,LOW);
				digitalWrite(motor_array[ID].left_pin,LOW);
				analogWrite(motor_array[ID].pwm_pin,0);
				
			}
			else if(motor_array[ID].motor_driver_name==Driver_BTS7960)
			{
				analogWrite(motor_array[ID].Right_pin,LOW);
				analogWrite(motor_array[ID].left_pin,LOW);
			}
			else if(motor_array[ID].motor_driver_name==Driver_Relay)
			{
			  digitalWrite(motor_array[ID].Right_pin,LOW);
			  digitalWrite(motor_array[ID].left_pin,LOW);
			}
			break;  
      case Up:
			if(motor_array[ID].motor_driver_name==Driver_L293N)
			{
				digitalWrite(motor_array[ID].Right_pin,HIGH);
				digitalWrite(motor_array[ID].left_pin,LOW);
				analogWrite(motor_array[ID].pwm_pin,motor_speed);
				
			}
			else if(motor_array[ID].motor_driver_name==Driver_BTS7960)
			{
				analogWrite(motor_array[ID].Right_pin,motor_speed);
				analogWrite(motor_array[ID].left_pin,LOW);
			}
			else if(motor_array[ID].motor_driver_name==Driver_Relay)
			{
			  digitalWrite(motor_array[ID].left_pin,LOW);
			  digitalWrite(motor_array[ID].Right_pin,HIGH);
			}
          break; 
      case Down:
			if(motor_array[ID].motor_driver_name==Driver_L293N)
			{
				
			  digitalWrite(motor_array[ID].Right_pin,LOW);
			  digitalWrite(motor_array[ID].left_pin,HIGH);
			  analogWrite(motor_array[ID].pwm_pin,motor_speed);
			}
			else if(motor_array[ID].motor_driver_name==Driver_BTS7960)
			{
			  analogWrite(motor_array[ID].Right_pin,LOW);
			  analogWrite(motor_array[ID].left_pin,motor_speed);
			}
			else if(motor_array[ID].motor_driver_name==Driver_Relay)
			{
				digitalWrite(motor_array[ID].Right_pin,LOW);
				digitalWrite(motor_array[ID].left_pin,HIGH);
			  
			  
			}
			
          break; 
    }
  
  
  
  
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

/*--------------------- IR Functions---------------------------------------*/
 



void IR_voidInti(void)
{
  
int IR_sensor_Numbers;
IR_sensor_Numbers=(sizeof(IR_sensor_array)/sizeof(IR_sensor_t));


  for(char count=0;count<IR_sensor_Numbers;count++)
  {
   pinMode(IR_sensor_array[count].digital_pin,INPUT);
  }
  Serial.println("finish_IR_Sensor");  
}

/*************************************************************************************/

reflectedlight_t   IR_reflectedlight_tGet_reflectedlight(char Copy_IR_sensor_ID)
{
  
  boolean Local_charIR_PIN_Statuse;
  reflectedlight_t reflectedlight;

  Local_charIR_PIN_Statuse=digitalRead(IR_sensor_array[Copy_IR_sensor_ID].digital_pin);


  if(Local_charIR_PIN_Statuse==Black)
  {
    reflectedlight=Black;
  }
  else if(Local_charIR_PIN_Statuse==White)
  {
	
    reflectedlight= White;
  }
  else
  {

  }


  return reflectedlight;
  
  

}
