int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void shift_Out(byte dataOut){
  boolean pinState;
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for(int i = 0; i <= 7; i++){
    digitalWrite(clockPin, LOW);
    if(dataOut && (1<<i)){
      pinState = HIGH;
    }else{
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(clockPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    digitalWrite(latchPin, LOW);
    shift_Out(i);
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
