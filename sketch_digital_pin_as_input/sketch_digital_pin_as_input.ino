#define BUTTON_PIN 2
#define LED_PIN 12

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(BUTTON_PIN));

  if(digitalRead(BUTTON_PIN) == HIGH){
    Serial.println("Button is PRESSED");
    digitalWrite(LED_PIN,HIGH);
  }else{
    Serial.println("NOT PRESSED");
    digitalWrite(LED_PIN,LOW);
  }
 
  delay(100);
}
