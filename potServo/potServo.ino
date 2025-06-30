#include <Servo.h> //Servomuzun fonksiyonlarini kullanacagimiz kutuphanemiz

Servo myServo; //Servo class'indan bir myServo nesnesi olusturduk birden fazla var myServo1,myServo2,...; seklinde yapabiliriz.
int pot = A0; //potansiyometremizin pini belirttik.

void setup() {
  myServo.attach(3);//attach bize arduino'ya servomuz hangi pinden PWM alacagini belirttigi  
  //yerdir istersek attach(pin,min,max) yaparak dereceleri ayarlayabiliriz 600𝝁(0º) ile 2400𝜇(180º) yazilir genelde
  pinMode(A0, INPUT);
}

void loop() {
  int potState = analogRead(pot);//potansiyometreden analog sekilde degerimizi aldik
  int deger = map(potState,0,1023,0,180); //map ile 0-1023 araligini 0-180 araligina cevirdik
  myServo.write(deger); //write degerler degistikce acisini degisterecektir.
  delay(10);
  /*
  * istersek 
  * int deger = map(potState0,1023,600,2400); //dereceleri mikrosaniyeye ayarlayipta yapabiliriz
  * myServo.writeMicroseconds(deger); //bunu kullanirken mutlaka writeMicroseconds() ile yapmamiz gerek
  * delay(10);
  */
}
