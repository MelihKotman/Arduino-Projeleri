#include <Servo.h>

int plusButton = 9; // Arttir butonumuz
int minusButton = 10; // Azalt butonumuz
Servo myServo; 
int angle = 90; // Baslangic derecesi 90º

void setup() {
  pinMode(plusButton,INPUT); 
  pinMode(minusButton,INPUT);
  myServo.attach(3);
  myServo.write(angle); //Ilk baslangicta kac derece oldugunu burada yaziyoruz
  Serial.begin(9600); //Dereceyi seri monitorde okumak icin baud degeri
}

void loop() {
  int plusState = digitalRead(plusButton); 
  int minusState = digitalRead(minusButton);
  //HIGH,LOW durumlarini aldiktan sonra
  if(plusState == HIGH){ //HIGH olunca 
    angle += 5; // 5º arttir
    if(angle > 180){ //eger 180º'den fazlaysa 180º kalsin
      angle = 180;
    }
    myServo.write(angle);
    delay(100);
  }
  if(minusState == HIGH){ //HIGH olunca
    angle -= 5; // 5º azalt
    if(angle < 0){ //eger 0º'dan fazlaysa 0º olarak kalsin
      angle = 0;
    }
    myServo.write(angle);
    delay(100);
  }
  Serial.print("Derece : ")
  Serial.println(angle);
}
