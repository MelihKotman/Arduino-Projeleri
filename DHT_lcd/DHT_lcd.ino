#include <LiquidCrystal.h> //LCD kütüphanesi
#include <DHT.h> //Sıcaklık Sensörü

//DHT PIN Değişkenleri
#define DHTPIN 2 // DHT'nin bağlı olduğu pin
#define DHTTYPE DHT11 //DHT tipi

//LCD PIN Değişkenleri
#define RS 12
#define E 11
#define D4 6
#define D5 5
#define D6 4
#define D7 3

DHT dht(DHTPIN, DHTTYPE); //DHT class'ından dht nesnesi oluşturduk

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); //LiquidCrystal class'ından lcd nesnesi oluşturdul

//LCD Ekranına Değerleri Yazdırma Fonksiyonu
void updateLCD(){
  float  temperature = dht.readTemperature(); //Sıcaklığı ölçer
  float  humidity = dht.readHumidity(); //Nem Değerini ölçer

  lcd.clear(); //Ekranı temizle

  if (isnan(humidity) || isnan(temperature)){ //Veri gelmiyorsa
    lcd.setCursor(0, 0);
    lcd.print("Nem/Sicaklik");
    lcd.setCursor(0, 1);
    lcd.print("Bilinmiyor.");
  }else {
    //Sıcaklık Değeri
    lcd.setCursor(0, 0);
    lcd.print("Sicaklik: ");
    lcd.print(temperature);
    lcd.print((char)223); // (char)223 ile birlikte ° sembolü yazılır
    lcd.print("C");

    //Nem Değeri
    lcd.setCursor(0, 1);
    lcd.print("Nem: ");
    lcd.print(humidity);
    lcd.print("%");
  }
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Nem/Sicaklik");

  lcd.setCursor(0, 1);
  lcd.print("Olcer");

  delay(1000);
}

void loop() {
  updateLCD(); //LCD ekranına yazdırma fonksiyonu
  delay(2000);
}
