#ifndef PressurePlateModule_h
#define PressurePlateModule_h


#if(ARDUINO>= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
class PressurePlateModule
{
public:
    PressurePlateModule(int, int);
    void Arm();
    void Disarm();
    void CheckTrigger();
private:
    int SensorOutputPin;
    int SensorInputPin;
    bool Armed;
}; 

#endif