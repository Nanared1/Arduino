/*
 * Nana Abekah                    *
 * Sometime mid March(20s), 2018  *
 * CETA basic line follower       *
*/


//motors and sensors ports
const int pwm_left = 9;
const int pwm_right = 11;
const int direct_1 = 8;
const int direct_2 = 12;
const int qti_right = A0;
const int qti_left = A1;
const int qti_mid = A2;

// qti clear value;
const int qtiOn = 600;
const int qtiOff = 60;
//Motor speeds
const int on_track_power = 200;
const int off_track_power = 90;
const int straight_power = 215;

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
int rs, ls;
bool left, right = false;
bool chk = false;
void loop() {
  // put your main code here, to run repeatedly:
  int right_val = analogRead(qti_right);
  int left_val = analogRead(qti_left);  
  int mid_val =  analogRead(qti_mid);
  
  Serial.print(right_val);
  Serial.println("    Right side");
  Serial.print(left_val);
  Serial.println("    Left side");
  if(left_val > qtiOn || right_val > qtiOn){
    if(right_val > qtiOn  && left_val > qtiOn){
      //right_motors(straight_power);
      //left_motors(straight_power);
      rs = 0;
      ls = 0;
      right = false;
      left = false;
    }
    else if(left_val > qtiOn && right_val < qtiOn){
      rs = 30;
      ls = -30;
      left = true;
      right = false;
    }
    else /*(right_val > qtiClear )*/{
      rs = -30;
      ls = 30;
      right = true;
      left = false;
    }
  }else if(right_val < qtiOn && left_val < qtiOn ){
    if(left){
      rs = 55;
      ls = -100;
    }else if(right){
      rs = -100;
      ls = 55;
    }
    right = false;
    left = false;
    chk = true;
  }

  right_motors(60 + rs);
  left_motors(60 + ls);
/*
  while(chk == true && (analogRead(qti_left) < qtiOn || analogRead(qti_right) < qtiOn)) {
    chk = false;
  }
*/  
  /*Serial.print("Left Val: ");
  Serial.print(left_val);
  Serial.print("  Right Val: ");
  Serial.println(right_val);
  delay(1000);*/
 
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


