#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  Wire.begin();
  Serial.println("I2C Scanner");

}

void loop()
{
  byte error, address;
  int devices = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("Device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();
      devices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();
    }
  }
  if (devices == 0)
    Serial.println("No I2C devices found.");
  else
    Serial.println("Scanning complete.");

  delay(5000); // Wait 5 seconds before rescanning
}
