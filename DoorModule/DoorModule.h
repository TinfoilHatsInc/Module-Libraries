#ifndef DoorModule_h
#define DoorModule_h


#if(ARDUINO>= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
class DoorModule
{
public:
    DoorModule(int, int);
    void Arm();
    void Disarm();
    void CheckTrigger();
private:
    int SensorOutputPin;
    int SensorInputPin;
    bool Armed;
};

#endif
