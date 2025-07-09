#include <LiquidCrystal.h>
//#include <LiquidCrystal_I2C.h>

//RS, E, D4, D5, D6, D7(Standart)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*I2C ile (Adres[ya hexadecimal ya da 0x27 gibi adres, satir sayisi, sutun sayisi])
*LiquidCrystal_I2C lcd(39, 16, 2);
*/
int upButton = 9; //Arttir Butonu
int downButton = 10; //Azalt Butonu
int counter = 0; //Sayac butonu
void setup() {
  lcd.begin(16, 2); //16x2 LCD
  /* Bu I2C'de olusabilecek tek farklilik onun disinda tum kodlar aynidir
  * lcd.init();
  * lcd.backlight();
  */
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  lcd.setCursor(0, 0); //Imleci (0,0)'a ayarla
  lcd.print("Sayac : ");
  lcd.setCursor(0, 1); //Imleci (0,1)'a ayarla
  lcd.print(counter);
}

void loop() {
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);
  if(upState == HIGH){
    counter++; //Sayiyi bir arttiracak
    updateDisplay(); //Ekrani yenile
    delay(100);
  }
  if(downState == HIGH){
    counter--; //Sayiyi bir azaltacak
    updateDisplay(); //Ekrani yenile
    delay(100);
  }
}
void updateDisplay(){
  lcd.clear();
  lcd.setCursor(0, 0); //Imleci (0,0)'a ayarla
  lcd.print("Sayac : ");
  lcd.setCursor(0, 1); //Imleci (0,1)'a ayarla
  lcd.print(counter);
}
