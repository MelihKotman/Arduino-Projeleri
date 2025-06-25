int redButton = 9;    // Pull-down direnci ile bağlanmış buton
int yellowButton = 8; // Pull-up direnci ile bağlanmış buton
int redLED = 3;       // Kırmızı LED (pull-down butona bağlı)
int yellowLED = 2;    // Sarı LED (pull-up butona bağlı)

// Amaç: Pull-down ve pull-up dirençlerle yapılan butonların çalışma mantığını göstermek
// Pull-down: Butona basılmadan Arduino pini GND'ye bağlı olduğu için LOW (0V) okunur.
//            Butona basılınca Arduino pinine 5V (HIGH) gelir.
// Pull-up: Butona basılmadan Arduino pini dahili pull-up direnci sayesinde 5V (HIGH) okunur.
//          Butona basılınca pin GND'ye çekildiği için LOW (0V) okunur.

void setup() {
  pinMode(redButton, INPUT);           // Pull-down direnci kullanılan buton pini
  pinMode(yellowButton, INPUT_PULLUP); // Dahili pull-up direnci kullanılan buton pini
  pinMode(redLED, OUTPUT);             // Kırmızı LED çıkışı
  pinMode(yellowLED, OUTPUT);          // Sarı LED çıkışı
}

void loop() {
  int redButton_state = digitalRead(redButton);
  int yellowButton_state = digitalRead(yellowButton);

  // Kırmızı buton: Basılınca HIGH olur, o zaman LED yanar
  if (redButton_state == HIGH) {
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(redLED, LOW);
  }

  // Sarı buton: INPUT_PULLUP olduğu için basılmadığında HIGH, basılınca LOW olur
  // Basılınca LED yanacak şekilde ayarlanmıştır
  if (yellowButton_state == HIGH) {
    digitalWrite(yellowLED, LOW); // Butona basılmadığında LED kapalı
  } else {
    digitalWrite(yellowLED, HIGH); // Butona basılınca LED açık
  }
}