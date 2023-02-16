#include <SoftwareSerial.h>

SoftwareSerial esp8266(10, 11);  // RX, TX pins for ESP8266
#define serialCommunicationSpeed 115200
#define DEBUG true

//https://mocki.io/v1/b915d693-5408-497b-bb9f-5843df4d5992
//https://run.mocky.io/v3/41755f80-3494-4b51-9dd3-fa94dbc95fd5
void setup() {
  Serial.begin(serialCommunicationSpeed);
  esp8266.begin(serialCommunicationSpeed);
  initiateWifi();
}

void getJSONData() {
  Serial.println("-----start------");



  sendData("AT+CIPSTART=\"TCP\",\"run.mocky.io\",80\r\n", 1000, DEBUG);
  delay(2000);

  String request = "GET https://run.mocky.io/v3/41755f80-3494-4b51-9dd3-fa94dbc95fd5\r\n";
  String requestLengthStr = String(request.length());

  sendData("AT+CIPSEND=" + requestLengthStr + "\r\n", 2000, DEBUG);
  esp8266.println(request);

  sendData("AT+CIPRXGET=4,0\r\n", 2000, DEBUG);  // read the HTTP response

  sendData("AT+CIPCLOSE\r\n", 2000, DEBUG);
  Serial.println("-----end--------");
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

  getJSONData();
}

void initiateWifi() {
  sendData("AT+RST\r\n", 2000, DEBUG);
  sendData("AT+CWJAP=\"gufranHotspot\",\"babu1267\"\r\n", 2000, DEBUG);
}


String sendData(String command, const int timeout, boolean debug) {
  String response = "";
  Serial.print("Command: ");
  esp8266.print(command);
  Serial.println("");

  long int time = millis();
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug) {
    Serial.print("Response : ");
    Serial.println(response);
  }
  return response;
}
