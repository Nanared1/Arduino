//----------------------Constants-------//
#define Kp 1.0         // PID
#define Ki 0
#define Kd 0

#define sensL A1        // Sensor Input
#define sensR A0
#define sensAvg 100
#define noise 50

#define dir1 8          // Motor Output
#define dir2 12
#define pwmL 9
#define pwmR 11

#define baseL 100       // Motor Speed
#define baseR 80
#define maxSL 190
#define maxSR 200
#define minS 0

//----------------------------------------Variables------------//
int targetL, targetR, sumL, sumR = 0;     // Input Threshold
int diffL, diffR, error, lastError = 0;   // Error Calculation
int offsetSpeed, speedL, speedR = 0;      // Motor Speed

void setup() {
  Serial.begin(9600);

  // Initialise I/O
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwmL, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(sensL, INPUT_PULLUP);
  pinMode(sensR, INPUT_PULLUP);

  // Set forward motor direction
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);

  // Get input range
  for(int i=0; i<sensAvg; i++) {
    sumL += analogRead(sensL);
    sumR += analogRead(sensR);
    delay(5);
  }

  // Get input average
  targetL = sumL/sensAvg;
  targetR = sumR/sensAvg;

  Serial.println(targetL, targetR);
}

void loop() {
  // Get input
  diffL = analogRead(sensL);
  diffR = analogRead(sensR);
  int left = false, right = false;

  // Get error
  /*if(diffL < 100 && diffR < 100){
    right_motors(80);
    left_motors(90);
    right = false;
    left = false;
  }*/
  if(diffL > 100){
    right_motors(80);
    left_motors(0);
    right = true;
    left=false;
  }else if(diffR > 100){
    left_motors(80);
    right_motors(0);
    right = false;
    left = true;
  }else{
    if(right){
      right_motors(85);
      left_motors(0);
      right = false;
    }else if(left){
      right_motors(0);
      left_motors(85);
      left = false;
    }else{
      left_motors(70);
      right_motors(70);
    }
  }

  delay(10);
}
void left_motors(int power){
   digitalWrite(dir1, HIGH);
   digitalWrite(dir2, LOW);
   analogWrite(pwmL, power);
}

void right_motors(int power){
   digitalWrite(dir1, HIGH);
   digitalWrite(dir2, LOW);
   analogWrite(pwmR, power);
}


