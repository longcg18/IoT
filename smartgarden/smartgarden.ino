/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6AJUTQIjL"
#define BLYNK_TEMPLATE_NAME "Smart garden"
#define BLYNK_AUTH_TOKEN "oF-HGZSOAzOnsKaNqetQcK2nmYmBHGYe"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#include "DHT.h"
#include "Servo.h"

const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */
const int dht_pin = D4;
const int dht_type = DHT11;
const int servo_pin = D2;


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "510B";
char pass[] = "hoilamdeogi";

int lightSensor = 0;
double h, t, s;
int light;
 
DHT dht(dht_pin, dht_type);

BlynkTimer timer;

void myTimer() {
  Blynk.virtualWrite(V1, lightSensor);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  pinMode(2, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimer); 
  dht.begin();
  light = 0;
}



void loop()
{
  s = ( 100.00 - ( (analogRead(sensor_pin)/1024.00) * 100.00 ) );
  h = dht.readHumidity();    
  t = dht.readTemperature();

  if(h <= 50 || s <= 50 || t >= 30)
  {
    light = 1;
  }
  else
  {
    light = 0;  
  }
  Serial.print("Nhiet do: ");
  Serial.println(t);               
  Serial.print("Do am khong khi: ");
  Serial.println(h);
  Serial.print("Do am dat:");
  Serial.println(s);

  Blynk.run();
  Blynk.virtualWrite(V5, s);
  Blynk.virtualWrite(V3, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, light);

  timer.run();
}