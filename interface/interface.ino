

#include <Keypad.h>

#include <LiquidCrystal.h>
#include "Programs.h"
#include "Start.h"

LiquidCrystal lcd(53, 51, 47, 45, 43, 41);

Start hello;

const byte rows = 2; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'}
};
byte rowPins[rows] = {27,29}; //connect to the row pinouts of the keypad
byte colPins[cols] = {31,33,35,37}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );



void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
 hello.print_test();
}

void loop() {
  char customKey = keypad.getKey();





//Choose program mode
  switch (customKey) {
    case 1: {
      Serial.print("Pr 1: ");
      Serial.println(program.number[0].Name);
      Serial.print("Temp: ");
      Serial.println(program.number[0].Temperature);
      Serial.println("Timp: ");
      Serial.println(program.number[0].Time);
    }

  }
/*program.number[0].Name = "xx";*/
    

}
