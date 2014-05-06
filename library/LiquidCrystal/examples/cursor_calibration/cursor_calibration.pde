#include <LiquidCrystal.h> //include LiquidCrystal library

LiquidCrystal lcd = LiquidCrystal(); //create a LiquidCrystal object to control an LCD

void setup(void){
   lcd.init(); //initialize the LCD
   digitalWrite(13,HIGH); //turn on an LED for debugging
}

void loop(void){
   delay(1000); //repeat forever
}
