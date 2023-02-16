
#define LED_PIN_RED 12
#define LED_PIN_GREEN 10
#define LED_PIN_BLUE 8

#define POTENTIOMETER_PIN A2

#define BUTTON_PIN 2

unsigned long LED_RED_DELAY = 500;

unsigned long MONO_TIME_RED = millis();

bool RED_STATE = LOW;
bool GREEN_STATE = LOW;
bool BLUE_STATE = LOW;


void setup() {
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(LED_PIN_BLUE, OUTPUT);
}


void loop() {

  unsigned long timeNow = millis();

  //red will blink with 500 ms delay
  if (timeNow - MONO_TIME_RED > LED_RED_DELAY) {
    if (RED_STATE == HIGH) {
      RED_STATE = LOW;
    } else {
      RED_STATE = HIGH;
    }
    digitalWrite(LED_PIN_RED, RED_STATE);
    MONO_TIME_RED += LED_RED_DELAY;
  }

  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_PIN_GREEN, LOW);
    digitalWrite(LED_PIN_BLUE, HIGH);
  } else {
    digitalWrite(LED_PIN_GREEN, HIGH);
    digitalWrite(LED_PIN_BLUE, LOW);
  }
}
