#include <LiquidCrystal.h> //include LiquidCrystal library

LiquidCrystal lcd = LiquidCrystal(); //create a LiquidCrystal object to control an LCD
char string1[] = "Hello!"; //variable to store the string "Hello!" 

void setup(void){
   lcd.init(); //initialize the LCD
   digitalWrite(13,HIGH); //turn on an LED for debugging
}
void loop(void){
   lcd.commandWrite(2); //bring the cursor to the starting position
   delay(1000); //delay 1000 ms to view change
   lcd.printIn(string1); //send the string to the LCD
   delay(1000); //delay 1000 ms to view change
} //repeat forever
