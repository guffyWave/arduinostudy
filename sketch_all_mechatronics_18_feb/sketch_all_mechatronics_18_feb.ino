
#define BLYNK_TEMPLATE_ID "TMPL8_x0koC7"
#define BLYNK_TEMPLATE_NAME "Mechatronics"
#define BLYNK_AUTH_TOKEN "2p_sjY_0YJOLq2S6pS_zjwwRVQvNQm5Z"

#define LED_PIN_RED 7
#define LED_PIN_YELLOW 8
#define LED_PIN_GREEN 9

#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char ssid[] = "shabbySpot";
char pass[] = "babu1267";

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 11);  // RX, TX


// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200
ESP8266 wifi(&EspSerial);

#include <Servo.h>

#define SERVO_PIN 12
#define PHOTORESISTOR_PIN A0



Servo servo;

double photoMaxValue = 0.0;

void setup() {

  Serial.begin(ESP8266_BAUD);
  // Set ESP8266 baud rate
  //EspSerial.begin(ESP8266_BAUD);
  //delay(10);

  // You can also specify server:
  // Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);

  servo.attach(SERVO_PIN);
  // delay(2000);
  // servo.write(90);
  //delay(5000);


  // delay(3000);

  // servo.write(0);

  // delay(2000);


  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YELLOW, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
}

void loop() {





  //Blynk.run();


  // double photoResistorValue = analogRead(PHOTORESISTOR_PIN);
  // if (photoResistorValue >= photoMaxValue) {
  //   photoMaxValue = photoResistorValue;
  // }

  // Serial.print(photoMaxValue);
  // Serial.print(" , ");
  // Serial.println(photoResistorValue);
  // photoResistorValue 1-2 -normal
  // 3 - first loght one

  if (photoMaxValue >= 50) {

  turnOffAll();
  digitalWrite(LED_PIN_RED, HIGH);
  delay(300);

  turnOffAll();
  digitalWrite(LED_PIN_GREEN, HIGH);
  delay(300);

  turnOffAll();
  digitalWrite(LED_PIN_YELLOW, HIGH);
  delay(300);
  } else {
    turnOffAll();
  }




  //delay(500);
}


void turnOffAll() {
  digitalWrite(LED_PIN_RED, LOW);
  digitalWrite(LED_PIN_GREEN, LOW);
  digitalWrite(LED_PIN_YELLOW, LOW);
}

BLYNK_WRITE(V1) {
  servo.write(param.asInt());
}

BLYNK_WRITE(V2) {
  servo.write(0);
}

BLYNK_WRITE(V3) {
  servo.write(90);
}
