#include <Servo.h>


int ledPin = 10; // Hedefi gorunce isik yakacak
int buzzerPin = 11; //Hedefi gorunce ses cikaracak
int servoPin = 9;
int trigPin = 2;
int echoPin = 3;
Servo myRadar;



void setup() {

  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  myRadar.attach(servoPin);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);

}
//Gonderilen ses dalgasinin suresini olctuk
long calcDuration(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH);
}
//Suresiyle ses hizinin yarisiyla carpip mesafemizi bulduk
float calcDistance(long dur){
  return dur * 0.01715;
}
void loop() {
  for(int angle = 5; angle <= 175; angle++){ // 5º ve 175º araliginda donecek servo motorumuz
    myRadar.write(angle);
    delay(30);
    long duration = calcDuration();
    float distance = calcDistance(duration);
    Serial.print("Açı : "); // Her dondugu aciyi bize verecek seri monitorden
    Serial.println(angle);
    Serial.print("º - Mesafe : "); // Her dondugundeki acidaki karsisindaki engelin mesafesini verecek
    Serial.println(distance);

    if(distance < 20){//eger 20 cm'den daha az yakinliktaysa engelimiz ses ve isik cikaracak
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    }
    else{ // Obur turlu hicibr ikaz isareti olmayacak
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
  }
  delay(500);
}
