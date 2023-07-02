#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

//LN286N circuit wiring
//const int ENA_PIN = 11; 
//const int IN1_PIN = 12; 
//const int IN2_PIN = 13;
//static float x = 0;
HX711 scale;

void setup() 
{
  //initializing load cell
  Serial.begin(57600);  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);            
  scale.set_scale(-459.542); //change the value of calibration factor
  scale.tare();               // reset the scale to 0
  Serial.println(scale.get_units(5), 1); // print the average of 5 readings from the ADC minus tare weight, divided by the SCALE parameter set with set_scale


  // initialize digital pins of LN286N as outputs.
//  pinMode(ENA_PIN, OUTPUT);
//  pinMode(IN1_PIN, OUTPUT);
//  pinMode(IN2_PIN, OUTPUT);
//
//  
//  digitalWrite(ENA_PIN, HIGH);


}

void loop() 
{
  float Weight = scale.get_units(5);
  Serial.print(scale.get_units(5), 1);
//  if(Wtcheck(Weight))
//  {
//
//    float d=(3)/(Weight+100);// to get displacement in m
//    float t=d/(5*10^-6); //displacement in m devided by velocity in mm/s(which is converted to m/ms) to get time (ms) required
//    actuator(t);
//
//
//  
//   scale.power_down();  // put the ADC in sleep mode
//   delay(5000);
//   if (Objctdet(Weight)){
//   scale.power_up();
//  }
//  else
//  {
//   Serial.println("Weight is not within limit");  
//  }
//  }
}

//function to detect the presence of person on the weighing machine
//boolean Objctdet(float Weight)
//{
//  if(Weight>5){
//    return true;
//    }
//  else
//   {
//    return false;
//    }
// 
//}
//
//boolean Wtcheck(float Weight)
//{
//  if(20 <= Weight<= 50)
//  {
//   return true;
//  }
//  else
//  {
//   return false;
//  }
//}
//
//
////function to work actuator
//void actuator(float t)
//{
//   if(x==0)
//   {
//      // extend the actuator
//  digitalWrite(IN1_PIN, HIGH);
//  digitalWrite(IN2_PIN, LOW);
//
//  delay(t); 
//  x=t;
//    }
//   else
//   {
//      // retracts the actuator
//  digitalWrite(IN1_PIN, LOW);
//  digitalWrite(IN2_PIN, HIGH);
//
//  delay(x);
//
//    // extend the actuator
//  digitalWrite(IN1_PIN, HIGH);
//  digitalWrite(IN2_PIN, LOW);
//
//  delay(t); 
//    }
//}
