const int car_red = 10;
const int car_yellow = 9;
const int car_green = 8;

const int peds_red = 11;
const int peds_green = 13;
const int bumper = 2;

const int cross_time = 5000;

unsigned long changeTime;
void setup() {
  // put your setup code here, to run once:
  pinMode(car_red, OUTPUT);
  pinMode(car_yellow, OUTPUT);
  pinMode(car_green, OUTPUT);
  pinMode(peds_red, OUTPUT);
  pinMode(peds_green, OUTPUT);

  pinMode(bumper, INPUT);

  digitalWrite(car_green, HIGH);
  digitalWrite(peds_red, HIGH);
}

void changeLights(){
  digitalWrite(car_green, LOW);
  digitalWrite(car_yellow, HIGH);
  delay(2000);

  digitalWrite(car_yellow, LOW);
  digitalWrite(car_red, HIGH);
  delay(1000);

  digitalWrite(peds_red, LOW);
  digitalWrite(peds_green, HIGH);
  delay(cross_time);

  for(int i = 0; i < 10; i++){
    digitalWrite(peds_green, HIGH);
    delay(250);
    digitalWrite(peds_green, LOW);
    delay(250);
  }

  digitalWrite(peds_red, HIGH);
  delay(500);

  digitalWrite(car_yellow, HIGH);
  digitalWrite(car_red, LOW);
  delay(1000);

  digitalWrite(car_yellow, LOW);
  digitalWrite(car_green, HIGH);

  changeTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(bumper);
  if(state == HIGH && (millis() - changeTime) > 5000){
    changeLights();
  }
}
