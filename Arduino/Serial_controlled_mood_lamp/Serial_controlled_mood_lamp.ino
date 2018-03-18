char buffer[18];
int red, green, yellow;

int redPin = 9;
int yellowPin = 10;
int greenPin = 11;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.flush();
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void splitString(char* data){
  Serial.print("Data Entered: ");
  Serial.println(data);
  char* parameter;
  parameter = strtok(data, " ,");

  while(parameter != NULL){
    setLed(parameter);
    parameter = strtok(NULL, " ,");
  }

  for(int i = 0; i < 16; i++){
    buffer[i] = '\0';
  }
  Serial.flush();
}


void setLed(char* data){
  if((data[0] == 'r') || (data[0] == 'R')){
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(redPin, Ans);
    Serial.print("Red is set to go: ");
    Serial.println(Ans);
  }
  if((data[0] == 'g') || (data[0] == 'G')){
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(greenPin, Ans);
    Serial.print("Green is set to go: ");
    Serial.println(Ans);
  }
  if((data[0] == 'b') || (data[0] == 'B')){
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(yellowPin, Ans);
    Serial.print("yellow is set to go: ");
    Serial.println(Ans);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    int index = 0;
    delay(100);
    int numChar = Serial.available();
    if(numChar > 15){
      numChar = 15;
    }
    while(numChar--){
      buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}
