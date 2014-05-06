#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#include <inttypes.h>

class LiquidCrystal {
public:
  LiquidCrystal();
  void commandWrite(int value);
  void init ();
  void print(int value); 
  void printIn(char value[]);
  void clear();
  /*
  //no room for following functions:
  void home();
  void setCursor(int index); 
  void shiftDisplayLeft();
  void shiftDisplayRight();
  */
};

#endif



