void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Arduino Initialised");
}

void loop() {
  // Power LED for 2 secs
   Serial.println("ON");
  digitalWrite(13, HIGH);
  delay(2000);
 
 // Off LED for 1 secs
  Serial.println("OFF");
  digitalWrite(13, LOW);
  delay(1000);
}
