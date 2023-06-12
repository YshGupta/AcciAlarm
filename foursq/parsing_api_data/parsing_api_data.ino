#include <WiFiNINA.h>
#include <WiFiSSLClient.h>
#include <ArduinoJson.h>

char ssid[] = "OnePlus Nord CE 2";
char password[] = "YASH1234";

void setup() {
  Serial.begin(9600);
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
    WiFiSSLClient client;
    if (client.connect("jsonplaceholder.typicode.com", 80)) { // Replace with your API endpoint
      client.println("GET /posts/1 HTTP/1.1");
      client.print("Host:jsonplaceholder.typicode.com\r\n");
      client.print("Connection: close\r\n");
      client.print("\r\n");
      while (client.connected()) {
        String line = client.readStringUntil('\n');
        if (line == "\r") {
          break;
        }
      }
      String payload = client.readString();
      Serial.println(payload);
//      // Parse the JSON data and extract the sections that we need
//      StaticJsonDocument<200> doc;
//      DeserializationError error = deserializeJson(doc, payload);
//      if (error) {
//        Serial.println("Error parsing JSON");
//      } else {
//        JsonArray items = doc["items"];
//        for (JsonObject item : items) {
//          String title = item["title"];
//          String address = item["address"]["label"];
//          Serial.print("Title: ");
//          Serial.println(title);
//          Serial.print("Address: ");
//          Serial.println(address);
//        }
//      }
    } else {
      Serial.println("Error connecting to server");
    }
    client.stop();
  }
  delay(1000); // Wait for 5 seconds before making the next request
}
