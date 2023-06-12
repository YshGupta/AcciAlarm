// 
//  #include <SoftwareSerial.h>   
//  SoftwareSerial SIM900A(2,3); // SoftSerial( RX , TX );   
  // 10 pin connect to TX of GSM SIM 900 Module   
  // 11 pin connect to RX of GSM SIM 900 Module   
  void setup()   
  {   
  Serial1.begin(9600); // Setting the baud rate of GSM Module    
  Serial.begin(115200); // Setting the baud rate of Serial Monitor (Arduino)   
  Serial.println ("SIM900A Ready");   
  delay(100);    
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
    
  }   
  
  void SendMessage()   
  {   
  Serial.println ("Sending Message");   
  Serial1.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode   
  delay(1000);   
  Serial.println ("Setting SMS Number");   
  Serial1.println("AT+CMGS=\"+919713265979\"\r"); //Write Mobile number to send message   
  delay(1000);   
  Serial.println ("Setting SMS Content");   
  Serial1.println("Helo ! google.comLatitude:31.7047266 Longitude:76.9379071\"\r""Elevation:779 m ");// Messsage content   
  delay(100);   
  Serial.println ("Finish");   
  Serial1.println((char)26);// ASCII code of CTRL+Z   
  delay(1000);   
  Serial.println ("Message has been sent ->hEY ! Yash ");   
  }   
