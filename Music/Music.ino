int musicpinA = 2;
int musicpinB = 4;
int musicpinC = 8;
int musicpinD = 12;
int potpinA = 3;
int potpinB = 5;
int potpinC = 6;
int potpinD = 10;


void setup() {
  Serial.begin(9600);


  pinMode(musicpinA, INPUT);
  pinMode(musicpinB, INPUT);
  pinMode(musicpinC, INPUT);
  pinMode(musicpinD, INPUT);


  pinMode(potpinA, OUTPUT);
  pinMode(potpinB, OUTPUT);
  pinMode(potpinC, OUTPUT);
  pinMode(potpinD, OUTPUT);
}


void loop() {
  int stateA = digitalRead(musicpinA);
  int stateB = digitalRead(musicpinB);
  int stateC = digitalRead(musicpinC);
  int stateD = digitalRead(musicpinD);


  if (stateA == HIGH) {
    tone(potpinA, 294);
    Serial.print("n");
  } else {
    noTone(potpinA);
  }


  if (stateB == HIGH) {
    tone(potpinB, 277.183);
    Serial.print("a");
  } else {
    noTone(potpinB);
  }


  if (stateC == HIGH) {
    tone(potpinC, 349);
  } else {
    noTone(potpinC);
  }      
 
  if (stateD == HIGH) {
    tone(potpinD, 440);
  } else {
    noTone(potpinD);
  }


  delay(10);
}






