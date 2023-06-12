#include <TinyGPS++.h>

// Create a TinyGPS++ object
TinyGPSPlus gps;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600); // Initialize Serial1 for communication with the GPS module
}

void loop()
{
  // Read data from GPS module
  while (Serial1.available())
  {
    if (gps.encode(Serial1.read()))
    {
      // If valid data is received from GPS module, extract latitude and longitude
      if (gps.location.isUpdated())
      {
        double latitude = gps.location.lat();
        double longitude = gps.location.lng();
        
        // Construct Google Maps link
//        String mapsLink = "https://www.google.com/maps?q=" + String(latitude, 6) + "," + String(longitude, 6);
        String mapsLink = "https://www.google.com/maps?q=@" + String(latitude, 6) + "," + String(longitude, 6);

        // Print the Google Maps link to serial monitor
        Serial.println("Google Maps Link: " + mapsLink);
      }
    }
  }
}
