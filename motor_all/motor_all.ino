/*
 		Board pin | NodeMCU GPIO | 	Arduino IDE
 					A- 										1 												5 or D1
 					A+ 										3 												0 or D3
 					B- 										2 												4 or D2
 					B+ 										4 												2 or D4
*/

const int pwmMotorA = D1;
const int dirMotorA = D3;

int motorSpeed = 0;

void setup() {
 	Serial.begin(115200);
 	Serial.println();

 	pinMode(pwmMotorA , OUTPUT);
 	pinMode(dirMotorA, OUTPUT);

 	Serial.println("Motor SHield 12E Initialized");
 	delay(2000);
}

void loop() {
  // motorSpeed = 100;

  digitalWrite(dirMotorA, HIGH);
  while (motorSpeed < 100) {
    //Serial.println(motorSpeed);
    analogWrite(pwmMotorA, motorSpeed);
    delay(1000);
    motorSpeed += 10;
  }

  delay(2000);

  digitalWrite(dirMotorA, LOW);
  while (motorSpeed > 0) {
    //Serial.println(motorSpeed);
    analogWrite(pwmMotorA, motorSpeed);
    
    delay(1000);
    motorSpeed -= 10;
  }





}