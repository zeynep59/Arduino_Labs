#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

#define echoPin 6
#define trigPin 7
#define led 8
#define buzzerPin 12


int BUZZER_LED_FREQ_MAX = 1000;
int BUZZER_LED_FREQ_MIN = 10;

int DIST_MAX = 100;
int DIST_MIN = 10;

int CURRENT_DIST = 0;
int CURRENT_FREQ = 0;

int UPDATE_FREQ_BUZZER = 200;
int UPDATE_FREQ_LCD = 200;

int counter = 0;
int buzzer_led_status = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  //lcd.setBacklight(1);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led,OUTPUT);
  
  //CURRENT_FREQ = (((CURRENT_DIST-DIST_MIN)/(DIST_MAX-DIST_MIN))*(BUZZER_LED_FREQ_MAX-BUZZER_LED_FREQ_MIN));
  //CURRENT_FREQ += BUZZER_LED_FREQ_MIN;
  Serial.begin(9600); 
}

void loop() {
  long start_time = micros();
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  int duration = pulseIn(echoPin,HIGH);
  
  CURRENT_DIST = (duration/29.1)/2;
  
    

  if(counter % UPDATE_FREQ_BUZZER == 0){
    CURRENT_FREQ = int(float(float(CURRENT_DIST-DIST_MIN)/float(DIST_MAX-DIST_MIN))*float(BUZZER_LED_FREQ_MAX-BUZZER_LED_FREQ_MIN)) + BUZZER_LED_FREQ_MIN;
    if(CURRENT_FREQ>= BUZZER_LED_FREQ_MAX){
      CURRENT_FREQ= BUZZER_LED_FREQ_MAX;
    }
    else if(CURRENT_FREQ<=BUZZER_LED_FREQ_MIN){
      CURRENT_FREQ=BUZZER_LED_FREQ_MIN;
    }
  }
  if(counter % UPDATE_FREQ_LCD == 0){
  lcd.setCursor(0, 0);             // 1. satır, 1. sütuna git
    lcd.print("DISTANCE :"); 
    if(CURRENT_DIST/1000>=1)lcd.print("");
    else if (CURRENT_DIST/100>=1) lcd.print(" ");
    else lcd.print("  ");
    lcd.print(CURRENT_DIST); 
    lcd.print("cm"); 


    lcd.setCursor(0,1);             // 1. satır, 1. sütuna git
    lcd.print("FREQUENCY:"); 
    if(CURRENT_FREQ/1000>=1)lcd.print("");
    else if (CURRENT_FREQ/100>=1) lcd.print(" ");
    else lcd.print("  ");
    lcd.print(CURRENT_FREQ); 
    lcd.print("ms");
         // Mesaj2'yi yazdır
    
  }
  

  if (CURRENT_DIST>=DIST_MIN && CURRENT_DIST <= DIST_MAX)
  {
    if(counter % CURRENT_FREQ == 0){
      if(buzzer_led_status == 0) {
      	digitalWrite(led,HIGH);
        tone(buzzerPin,CURRENT_FREQ);
        buzzer_led_status = 1;
      }
      else{
        noTone(buzzerPin);
        digitalWrite(led,LOW);
        buzzer_led_status = 0;
      }
    }
  }
  else{
    noTone(buzzerPin);
    digitalWrite(led,LOW);
    buzzer_led_status = 0;
  }
  
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
  counter= counter +1;
}


