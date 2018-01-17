#include <Wire.h>

int SensorOutputPin;
int SensorInputPin;
boolean Armed;
byte Signature = 11000000;
int alarmStatus = 0;
int hashPoint = 0;
int slaveAddress = 127;
int hash[8];
int requestAddress = 200;


void setup(){
  Wire.begin(slaveAddress);
  Wire.onReceive(processReceived);
  Wire.onRequest(writeBackEvent);
    SensorOutputPin = 8;
    SensorInputPin = 9;
    Armed = true;
    pinMode(SensorOutputPin,OUTPUT);
    pinMode(SensorInputPin,INPUT);
    //TEST INDICATOR
    pinMode(LED_BUILTIN, OUTPUT);
    Arm();
}


void loop(){
  CheckTrigger();
}

void Arm(){
	if (Armed == true){
		digitalWrite(SensorOutputPin,HIGH);
    	Armed = true;
	}
}

void Disarm(){
	if (Armed == true){
		digitalWrite(SensorOutputPin,LOW);
		Armed = false;
	}
}

void CheckTrigger(){
    if ((Armed == true)&&(digitalRead(SensorInputPin) == HIGH)){
    	//TO REPLACE WITH THE ALARM TRIGGER
    	digitalWrite(LED_BUILTIN, HIGH);
      alarmStatus = 1;
    } else {
    	digitalWrite(LED_BUILTIN, LOW);
      alarmStatus = 0;
    }
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
