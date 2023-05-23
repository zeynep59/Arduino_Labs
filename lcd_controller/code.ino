#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

String LCD_ROW_1 = "This text is for row 0 and longer than 16 characters.";
String LCD_ROW_2 = "ABCD EFGH";

boolean SCROLL_FLAG = true;

char SCROLL_DIRECTION = 'R';

int SCROLL_WAIT = 1000;


void setup()
{
  lcd.begin(16, 2);
  lcd.clear(); // clear the LCD screen

}

void loop()
{
  int j = 0;
  int k = 0;
  int counter = 0;
  while(true) {
    long start_time = micros();
    int i;
    if (counter % SCROLL_WAIT == 0) {
      for (i = 0; i < 16; i++) {
        lcd.setCursor(i, 0);
        lcd.print(" ");
        lcd.setCursor(i, 1);
        lcd.print(" ");
      }
      if (LCD_ROW_1.length() > 16 ) {
        for (i = 0; i < 16; i++) {
          lcd.setCursor(i, 0);
          if((i+j)>0)lcd.print(LCD_ROW_1.charAt((i + j) % LCD_ROW_1.length())); //sola
          else lcd.print(LCD_ROW_1.charAt((LCD_ROW_1.length()+(i + j)) % LCD_ROW_1.length())); //sağa
        }
      }
      else {
        for (i = 0; i < LCD_ROW_1.length(); i++) {
          if((i-j)>0)lcd.setCursor((i - j) % 16, 0);
          else lcd.setCursor((16+(i - j)) % 16, 0);
          lcd.print(LCD_ROW_1.charAt(i));
        }
      }
      if (LCD_ROW_2.length() > 16) {
        for (i = 0; i < 16; i++) {
          lcd.setCursor(i, 1);
          if((i+k)>0)lcd.print(LCD_ROW_2.charAt((i + k) % LCD_ROW_2.length()));
          else lcd.print(LCD_ROW_2.charAt((LCD_ROW_2.length()+(i + k)) % LCD_ROW_2.length()));
        }
      }
      else {
        for (i = 0; i < LCD_ROW_2.length(); i++) {
          if((i-k)>0)lcd.setCursor((i - k) % 16, 1);
          else lcd.setCursor((16+(i - k)) % 16, 1);
          lcd.print(LCD_ROW_2.charAt(i));
        }
      }
      if (SCROLL_FLAG){
        if(SCROLL_DIRECTION=='L')j++;
        else j--;
        if(LCD_ROW_1.length() < 16&& j>=16) j=0;
      }
      if (SCROLL_FLAG){
        if(SCROLL_DIRECTION=='L')k++;
        else k--;
        if(LCD_ROW_2.length() < 16&& k>=16) k=0;
      }
    }
    long end_time = micros();
    if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
    counter++;
  }
}