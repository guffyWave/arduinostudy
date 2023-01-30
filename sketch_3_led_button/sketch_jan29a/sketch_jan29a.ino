
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 9
#define LED_PIN_GREEN 10

void setup() {
  pinMode(LED_PIN_RED,OUTPUT);
  pinMode(LED_PIN_YELLOW,OUTPUT);
  pinMode(LED_PIN_GREEN,OUTPUT);
  
}

void turnOffAll(){ 
  digitalWrite(LED_PIN_RED,LOW);
  digitalWrite(LED_PIN_GREEN,LOW);
  digitalWrite(LED_PIN_YELLOW,LOW);
}

void loop() {
  turnOffAll();
  
  digitalWrite(LED_PIN_RED,HIGH);
  delay(3000);
  
  turnOffAll();
  digitalWrite(LED_PIN_GREEN,HIGH);
  delay(3000);
  
  turnOffAll();
  digitalWrite(LED_PIN_YELLOW,HIGH);
  delay(1000);

}
