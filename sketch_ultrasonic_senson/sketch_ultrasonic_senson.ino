#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ULTRASONIC_TRIGGER_DELAY = 100;

void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
}

void triggerUltrasonicSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

double getUltrasonicDistance() {
  unsigned long timeBegin = micros();
  double durationMicros = pulseIn(ECHO_PIN, HIGH); // this function takes more/less time depending on distance on object
  unsigned long timeEnd = micros();
  unsigned long codeDuration = timeEnd - timeBegin;
  Serial.println(codeDuration); // codeduration i.e pulse() function is causing to much delay when obstacle is distant 

  double distance = durationMicros / 58.0;  // cm , for inches (/148.0)
  //distance= duration*speed
  // 340 m/s speed of sound in air  --> 0.034 cm/microsec
  // duration * (0.034/2) ---> to and fro i.e. 2
  return distance;
}


void loop() {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeUltrasonicTrigger > ULTRASONIC_TRIGGER_DELAY) {
    lastTimeUltrasonicTrigger += ULTRASONIC_TRIGGER_DELAY;

    //action
    //trigger sensor
    triggerUltrasonicSensor();
    Serial.println(getUltrasonicDistance());
    //read pulse on echo pin
  }
}
