
int led_PIN = 3; // PWM destekleyen LED pini (çok önemli!)
int pot_PIN = A0; // Potansiyometre bağlı pin

void setup() {
  Serial.begin(9600); // baud degeridir serial monitore kac bit veri gonderilecegi hesaplanir
  pinMode(led_PIN,OUTPUT);
}

void loop() {
  int Direnc = analogRead(pot_PIN); // analog degeri direnc degiskenine atariz
  int Parlaklik = map(Direnc, 0, 1023, 0, 255); //0-1023 araligini 0-255 araligina cevirmemizi saglar
  analogWrite(led_PIN,Parlaklik); //Cevrilen araliktaki degeri parlaklik olarak LED'e gondeririz
  Serial.print("Direnc : ");
  Serial.println(Direnc); //Direnc degerini serial monitorde okuyor
  Serial.print("Parlaklik : ");
  Serial.println(Parlaklik); // Parlaklik degerini serial monitorde okuyor
}
