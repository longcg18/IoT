// MQ2 Gas Sensor

const int Gas_analog = A0;
const int Gas_digital = D2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Gas_analog, INPUT);
  pinMode(Gas_digital, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  Serial.print("Gas digital: "); 
  Serial.println(Gas_digital);

  Serial.print("Gas analog: "); // if analog > 500 : co' ga
  Serial.println(Gas_analog);
}
