/*************************************************************
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - Arduino Uno board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLfFlDDWJy"
#define BLYNK_TEMPLATE_NAME "IOT HOME LIGHTS"
#define BLYNK_AUTH_TOKEN "lGrlwv318e9WNSCM67xs544s9-v6TTun"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

//#define LED_PIN_BLUE 9

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "gufranHotspot";
char pass[] = "babu1267";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 11);  // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup() {
  // Debug console
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  //Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);  //Old sdk initialisation , not reuired any more 
  // You can also specify server:
   Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);


  //pinMode(LED_PIN_BLUE, OUTPUT);
}

void loop() {
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!

  //digitalWrite(LED_PIN_BLUE, HIGH);
}
