#define Kp 5.1
#define Ki 0
#define Kd 0
#define maxSL 190
#define maxSR 200
#define minS 0
#define baseL 140
#define baseR 150

#define dir1 8
#define dir2 12
#define pwmL 9
#define pwmR 11

#define sensL A1
#define sensR A0
#define sensAvg 100
#define noise 50

int targetL, targetR, diffL, diffR, error, lastError = 0;
int offsetSpeed, speedL, speedR = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwmL, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(sensL, INPUT_PULLUP);
  pinMode(sensR, INPUT_PULLUP);

  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);

  int sumL, sumR = 0;

  for(int i=0; i<sensAvg; i++) {
    sumL += analogRead(sensL);
    sumR += analogRead(sensR);
    delay(5);
  }

  targetL = sumL/sensAvg;
  targetR = sumR/sensAvg;

  Serial.println(targetL, targetR);
}

void loop() {
  diffL = abs(targetL-analogRead(sensL))*-1;
  diffR = abs(targetR-analogRead(sensR));

  if (diffL < noise) diffL = 0;
  if (diffR < noise) diffR = 0;

  if (diffR != 0) error = diffR;
  else if (diffL != 0) error = diffL;
  else error = 0;

  offsetSpeed = Kp * error + Kd * (error - lastError) + Ki * (error + lastError);
  lastError = error;

  speedL = baseL + offsetSpeed;
  speedR = baseR - offsetSpeed;

  if (speedL > maxSL) speedL = maxSL;
  else if (speedL < minS) speedL = minS;
  if (speedR > maxSR) speedR = maxSR;
  else if (speedR < minS) speedR = minS;

  analogWrite(pwmL, speedL);
  analogWrite(pwmR, speedR);

  delay(10);
}
