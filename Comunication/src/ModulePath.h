#include "Arduino.h"
#include "TinfoilModule.h"
#include "EEPROM.h"
#include "Wire.h"


class ModuleLogin: public TinFoilModule{
public:
  ModuleLogin();

private:
  static int slaveAddress;
  static int requestFeedback;

  void logEvent();
  void writeBackEvent();
};
