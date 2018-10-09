const int pwm_1 = 5;
//const int in_1 = 3;
//const int in_2 = 4;
const int qtiR = A0;
const int qtiL = A1;
//motor pins go to digital
//pwm goes to analog
//M.P recieves HIGH and LOW states; PWM receives input for motor power.
#define in1 12          // Motor Output
#define in2 8
#define pwmL 9
#define pwmR 11
void setup() {
  // put your setup code here, to run once:
  pinMode(pwmL, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(qtiL, INPUT_PULLUP);
  pinMode(qtiR, INPUT_PULLUP);
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:

  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwmL, 190);
  analogWrite(pwmR, 200);
  /*Serial.print("Left Value: ");
  Serial.print(analogRead(qtiL));
  Serial.print("     Right Value: ");
  Serial.println(analogRead(qtiR));*/
  //delay(1000);

  
}
