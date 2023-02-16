
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 10

unsigned long LED_RED_DELAY =300;
unsigned long LED_YELLOW_DELAY =1000;

unsigned long MONO_TIME_RED = millis();
unsigned long MONO_TIME_YELLOW = millis();

bool RED_STATE=HIGH;
bool YELLOW_STATE=HIGH;


void setup() {
  pinMode(LED_PIN_RED,OUTPUT);
  pinMode(LED_PIN_YELLOW,OUTPUT);
}


void loop() {

  unsigned long timeNow=millis();
  
  if(timeNow - MONO_TIME_RED > LED_RED_DELAY){
    if(RED_STATE == HIGH){
      RED_STATE= LOW;
    }else{
       RED_STATE= HIGH;
    }
    digitalWrite(LED_PIN_RED,RED_STATE);
    MONO_TIME_RED += LED_RED_DELAY ;
  }
  
  
  if(timeNow - MONO_TIME_YELLOW > LED_YELLOW_DELAY){
    
    if(YELLOW_STATE == HIGH){
      YELLOW_STATE= LOW;
    }else{
       YELLOW_STATE= HIGH;
    }
    
    digitalWrite(LED_PIN_YELLOW,YELLOW_STATE);
    MONO_TIME_YELLOW += LED_YELLOW_DELAY ;
  }
  
}


