#include <LiquidCrystal.h>
//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //16x2 LCD
  lcd.print("Test LCD"); //"Test LCD" basilir
  delay(2000); //2 saniye bekle

  lcd.clear(); //Tum ekrani temizle
  lcd.print("Reprinted"); //"Reprinted" basilir
  delay(2000); //2 saniye bekle

  lcd.home(); //İmleci (0,0)'a alir yani sol ustten baslar.
  lcd.print("Hello!"); //"Hello" basilir

  //Burada "Reprinted" kelimesinin ilk alti harfi "Hello!" yerine degisir ve sonucunda "Hello!ted" cikar
}

void loop() {
  // put your main code here, to run repeatedly:

}
