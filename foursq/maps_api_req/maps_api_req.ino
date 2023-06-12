#include <WiFiNINA.h>
#include <ArduinoJson.h>

char ssid[] = "your_SSID"; // your network SSID (name)
char pass[] = "your_PASSWORD"; // your network password
int status = WL_IDLE_STATUS; // the WiFi radio's status

WiFiClient client; // create a WiFi client object

void setup() {
  Serial.begin(9600); // initialize serial communication
  while (!Serial); // wait for serial port to connect
  Serial.println("Connecting to WiFi network...");
  status = WiFi.begin(ssid, pass); // attempt to connect to WiFi network
  while (status != WL_CONNECTED) { // if not connected, keep trying
    delay(500);
    Serial.print(".");
    status = WiFi.begin(ssid, pass);
  }
  Serial.println("\nConnected to WiFi network!");
}

void loop() {
  if (client.connect("maps.googleapis.com", 443)) { // connect to Google Places API endpoint
    Serial.println("Connected to Google Places API endpoint!");
    client.print("GET /maps/api/place/nearbysearch/json?location=your_latitude,your_longitude&radius=5000&type=hospital&key=your_api_key HTTP/1.1\r\n"); // send HTTP GET request
    client.print("Host: maps.googleapis.com\r\n");
    client.print("Connection: close\r\n");
    client.print("\r\n");
    while (client.connected()) { // read response from Google Places API endpoint
      if (client.available()) {
        String line = client.readStringUntil('\n');
        if (line.startsWith("{\"name\":")) {
          DynamicJsonDocument doc(1024);
          deserializeJson(doc, line);
          String name = doc["name"];
          Serial.print("Nearest hospital: ");
          Serial.println(name);
          break;
        }
      }
    }
    client.stop(); // close connection
    Serial.println("Connection closed.");
  }
  else {
    Serial.println("Unable to connect to Google Places API endpoint.");
  }
  delay(5000); // wait 5 seconds before fetching data again
}
