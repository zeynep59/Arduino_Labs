// C++ code
//
/*
  Fade
  This example shows how to fade an LED on pin 9
  using the analogWrite() function.

  The analogWrite() function uses PWM, so if  you
  want to change the pin you're using, be  sure to
  use another PWM capable pin. On most  Arduino,
  the PWM pins are identified with   a "~" sign,
  like ~3, ~5, ~6, ~9, ~10 and ~11.
*/

#define LED 2
#define SENSOR A1

int LED_ACTIVATION_VALUE = 500;
int SERIAL_OUTPUT_FREQUENCY = 500; 
int counter = 0;
int status = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  	long start_time = micros();
 	
  
  	digitalWrite(LED, LOW);
  	int value = analogRead(SENSOR);
  	
  if(value >= LED_ACTIVATION_VALUE ){
    digitalWrite(LED, LOW);
  	status = 1;
  }
  else{
    digitalWrite(LED, HIGH);
    status = 0;
  }
  
  if (counter % SERIAL_OUTPUT_FREQUENCY == 0){
    Serial.print("LIGHT SENSOR: ");
    Serial.print(value);
    Serial.println();
    
    Serial.print("LED   STATUS: ");
    if (status) Serial.print("OFF");
    else Serial.print("ON");
    Serial.println();
  }
    
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
  counter++;
}