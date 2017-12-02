#ifndef SirenModule_h
#define SirenModule_h


#if(ARDUINO>= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
class SirenModule
{
public:
    SirenModule(int);
    void soundAlarm();
    void turnOffAlarm();
private:
    int SirenPin;
}; 



#endif