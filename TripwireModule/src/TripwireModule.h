#ifndef TripwireModule_h
#define TripwireModule_h


#if(ARDUINO>= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
class TripwireModule
{
public:
    MotionModule(int);
    void CheckTrigger();
    void MeasureDistance();
private:
    int UltrasonicSensorPin;
    int TriggerDistance;
}; 

#endif