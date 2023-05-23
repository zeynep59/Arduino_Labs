#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 10    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

// Boundaries
int TEMPERATURE_MIN = 30;
int TEMPERATURE_MAX = 35;

int HUMIDITY_MIN = 30;
int HUMIDITY_MAX = 60;

int LIGHT_MIN = 30;
int LIGHT_MAX = 100;

int seconds = 0;
const int analogLight = A1;

// Humidity-temperature variables
int humiditysensorOutput = 0;
int humidity = 0;
double Voltage = 0;
double tempC = 0;

// LCD display
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
int delay_time = 0; // If there are multiple values out of bounds

// LDR output
int ldr_out = 0;

// LED
int led = 6;

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  dht.begin();
  pinMode(A1, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  // Read the light value
  ldr_out = analogRead(analogLight);

  // Read and calculate humidity and temperature
  humidity = dht.readHumidity();
  tempC = dht.readTemperature();      // 500 is the offset

  // Check the temperatures
  if (tempC > TEMPERATURE_MAX)
  {
    delay(delay_time);
    delay_time += 3000;
    lcd_1.clear();
    lcd_1.print("TEMP IS TOO HIGH");
    lcd_1.setCursor(0, 1);
    lcd_1.print("TMAX:");
    lcd_1.print(TEMPERATURE_MAX);
    lcd_1.print(" TCUR:");
    lcd_1.print(int(tempC));
    Serial.print("TEMP:  ");
    Serial.println(tempC);
  }
  else if (tempC < TEMPERATURE_MIN)
  {
    delay(delay_time);
    delay_time += 3000;
    lcd_1.clear();
    lcd_1.print("TEMP IS TOO LOW");
    lcd_1.setCursor(0, 1);
    lcd_1.print("TMIN:");
    lcd_1.print(TEMPERATURE_MIN);
    lcd_1.print(" TCUR:");
    lcd_1.print(int(tempC));
    Serial.print("TEMP:  ");
    Serial.println(dht.readTemperature());
  }

  // Check the humidity
  if (humidity > HUMIDITY_MAX)
  {
    delay(delay_time);
    delay_time += 3000;
    lcd_1.clear();
    lcd_1.print("HUM IS TOO HIGH");
    lcd_1.setCursor(0, 1);
    lcd_1.print("HMAX:");
    lcd_1.print(HUMIDITY_MAX);
    lcd_1.print(" HCUR:");
    Serial.print("HUM: ");
    Serial.println(dht.readHumidity());
    lcd_1.print(humidity);
  }
  else if (humidity < HUMIDITY_MIN)
  {
    delay(delay_time);
    delay_time += 3000;
    lcd_1.clear();
    lcd_1.print("HUM IS TOO LOW");
   
    lcd_1.setCursor(0, 1);
    lcd_1.print("HMIN:");
    lcd_1.print(HUMIDITY_MIN);
    lcd_1.print(" HCUR:");
    lcd_1.print(int(humidity));
    Serial.print(dht.readHumidity());
    Serial.println("Humidity IS TOO LOW");
  }

  // Check light
  if (ldr_out < LIGHT_MIN)
  {
    delay(delay_time);
    delay_time += 3000;
    lcd_1.clear();
    lcd_1.print("LIGHT IS TOO LOW");
    lcd_1.setCursor(0, 1);
    lcd_1.print("LMIN:");
    lcd_1.print(LIGHT_MIN);
    lcd_1.print(" LCUR:");
    lcd_1.print(ldr_out);
    Serial.print(ldr_out);
    Serial.println("LIGHT IS TOO LOW");
  }
  else if (ldr_out > LIGHT_MAX)
  {
    delay(delay_time);
    delay_time += 3000;
    lcd_1.clear();
    lcd_1.print("LIGHT IS TOO HIGH");
    lcd_1.setCursor(0, 1);
    lcd_1.print("LMAX:");
    lcd_1.print(LIGHT_MAX);
    lcd_1.print(" LCUR:");
    lcd_1.print(ldr_out);
    Serial.print(ldr_out);
    Serial.println("LIGHT IS TOO HIGH");
  }
    Serial.print("TEMP");
    Serial.println(dht.readTemperature());
  if (delay_time == 0)
  { // Optimal
    digitalWrite(led, LOW);
    lcd_1.clear();
    lcd_1.print("T:");
    lcd_1.print(int(tempC));
    lcd_1.print("  H:");
    lcd_1.print(humidity);
    lcd_1.print(" L:");
    lcd_1.print(ldr_out);
    lcd_1.setCursor(0, 1);
    lcd_1.print("STATUS: OPTIMAL");
    delay(1000);
    
  }
  else
  {
    digitalWrite(led, HIGH);
    delay_time = 0;
    delay(1000);

  }
  

}