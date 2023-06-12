#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("LCD with Arduino");
  pinMode(9, OUTPUT);  // optional, enable backlight
  digitalWrite(9, HIGH); // optional, enable backlight
  analogWrite(5, 60); // set contrast to 60 (0-255)
}

void loop() {
  // Do nothing in the loop
}
