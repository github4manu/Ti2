// Do not remove the include below
#include "MsTimer2_test.h"

// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;	// 1.0 built in LED pin var
#else
const int led_pin = 13;			// default to pin 13
#endif

#define FLASHHIGHMS 500
#define FLASHHIGHCNT 1
void flashhigh()
{
  if (MsTimer2::count>=FLASHHIGHCNT) {
	  MsTimer2::stop();
	  MsTimer2::set(500, flashlow); // 500ms period
	  MsTimer2::start();
  } else {
    digitalWrite(led_pin, HIGH);
    //....
  }
}

#define FLASHLOWMS 250
#define FLASHLOWCNT 2
void flashlow()
{
	  if (MsTimer2::count>=FLASHLOWCNT) {
		  MsTimer2::stop();
		  MsTimer2::set(FLASHHIGHMS, flashhigh); // 500ms period
		  MsTimer2::start();
	  } else {
	    digitalWrite(led_pin, LOW);
	    //....
	  }
}


//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	  pinMode(led_pin, OUTPUT);
	  MsTimer2::set(500, flashhigh); // 500ms period
	  MsTimer2::start();

}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
