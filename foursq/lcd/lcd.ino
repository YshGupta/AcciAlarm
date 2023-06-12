#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize LCD display
  Wire.beginTransmission(0x27);
  Wire.write(0x00); // Command byte
  Wire.write(0x38); // Set 2 lines and 5x8 font
  Wire.write(0x0C); // Turn on and cursor
  Wire.write(0x01); // Clear display
//  Wire.endTransmission();
 Wire.write(0x57); // Set cursor to first line, first character
  Wire.print("Hello, world!");
}

void loop() {
  // Display "Hello, world!" on first line
  Wire.beginTransmission(0x27);
  Wire.write(0x80); // Set cursor to first line, first character
  Wire.print("Hello, world!");
  Wire.endTransmission();
  
  delay(1000);
}
