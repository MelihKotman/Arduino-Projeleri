#include <LiquidCrystal.h>
//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Turkce karakter yerine "ok" isareti yap
//Her karakterin 5 piksel genisligi 8 piksel yuksekligi vardir bastaki B ise bize Byte anlamini verir
byte arrowSymbol[8]= {
  B00100,
  B00110,
  B00111,
  B11111,
  B00111,
  B00110,
  B00100,
  B00000
};
void setup() {
  lcd.begin(16, 2); //16x2 LCD
  lcd.createChar(0, arrowSymbol); //"→" isaretini(kendi yaptigimizi) bir byte yapar
  lcd.setCursor(0, 0); //Imleci (0,0)'a al
  lcd.print("Yon: "); //"Yon: " basilir
  lcd.setCursor(5, 0); //Imleci (5,0)'a al
a  lcd.write(byte(0)); //"→" isareti basilir 
}
void loop() {
  // put your main code here, to run repeatedly:

}
