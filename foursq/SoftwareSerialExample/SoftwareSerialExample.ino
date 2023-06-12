#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(8, 7); // RX, TX pins of SIM900A

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
  delay(1000);
  Serial.println("Initializing GSM module...");
  gsmSerial.println("AT"); // Send AT command to the module
  delay(1000);
  while(gsmSerial.available()) { // Read and print response from module
    Serial.write(gsmSerial.read());
  }
}

void loop() {
  String number = "+123456789"; // Phone number to call
  Serial.println("Making a call to " + number);
  gsmSerial.println("ATD" + number + ";"); // Send ATD command to dial the number
  delay(10000); // Wait for the call to connect
  gsmSerial.println("ATH"); // Send ATH command to hang up the call
  Serial.println("Call ended");
  delay(5000); // Wait before making another call
}
