#include "LifeStatus.h"
#include "Arduino.h"
#include <EEPROM.h>


LifeStatus::LifeStatus(uint64_t signature)
{
    LS_location_sig = 0;
    EEPROM.put(LS_location_sig, signature);
}

uint64_t LifeStatus::init()
{   
    uint64_t LS_signature;
    EEPROM.get(LS_location_sig,LS_signature);
    return LS_signature;
}

void LifeStatus::initHash(uint64_t hash)
{
    LS_location_hash = sizeof(uint64_t);
    EEPROM.put(LS_location_hash,hash);
}