#include <WiFiNINA.h>
//#include <WiFiSSLClient.h>
#include <ArduinoJson.h>

char ssid[] = "OnePlus Nord CE 2";
char pass[] = "YASH1234";

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
//  while (!Serial);
  Serial.println("Starting...");

  if (!WiFi.begin(ssid, pass)) {
    Serial.println("WiFi connection failed!");
    while (true);
  }

  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiSSLClient client;
    if (client.connect("browse.search.hereapi.com", 443)) {
      client.println("GET /v1/browse?at=31.708401,76.932198&limit=4&categories=800-8000-0000&apiKey=X62ZFkTVetzJyRyb5kgM-9qVlcjwJ5-Cqex6gSq56Ig HTTP/1.1");
      client.println("Host: browse.search.hereapi.com");
      client.println("Connection: close");
      client.println();
      while (client.connected()) {
        String line = client.readStringUntil('\n');
        if (line == "\r") {
          break;
        }
      }
      String payload = client.readString();
//      Serial.println(payload);
      parsee(payload);
      client.stop();
    }
  }
  delay(5000);
}

void parsee(String json){
  DynamicJsonDocument doc(10000);
  DeserializationError error=  deserializeJson(doc, json);
   if (error) {
    Serial.println("Failed to parse JSON");
    return;
  }
// Get the array of hospitals from the JSON response
  JsonArray hospitals = doc["items"];

  // Iterate over the array of hospitals
  for (JsonObject hospital : hospitals) {
    // Get the name of the hospital
    String name = hospital["title"].as<String>();

    // Get the address of the hospital
    JsonObject address = hospital["address"];
    String street = address["street"].as<String>();
    String subdistrict = address["subdistrict"].as<String>();
    String district = address["district"].as<String>();
    String city = address["city"].as<String>();
    String state = address["state"].as<String>();
    String postalCode = address["postalCode"].as<String>();
    String fullAddress = street + ", " + subdistrict + ", " + district + ", " + city + ", " + state + " " + postalCode;

    // Get the phone number of the hospital
    String phoneNumber = "";
    if (hospital["contacts"].size() > 0) {
      JsonArray phoneNumbers = hospital["contacts"][0]["phone"];
      int cnt = 0;
      if (phoneNumbers.size() > 0) {
        while(cnt < phoneNumbers.size()){
          phoneNumber += phoneNumbers[cnt]["value"].as<String>();
          phoneNumber += " , " ;
          cnt++;
        }
        
      }
    }

    // Print the name, address, and phone number of the hospital
    Serial.println("Hospital: " + name);
    Serial.println("Address: " + fullAddress);
    Serial.println("Phone: " + phoneNumber);
    Serial.println();
  }
}
