
#define buzzerPin 6
int counter = 0;
int SOUND_DURATION = 500;
int SILENCE_DURATION = 50;


int Sli = 0;
int Do = 262;
int Re = 294;
int Mi = 330;
int Fa = 349;
int Sol = 392;
int La = 440;
int Si = 494;
int Ince_do = 523;

int nota_sayisi;
int flag = 0;
int notalar[]= {
      Do, Do, Sol, Sol, La, La, Sol,
      Sli,Fa,Fa,Mi,Mi,Re,Re,Do
  };
int cursor = 0;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  nota_sayisi = sizeof(notalar)/sizeof(*notalar);
}


void loop() {
  //read the pushbutton value into a variable
  long start_time = micros();
  int sensorVal = digitalRead(2);
  //print out the value of the 

  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == LOW) {
    flag = 1;
  }
  if(flag){
    if(counter % (SOUND_DURATION+SILENCE_DURATION) == 0 || counter == 1 || counter == 0)
    {
      if(notalar[cursor]!= Sli )
      {
        tone(buzzerPin, notalar[cursor]);
      }
    }
    if(counter % SOUND_DURATION == 0){
      noTone(buzzerPin);
      if(cursor >= nota_sayisi)
      { 
        noTone(buzzerPin);
        cursor = 0;
        counter = 0;
        flag = 0;
      }
      else {
        cursor++;
      }
      counter = 0;
    }
  }
  
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
  counter++;
}