#include <WiFi.h>
#include <HTTPClient.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("OnePlus Nord Ce 2", "YASH1234");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  HTTPClient http;
  String url = "https://api.maptiler.com/maps/hybrid/nearest/hospitals.json?key=YOUR_API_KEY&lat=LATITUDE&lon=LONGITUDE";
  url.replace("YOUR_API_KEY", "Tgi71kPVS84Cs37gjTr5");
  url.replace("LATITUDE", "31.708401");
  url.replace("LONGITUDE", "76.932198");

  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
  }
  else {
    Serial.println("Error on HTTP request");
  }
  http.end();
}

void loop() {
  // do nothing
}
