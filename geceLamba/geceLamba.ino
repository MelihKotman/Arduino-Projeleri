int LDR_PIN = A0; // LDR Analog sinyal pini
int LED_PIN = 6; // LED pini
int PIR_PIN = 5; // PIR pini


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ResisDeger = analogRead(LDR_PIN); // Ilk once bir PIR'in direnc degerini aliyoruz
  Serial.print("Ω :");
  Serial.println(ResisDeger);
  delay(100); // 1 saniye beklemeli direnc degerini yaziyor
  if(ResisDeger >= 500 && ResisDeger < 1000){ // Eger 500-999 Ω araligindaysa
    int PIRstate = digitalRead(PIR_PIN); // Hareketin durumunu al
    if(PIRstate == HIGH){ // Eger varsa LED'i yak
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Hareket Algilandi, isik yakildi");
      delay(100);
    } else{ // Yoksa LED'i kapali tut
      digitalWrite(LED_PIN, LOW);
      Serial.println("Hareket Algilanmadi");
      delay(100);
    }
  } else if(ResisDeger < 499 && ResisDeger >= 0){ // Eger 0-499 Ω araligindaysa LED'i kapali tut ve karanlik olmadi de
    Serial.print("Karanlik Olmadi ");
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}
