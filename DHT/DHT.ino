#include <DHT.h>

#define DHTPIN 2          // DHT sensörünün DATA pinin bağlı olduğu yer
#define DHTTYPE DHT11     // Sensör tipini belirtiyorz (DHT11 mi DHT22 mi)

DHT dht(DHTPIN, DHTTYPE); // Burada DHT class'ından dht nesnesi oluşturup pini ve çeşidini veriyoruz

void setup() {
  Serial.begin(9600);
  dht.begin();           // Sensörü başlattığımız yer
}

void loop() {
  float temperature = dht.readTemperature(); // Sıcaklık °C ölçümünü yapar Celcius cinsinden
  float humidity = dht.readHumidity();       // Nem % ölçmünü yapar yüzdelik şekilde

  // Eğer okuma başarısız olursa NaN döner, bu kontrol edilir (Kontrol noktası)
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT sensöründen veri alınamadı!");
  } else { //Direkt burada yazımı yaparız
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C\tHumidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }

  delay(1000); // 1 saniye bekle
}