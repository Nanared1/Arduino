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
const int qtiOn = 150;
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
  //int mid_val =  analogRead(qti_mid);

  if(right_val < qtiOn && left_val < qtiOn){
      right_motors(60); // 60
      left_motors(75); // 75
//      unsigned long startTime = millis();  //Start counting
//      unsigned long elapsedTime = 0 - startTime;
//      if((startTime - elapsedTime) > 0 && (startTime - elapsedTime) < 500){
//        Serial.println((startTime - elapsedTime));
//        startTime++;
//        right_motors(70); // 60
//        left_motors(85); // 75
//      }
      //Serial.println("slow");
  }
  if(right_val < qtiOn && left_val > qtiOn){
    right_motors(75); //75
    left_motors(0);
  }
  if(right_val > qtiOn && left_val < qtiOn){
    right_motors(0); 
    left_motors(65); //65
  }
 
 //delay(5);
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


