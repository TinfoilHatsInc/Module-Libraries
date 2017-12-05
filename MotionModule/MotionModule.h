2.2 threshold
lower = not triggered
higher = triggered.

#ifndef MotionModule_h
#define MotionModule_h


#if(ARDUINO>= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
class MotionModule
{
public:
    MotionModule(int);
    void CheckTrigger();
private:
    int SensorAnalogPin;
    int Threshold;
}; 

#endif