int potPin = 0;
float temperature = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("LM35 Temperature    ");
  analogReference(INTERNAL);
}

void printTenths(int value){
  Serial.print(value / 10);
  Serial.print(".");
  Serial.print(value % 10);
}

void loop() {
  // put your main code here, to run repeatedly:
  int span = 20;
  int aRead = 0;
  for(int i = 0; i < span; i++){
    aRead += analogRead(potPin);
  }
  aRead /= 20;
  temperature  = ((100*1.1*aRead)/1024)*10;
  Serial.println("Analog in reading: ");
  Serial.print(long(aRead));
  Serial.println(" - Calculated Temp: ");
  printTenths(long(temperature));
  delay(500);
}
