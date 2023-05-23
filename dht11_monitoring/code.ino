#include <LiquidCrystal.h>
#include <DHT.h>
#include <Wire.h>

#define buttonPin 2
#define DHTPIN 10    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  


LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
DHT dht(DHTPIN, DHTTYPE);



int state = 0;
int state_change= 0;

void setup(){  
  lcd.begin(16, 2);
  lcd.clear();
  dht.begin();


  pinMode(A1, INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop(){
  


  int sensorVal = digitalRead(2);
  if (sensorVal == LOW) {
    if(state_change != 1){
      if(state ==1) state = 0;
      else state = 1;
    }
    state_change = 1;
  }
  else{
    state_change = 0;
  }
   
  if(state == 1){
     print_tr();
  }
  else{
     print_en();
  }
 
}

void print_tr(){
  lcd.setCursor(0, 0);
  lcd.print("SIC(C):");
   lcd.setCursor(14, 0);
  lcd.print("TR");
  lcd.setCursor(0, 1);
  lcd.print("NEM(%):");
  lcd.setCursor(7, 0);
  //sıc
  if(dht.readTemperature()/100 >= 1){
    lcd.print(dht.readTemperature());
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readTemperature());
  }
  //nem
  lcd.setCursor(7, 1);
  if(dht.readHumidity()/100 >= 1){
    lcd.print(dht.readHumidity());
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readHumidity());
  }
}
  
void print_en(){
  lcd.setCursor(0, 0);
  lcd.print("TEM(F):");
  lcd.setCursor(14, 0);
  lcd.print("EN");
  lcd.setCursor(0, 1);
  lcd.print("HUM(%):");
  // sıcaklık
  lcd.setCursor(7, 0);
  if(dht.readTemperature()/100 >= 1){
    lcd.print(dht.readTemperature(true));
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readTemperature(true));
  }
  //nem
  lcd.setCursor(7, 1);
  if(dht.readHumidity()/100 >= 1){
    lcd.print(dht.readHumidity());
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readHumidity());
  }
}



/*
//Code for the tinkercad design
#define buttonPin 2

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);


const int analogIn = A0;
int humiditysensorOutput = 0;
// Defining Variables
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;
int state = 0;
int state_change= 0;

void setup(){  
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  pinMode(A1, INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop(){
  
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  tempC = (Voltage-500) * 0.1; // 500 is the offset
  tempF = (tempC * 1.8) + 32; // convert to F  
  humiditysensorOutput = analogRead(A1);
  int sensorVal = digitalRead(2);
  if (sensorVal == LOW) {
    if(state_change != 1){
      if(state ==1) state = 0;
      else state = 1;
    }
    state_change = 1;
  }
  else{
    state_change = 0;
  }
   
  if(state == 1){
     print_tr(tempC,map(humiditysensorOutput, 0, 1023, 10, 70));
  }
  else{
     print_en(tempF,map(humiditysensorOutput, 0, 1023, 10, 70));
  }
 
}

void print_tr(double temp,double hum){
  lcd.setCursor(0, 0);
  lcd.print("SIC(C):");
   lcd.setCursor(14, 0);
  lcd.print("TR");
  lcd.setCursor(0, 1);
  lcd.print("NEM(%):");
  lcd.setCursor(7, 0);
  //sıc
  if(temp/100 >= 1){
    lcd.print(temp);
  }
  else{
    lcd.print(" ");
    lcd.print(temp);
  }
  //nem
  lcd.setCursor(7, 1);
  if(hum/100 >= 1){
    lcd.print(hum);
  }
  else{
    lcd.print(" ");
    lcd.print(hum);
  }
}
  
void print_en(double temp, double hum){
  lcd.setCursor(0, 0);
  lcd.print("TEM(F):");
  lcd.setCursor(14, 0);
  lcd.print("EN");
  lcd.setCursor(0, 1);
  lcd.print("HUM(%):");
  // sıcaklık
  lcd.setCursor(7, 0);
  if(temp/100 >= 1){
    lcd.print(temp);
  }
  else{
    lcd.print(" ");
    lcd.print(temp);
  }
  //nem
  lcd.setCursor(7, 1);
  if(hum/100 >= 1){
    lcd.print(hum);
  }
  else{
    lcd.print(" ");
    lcd.print(hum);
  }
}
*/