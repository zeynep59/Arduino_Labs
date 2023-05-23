// define the LED pin numbers and count of LEDs
const int LED_PIN[] = {13, 12, 11, 10, 9};
const int LED_COUNT = sizeof(LED_PIN) / sizeof(LED_PIN[0]);

// define the increment value and wait time for LED sequence
const int INCREMENT_VALUE = 1;
const int WAIT_TIME = 500;

// initialize variables for LED sequence
int counter = 0;
int period = 0;


// initialize variable to track time elapsed
unsigned long previousMillis = 0;

void setup() {
  // set LED pins as output
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PIN[i], OUTPUT);
  }
}

void loop() {
  // get current time
  unsigned long currentMillis = millis();
  
  // check if wait time has elapsed
  if (currentMillis - previousMillis >= WAIT_TIME) {
    // update previous time to current time
    previousMillis = currentMillis;
    
    // increment counter and period variables
    counter += INCREMENT_VALUE;
    if (counter > 31) {
      counter = counter % 32;
      period++;
    }
    
    // if period has elapsed, turn off all LEDs and enter infinite loop
    if (period > 3) {
      for (int i = 0; i < LED_COUNT; i++) {
        digitalWrite(LED_PIN[i], LOW);
      }
      while (true) {}
    } 
    // otherwise, light LEDs according to binary value of counter
    else {
      lightLED(counter);
    }
  }
}

// function to light LEDs according to binary value of input parameter
void lightLED(int value) {
  
  // iterate over LED pins from right to left
  for (int i = LED_COUNT - 1; i >= 0; i--) {
    // set LED pin to the corresponding binary bit
    digitalWrite(LED_PIN[i], value & 1);
    // shift right to get next binary bit
    value = value >> 1;
  }
}
