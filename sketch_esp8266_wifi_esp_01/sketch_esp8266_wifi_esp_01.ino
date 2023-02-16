#include <SoftwareSerial.h>

SoftwareSerial esp8266(10, 11);
#define serialCommunicationSpeed 115200
#define DEBUG true

int sampleValue = 1;

void setup() {
  Serial.begin(serialCommunicationSpeed);
  esp8266.begin(serialCommunicationSpeed);
  initiateWifi();
}

void updateThinkSpeak() {
  sampleValue = sampleValue * 2;
   Serial.print(" sampleValue = ");
   Serial.println(sampleValue);

  Serial.println("-----------");
  sendData("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n", 1000, DEBUG);
  delay(2000);
  String cmdlen;
  String sampleValueStr = String(sampleValue);
  String cmd = "GET https://api.thingspeak.com/update?api_key=AFJURGU9A3L54WV0&field1="+sampleValueStr+"\r\n";
  cmdlen = cmd.length();

  sendData("AT+CIPSEND=" + cmdlen + "\r\n", 2000, DEBUG);
  esp8266.println(cmd);

  Serial.print("");
  sendData("AT+CIPCLOSE\r\n", 2000, DEBUG);
  Serial.print("");
  delay(10000);
}

void loop() {


  // esp8266.println("AT");
  // delay(1000);
  // while (esp8266.available()) {
  //   Serial.write(esp8266.read());
  //   //Serial.println(esp8266.read());
  // }

  // while (esp8266.available()) {
  //   Serial.write(esp8266.read());
  //   //Serial.println(esp8266.read());
  // }

  updateThinkSpeak();
}

void initiateWifi() {
  sendData("AT+RST\r\n", 2000, DEBUG);
  sendData("AT+CWJAP=\"gufranHotspot\",\"babu1267\"\r\n", 2000, DEBUG);
}


String sendData(String command, const int timeout, boolean debug) {
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug) {
    Serial.print(response);
  }
  return response;
}
