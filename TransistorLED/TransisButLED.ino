int buttonPIN = 2; //Butonun pini
int basePIN = 3; //LED'i yakmak icin gereken transistorun base ucu

void setup() {
  pinMode(buttonPIN,INPUT);
  pinMode(basePIN,OUTPUT);

}

void loop() {
  int buttonState = digitalRead(buttonPIN);//Buton durumunu aliyoruz
  //Ve buna gore LED'i yakip sonduruyoruz
  if(buttonState == HIGH){
    digitalWrite(basePIN,HIGH);
  }
  else if(buttonState == LOW){
    digitalWrite(basePIN,LOW);
  }

}
