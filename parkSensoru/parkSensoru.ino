int trigPin = 2;
int echoPin = 3;
int ledPin = 5;
int buzzerPin = 9;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

}


long measurePulse() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);         // Temiz sinyal için
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);        // 10 µs tetik darbesi
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH, 30000);  // Echo süresi (max 30 ms = ~5 metre)
}


float calcDistance(long duration){
  return duration * 0.01715; //cm cinsinden
}
void loop(){
  long duration2 = measurePulse();
  float mesafe = calcDistance(duration2);

  if (mesafe > 0 && mesafe <= 10) { // 10cm ile 0cm arasi daha cok sesli cal
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); // yüksek ton
  }
  else if (mesafe > 10 && mesafe <= 30) { // 30cm ile 10cm arasi cok sesli cal
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 700);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  }
  else if (mesafe > 30 && mesafe <= 50) { // 50cm ile 30cm arasi ses cal
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 440);
    delay(200);
    noTone(buzzerPin);
    delay(200);
  }
  else { // onun disinda calma
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(100); // sensörü çok sık okutmamak için
  

}
