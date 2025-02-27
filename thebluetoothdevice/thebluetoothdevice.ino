// Define motor pins
#define motor1Pin 3  // Motor 1 control (via MOSFET)
#define motor2Pin 5  // Motor 2 control (via MOSFET)

void setup() {
  // Set motor control pins as OUTPUT
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);

  // Start serial communication for Bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();  // Read Bluetooth command

    if (command == 'F') {  // Move Forward
      digitalWrite(motor1Pin, HIGH);
      digitalWrite(motor2Pin, HIGH);
    }
    else if (command == 'B') {  // Move Backward
      digitalWrite(motor1Pin, LOW);
      digitalWrite(motor2Pin, LOW);
    }
    else if (command == 'L') {  // Turn Left (Reverse motor 1 and move motor 2)
      digitalWrite(motor1Pin, LOW);
      digitalWrite(motor2Pin, HIGH);
    }
    else if (command == 'R') {  // Turn Right (Reverse motor 2 and move motor 1)
      digitalWrite(motor1Pin, HIGH);
      digitalWrite(motor2Pin, LOW);
    }
    else if (command == 'S') {  // Stop
      digitalWrite(motor1Pin, LOW);
      digitalWrite(motor2Pin, LOW);
    }
  }
}
