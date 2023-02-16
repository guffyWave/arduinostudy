#include <EEPROM.h> 

void setup() {
  Serial.begin(115200);

   // Write 
  // EEPROM.write(0,44);
  // EEPROM.write(200,150);

  // Read
  // Serial.println(EEPROM.read(0));
  // Serial.println(EEPROM.read(89)); --> default value =255
  // Serial.println(EEPROM.read(200));
}

void loop() {
  // put your main code here, to run repeatedly:
}
