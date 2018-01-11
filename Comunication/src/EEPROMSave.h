#include "/usr/share/arduino/libraries/EEPROM/EEPROM.h"
#include <string>

class EEMPROMSave{
public:
  int saveHash(std::string hash);
  int saveAddress(std::string addr);

private:
  uint8_t EEPROMPointer;
};
