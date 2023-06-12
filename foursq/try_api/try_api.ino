#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>

char ssid[] = "your_SSID"; // Replace with your network SSID
char pass[] = "your_PASSWORD"; // Replace with your network password
int status = WL_IDLE_STATUS;

const char* host = "browse.search.hereapi.com"; // Replace with your API endpoint
const int httpsPort = 443;

const char* apiKey = "X62ZFkTVetzJyRyb5kgM-9qVlcjwJ5-Cqex6gSq56Ig"; // Replace with your API key

WiFiSSLClient wifiClient;
HttpClient client = HttpClient(wifiClient, host, httpsPort);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  // Connect to Wi-Fi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  Serial.println("Connected to Wi-Fi");

  // Set up SSL connection
//  wifiClient.setInsecure();

  // Make GET request to API endpoint
  String url = "/v1/browse?at=31.708401,76.932198&limit=1&categories=800-8000-0000&apiKey=";
  url += apiKey;
  client.get(url);
  Serial.println("Response:");
  Serial.println(client.responseStatusCode());
  Serial.println(client.responseBody());
}

void loop() {
  // Do nothing
}
