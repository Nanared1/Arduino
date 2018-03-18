byte ledPin[] = {4,5,6,7,8,9,9,10,11,12,13};
int ledDelay;
int direction_LED = 1;
int currentLed = 0;
unsigned long changeTime;
int potPin = 2;

void setup() {
  for(int i = 0; i <= 10; i++){
    pinMode(ledPin[i], OUTPUT);
    
  }
  changeTime = millis();
}

void changeLed(){
  for(int i = 0; i <= 10; i++){
    digitalWrite(ledPin[i], LOW);
  }
  digitalWrite(ledPin[currentLed], HIGH);
  currentLed+=direction_LED;
  if(currentLed == 10){  direction_LED = -1; }
  if(currentLed == 0){  direction_LED = 0;  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ledDelay = analogRead(potPin);
  if((millis()-changeTime) > ledDelay){
    changeLed();
    changeTime = millis();
  }
}
