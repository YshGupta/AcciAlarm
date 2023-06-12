 
  #include <SoftwareSerial.h>   
  SoftwareSerial SIM900A(2,3); // SoftSerial( RX , TX );   
  // 10 pin connect to TX of GSM SIM 900 Module   
  // 11 pin connect to RX of GSM SIM 900 Module   
  void setup()   
  {   
  SIM900A.begin(9600); // Setting the baud rate of GSM Module    
  Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)   
  Serial.println ("SIM900A Ready");   
  delay(100);   
  Serial.println ("Type s to send message ");   
  }   
  void loop()   
  {   
  if (Serial.available()>0)   
   switch(Serial.read())   
  {   
   case 's':   
   SendMessage();   
   break;   
  }   
  if (SIM900A.available()>0)   
   Serial.write(SIM900A.read());   
  }   
  void SendMessage()   
  {   
  Serial.println ("Sending Message");   
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode   
  delay(1000);   
  Serial.println ("Setting SMS Number");   
  SIM900A.println("AT+CMGS=\"+919713265979\"\r"); //Write Mobile number to send message   
  delay(1000);   
  Serial.println ("Setting SMS Content");   
  SIM900A.println("Helo ! google.comLatitude:31.7047266 Longitude:76.9379071\"\r""Elevation:779 m ");// Messsage content   
  delay(100);   
  Serial.println ("Finish");   
  SIM900A.println((char)26);// ASCII code of CTRL+Z   
  delay(1000);   
  Serial.println ("Message has been sent ->hEY ! Yash ");   
  }   
