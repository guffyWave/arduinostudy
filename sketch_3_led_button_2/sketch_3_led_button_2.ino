
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 9
#define LED_PIN_GREEN 10
#define PUSH_BUTTON 2


void setup() {
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YELLOW, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);

  pinMode(PUSH_BUTTON, INPUT);
}

void loop() {



  if (digitalRead(PUSH_BUTTON) == LOW ) {
    digitalWrite(LED_PIN_RED, HIGH);
    digitalWrite(LED_PIN_GREEN, HIGH);
    digitalWrite(LED_PIN_YELLOW, LOW);
    delay(300);

    digitalWrite(LED_PIN_RED, LOW);
    digitalWrite(LED_PIN_GREEN, LOW);
    digitalWrite(LED_PIN_YELLOW, HIGH);
    delay(300);
  } else {
    digitalWrite(LED_PIN_RED, LOW);
    digitalWrite(LED_PIN_GREEN, LOW);
    digitalWrite(LED_PIN_YELLOW, HIGH);
  }
}
