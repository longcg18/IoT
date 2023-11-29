const int RED = D0;
const int YEL = D1;
const int GRE = D2;



void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YEL, OUTPUT);
  pinMode(GRE, OUTPUT);

  digitalWrite(GRE, LOW);
  digitalWrite(YEL, LOW);
  digitalWrite(RED, LOW);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(RED, HIGH);
  delay(2000);
  digitalWrite(RED, LOW);

  digitalWrite(GRE, HIGH);
  delay(2000);
  digitalWrite(GRE, LOW);

  digitalWrite(YEL, HIGH);
  delay(2000);
  digitalWrite(YEL, LOW);
}
