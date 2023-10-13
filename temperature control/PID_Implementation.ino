#include "Arduino.h"
#include "PID.h"

PID::PID()
{ 
  //Thermo t(55);
  previous_error = current_error;
  current_error = t.getError();
  
   previous_time = Time;
  Time = millis();
  elapsed_time = (Time - previous_time)/1000;
}

float PID::getPID_P(){
  PID_P = kp * current_error;
  return PID_P;
}

float PID::getPID(){
   pid = getPID_P() + getPID_D() + getPID_I();
   return pid;
}

float PID::waitPID(){
  int relayPin = 5;// set pin 3 for relay out
pinMode(relayPin, OUTPUT);
current_error = t.getError();
if(millis() >= prevTime + changeInTime){
  if(current_error > 0){
 digitalWrite(relayPin, HIGH);// set relay pin to HIGH
 }
 else {
   digitalWrite(relayPin, LOW);// set relay pin to LOW
 }
changeInTime = map(pid_value.getPID(),-1000,7000,0,6000);
  prevTime = millis();
 }
}

float PID::getPID_D(){
  
   PID_D = kd * (current_error - previous_error)/elapsed_time;
   return PID_D;
 }

 float PID::getPID_I(){
  if(current_error  <= 0.5 && current_error  >= -0.5){
  _PID_I = PID_I + (ki * current_error);
  PID_I = _PID_I;
  return PID_I;
  }


}
