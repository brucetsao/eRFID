#include <SPI.h>
#include <RFID.h>

RFID rfid(53,5);       //this is used for Arduino Mega 2560
//RFID rfid(10,5);    //this is used for Arduino UNO
//use library  is to declare like this 
//   RFID  devicename(NASS_pin_name, Reset_pin_name)l
void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  
}

void loop()
{
    if (rfid.isCard()) {
      
          Serial.println("IS CARD");
          
          if (rfid.readCardSerial()) {
            
                        Serial.println(" ");
                        Serial.println("RFID Card Number is : ");
			Serial.print(rfid.serNum[0],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[1],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[2],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[3],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[4],HEX);
                        Serial.println(" ");
                        
                       
            
          }
          
    }
    
    rfid.halt();
    delay(500);
}
