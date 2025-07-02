
/* HC-SR04 - pulseIN() ile Mesafe Olcumu*/

int trigPin = 2; //Trigger yani verici sinyal pini 
int echoPin = 3; //Echo yani alici sinyal pini (PWM)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
//Bu fonksiyon bize sinyalin tetikleme baslangici ile tetiklenme sonucunu alir ve bize long ile geri dondurur
long measurePulse(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5); //Tetikleme baslangici icin temiz sinyal
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // 10µs tetik darbesi

  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH); // Yani sinyalinin suresini al
}
//Alinmis sinyalden mesafe olcumu yapilir 
// Bunu yaparken genelde mesafe = zaman * 0.01715 veya zaman / 58.2 veya zaman * 0.0343 / 2 kullanilir
float calcDistance(long duration){
  return duration * 0.01715; //cm cinsinden
}
void loop() {
  long duration2 = measurePulse();
  float distance = calcDistance(duration2);

  Serial.print(" Mesafe ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(50); // Stabil olcum icin kisa gecikme
  

}
