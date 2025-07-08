#include <LiquidCrystal.h>
//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //16x2 LCD
  lcd.print(">> Melih <<"); //Toplam 10 karakter ediyor

  delay(1000); //1 s bekle
  for(int i = 0; i < 10; i++){ //Karakter sayisi kadar
    lcd.scrollDisplayLeft(); //Tum metni bir sola gonder
    delay(500); //0.5 s bekle
  }

  for(int i = 0; i < 10; i++){ //Karakter sayisi kadar
    lcd.scrollDisplayRight(); //Tum metni bir saga gonder
    delay(500); //0.5 s bekle
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
