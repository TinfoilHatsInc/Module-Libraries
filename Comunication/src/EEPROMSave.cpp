#include "EEPROMSave.h"

uint8_t EEPROMPointer = EEPROM.get(0);

int saveHash(std::string hash){
  EEPROM.write(EEPROMPointer, hash);
}

int saveAddress(std::string addr){
  EEPROM.write(EEPROMPointer, addr);
}
