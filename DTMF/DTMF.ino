/* HT9200A DTMF Generator Test                             BroHogan 7/17/09
 * SETUP FOR SERIAL MODE - Requires 3 pins - Data and Clock (100KHz) and CE
 * Wire per data sheet - 3.57MHz xtal (4.0MHz won't dial) S/P to GND = serial
 * modified by Steve Spence - http://arduinotronics.blogspot.com
 */

#include <HT9200.h>                     // defines for HT9200 DTMF chip
#define DATA_PIN   2                    // Data (serial)
#define CLOCK_PIN  3                    // Clock (serial)
#define CE_PIN     4                    // Chip Enable pin (must control)

#define PHONE_NMBR "2642262"         // phone # to dial
char PhoneNum[] = PHONE_NMBR;           // load phone # for dialer

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(CE_PIN, OUTPUT);
  Init_HT9200();                        // init the chip
}

void loop() {
  Dialer();                             // dials phone
  delay(3000);
} 

void Init_HT9200 (){
  digitalWrite(CE_PIN, HIGH);           // start with chip disabled (else you go nuts)
  digitalWrite(CLOCK_PIN, HIGH);        // start with clock pin high
  digitalWrite(CE_PIN, LOW);            // now enable the chip
  delay(10);                            // delay 10ms to ramp up the ocillator
  DTMF_Out (DTMF_OFF,1,0);              // turn off any tone from previous run
}

void DTMF_Out (byte digit, long duration, long pause){  // FOR SERIAL COMM
  if (digit == 0) digit = 10;           // take care of 0 here
  for (byte i=0; i<5 br="br" i="i">    digitalWrite(CLOCK_PIN, HIGH);      // clock high while setting data
    digitalWrite(DATA_PIN, bitRead(digit,i)); // set data LSB->MSB
    delayMicroseconds(5);               // 1/2 of 100K Clock speed
    digitalWrite(CLOCK_PIN, LOW);       // clock low to latch data
    delayMicroseconds(5);               // 1/2 of 100K Clock speed
  }
  delay(duration);                      // how long tone will play
  if (pause != 0){                      // tone sounds continuously if zero
    for (byte i=0; i<5 above="above" as="as" br="br" i="i" nbsp="nbsp" same="same">      digitalWrite(CLOCK_PIN, HIGH);
      digitalWrite(DATA_PIN, bitRead(DTMF_OFF,i));
      delayMicroseconds(5);
      digitalWrite(CLOCK_PIN, LOW);
      delayMicroseconds(5);
    }
    delay(pause);                       // how long pause between tones
  }
}


void Dialer(){  // dials tones from number
  for (byte i=0; i<7 i="i" nbsp="nbsp" p="p"> //i<7 11="11" 7="7" br="br" digit="digit" for="for" i="i" number="number">    DTMF_Out(PhoneNum[i]-'0',500,100);  // 1/2 sec tone with 1/10 pause
  }
}


