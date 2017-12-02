#include "SirenModule.h"


SirenModule::SirenModule(int pin)
{
    SirenPin = pin;
    pinMode(SirenPin,OUTPUT);
}

void SirenModule::soundAlarm()
{
    digitalWrite(SirenPin,HIGH);
}

void turnOffAlarm()
{
    digitalWrite(SirenPin,LOW);
}