#include <LiquidCrystal.h>
//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //16x2 LCD
  lcd.setCursor(15, 0); //Imleci (15,0)'a getir yani en ust sag

  lcd.rightToLeft(); //Sagdan sola yaz
  lcd.print("TO RIGHT"); //"THGIR OT" basilir

  delay(2000); //2 s bekle

  lcd.setCursor(0, 1); //Imleci (0, 1)'e getir yani en alt sol
  lcd.leftToRight(); //Soldan saga yaz
  lcd.print("TO LEFT"); //"TO LEFT" basilir
}

void loop() {
  // put your main code here, to run repeatedly:

}
