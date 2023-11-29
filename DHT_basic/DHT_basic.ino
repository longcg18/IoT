
#include<DHT.h>

#define DHTTYPE DHT11
#define DHTPIN D2 // Luu y, ne' cai chan D0 ra ho. cai'

DHT dht(DHTPIN, DHTTYPE);

float temp;
float humid;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  temp = dht.readTemperature();
  humid = dht.readHumidity();

  Serial.print("Nhiet do: ");
  Serial.print(temp);
  Serial.println(" oC");

  Serial.print("Do am: ");
  Serial.print(humid);
  Serial.println(" %");
}
