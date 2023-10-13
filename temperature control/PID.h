#ifndef PID_h
#define PID_h
#include "Thermo.h"
#include "Arduino.h"

class PID
{
  public:
    PID();
    float getPID_P();
    float getPID_D();
    float getPID_I();
    float getPID();
    float waitPID();


  private:
    float PID_P;
    float kp = 200.5; //200.5
    float error;
    float current_error;
    float previous_error;
    float _previous_error;
    float PID_D;
    float kd = 25;
    float _elapsed_time;
    float ki = 1.5;
    float  _PID_I;
    float  PID_I;
    float pid;
    float previous_time;
    float Time;
    float elapsed_time;

};
Thermo t(55);//am creat un obiect temp care apeleaza functia getError() din Thermo

#endif
