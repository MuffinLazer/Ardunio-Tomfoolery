int motorPin = 6;   
int potPin = A0;   

void setup() {
  Serial.begin(9600);   
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int reading = analogRead(potPin); 
  int motorSpeed = map(reading, 0, 1024, 0, 1020); 

  analogWrite(motorPin, motorSpeed);

  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);  
  delay(150); 
}
