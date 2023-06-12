#include <WiFiNINA.h>

char ssid[] = "OnePlus Nord CE 2"; // Replace with your WiFi network name
char pass[] = "YASH1234"; // Replace with your WiFi network password
int status = WL_IDLE_STATUS; // WiFi status
WiFiClient client; // WiFi client

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  status = WiFi.begin(ssid, pass);
  while (status != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    status = WiFi.status();
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  // Make HTTP request to Foursquare Places API
  if (client.connect("api.foursquare.com", 443)) {
    Serial.println("Connected to server");
    client.println("GET /v2/venues/search?ll=31.708401,76.932198&radius=5000&query=hospital&client_id=RC5B5EAJPLLK5X3LJQIE2ARYXTNRW3RHACQ1AVYV42503OKS&client_secret=K1ZPW3HV0FZ2XRJVKQW0ZBMOIVBTXHNQLPY2ZWMT3JZCNXAL&v=20220101 HTTP/1.1");
    client.println("Host: api.foursquare.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Connection failed");
  }

  // Read HTTP response
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
  }

  // Disconnect from server
  client.stop();

  // Wait for a few seconds before making another request
  delay(5000);
}
