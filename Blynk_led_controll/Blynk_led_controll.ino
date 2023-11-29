#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL65dP4nhbs"
#define BLYNK_TEMPLATE_NAME "1stBlynk"
#define BLYNK_AUTH_TOKEN "RJ4WawBYTFcRUVBkII-ssHMCtAA-hAFu"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "510B";
char pass[] = "hoilamdeogi";

const int LED = D2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V1) {
  if (param.asInt() == 1) {
    digitalWrite(LED, HIGH);
    Serial.println("ON");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("OFF");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
