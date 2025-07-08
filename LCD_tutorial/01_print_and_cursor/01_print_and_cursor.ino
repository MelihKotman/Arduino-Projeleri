#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7 sırasıyla
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {

  lcd.begin(16,2); //16 sutun ,2 satir
  lcd.print("Hello,"); //Ilk satirdan baslar ve ilk satira soldan baslayarak "Hello," yazar

  lcd.setCursor(0,1); //Bu sefer altina yazacaksak 0.sutun, 1.satir yapariz
  lcd.print("World!"); //Son satirdan baslar ve son satira soldan baslayarak "World!" yazar.

  lcd.setCursor(10,1); // (0-15,0-1) araliginda sayi yazilir ve bu (sutun,satir) yerini verir.
  lcd.cursor(); //Bu belirledigimiz satirda ise bize imlec belirtir.

}

void loop() {
  

}
