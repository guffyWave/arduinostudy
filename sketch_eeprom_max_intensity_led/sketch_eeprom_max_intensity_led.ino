#include <EEPROM.h>

#define EEPROM_ADDRESS_MAX_INTENTSITY 0

#define POTENTIOMETER_PIN A2
#define LED_PIN 10

//LED on pin 10 , fade-in /out based on potentio meter
// Max intensity from serial
// Save max intensity to EEPROM

byte maxBrightness;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);

  maxBrightness = EEPROM.read(EEPROM_ADDRESS_MAX_INTENTSITY);
  if (maxBrightness == 0) {
    maxBrightness = 255;
  }
}

void loop() {

  //taking max intensity from serial monitor
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if (data >= 0 && data < 255) {
      Serial.println(data);
      EEPROM.write(EEPROM_ADDRESS_MAX_INTENTSITY, data);
      maxBrightness = data;
    }
  }

  byte LEDBrightness = analogRead(POTENTIOMETER_PIN) / 4;
  if (LEDBrightness > maxBrightness) {
    LEDBrightness = maxBrightness;
  }
  analogWrite(LED_PIN, LEDBrightness);
}
