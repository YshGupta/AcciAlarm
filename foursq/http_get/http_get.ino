#include <WiFiNINA.h>

char ssid[] = "OnePlus Nord CE 2"; // your network SSID (name)
char pass[] = "YASH1234"; // your network password
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
  if (client.connect("worldtimeapi.org", 80)) { // connect to website endpoint
    Serial.println("Connected to website endpoint!");
    client.println("GET /api/timezone/Europe/London HTTP/1.1"); // send HTTP GET request
    client.println("Host: worldtimeapi.org");
    client.println("Connection: close");
    client.println();
    while (client.connected()) { // read response from website endpoint
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
      }
    }
    client.stop(); // close connection
    Serial.println("\nConnection closed.");
  }
  else {
    Serial.println("Unable to connect to website endpoint.");
  }
  delay(5000); // wait 5 seconds before fetching data again
}
