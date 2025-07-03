#include <Servo.h>

int greenPin = 10; // Gecis Isigi pini
int redPin = 9; // Dur Isigi pini
int barrierServoPin = 6; //Servo pini
int trigPin = 2; // Verici sinyal pini
int echoPin = 3; // Alici sinyal pini

Servo barrierServo;

void setup(){
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  barrierServo.attach(barrierServoPin);
  barrierServo.write(0); // Ilk basta bariyerimizi 0 dereceye ayarladik ardindan
}
//HC SR04'de ogrendigimiz vericiden cikan sinyalin engele carpma suresini buluyoruz.
long calcDuration(){
    digitalWrite(trigPin, LOW);
  delayMicroseconds(5); //Tetikleme baslangici icin temiz sinyal
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // 10µs tetik darbesi

  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}
//Buldugumuz sureyi sesin hizi'nin yarısı ile carpip mesafeyi buluyoruz
float calcDistance(long dur){
  return dur * 0.01715;
}
void loop(){
  int duration = calcDuration();
  int distance = calcDistance(duration);

  if(distance < 20){ //20 cm uzakliktan azsa kapiyi ac ve gecis isigini yak ve 5 s bekle
    barrierServo.write(0);
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
    delay(500);
  }
  else{ // 20 cm ve 20 cm'den coksa kapiyi kapa ve dur isigini yak
    barrierServo.write(80);
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }
  delay(500);
}