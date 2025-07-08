#include <LiquidCrystal.h>
//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  lcd.begin(16, 2); //16x2 LCD
  int sayi = 42;

  //Decimal Bicimde Yazim 
  //Burada 10'luk sisteme gore yazar ve bu kullandigimiz sayimdir
  lcd.print("DEC = ");
  lcd.print(sayi, DEC); //Yazarken saginda mutlaka "DEC" belirtilmeli "42"
  delay(2000);

  lcd.clear();

  //Hexadecimal Bicimde Yazim
  //Burada 16'lik sisteme gore yazip yapar ve buda sayiyi hep 16'ya bolup cikan kalanlarla sayi olusur
  lcd.print("HEX = ");
  lcd.print(sayi, HEX); //Yazarken saginda mutlaka "HEX" belirtilmeli "2A"
  delay(2000);

  lcd.clear();

  //Binary Bicimde Yazim
  //Burada 2'lik sisteme gore yazip yapar ve buda sayiyi hep 2'ye bolup cikan kalanlarla sayi olusur
  lcd.print("BIN = ");
  lcd.print(sayi, BIN); //Yazarken saginda mutlaka "BIN" belirtilmeli "101010"
  delay(2000);

  lcd.clear();

  //Octal Bicimde Yazim
  //Burada 8'lik sisteme gore yazip yapar ve buda sayiyi hep 8'e bolup cikan kalanlarla sayi olusur
  lcd.print("OCT = ");
  lcd.print(sayi, OCT); //Yazarken saginda mutlaka "OCT" belirtilmeli
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
