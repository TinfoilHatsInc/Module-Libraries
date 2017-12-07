#include "ModulePath.h"

ModulePath::ModulePath(){
  ModulePath::slaveAddress = 127;
  ModulePath::requestFeedback = 0;
  Wire.begin(ModulePath::slaveAddress);
  Wire.onReceive(logEvent);
  Wire.onRequest(writeBackEvent);
}

void ModulePath::logEvent(){
  int request = Wire.read();
  char c;
  switch (request) {
    case 128:
      ModulePath::requestFeedback = request;
      while(1 < Wire.available()){
        c = Wire.read();
          //Respond with Signature
        }
    break;
    case 127:
      ModulePath::requestFeedback = request;
      while(1 < Wire.available()){
        c = Wire.read();
          //React by saving the first Hash, respond 200
        }
    break;
    case 126:
      ModulePath::requestFeedback = request;
      while(1 < Wire.available()){
        c = Wire.read();
          //React by saving new slaveAddress, respond 200
        }
    break;
    case 125:
      ModulePath::requestFeedback = request;
      while(1 < Wire.available()){
        c = Wire.read();
          //Respond with alarm status
        }
    break;
    case 124:
      ModulePath::requestFeedback = request;
      while(1 < Wire.available()){
        //Respond with Hash
      }
    break;
    case 123:
      ModulePath::requestFeedback = request;
      while(1 < Wire.available()){
        //Respond with 200/201
      }
    break;
  }
}


void writeBackEvent(){
  switch (ModulePath::requestFeedback) {
    case 200:
      Wire.write(200);
      ModulePath::requestFeedback = 0;
    break;
    case 201:
      Wire.write(201);
      ModulePath::requestFeedback = 0;
    break;
    case 128:
      Wire.write(TinfoilModule::Signature);
      ModulePath::requestFeedback = 0;
    break;
    case 125:
      Wire.write(TinfoilModule::status);
      ModulePath::requestFeedback = 0;
    break;
  }
}
