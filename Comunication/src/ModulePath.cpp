#include "ModulePath.h"

ModulePath::ModulePath(){
  ModulePath::slaveAddress = 127;
  ModulePath::requestAddress = 0;
  Wire.begin(ModulePath::slaveAddress);
  Wire.onReceive(logEvent);
  Wire.onRequest(writeBackEvent);
}

void ModulePath::relog(int newAddr){
  ModulePath::slaveAddress = newAddr;
  Wire.begin(ModulePath::slaveAddress);
  Wire.onReceive(logEvent);
  Wire.onRequest(writeBackEvent);
}

void ModulePath::logEvent(){
  int request = Wire.read();
  char c;
  int pointer = 0;
  switch (request) {
    case 128:
      char[50] buffer;
      ModulePath::requestAddress = 200;
      while(1 < Wire.available()){
        c = Wire.read();
          buffer[pointer++] = c;
        }
        EEPROMSave::saveAddress(std::string(buffer));
        pointer = 0;
    break;
    case 127:
      char[50] buffer;
      ModulePath::requestAddress = 200;
      while(1 < Wire.available()){
        c = Wire.read();
          buffer[pointer++] = c;
        }
        EEPROMSave::saveHash(std::string(buffer));
        pointer = 0;
    break;
    case 126:
      ModulePath::requestAddress = 200;
      while(1 < Wire.available()){
        c = Wire.read();
        }
        relog(EEPROMSave::getAddress);
    break;
    case 125:
      ModulePath::requestAddress = 125;
      while(1 < Wire.available()){
        c = Wire.read();
        }
    break;
    case 124:
      ModulePath::requestAddress = request;
      while(1 < Wire.available()){
      }
    break;
    case 123:
      ModulePath::requestAddress = request;
      while(1 < Wire.available()){
        //Respond with 200/201
      }
    break;
  }
}


void ModulePath::writeBackEvent(){
  switch (ModulePath::requestAddress) {
    case 200:
      Wire.write(200);
      ModulePath::requestAddress = 0;
    break;
    case 201:
      Wire.write(201);
      ModulePath::requestAddress = 0;
    break;
    case 128:
      Wire.write(TinfoilModule::Signature);
      ModulePath::requestAddress = 0;
    break;
    case 125:
      Wire.write(TinfoilModule::alarmStatus);
      ModulePath::requestAddress = 0;
    break;
  }
}

//hash 8 bytes
//
