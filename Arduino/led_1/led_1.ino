
int Led_Pin = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led_Pin, OUTPUT);
}

void blips(int time_, int counts){
  int num = 0;
  while(num <= counts){
    digitalWrite(Led_Pin, HIGH);
    delay(time_);
    digitalWrite(Led_Pin, LOW);
    delay(time_);
    num++;
  }
}
int counter = 0;
void loop() {
  // put your main code here, to run repeatedly:
  while(counter < 5){
    blips(200, 3);
    blips(1000, 3);
    blips(200, 3);
    delay(2000);
    counter++;
  }
}
