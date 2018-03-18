int ledPin = 6;
int ldrPin = 0;
int lightVal = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(ldrPin);
  digitalWrite(ledPin, HIGH);
  delay(lightVal);
  digitalWrite(ledPin, LOW);
  delay(lightVal);
}
