#include <LiquidCrystal.h> //include LiquidCrystal library

LiquidCrystal lcd = LiquidCrystal(); //create a LiquidCrystal object to control an LCD

void setup(void){
   lcd.init(); //initialize the LCD
   digitalWrite(13,HIGH); //turn on an LED for debugging
}

void loop(void){
   lcd.clear(); //clear the display
   delay(1000); //delay 1000 ms to view change
   lcd.print('a'); //send individual letters to the LCD
   lcd.print('b');
   lcd.print('c');
   delay(1000);//delay 1000 ms to view change
   
} //repeat forever
