#include <WiFiNINA.h>

char ssid[] = "IITMandi_5.0 GHz"; // your network SSID (name)
char pass[] = "wifi@iit"; // your network password

char proxy[] = "http://gateway.iitmandi.ac.in"; // your proxy server address
int port = 8080; // your proxy server port number

int status = WL_IDLE_STATUS; // the WiFi radio's status

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // set the proxy server address and port number
  WiFi.setProxyAddress(proxy, port);

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(5000);
  }

  Serial.println("Connected to WiFi network");
}

void loop() {
  // do nothing
}
