#include "SirenModule.h"


SirenModule::SirenModule(int pin)
{
    SirenPin = pin;
    pinMode(SirenPin,OUTPUT);
}

void SirenModule::turnOnSiren()
{
    digitalWrite(SirenPin,HIGH);
}

void SirenModule::turnOffSiren()
{
    digitalWrite(SirenPin,LOW);
}
