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
  diffL = abs(targetL-analogRead(sensL));
  diffR = abs(targetR-analogRead(sensR));

  // Filter input
  if (diffL < noise) diffL = 0;
  if (diffR < noise) diffR = 0;

  // Get error
  if (diffR != 0) error = diffR;
  else if (diffL != 0) error = diffL*-1;
  else error = 0;

  // Calculate speed offset
  offsetSpeed = Kp * error + Kd * (error - lastError) + Ki * (error + lastError);
  lastError = error;

  // Calculate motor speed
  speedL = baseL + offsetSpeed;
  speedR = baseR - offsetSpeed;

  // Filter motor speed
  if (speedL > maxSL) speedL = maxSL;
  else if (speedL < minS) speedL = minS;
  if (speedR > maxSR) speedR = maxSR;
  else if (speedR < minS) speedR = minS;

  // Output motor speed
  analogWrite(pwmL, speedL);
  analogWrite(pwmR, speedR);

  delay(10);
}

