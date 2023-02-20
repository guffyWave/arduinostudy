#define ECHO_PIN 3
#define TRIGGER_PIN 4

#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4  // using as digital pin
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);


unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ULTRASONIC_TRIGGER_DELAY = 100;

#define LED_PIN_RED A0
#define LED_PIN_YELLOW A1
#define LED_PIN_GREEN A2

#define BUZZER_PIN 2

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile boolean newDistanceAvailable = false;


String marioLine1 = "¯\_(ツ)_/¯";
String marioLine2 = "˙ ͜ʟ˙";
String marioLine3 = "╭∩╮(-_-)╭∩╮";
String marioLine4 = "ᶘ ᵒᴥᵒᶅ";
String marioLine5 = "( ° ᴗ°)~ð (/❛o❛\)";
String marioLine6 = "Hello from ";
String marioLine7 = "Gufran Khurshid";

void echoPinInterrupt() {
  if (digitalRead(ECHO_PIN) == HIGH) {  //start measuring
    //rising
    pulseInTimeBegin = micros();
  } else {
    //stop measuring
    pulseInTimeEnd = micros();
    newDistanceAvailable = true;
  }
}

void powerLEDsFromDistance(double distance) {
  if (distance <= 8) {

    
    // red
    turnOffAll();
    digitalWrite(LED_PIN_RED, HIGH);
    delay(50);

    turnOffAll();
    digitalWrite(LED_PIN_GREEN, HIGH);
    delay(100);

    turnOffAll();
    digitalWrite(LED_PIN_YELLOW, HIGH);
    delay(10);
    
    sing(0);

    //sing the mario tunes


  } else if (distance <= 30 && distance > 8) {
    // blue
    digitalWrite(LED_PIN_GREEN, LOW);
    digitalWrite(LED_PIN_YELLOW, HIGH);
    digitalWrite(LED_PIN_RED, LOW);

  } else {
    // green
    digitalWrite(LED_PIN_GREEN, HIGH);
    digitalWrite(LED_PIN_YELLOW, LOW);
    digitalWrite(LED_PIN_RED, LOW);
  }
}

void turnOffAll() {
  digitalWrite(LED_PIN_RED, LOW);
  digitalWrite(LED_PIN_GREEN, LOW);
  digitalWrite(LED_PIN_YELLOW, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YELLOW, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO_PIN), echoPinInterrupt, CHANGE);

  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin(16, 2);

      turnOffAll();
    digitalWrite(LED_PIN_RED, HIGH);
    delay(50);

    turnOffAll();
    digitalWrite(LED_PIN_GREEN, HIGH);
    delay(100);

    turnOffAll();
    digitalWrite(LED_PIN_YELLOW, HIGH);
    delay(10);
}



void printTextLoopHorizontaly(String text, int lineIndex) {

  int i, j = lineIndex;

  for (i = 0; i < text.length(); i++) {
    if (i < 15) {
      lcd.setCursor(i, 0);
      lcd.print(text.charAt(i));
      delay(150);
    } else {
      for (i = 16; i < text.length(); i++) {
        j++;
        lcd.setCursor(0, 0);
        lcd.print(text.substring(j, j + 16));
        delay(250);
      }
    }
  }
}

void triggerUltrasonicSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance() {
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0;  // cm , for inches (/148.0)
  //distance= duration*speed
  // 340 m/s speed of sound in air  --> 0.034 cm/microsec
  // duration * (0.034/2) ---> to and fro i.e. 2
  return distance;
}


void loop() {

  //powerLEDsFromDistance(15);

  //printTextLoopHorizontaly("Hello from Gufran Khurshid",0);

  lcd.setCursor(0, 0);
  lcd.print("Hi from  Gufran");


  unsigned long timeNow = millis();
  if (timeNow - lastTimeUltrasonicTrigger > ULTRASONIC_TRIGGER_DELAY) {
    lastTimeUltrasonicTrigger += ULTRASONIC_TRIGGER_DELAY;

    //action
    //trigger sensor
    triggerUltrasonicSensor();
    // Serial.println(getUltrasonicDistance());
    //read pulse on echo pin
  }

  if (newDistanceAvailable) {
    newDistanceAvailable = false;
    double distance = getUltrasonicDistance();


    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.setCursor(6, 1);
    lcd.print(distance);

    powerLEDsFromDistance(distance);
  }
}




//Mario
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

//for Mario
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0, 0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

int tempo[] = {
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,

  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,

  9,
  9,
  9,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,

  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,

  9,
  9,
  9,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
  12,
};

//For Mario
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};

//For Mario
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

int song = 0;

//Mario
void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(BUZZER_PIN, underworld_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(BUZZER_PIN, 0, noteDuration);
    }

  } else {

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(BUZZER_PIN, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(BUZZER_PIN, 0, noteDuration);
    }
  }
}

//Mario
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2;  // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000;  // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) {  // for the calculated length of time...
    digitalWrite(targetPin, HIGH);        // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue);        // wait for the calculated delay value
    digitalWrite(targetPin, LOW);         // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue);        // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
}
