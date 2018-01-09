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
    void turnOnSiren();
    void turnOffSiren();
private:
    int SirenPin;
}; 



#endif