#define LED_PIN 11

int lum=0;
//boolean direction=true; // true =up , false = down

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  //analogWrite(LED_PIN, 200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(lum);

  if(lum==0){
    for (lum=0; lum<255; lum++) {
      analogWrite(LED_PIN, lum);
      Serial.println(lum);
      delay(10);
    }
  } 
  
  if(lum==255) {
    for (lum=255; lum>0; lum--) {
      analogWrite(LED_PIN, lum);
      Serial.println(lum);
      delay(10);
    }
  }

}
