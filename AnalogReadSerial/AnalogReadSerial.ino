
const int ledPin = 5; 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  delay(100);
  float small_num = sensorValue * (5/ 1023.0);
  analogWrite(ledPin, small_num);
  Serial.println(small_num);
  Serial.println(sensorValue);
  delay(100);  // delay in between reads for stability

}
