/*
 * Nana Abekah                    *
 * April 3rd 2018                 *
 * CETA basic PID line follower   *
*/

int qti_setPoint = 200;
int MAX_SPEED = 100;
int BASE_SPEED = 60;
int errorM = 12;
//motors and sensors ports
const int pwm_left = 9;
const int pwm_right = 11;
const int direct_1 = 12;
const int direct_2 = 8;
const int qti_right = A0;
const int qti_left = A1;
const int qti_mid = A2;

// qti clear value;
const int qtiClear = 200;

//Motor speeds
const int on_track_power = 200;
const int off_track_power = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm_left, OUTPUT);
  pinMode(pwm_right, OUTPUT);
  pinMode(direct_1, OUTPUT);
  pinMode(direct_2, OUTPUT);
  pinMode(qti_right, INPUT_PULLUP);//Check to make sure this works
  pinMode(qti_left, INPUT_PULLUP);
  pinMode(qti_mid, INPUT_PULLUP);
  Serial.begin(9600);
}

//PID Constants
const float kP = 0.6;
const float kD = 0;
int error, lastError, error_D, output;
void loop() {
  // put your main code here, to run repeatedly:
  int right_val = analogRead(qti_right);
  int left_val = analogRead(qti_left); 
  int mid_val = analogRead(qti_mid); 

  if(right_val < qti_setPoint && mid_val < qti_setPoint && left_val > qti_setPoint){
    error = -1*errorM;
  }else if(right_val < qti_setPoint && mid_val > qti_setPoint && left_val < qti_setPoint){
    error = 0;
  }else if(right_val > qti_setPoint && mid_val < qti_setPoint && left_val < qti_setPoint){
    error = 1*errorM;
  }else{
    if(error == -1*errorM || error == -2*errorM){
      error = -2*errorM;
    }else{
      error = 2*errorM;
    }
  }
  error_D = error - lastError;
  output = (error*kP) + (error_D*kD);
  lastError = error;

  int left_speed = BASE_SPEED + output;
  int right_speed = BASE_SPEED - output ;


  if(right_speed > MAX_SPEED) right_speed  = MAX_SPEED;
  if(left_speed > MAX_SPEED) left_speed  = MAX_SPEED;
  if(right_speed < 0) right_speed  = 0;
  if(left_speed < 0) left_speed  = 0;
 
  //right_motors(right_speed);
  //left_motors(left_speed);
  
  Serial.print("Left Value: ");
  Serial.print(left_val);
  Serial.print("     Mid Value: ");
  Serial.print(mid_val);
  Serial.print("     Right Value: ");
  Serial.print(right_val);
  Serial.print("     Error: ");
  Serial.print(output);
  Serial.print("     Right Speed: ");
  Serial.print(right_speed);
  Serial.print("     Left Speed: ");
  Serial.println(left_speed);
  delay(10);
}

void left_motors(int power){
   digitalWrite(direct_1, LOW);
   digitalWrite(direct_2, HIGH);
   analogWrite(pwm_left, power);
}

void right_motors(int power){
   digitalWrite(direct_1, LOW);
   digitalWrite(direct_2, HIGH);
   analogWrite(pwm_right, power);
}


