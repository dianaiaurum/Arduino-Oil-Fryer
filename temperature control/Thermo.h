#ifndef Thermo_h
#define Thermo_h
#include "Arduino.h"

class Thermo
{
  public:
    Thermo(float temp);
    float current_temp;
    float error;
    float target_temp;
    float getError();
   
};

#endif
