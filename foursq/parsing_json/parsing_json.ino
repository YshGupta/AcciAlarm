#include <WiFiNINA.h>
#include <ArduinoJson.h>

char ssid[] = "OnePlus Nord CE 2";
char password[] = "YASH1234";

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Starting...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
  WiFiClient client;
  if (client.connect("browse.search.hereapi.com", 443)) { // Replace with your API endpoint
    client.println("GET /v1/browse?at=31.708401,76.932198&limit=1&categories=800-8000-0000&apiKey=X62ZFkTVetzJyRyb5kgM-9qVlcjwJ5-Cqex6gSq56Ig HTTP/1.1");
    client.println("Host: browse.search.hereapi.com");
    client.println("Connection: close");
    client.println();
    String payload = "";
    while (client.connected()) {
      while (client.available()) {
        char c = client.read();
        Serial.println(c);
        payload += c;
      }
    }
//    Serial.println(payload);
  } else {
    Serial.println("Error connecting to server");
  }
  client.stop();
}

  delay(5000); // Wait for 5 seconds before making the next request
}
