#include <LiquidCrystal.h>

//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //16x2 LCD
  lcd.setCursor(0, 0); //Imleci (0,0)'a alir

  lcd.print("Blink active: "); //"Blink aktif" basilir
  lcd.setCursor(0, 1); //Imleci (0,1)'e alir
  lcd.blink(); // Imlec yanip soner
  lcd.print("Waiting..."); //"Waiting..." basilir
  }

void loop() {
  // put your main code here, to run repeatedly:

}
