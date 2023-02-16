#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4  // using as digital pin
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9


LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

String lineFirst = "", lineSecond = "";
int currentLine = 0;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  //lcd.setCursor(x,y);// setting cursor at x,y , x=0 to 15 , y=0 to 1
  // lcd.setCursor(3, 0);
  // lcd.print("Hello");
  // lcd.setCursor(1, 1);
  // lcd.print("World");
  // delay(1000);
  // lcd.print("Arduino");
  // lcd.setCursor(0, 0);
  // lcd.print("I love you ");
  // lcd.setCursor(0, 1);
  // lcd.print("meri pyaari Shab ");

  //read the string from Serail
  //print on LCD , input first ->line 1 , input second -> line 2
  //validate userInput <16
}

void loop() {

  if (Serial.available() > 0) {
    if (currentLine == 0) {
      lineFirst = Serial.readString();
      currentLine = 1;
    } else  {
      lineSecond = Serial.readString();
      currentLine = 0;
    }
  }

  lcd.setCursor(0, 0);
  lcd.print(lineFirst);
  lcd.setCursor(0, 1);
  lcd.print(lineSecond);
}
