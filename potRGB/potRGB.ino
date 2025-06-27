int red_pot = A0;
int green_pot = A1;
int blue_pot = A2;

int redPin = 3;
int greenPin = 5;
int bluePin = 6;



void setup() {
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //Potansiyometredeki degeri oncelikle analogRead fonksiyonuyla okuyoruz
  int redVal = analogRead(red_pot);
  int greenVal = analogRead(green_pot);
  int blueVal = analogRead(blue_pot);

  //Ardindan map fonksiyonuyla 0-1023 araliginda olan pot degerini, renk araligina dokuyoruz(0-255)
  int redPWM = map(redVal,0,1023,0,255);
  int greenPWM = map(greenVal,0,1023,0,255);
  int bluePWM = map(blueVal,0,1023,0,255);

  //Ardindan cevrilen degeri led bacaginin bagli oldugu pinlere atiyoruz
  analogWrite(redPin,redPWM);
  analogWrite(greenPin,greenPWM);
  analogWrite(bluePin,bluePWM);

  //Kaca kac deger oldugunu gormek icin bunu yapiyoruz
  Serial.print("R: ");
  Serial.print(redPWM);
  Serial.print(" | G: ");
  Serial.print(greenPWM);
  Serial.print(" | B: ");
  Serial.println(bluePWM);
}
