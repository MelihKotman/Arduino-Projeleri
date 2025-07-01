int transPin = 3;  // Base kontrol pini

void setup() {
  pinMode(transPin, OUTPUT);
}

void loop() {
  digitalWrite(transPin, HIGH); // Transistör ON → LED yanar
  delay(1000);
  digitalWrite(transPin, LOW);  // Transistör OFF → LED söner
  delay(1000);
}