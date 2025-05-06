#include <Servo.h>
#define motor1Pin 5  // Motor 1 control (via MOSFET)
#define motor2Pin 6  // Motor 2 control (via MOSFET)

Servo myservo1;
Servo myservo2;

int azimuthpos = 90;
int verticalpos = 90;
void setup() {
  // Set motor control pins as OUTPUT
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  myservo1.attach(9);
  myservo2.attach(10);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Azimuth servo angle: ");
  Serial.print(azimuthpos);
  Serial.print('\n');
  Serial.print("Vertical servo angle: ");
  Serial.println(verticalpos);

    delay(50);

  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'O') {
      azimuthpos = max(0, azimuthpos - 10); 
      myservo1.write(azimuthpos); 
    }
    if (command == 'P') {
      azimuthpos = min(180, azimuthpos + 10);
      myservo1.write(azimuthpos); 
    }
    if (command == 'Q') {
      verticalpos = max(40, verticalpos - 10); 
      myservo2.write(verticalpos); 
    }
    if (command == 'E') {
      verticalpos = min(180, verticalpos + 10); 
      myservo2.write(verticalpos);  
    }
    if (command == 'F') {
      digitalWrite(motor1Pin, HIGH);
      digitalWrite(motor2Pin, HIGH);
    }
    else if (command == 'L') {
      digitalWrite(motor1Pin, LOW);
      digitalWrite(motor2Pin, HIGH);
    }
    else if (command == 'R') {  
      digitalWrite(motor1Pin, HIGH);
      digitalWrite(motor2Pin, LOW);
    }
    else if (command == 'S') { 
      digitalWrite(motor1Pin, LOW);
      digitalWrite(motor2Pin, LOW);
    }
  }
}
