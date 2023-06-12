#include <Wire.h>

#define SIM900A_ADDRESS 0x6A // I2C address of SIM900A module

void setup() {
  Wire.begin();
  Serial.begin(115200); // Serial communication with Arduino IDE
}

void loop() {
  // Send data to SIM900A
  Wire.beginTransmission(SIM900A_ADDRESS);
  Wire.write("AT");
  Wire.endTransmission();

  delay(1000);

  // Read data from SIM900A
  Wire.requestFrom(SIM900A_ADDRESS, 13);
  while (Wire.available()) {
    Serial.write("HI");
    // Send data to Arduino IDE
    Serial.write( Wire.read());
  }

  delay(1000);
}
