#include <Servo.h>
#include <stdio.h>

Servo Servo1;
Servo Servo2;

int servoPinA = 9;
int servoPinB = 10;
int potPin = A0;

void setup() {
    Serial.begin(9600);
    Servo1.attach(servoPinA);
    Servo2.attach(servoPinB);
}




void loop() {
    int reading = analogRead(potPin);
    int angle = map(reading, 0, 1023, 0, 180 /10) *10;
    Servo1.write(angle);
    Servo2.write(180 - angle);
    Serial.print(angle);
    Serial.print("\n");
    delay(100);
}
