#include <LiquidCrystal.h>

//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //16x2 LCD
  lcd.print("It appears");

  delay(2000); //2 s bekle
  lcd.noDisplay(); //Ekrani gizle
  delay(2000); //2 s bekle
  lcd.display(); //Ekrani tekrar ac
  lcd.setCursor(0, 1); //Imleci (0,1)'e getir
  lcd.print("We are here");
}

void loop() {
  // put your main code here, to run repeatedly:

}
