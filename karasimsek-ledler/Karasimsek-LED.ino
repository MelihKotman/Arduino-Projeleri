
int leds[] = {2,3,4,5,6,7}; //LED pinlerinin sayilarini bir dizide tuttuk

void setup() {

  for(int i = 0; i < 6; i++){ //LED'lerin pinlerini cikis olarak ayarladik
    pinMode(leds[i],OUTPUT);
  }

}

void loop() {
  for(int i = 0; i < 6; i++){ // En bastakinden en son pine kadar yak ve aralarda 1 saniye(100 ms) bekle
    digitalWrite(leds[i],HIGH);
    delay(100);
    digitalWrite(leds[i],LOW);
  }

  for(int i = 5; i--; i > -1){ // En sondakinden ilk pine kadar yak ve aralarda 1 saniye(100 ms) bekle
    digitalWrite(leds[i],HIGH);
    delay(100);
    digitalWrite(leds[i],LOW);
  }
}
