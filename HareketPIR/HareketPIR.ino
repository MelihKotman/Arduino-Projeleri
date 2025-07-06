int BUZZ_PIN = 5; // Hareket algilaninca ses cikaracak
int GREEN_PIN = 10; // Hareket olmadigi zamanda yesil isik yanacak
int RED_PIN = 9; // Hareket oldugunda kirmizi isik yanacak
int PIR_PIN = 3; // Hareketi algilama sinyal ucu pini

void setup() {
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT); // Cunku bir hareket girisi sinyali olmali ki digerlerini yakalim
  Serial.begin(9600);
}

void loop() {
  int PIRstate = digitalRead(PIR_PIN); //Harekt oldugunda bize HIGH ve LOW gonderecek
  if(PIRstate == HIGH){ // Eger HIGH ise kirmizi LED'i ve Buzzer'ı calistir
    digitalWrite(BUZZ_PIN, HIGH);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    Serial.println("Hareket Algilandi");
    delay(50);
  }else { //Eger LOW ise yesil LED'i calistir ve geri kalan dursun
    digitalWrite(BUZZ_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    Serial.println("Hareket Algilanmadi");
    delay(50);
  }
  delay(100);
}
