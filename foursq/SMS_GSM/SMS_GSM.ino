void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  SendMessage();
  delay(5000);
}

 void SendMessage()   
  {   
  Serial.println ("Sending Message");   
  Serial1.println("AT+CMGF=1");                   //Sets the GSM Module in Text Mode   
  delay(5000);   
  Serial.println ("Setting SMS Number");   
  Serial1.println("AT+CMGS=\"+919713265979\"\r"); //Write Mobile number to send message   
  delay(1000);   
  Serial.println ("Setting SMS Content");   
  Serial1.println("Hey");                      // Messsage content   
  delay(100);   
  Serial.println ("Finish");   
  Serial1.println((char)26);                      // ASCII code of CTRL+Z   
  delay(1000);   
  Serial.println ("Message has been sent Yash ");   
  }  
