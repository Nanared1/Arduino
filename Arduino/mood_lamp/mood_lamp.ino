float RGB1[3];
float RGB2[3];
float INC[3];

int red, green, yellow;

int redPin = 9;
int yellowPin = 10;
int greenPin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));

  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;

  RGB2[0]=random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);

  /*pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  randomSeed(analogRead(0));
  
  for(int i = 0; i < 3; i++){
    INC[i] = (RGB1[i] - RGB2[i])/256;
  }

  for(int i = 0; i < 256; i++){
    red = int(RGB1[0]);
    yellow = int(RGB1[1]);
    green = int(RGB1[2]);

    analogWrite(redPin, red);
    analogWrite(yellowPin, yellow);
    analogWrite(greenPin, green);
    delay(100);

    RGB1[0] -= INC[0];
    RGB1[1] -= INC[1];
    RGB1[2] -= INC[2];
  }
  for(int i = 0; i < 3; i++){
    RGB2[i] = random(556) - 300;
    RGB2[i] = constrain(RGB2[i], 0, 255);
    delay(1000);
  }
}
