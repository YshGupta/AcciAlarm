#include <TinyGsmClient.h>

// Define GSM module connection parameters
const char apn[] = "airtelgprs.com";
const char gprsUser[] = "your_username";
const char gprsPass[] = "your_password";

TinyGsm modem(Serial1);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  Serial1.begin(115200);
  delay(1000);
  
  // Unlock your SIM card with a PIN if necessary
  //modem.simUnlock("1234");
  
  // Connect to the GSM network
  if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
    Serial.println("GSM initialization failed.");
  }
  else {
    Serial.println("GSM initialized successfully.");
  }
}

void loop() {
  // Your code here
}
