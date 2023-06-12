#include <WiFiNINA.h>
#include <ArduinoJson.h>

char ssid[] = "OnePlus Nord CE 2"; // Replace with your WiFi network name
char pass[] = "YASH1234"; // Replace with your WiFi network password
int status = WL_IDLE_STATUS; // WiFi status
WiFiClient client; // WiFi client

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
//
//  // Connect to WiFi network
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  status = WiFi.begin(ssid, pass);
//  while (status != WL_CONNECTED) {
//    delay(1000);
//    Serial.print(".");
//    status = WiFi.status();
//  }
//  Serial.println("");
//  Serial.println("WiFi connected");
}

void loop() {
  // Set the latitude and longitude of the location you want to search around
  float latitude = 31.708401;
  float longitude = 76.932198;

  // Set the search radius in kilometers
  int radius = 5;

  // Set the API endpoint and parameters
  String url = "https://www.who.int/data/gho/data/indicators/indicator-gho-0000002669.json";
  url += "?filter=within_circle(location," + String(latitude) + "," + String(longitude) + "," + String(radius) + ")";
  url += "&format=json&page=1&pageSize=100";
  Serial.println(url);
//  
//  // Send the API request and get the response
//  if (client.connect("www.who.int", 443)) {
//    Serial.println("Connected to server");
//    client.println("GET " + url + " HTTP/1.1");
//    client.println("Host: www.who.int");
//    client.println("Connection: close");
//    client.println();
//  } else {
//    Serial.println("Connection failed");
//  }
//
//  // Read HTTP response
//  String response = "";
//  while (client.connected()) {
//    if (client.available()) {
//      char c = client.read();
//      response += c;
//    }
//  }
//
//  // Disconnect from server
//  client.stop();
//
//  // Parse the response JSON and extract the hospital details
//  StaticJsonDocument<1024> doc;
//  DeserializationError error = deserializeJson(doc, response);
//  if (error) {
//    Serial.println("JSON parsing failed");
//    return;
//  }
//
//  JsonArray facts = doc["fact"].as<JsonArray>();
//  JsonObject hospital;
//  float min_distance = 999999;
//  for (JsonVariant fact : facts) {
//    if (fact["Dim1"] == "Hospitals") {
//      float hospital_latitude = fact["Dim3"];
//      float hospital_longitude = fact["Dim4"];
//      float distance = sqrt(pow(hospital_latitude - latitude, 2) + pow(hospital_longitude - longitude, 2));
//      if (distance < min_distance) {
//        hospital = fact;
//        min_distance = distance;
//      }
//    }
//  }
//
//  // Print the nearest hospital details
//  if (hospital) {
//    String name = hospital["SpatialDim"].as<String>();
//    float hospital_latitude = hospital["Dim3"];
//    float hospital_longitude = hospital["Dim4"];
//    Serial.println("Nearest hospital: " + name);
//    Serial.println("Latitude: " + String(hospital_latitude));
//    Serial.println("Longitude: " + String(hospital_longitude));
//  } else {
//    Serial.println("No hospitals found within the search radius");
//  }
//
//  // Wait for a few seconds before making another request
//  delay(5000);
}
