#include <LiquidCrystal.h>

//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); //16x2 LCD
  
  lcd.setCursor(0, 0); //Imleci (0,0)'a al
  lcd.print("AutoScroll ON:"); 

  lcd.setCursor(15, 1); //Imleci (15,1)'e al
  delay(500);//0.5 s bekle
  lcd.autoscroll();  // Otomatik kaydırma aktif

  for (int i = 0; i < 10; i++) { //0-9'a kadar tum sayilari bastir
    lcd.print(i);
    delay(500); //0.5 s bekle
  }

  delay(2000); //2 s bekle
  lcd.noAutoscroll();  // Otomatik kaydırma kapalı
  lcd.clear(); //Ekrani temizle

  lcd.setCursor(0, 0); //Imleci (0,0)'a al
  lcd.print("AutoScroll OFF");
  lcd.setCursor(0, 1);// Imleci (0,1)'e al
  
  lcd.print("1234567890");
}


void loop() {
  // put your main code here, to run repeatedly:

}
