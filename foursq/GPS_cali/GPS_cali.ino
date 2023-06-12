void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);                        // initialize serial communication with baud rate 115200
  Serial1.begin(9600);                         // initialize serial communication with baud rate 9600
   delay(1000);         

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial1.available()){
    Serial.write(Serial1.read());
  }

}
