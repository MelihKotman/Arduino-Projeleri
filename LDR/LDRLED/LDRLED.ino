int LEDPin = 3; //PWM olarak LED veya Base(Transistor)
int LDRPin = A0; //Analog olarak LDR

void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(LDRPin,INPUT);//Burada ayni pot gibi bir veri alisi olacak
  Serial.begin(9600);
}


void loop() {
  int Resisdeger = analogRead(LDRPin);//Direnc degerini olctu ve bu deger LDR'den oturu (0-999)Ω araliginda olmalidir
  Serial.print("Ω :");
  Serial.println(Resisdeger);
  if(Resisdeger > 500 && Resisdeger <= 999){// 999-501Ω arasi LED yak
    digitalWrite(LEDPin,HIGH);
  }
  else if(Resisdeger <= 500 && Resisdeger >= 0){ //500-0Ω arasi LED kapa
    digitalWrite(LEDPin,LOW);
  }

}
