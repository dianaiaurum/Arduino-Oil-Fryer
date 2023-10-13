/*In this class we calculate the difference in temperature(error) by reading the temperature 
 from the thermocouple and the temperature that is introduced by the user*/

#include "Thermo.h"
#include "Arduino.h"

#define MAX6675_CS   3
#define MAX6675_SO   4
#define MAX6675_SCK  2

 Thermo::Thermo(float temp)
 {
  //We set the target temperature
  target_temp = temp;
 }
float Thermo::getError()
 {
  //We read the current temperature from the thermocouple
   MAX6675 thermocouple(MAX6675_SCK, MAX6675_CS, MAX6675_SO);
   current_temp = thermocouple.readCelsius();
  //We calculate the error 
   error = target_temp - current_temp;

  return error;
 }
