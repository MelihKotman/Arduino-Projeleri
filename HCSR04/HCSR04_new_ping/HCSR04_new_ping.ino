#include <NewPing.h> // HC-SR04 ve benzeri sensorler icin kutuphane

#define TRIG_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 200 // Olcum siniri cm

// NewPing nesnesi: pinler ve maksimum mesafe parametreleri ile oluşturulur
//Tum donanim ve limit bilgisi burada setlenir ve kod boyunca kullanilir
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() {
  Serial.begin(115200);         // Seri haberleşmeyi başlat
  // NewPing: pinMode ayarlarına gerek yok; kütüphane kendi yapısını kullanır
}

void loop() {
  // Sensoru tetikler, yankiyi olcer dogrudan tam sayı cm olarak doner, basarisizda olcumlerde 0 doner
  delay(50); // Istikrarlı ve güvenli ölçüm periyodu sağlar; sensör (~29 ms) ritmine uygun
  unsigned int cm = sonar.ping_cm(); // olcum yapar ve sonucu cm olarak doner
  /*
  * Alternatif olarak 
  * int dur_us = sonar.pig_median(5); //Belirlenen sayida olcum yapar sonra aykiri degerleri atarak median degeri doner gurultuye direnclidir
  * int cm = dur_us / US_ROUNDTRIP_CM; // US_ROUNDTRIP_CM sabiti (~58 μs/cm) dönüşümü sağlar.
  */
  Serial.print("Mesafe: ");
  if (cm == 0) Serial.println("Uzakta");  // Eğer obje limit dışında ise 0 döner
  else {
    Serial.print(cm);
    Serial.println(" cm");

  }
}
