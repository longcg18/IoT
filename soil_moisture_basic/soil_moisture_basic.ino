// Khong can chan Digital

const int analog_pin = A0;
float soil_humid;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(analog_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:  
  soil_humid = ( 100.00 - ( (analogRead(analog_pin)/1024.00) * 100.00 ) );

  Serial.print("Do am dat: ");
  Serial.print(soil_humid);
  Serial.println("%")
  delay(2000);
}
