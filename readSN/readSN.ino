#include <SPI.h>
#include <RFID.h>

RFID rfid(53,5);       //this is used for Arduino Mega 2560
//RFID rfid(10,5);    //this is used for Arduino UNO


void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  
}

void loop()
{
    if (rfid.isCard()) {                                     //找尋卡片
          if (rfid.readCardSerial()) {                       //取得卡片的ID+CRC校驗碼
                        //第0~3個byte:卡片ID
                        Serial.println(" ");
                        Serial.print("RFID Card Number is : ");
			Serial.print(rfid.serNum[0],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[1],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[2],HEX);
                        Serial.print(" , ");
			Serial.println(rfid.serNum[3],HEX);
                        //第4個byte:CRC校驗位元
                        Serial.print("CRC is : ");
                        Serial.println(rfid.serNum[4],HEX);
          }
          
    }   
    rfid.halt();        //命令卡片進入休眠狀態
    delay(500);         //延時0.5秒
}
