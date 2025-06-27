int buttonPin = 2; //buton'un degerini aldigimiz pin
int buzzerPin = 8; //buzzer'in bagli oldugu pin(AKTIF)
int buttonState; //buton durumu

void setup() {
  pinMode(buzzerPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin); //Butonun durumunu digitalRead ile okuyoruz
  if(buttonState == HIGH){ //Pullup kullandigimiz icin
    digitalWrite(buzzerPin,LOW); // Buton HIGH iken Buzzer LOW
  }
  else{
    digitalWrite(buzzerPin,HIGH); // Buton LOW iken Buzzer HIGH
  }

}
