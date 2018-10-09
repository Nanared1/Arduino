/*
 * Nana Abekah                    *
 * Sometime mid March(20s), 2018  *
 * CETA basic line follower       *
*/


//motors and sensors ports
const int pwm_left = 6;
const int pwm_right = 5;
const int direct_1 = 4;
const int direct_2 = 7;
const int qti_right = A1;
const int qti_left = A0;

// qti clear value;
const int qtiClear = 100;
const int qtiOff = 920;
//Motor speeds
const int on_track_power = 250;
const int off_track_power = 90;
const int straight_power = 255;

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

bool left, right = false;
void loop() {
  
  // put your main code here, to run repeatedly:
  int right_val = analogRead(qti_right);
  int left_val = analogRead(qti_left);  
  Serial.print(right_val);
  Serial.println("    Right side");
  Serial.print(left_val);
  Serial.println("    Left side");
  if(right_val > qtiClear && left_val > qtiClear){
    right_motors(straight_power);
    left_motors(straight_power);
  }
  else if(left_val > qtiClear){
    right_motors(on_track_power);
    left_motors(off_track_power);
    left = true;
    right = false;
  }
  else if(right_val > qtiClear ){
    right_motors(off_track_power);
    left_motors(on_track_power);
    left = false;
    right = true;
  }
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


