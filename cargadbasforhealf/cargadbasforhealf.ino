int motorPinA = 6;
int motorPinB = 9;
int potPin = A0;   

void setup() {
  Serial.begin(9600);
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop() {
  int reading = analogRead(potPin); 
  int motorSpeed = map(reading, 0, 1023, 0, 1020); 
  analogWrite(motorPinA, motorSpeed);
  analogWrite(motorPinB, -motorSpeed);

  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);  
  delay(150); 
}
