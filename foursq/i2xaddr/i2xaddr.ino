
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  lcd.init();                     
  lcd.backlight();
  }
void loop()
{
  lcd.print("HEy");
  delay(2000);
  }
