void setup() {
  // intialise serial communication
  Serial.begin(9600); // 9600- how fast the data writes 
  Serial.println("Hello Arduino");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("In the loop");
  delay(500);

}
