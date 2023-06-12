//#include <SoftwareSerial.h>

// Define the RX and TX pins used by the GSM module
//const int GSM_RX_PIN = 2; // Connect to GSM TX pin
//const int GSM_TX_PIN = 3; // Connect to GSM RX pin

// Create a SoftwareSerial object for the GSM module
//SoftwareSerial gsmSerial(GSM_RX_PIN, GSM_TX_PIN);

void setup() {
  // Start the serial communication with the GSM module
  Serial1.begin(9600);
  Serial.begin(115200);
  // Wait for the GSM module to initialize
  delay(1000);

  // Initialize the GSM module by sending AT commands
  Serial1.println("AT");
  delay(500);
  Serial1.println("AT+CPIN?");
  delay(500);

  // Make a call to the specified phone number
  Serial1.println("ATD+919713265979;"); // Replace +1234567890 with the phone number you want to call
  delay(10000); // Wait for 10 seconds for the call to connect

  // Hang up the call
  Serial1.println("ATH");

  if(Serial1.available()){
    Serial.write(Serial1.read());
  }
}

void loop() {
  if(Serial.available()){
    Serial1.write(Serial.read());
    Serial.write(Serial1.read());
    }
    if(Serial1.available()){
      Serial.write(Serial1.read());
    }
  // Do nothing in the loop
}
