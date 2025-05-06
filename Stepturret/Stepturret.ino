#include <Servo.h>
#define motor1Pin 6
#define motor2Pin 9

Servo myservo1;
Servo myservo2;

int azimuthpos = 90;
int verticalpos = 90;

void setup() {

pinMode(motor1Pin, OUTPUT);
pinMode(motor2Pin, OUTPUT);
myservo1.attach(6);
myservo2.attach(9);
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("Azimuth servo angle: ");
  Serial.print(azimuthpos);

  Serial.print('\n');

  Serial.print("Vertical servo angle: ");
  Serial.println(verticalpos);
   delay(50);


myservo1.write(azimuthpos);
myservo2.write(verticalpos);


  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'O') {
      azimuthpos = max(0, azimuthpos - 10); 
      myservo1.write(azimuthpos); 
    }
    if (command == 'i') {
      azimuthpos = max(0, azimuthpos + 10); 
      myservo1.write(azimuthpos); 
    }

  }
}