/*
* Notalarin Frekanslari
* Do = 262 Hz
* Re = 294 Hz
* Mi = 330 Hz
* Fa = 349 Hz
* Sol = 392 Hz
* La = 440 Hz
* Si = 494 Hz
* Do(Kalin) = 523 Hz
*/
int buzzerPin = 3;
int doButton = 4;
int reButton = 5;
int miButton = 6;
int faButton = 7;
int solButton = 8;
int laButton = 9;
int siButton = 10;
int DoButton = 11;

//Daha kolay olmasi icin hepsini bir fonksiyon yaptik
void doPlay(){
  tone(buzzerPin,262,1000);
}
void rePlay(){
  tone(buzzerPin,294,1000);
}
void miPlay(){
  tone(buzzerPin,330,1000);
}
void faPlay(){
  tone(buzzerPin,349,1000);
}
void solPlay(){
  tone(buzzerPin,392,1000);
}
void laPlay(){
  tone(buzzerPin,440,1000);
}
void siPlay(){
  tone(buzzerPin,494,1000);
}
void DoPlay(){
  tone(buzzerPin,523,1000);
}
void setup() {

  pinMode(buzzerPin,OUTPUT);
  pinMode(doButton,INPUT);
  pinMode(reButton,INPUT);
  pinMode(miButton,INPUT);
  pinMode(faButton,INPUT);
  pinMode(solButton,INPUT);
  pinMode(laButton,INPUT);
  pinMode(siButton,INPUT);
  pinMode(DoButton,INPUT);
}

void loop() {
   if (digitalRead(doButton) == HIGH)       doPlay();
  else if (digitalRead(reButton) == HIGH)  rePlay();
  else if (digitalRead(miButton) == HIGH)  miPlay();
  else if (digitalRead(faButton) == HIGH)  faPlay();
  else if (digitalRead(solButton) == HIGH) solPlay();
  else if (digitalRead(laButton) == HIGH)  laPlay();
  else if (digitalRead(siButton) == HIGH)  siPlay();
  else if (digitalRead(DoButton) == HIGH)  DoPlay();
  else noTone(buzzerPin);  // Hiçbir tuşa basılmadıysa sesi kes
}
