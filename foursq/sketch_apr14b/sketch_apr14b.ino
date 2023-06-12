void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200); // initialize serial communication with baud rate 115200
  Serial1.begin(9600);
 
  // Wait for the GSM module to initialize
  delay(1000);
  Serial1.println("AT+CMGF=0");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial1.available()){
     Serial1.println("ATD+919713265979;");
     delay(10000);
  }
}
