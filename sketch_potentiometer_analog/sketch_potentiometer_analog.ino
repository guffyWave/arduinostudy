#define POTENTIOMETER_PIN A2
#define LED_PIN 11

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
 int potentioMeterValue = analogRead(POTENTIOMETER_PIN);
 ///int ledBrightness=(int)((0.2490)*potentioMeterValue);
 //or below
 int ledBrightness=potentioMeterValue/4;
 Serial.println(ledBrightness);
 analogWrite(LED_PIN, ledBrightness);
// Serial.println(potentioMeterValue);
// delay(100);
}
