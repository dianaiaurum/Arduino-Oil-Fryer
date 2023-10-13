#include <Keypad.h>
#include "Thermo.h"
#include <max6675.h>

#include "Arduino.h"
#define MAX6675_CS   3
#define MAX6675_SO   4
#define MAX6675_SCK  2

#include "PID.h"


PID pid_value;

float aux = pid_value.getPID();
float changeInTime = map(aux, -1000, 7000, 0, 6000);
// SSR relay

float prevTime = 0;
//temperature



const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9};
byte colPins[COLS] = {10, 11, 12, 13};


Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  MAX6675 thermocouple(MAX6675_SCK, MAX6675_CS, MAX6675_SO);

  //declarare potentiometru
  pinMode(A0, INPUT);

}

// loop code for Robojax Solid State Relay
void loop() {

  MAX6675 thermocouple(MAX6675_SCK, MAX6675_CS, MAX6675_SO);
  pid_value.waitPID();
  Serial.println(thermocouple.readCelsius());
  //Serial.println(pid);
  delay(500);

}
