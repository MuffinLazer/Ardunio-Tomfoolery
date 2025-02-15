int motorPinA = 6;
int motorPinB = 9;
int potPinA = A0;   
int potPinB = A1;

void setup() {
  Serial.begin(9600);
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop() {
  int readingA = analogRead(potPinA); 
  int readingB = analogRead(potPinB); 
  int motorSpeedA = map(readingA, 0, 1023, 0, 255); 
  int motorSpeedB = map(readingB, 0, 1023, 0, 255); 
  analogWrite(motorPinA, motorSpeedA);
  analogWrite(motorPinB, motorSpeedB);

  Serial.print("Motor Speed: ");
  Serial.println(motorSpeedA);
  Serial.println(motorSpeedB);
  delay(150); 
}
