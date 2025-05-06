#include <Stepper.h>

// # steps for full 360-degree rotation, change to fit your motor
int stepsPerRevolution = 2048;

// set a speed for the stepper motor
int rpm = 10;

// initialize stepper library on pins 8 - 11
// pin order IN1, IN3, IN2, IN4
Stepper myStepper1 (stepsPerRevolution, 8, 11, 9, 12);
Stepper myStepper2 (stepsPerRevolution, 3, 5, 4, 6);
void setup() {
  myStepper1.setSpeed(rpm);
  myStepper2.setSpeed(rpm);
}

void loop() {
  // make a full revolution in one direction
  myStepper1.step(stepsPerRevolution);
  myStepper2.step(-stepsPerRevolution);
  delay(500);

  // make a full revolution in the opposite direction
  myStepper1.step(-stepsPerRevolution);
  myStepper2.step(stepsPerRevolution);
  delay(500);
}