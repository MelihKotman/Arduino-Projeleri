#include <LiquidCrystal.h>
//#include <LiquidCrystal_I2C.h>

//LCD (RS, E, D4, D5, D6, D7)(Standart)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*
* LCD I2C ile (Adres[ya hexadecimal  ya da 0x27 gibi adres, satir sayisi, sutun sayisi])
*LiquidCrystal_I2C lcd(39, 16, 2);
*/
int move_count = 0; //Hareket Sayisi
int greenLED = 9; //Hareket olmayınca yesil LED yanacak
int redLED = 10; //Hareket olunca kirmizi LED yanacak
int PIRPin = 6; //Hareket sensoru

void setup() {
  lcd.begin(16, 2);
  /*
  *lcd.init();
  *lcd.backlight();
  */
  lcd.setCursor(0, 0);
  lcd.print("Movement Counter :");
  lcd.setCursor(0, 1);
  lcd.print(move_count);
  pinMode(PIRPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
}
bool lastState = LOW; //Baslangicta sensorun kapali oldugunu varsay
void loop() {
  int pirState = digitalRead(PIRPin); //Sensorden bilgi al
  if(pirState != lastState){ //Eger son seyle esit degilse degisim yap
    if(pirState == HIGH){
    moveDetected(); //Hareket edildi fonksiyonunu calistir
  } else {
    notMove(); //Hareket edilmedi fonksiyonunu calistir
  }
  lastState = pirState; //Amac ekranin surekli yorulmamasi icin
  delay(50);
  }
  
}
//Hareket varken ekran degisecek ve hareket var diyip kirmizi LED'i yakacak
void moveDetected(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Movement");
  lcd.setCursor(0, 1);
  lcd.print("Detected!");
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  move_count++;
}
//Hareket yokken ekran degisecek ve hareket yok diyip yesil LED'i yakacak
void notMove(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Movement Counter :");
  lcd.setCursor(0, 1);
  lcd.print(move_count);
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}


