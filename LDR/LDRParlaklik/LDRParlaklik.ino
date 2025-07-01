int LEDPin = 3; //PWM olarak LED
int LDRPin = A0; //Analog olarak LDR

void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(LDRPin,INPUT);//Burada ayni pot gibi bir veri alisi olacak
  Serial.begin(9600);
}


void loop() {
  int Resisdeger = analogRead(LDRPin);//Direnc degerini olctu
  int parlaklik = map(Resisdeger,0,999,0,255); //LDR Direnc araliginden PWM'e gore aralik yaptirdik
  Serial.print("Ω :");
  Serial.println(Resisdeger);
  Serial.print("Parlaklik :");
  Serial.println(parlaklik);
  delay(10); 
  analogWrite(LEDPin,parlaklik); //Buna gorede led parlakligi degisecek
  //Analog kullanma sebebimiz HIGH ve LOW degil bizim gene analog deger aldigimizdan oturudur

}
