#define PHOTORESISTOR_PIN A0
#define LED_GREEN 10

int ledLuminosity = 125;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  double photoResistorValue = analogRead(PHOTORESISTOR_PIN);
  Serial.print(photoResistorValue);
  Serial.print("-");

  //read photoresistor value
  //define threshhold  -- when value < threshold --> poweron the LED
  // Increase LED brightness if  photoresistor value is low

  //.  y      x
  //.  0.    700
  //   255.   180
  // therefor eqn : y= -0.4903 x + 343.26

  ledLuminosity =  Math.abs((-0.4903 * photoResistorValue) + 343.26);

  Serial.println(ledLuminosity);


  analogWrite(LED_GREEN, ledLuminosity);
}
