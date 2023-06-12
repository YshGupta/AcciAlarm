void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
}

void loop() {
//   put your main code here, to run repeatedly:
  while(Serial.available()){
    Serial1.write(Serial.read());
  }
  while(Serial1.available()){
    Serial.write(Serial1.read());
  }
}
