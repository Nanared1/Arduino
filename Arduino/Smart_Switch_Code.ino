#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int off = 8, on = 9, rot_enc_A = 10, rot_enc_B = 11, soundPin = A2, relay = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("Welcome");
  lcd.setCursor(5, 1);
  lcd.print("Nana A.");
  pinMode(off, INPUT);
  pinMode(on, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(rot_enc_A, INPUT_PULLUP);
  pinMode(rot_enc_B, INPUT_PULLUP);
  pinMode(soundPin, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int relay_state = HIGH;
int aState;
int aLastState;
int counter = 0;

void initiate(){
  delay(1000);
  lcd.clear();
  digitalWrite(relay, relay_state);
  lcd.setCursor(3,0);
  lcd.print("Device OFF");
}

int read_enc(){
  do{
     aState = digitalRead(rot_enc_A); // Reads the "current" state of the outputA
     // If the previous and the current state of the outputA are different, that means a Pulse has occured
     if (aState != aLastState){     
       // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
       if (digitalRead(rot_enc_B) != aState) { 
         counter ++;
       } else {
         counter --;
       }
       Serial.print("Position: ");
       Serial.println(counter);
     } 
     aLastState = aState; // Updates the previous state of the outputA with the current state
  }while(digitalRead(off) != 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  initiate();
  while(1){
    lcd.setCursor(2,1);
    lcd.print("ON");
    lcd.setCursor(12,1);
    lcd.print("OFF");
    lcd.setCursor(6,1);
    lcd.print(analogRead(soundPin));
    
    if(digitalRead(off) == HIGH){
      relay_state = LOW;
      lcd.setCursor(3,0);
      lcd.print("Device ON ");
      //digitalWrite(relay, relay_state);
    }

    if(digitalRead(on) == HIGH){
      relay_state = HIGH;
      lcd.setCursor(3,0);
      lcd.print("Device OFF");
    }

    if(analogRead(soundPin) >= 1011){
      if(relay_state == HIGH){
        relay_state = LOW;
        lcd.setCursor(3,0);
        lcd.print("Device ON ");
        delay(550);
      }else{
        relay_state = HIGH;
        lcd.setCursor(3,0);
        lcd.print("Device OFF");
        delay(550);
      }
    }
    digitalWrite(relay, relay_state);
    Serial.println(analogRead(soundPin));
    delay(100);
  }
}
