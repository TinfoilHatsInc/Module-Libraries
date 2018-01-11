#include "/usr/share/arduino/hardware/arduino/cores/arduino/Arduino.h"
#include "TinfoilModule.h"
#include "/usr/share/arduino/libraries/Wire/Wire.h"


class ModuleLogin: public TinFoilModule{
public:

  ModuleLogin();

private:
  static int slaveAddress;
  static int requestAddress;

  void logEvent();
  void relog(int newAddr);
  void writeBackEvent();
};
