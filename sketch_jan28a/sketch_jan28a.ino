 void setup() {
  // Set LED pin to output
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(3000);
  digitalWrite(13, LOW);
  delay(3000);

}

