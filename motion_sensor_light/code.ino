
// Pin definitions for motion sensor, LED and seven segment display
const int motionSensorPin = 2;
const int LEDPin = 13;
const int segmentAPin = 11;
const int segmentBPin =12;
const int segmentCPin = 6;
const int segmentDPin = 7;
const int segmentEPin = 8;
const int segmentFPin = 10;
const int segmentGPin = 9;

// Global variables
int TIMER_START = 30;       // LED on time in ms
int TIMER_SPEED = 500;      // Timer speed in ms
int ANIMATION_SPEED = 200;  // Animation speed in ms

// Variables for motion sensor and timer
bool motionDetected = false;
unsigned long timerStartTime = 0;
unsigned long previous_led = 0;
unsigned long current = 0;
unsigned long segment_start = 0;
bool end = false;
int counter;
int counter2 = TIMER_START;

// Variables for seven segment display
int remainingTime = TIMER_START;
int currentSegment = segmentAPin;



void resetDisplay(){
    //turn off all segments
    digitalWrite(segmentAPin,HIGH); 
    digitalWrite(segmentBPin,HIGH); 
	digitalWrite(segmentCPin,HIGH); 
    digitalWrite(segmentDPin,HIGH); 
    digitalWrite(segmentEPin,HIGH); 
    digitalWrite(segmentFPin,HIGH); 
    digitalWrite(segmentGPin,HIGH); 
    }
    

