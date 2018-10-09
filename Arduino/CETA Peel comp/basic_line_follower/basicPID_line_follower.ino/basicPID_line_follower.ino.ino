/*
 * Nana Abekah                    *
 * April 3rd 2018                 *
 * CETA basic PID line follower   *
*/

#define qti_setPoint 70
#define MAX_SPEED 255

//motors and sensors ports
const int pwm_left = 6;
const int pwm_right = 5;
const int direct_1 = 4;
const int direct_2 = 7;
const int qti_right = A1;
const int qti_left = A0;

// qti clear value;
const int qtiClear = 100;

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
  Serial.begin(9600);
}

//PID Constants
const float kP = .10;
const float kI = 0;
const float kD = .05;

bool on_right_last, on_left_last;
bool left, right = false;
void loop() {
  // put your main code here, to run repeatedly:
  int right_val = analogRead(qti_right);
  int left_val = analogRead(qti_left);  

  float error, lastError, error_D, output, erroInte;
  int sensor_val = 0;
  if(right_val > qti_setPoint){
    sensor_val = right_val;
    //Serial.print(sensor_val);
    //Serial.println("  Right side");
  }
  if(left_val > qti_setPoint){
    sensor_val = left_val;
    //Serial.print(sensor_val);
    //Serial.println("  Left Side");
  }
  if(left_val < qti_setPoint && right_val < qti_setPoint){
    sensor_val = (left_val+right_val)/2;
    //Serial.print(sensor_val);
    //Serial.println("  Both Sides");
  }
  
  error = sensor_val-qti_setPoint;
  //erroInte = constrain(erroInte + error, -50, 50);
  error_D = error - lastError;
  output = ((error*kP) + (error_D*kD) + (erroInte*kI));
  lastError = error;

  int speed_1 = MAX_SPEED + output;
  int speed_2 = MAX_SPEED - output;

  if(speed_1 > MAX_SPEED){  speed_1 = MAX_SPEED;  }
  if(speed_2 > MAX_SPEED){ speed_2 = MAX_SPEED; }
  if(speed_1 < 0){  speed_1 = 0;  }
  if(speed_2 < 0){ speed_2 = 0; }

  int right_speed, left_speed = 0;
  /*if(left_val > qtiClear ){
    right_speed = speed_2;
    left_speed = speed_1;
  }
  if(right_val > qtiClear ){
    right_speed = speed_1;
    left_speed = speed_2;
  }
  if(right_val < qtiClear && left_val < qtiClear){
    right_speed = speed_1;
    left_speed = speed_1;
  }*/

  if(left_val > qtiClear || right_val > qtiClear){
    if(left_val > qtiClear ){
      right_speed = speed_2;
      left_speed = speed_1;
      left = false; // true
      right = false;
    }
    if(right_val > qtiClear ){
      right_speed = speed_1;
      left_speed = speed_2;
      left = false;
      right = false; // true
    }
  }else{
    if(left){
      right_speed = speed_1;
      left_speed = speed_2;
    }else if(right){
      right_speed = speed_2;
      left_speed = speed_1;
    }else{
      right_speed = speed_1;
      left_speed = speed_1;
    }
  }

  right_motors(left_speed/1.2);
  left_motors(right_speed/1.2);

  Serial.print("Left Speed: ");
  Serial.print(right_speed);
  Serial.print("     Right Speed");
  Serial.println(left_speed);
  delay(1);
}

void left_motors(int power){
   digitalWrite(direct_1, HIGH);
   digitalWrite(direct_2, LOW);
   analogWrite(pwm_left, power);
}

void right_motors(int power){
   digitalWrite(direct_1, HIGH);
   digitalWrite(direct_2, LOW);
   analogWrite(pwm_right, power);
}


