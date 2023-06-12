#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>

// Replace with your actual network credentials
char ssid[] = "OnePlus Nord CE 2";
char pass[] = "YASH1234";

void setup() {
  Serial.begin(9600);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  // Create a WiFi client object
  WiFiClient wifiClient;

  // Create an HTTP client object
  HttpClient httpClient = HttpClient(wifiClient, "example.com", 80);

  // Make an HTTP request
  httpClient.get("/");

  // Check the HTTP status code
  int statusCode = httpClient.responseStatusCode();
  Serial.print("HTTP status code: ");
  Serial.println(statusCode);

  // Check the content type
  String contentType = httpClient.responseBody("Content-Type");
  Serial.print("Content type: ");
  Serial.println(contentType);

  // Read the response body
  String responseBody = httpClient.responseBody();
  Serial.print("Response body: ");
  Serial.println(responseBody);

  // Extract the title and body text from the response body
  int titleStart = responseBody.indexOf("<title>") + 7;
  int titleEnd = responseBody.indexOf("</title>");
  String title = responseBody.substring(titleStart, titleEnd);
  Serial.print("Title: ");
  Serial.println(title);

  int bodyStart = responseBody.indexOf("<body>") + 6;
  int bodyEnd = responseBody.indexOf("</body>");
  String body = responseBody.substring(bodyStart, bodyEnd);
  Serial.print("Body: ");
  Serial.println(body);

  delay(5000);
}
