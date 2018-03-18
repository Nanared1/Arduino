
int speakerPin = 9;
int length = 15;
char notes[] = "ccggaagffeeddc  ";
int beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};
int tempo = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(speakerPin, OUTPUT);
}

void playTone(int tone, int duration){
  for(long i = 0; i < duration*1000L; i += tone*2){
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration){
  char names[] = {'c','d','e','f','g','a','b','c'};
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
  for(int i = 0; i < 8; i++){
     if(names[i] == note){
      playTone(tones[i], duration);
     }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i< length; i++){
    if(notes[i] == ' '){
      delay(beats[i]*tempo);
    }else{
      playNote(notes[i], beats[i]*tempo);
    }
    delay(tempo/2);
  }
}