void setup() {
  // Initialize pins
  pinMode(motionSensorPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(segmentAPin, OUTPUT);
  pinMode(segmentBPin, OUTPUT);
  pinMode(segmentCPin, OUTPUT);
  pinMode(segmentDPin, OUTPUT);
  pinMode(segmentEPin, OUTPUT);
  pinMode(segmentFPin, OUTPUT);
  pinMode(segmentGPin, OUTPUT);
  TIMER_START = TIMER_START * 1000;
 
  // Start serial communication for debugging
  Serial.begin(9600);
  resetDisplay();
}


    
void loop() {
 
  //Serial.print(digitalRead(motionSensorPin));
  //Serial.println();  // Check if motion is detected
  if (motionDetected!=true && digitalRead(motionSensorPin) == HIGH) {
  
    motionDetected = true;
    digitalWrite(LEDPin, HIGH); // Turn on LED
    segment_start = millis();
    resetDisplay();
    counter =15;
  }
  
  else{
    current = millis();
    if(current - segment_start >= TIMER_START){
      //turn of the led
       digitalWrite(LEDPin, LOW); // Turn off LED
       motionDetected = false;
       resetDisplay();

    }
  }
  current = millis();
  if(motionDetected == true ){
    current = millis();
    
    if( counter>15 && (current-segment_start)<TIMER_START - 15000){ //start animation for number that is bigger than 15
      startAnimation();
    }
       
    else if(counter<=15){
      if((TIMER_START/1000)>15){
        displaySegments(counter);
        counter -= 1;
      }
      else{
        displaySegments(counter2);
        counter2 -= 1;
      }
      resetDisplay();
         if(counter == -1 || counter2==-1) {
           motionDetected = false;
           digitalWrite(LEDPin, LOW); // Turn off LED
         }

    }
    else{
      resetDisplay();
    }

  }
}


void startAnimation(){
  unsigned int current2 = millis();
  int leds[] = {segmentAPin, segmentBPin, segmentCPin, segmentDPin, segmentEPin, segmentFPin};
  int i = 0;
  digitalWrite(segmentGPin,HIGH); 

  while(true){
     digitalWrite(leds[(i-1)%6],HIGH); 
     digitalWrite(leds[i%6],LOW); 
	 delay(200);
     current = millis();
    if(current - segment_start >=TIMER_START - 15000){
      break;
    }
    i += 1;
       }
     }

  

void displaySegments(int number) {
  resetDisplay();
  switch(number){
   
    case 15: //F
  		digitalWrite(segmentAPin, LOW);
  		digitalWrite(segmentEPin, LOW);
  		digitalWrite(segmentFPin, LOW);
  		digitalWrite(segmentGPin, LOW);
        delay(TIMER_SPEED);

  	break;
    
    case 14: //E
  		digitalWrite(segmentAPin, LOW);
  		digitalWrite(segmentEPin, LOW);
  		digitalWrite(segmentFPin, LOW);
  		digitalWrite(segmentGPin, LOW);
      	digitalWrite(segmentDPin, LOW);
        delay(TIMER_SPEED);


  	break;
    case 13: //d
  		digitalWrite(segmentBPin, LOW);
  		digitalWrite(segmentEPin, LOW);
  		digitalWrite(segmentCPin, LOW);
  		digitalWrite(segmentGPin, LOW);
      	digitalWrite(segmentDPin, LOW);
        delay(TIMER_SPEED);


  	break;
    case 12: //C
  		digitalWrite(segmentAPin, LOW);
  		digitalWrite(segmentEPin, LOW);
  		digitalWrite(segmentFPin, LOW);
      	digitalWrite(segmentDPin, LOW);
        delay(TIMER_SPEED);


  	break;
    case 11: //b
  		digitalWrite(segmentFPin, LOW);
  		digitalWrite(segmentEPin, LOW);
  		digitalWrite(segmentCPin, LOW);
  		digitalWrite(segmentGPin, LOW);
      	digitalWrite(segmentDPin, LOW);
        delay(TIMER_SPEED);


  	break;
    case 10: //A
  		digitalWrite(segmentFPin, LOW);
  		digitalWrite(segmentEPin, LOW);
  		digitalWrite(segmentCPin, LOW);
  		digitalWrite(segmentGPin, LOW);
      	digitalWrite(segmentBPin, LOW);
        digitalWrite(segmentAPin, LOW);
        delay(TIMER_SPEED);

  	break;
    
    case 0 :
        digitalWrite(segmentAPin,LOW);
        digitalWrite(segmentBPin,LOW);
        digitalWrite(segmentCPin,LOW);
        digitalWrite(segmentDPin,LOW);
        digitalWrite(segmentEPin,LOW);
        digitalWrite(segmentFPin,LOW);
        delay(TIMER_SPEED);

    break;
    
    case 1 :
   		digitalWrite(segmentBPin,LOW);
  		digitalWrite(segmentCPin,LOW);
        delay(TIMER_SPEED);

	break;    

    case 2 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentBPin,LOW);
      digitalWrite(segmentDPin,LOW);
      digitalWrite(segmentEPin,LOW);
      digitalWrite(segmentGPin,LOW);
      delay(TIMER_SPEED);

    break;    

    case 3 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentBPin,LOW);
      digitalWrite(segmentCPin,LOW);
      digitalWrite(segmentDPin,LOW);
      digitalWrite(segmentGPin,LOW);
      delay(TIMER_SPEED);

    break;

    case 4 :
      digitalWrite(segmentBPin,LOW);
      digitalWrite(segmentCPin,LOW);
      digitalWrite(segmentFPin,LOW);
      digitalWrite(segmentGPin,LOW);
      delay(TIMER_SPEED);    
    break;

    case 5 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentCPin,LOW);
      digitalWrite(segmentDPin,LOW);
      digitalWrite(segmentFPin,LOW);
      digitalWrite(segmentGPin,LOW);      
      delay(TIMER_SPEED);

    break;

    case 6 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentCPin,LOW);
      digitalWrite(segmentDPin,LOW);
      digitalWrite(segmentEPin,LOW);
      digitalWrite(segmentFPin,LOW);
      digitalWrite(segmentGPin,LOW);
      delay(TIMER_SPEED);
    break;

    case 7 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentBPin,LOW);
      digitalWrite(segmentCPin,LOW);
      delay(TIMER_SPEED);
    break;    

    case 8 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentBPin,LOW);
      digitalWrite(segmentCPin,LOW);
      digitalWrite(segmentDPin,LOW);
      digitalWrite(segmentEPin,LOW);
      digitalWrite(segmentFPin,LOW);
      digitalWrite(segmentGPin,LOW);
      delay(TIMER_SPEED);
    break;   

    case 9 :
      digitalWrite(segmentAPin,LOW);
      digitalWrite(segmentBPin,LOW);
      digitalWrite(segmentCPin,LOW);
      digitalWrite(segmentDPin,LOW);
      digitalWrite(segmentFPin,LOW);
      digitalWrite(segmentGPin,LOW);
      delay(TIMER_SPEED);
    break;
	
    default:
      digitalWrite(segmentAPin,LOW); 
      digitalWrite(segmentBPin,LOW); 
      digitalWrite(segmentCPin,LOW); 
      digitalWrite(segmentDPin,LOW); 
      digitalWrite(segmentEPin,LOW); 
      digitalWrite(segmentFPin,LOW); 
      digitalWrite(segmentGPin,LOW); 
    break;
    
       
    
  }
  
}







