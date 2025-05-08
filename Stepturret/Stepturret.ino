#include <Servo.h>

Servo myServo1;
Servo myServo2;

void setup() {
  Serial.begin(9600);
  myServo1.attach(9);
  myServo1.write(90);    

  myServo2.attach(6);
  myServo2.write(90);      
}

void loop() {

  if (Serial.available() > 0) {
    int angle1 = Serial.parseInt();       
    int angle2 = Serial.parseInt();
  
    if (angle1 >= 0 && angle1 <= 180 && angle2 >= 0 && angle2 <= 180) {

      myServo1.write(angle1);               // move servo to that angle
      myServo2.write(angle2);
      Serial.print("Servo1 set to "); 
      Serial.println(angle1);
      Serial.print("Servo2 set to ");
      Serial.println(angle2);

    } 

    else {
      Serial.println("Angle out of range");
    }

    while (Serial.available() > 0) Serial.read();
  }
}
