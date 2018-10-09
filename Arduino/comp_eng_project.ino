//int RELAY1 = 8;
////int in2 = 8;
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(RELAY1, OUTPUT);
//  //pinMode(in2, OUTPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  int val = Serial.read() - '0';
//  if (val == 1) { // test for command 1 then turn on LED
//    //Serial.println("RELAY on");
//    digitalWrite(RELAY1, LOW); // turn on LED
//    Serial.println("led off");
//
//  }
//  else if (val == 0) // test for command 0 then turn off LED
//  {
//    // Serial.println("RELAY OFF");
//    digitalWrite(RELAY1, HIGH); // turn off LED
//    Serial.println("led ON");
//  }
//  Serial.println("Arduino program");
//  delay(500);
//}


/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/









//// include the library code:
//#include <LiquidCrystal.h>
//
//// initialize the library by associating any needed LCD interface pin
//// with the arduino pin number it is connected to
//const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, on = 11, off = 12, potPin = A0, soundPin = A2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//void setup() {
//  // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
//  // Print a message to the LCD.
//  
//  lcd.print("User INT");
//  pinMode(on, INPUT);
//  pinMode(off, INPUT);
//  pinMode(potPin, INPUT);
//  pinMode(soundPin, INPUT_PULLUP);
//  Serial.begin(9600);
//}
//
//int on_off = 0;
//
//void loop() {
//  // set the cursor to column 0, line 1
//  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(0, 1);
//  // print the number of seconds since reset:
//  if(digitalRead(on) == HIGH){
//    on_off = 1;
//  }
//  if(digitalRead(off) == HIGH){
//    on_off = 0;
//  }
//  lcd.print(on_off);
//  Serial.print(digitalRead(off));
//  Serial.print(digitalRead(on));
//  Serial.println();
//
//  lcd.setCursor(4,1);
//  lcd.print("Sound:");
//  lcd.setCursor(11,1);
//  lcd.print(analogRead(soundPin));
//  delay(500);
//}



//int val;
//int encoder0PinA = 10;
//int encoder0PinB = 9;
//int encoder0Pos = 5;
//int encoder0PinALast = LOW;
//int n = LOW;
//
//void setup() {
//  pinMode (encoder0PinA, INPUT);
//  pinMode (encoder0PinB, INPUT);
//  Serial.begin (9600);
//}
//
//void loop() {
//  n = digitalRead(encoder0PinA);
//  if ((encoder0PinALast == LOW) && (n == HIGH)) {
//    if (digitalRead(encoder0PinB) == LOW) {
//      encoder0Pos--;
//    } else {
//      encoder0Pos++;
//    }
//    Serial.println(encoder0Pos);
//    //Serial.print ("/");
//  }
//  encoder0PinALast = n;
//}

 
// #define outputA 10
// #define outputB 11
// int counter = 0; 
// int aState;
// int aLastState;  
// void setup() { 
//   pinMode (outputA,INPUT_PULLUP);
//   pinMode (outputB,INPUT_PULLUP);
//   
//   Serial.begin (9600);
//   // Reads the initial state of the outputA
//   aLastState = digitalRead(outputA);   
// } 
// void loop() { 
//   aState = digitalRead(outputA); // Reads the "current" state of the outputA
//   // If the previous and the current state of the outputA are different, that means a Pulse has occured
//   if (aState != aLastState){     
//     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
//     if (digitalRead(outputB) != aState) { 
//       counter ++;
//     } else {
//       counter --;
//     }
//     Serial.print("Position: ");
//     Serial.println(counter);
//   } 
//   aLastState = aState; // Updates the previous state of the outputA with the current state
// }













