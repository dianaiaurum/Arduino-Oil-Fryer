//a library of every menu 
#include <LiquidCrystal.h>
   extern class LiquidCrystal lcd;

class Start
{
  public:
    Start();
    void main_menu();
};

Start::Start(){
}

//main menu
void Start::main_menu() {
      lcd.setCursor(0, 0);
      lcd.print("Progams: 1-6");
      lcd.setCursor(0, 1);
      lcd.println("A-Manual Mode");
      lcd.setCursor(0, 2);
      lcd.println("B-Config Mode");
  }
  
