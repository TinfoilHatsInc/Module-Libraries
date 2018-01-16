#include <Wire.h>

int SirenPin;
byte Signature = 11001011;
int alarmStatus = 0;
int hashPoint = 0;
int slaveAddress = 127;
int hash[8];
int requestAddress = 200;

void setup(){  
  Serial.begin(9600);
  SirenModule(9);
  turnOnSiren();
  Serial.println(SirenPin);
  delay(1000);
  turnOffSiren();
  Wire.begin(slaveAddress);
  Wire.onRequest(writeBackEvent);
  Wire.onReceive(processReceived);
}

void loop(){
  if(alarmStatus == 1){
    turnOnSiren();
  }else{
    turnOffSiren();
  }
  delay(10);
}

void processReceived(int byteCount){
  int temp;
  int buffer[10];
  int pointer = 0;
  while(Wire.available()){
    temp = (int) Wire.read();
    buffer[pointer++] = temp;
  }
  pointer = 0;
  switch (buffer[0]) {
    case 128:
      requestAddress = 128;
      slaveAddress = buffer[1];
    break;
    case 127:
      requestAddress = 200;
      for (int i = 0; i < 8; i++) {
        hash[i] = buffer[i+1];
      }
      relog(slaveAddress);
    break;
    case 125:
      requestAddress = 125;
    break;
    case 124:
      requestAddress = 124;
    break;
    case 123:
      requestAddress = 200;
      for (int i = 0; i < 8; i++) {
        hash[i] = buffer[i+1];
      }
    break;
    case 122:
      requestAddress = 200;
      alarmStatus = 1;
    break;
    case 121:
      requestAddress = 200;
      alarmStatus = 0;
  }
}


void writeBackEvent(){

  switch (requestAddress) {
    case 200:
      Wire.write(200);
      requestAddress = 0;
    break;
    case 201:
      Wire.write(201);
      requestAddress = 0;
    break;
    case 128:
      Wire.write(Signature);
      requestAddress = 0;
    break;
    case 125:
      Wire.write(alarmStatus);
      requestAddress = 0;
    break;
    case 124:
      Wire.write(hash[hashPoint++]);
      if(hashPoint == 8){
        hashPoint = 0;
        requestAddress = 0;
      }
    break;
  }
}


void relog(int newAddr){
  slaveAddress = newAddr;
  Wire.begin(slaveAddress);
  Wire.onReceive(processReceived);
  Wire.onRequest(writeBackEvent);
}

void SirenModule(int pin)
{
    SirenPin = pin;
    pinMode(SirenPin,OUTPUT);
}

void turnOnSiren()
{
    digitalWrite(SirenPin,HIGH);
}

void turnOffSiren()
{
    digitalWrite(SirenPin,LOW);
}
