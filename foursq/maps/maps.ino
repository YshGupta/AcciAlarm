#include <WiFiNINA.h>
#include<WiFiClient.h>
WiFiClient client;
char ssid[] = "OnePlus Nord CE 2";      // your network SSID (name)
char password[] = "YASH1234";  // your network password (use for WPA, or use as key for WEP)

int status = WL_IDLE_STATUS;    // the WiFi radio's status
String apiKey = "AIzaSyCHaeV1Qb4pNwKJRZh5OYubDk69QS1jVJ4";

// Replace with your actual latitude and longitude
String latitude = "31.708401";
String longitude = "76.932198";

void setup() {
  Serial.begin(9600);       // initialize serial communication
  while (!Serial);          // wait for serial port to connect. Needed for native USB port only

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, password);
    // wait 10 seconds for connection:
    delay(10000);
  }

  // if you get a connection, print WiFi status:
  Serial.println("Connected to WiFi");
  printWiFiStatus();
  
  
}

void loop() {
  // do nothing
  
  String url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json?location=" + latitude + "," + longitude + "&radius=5000&type=hospital&key=" + apiKey;
  if (client.connect("maps.googleapis.com", 443)) {
    client.println("GET " + url + " HTTP/1.1");
    client.println("Host: maps.googleapis.com");
    client.println("Connection: close");
    client.println();
  }

   while (client.available()) {
    Serial.println("fetching");
    String line = client.readStringUntil('\r');
    if (line.startsWith("    \"name\":")) {
      // Print the name of the nearest hospital
      String name = line.substring(14, line.length() - 2);
      Serial.print("Nearest hospital: ");
      Serial.println(name);
    }
    if (line.startsWith("    \"vicinity\":")) {
      // Print the address of the nearest hospital
      String address = line.substring(18, line.length() - 2);
      Serial.print("Address: ");
      Serial.println(address);
    }
  }
  
}

void printWiFiStatus() {
  // print the SSID of the network you're connected to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
