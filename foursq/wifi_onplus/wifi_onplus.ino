#include <WiFiNINA.h>

char ssid[] = "OnePlus Nord CE 2";      // your network SSID (name)
char password[] = "YASH1234";  // your network password (use for WPA, or use as key for WEP)

int status = WL_IDLE_STATUS;    // the WiFi radio's status

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
  delay(10000);
  printWiFiStatus();
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
