
#include "DoorModule.h"


DoorModule::DoorModule(int OutputPin, int InputPin){
    SensorOutputPin = OutputPin;
    SensorInputPin = InputPin;
    Armed = FALSE;
    pinMode(SensorOutputPin,OUTPUT);
    pinMode(SensorInputPin,INPUT);
    //TEST INDICATOR
    pinMode(LED_BUILTIN, OUTPUT);
}

void DoorModule::Arm(){
	if (Armed == FALSE){
		digitalWrite(SensorOutputPin,HIGH);
    	Armed = TRUE;
	}
}

void DoorModule::Disarm(){
	if (Armed == TRUE){
		digitalWrite(SensorOutputPin,LOW);
		Armed = FALSE;
	}
}

void DoorModule::CheckTrigger(){
    if ((Armed == TRUE)&&(digitalRead(sensorInputPin) == LOW)){
    	//TO REPLACE WITH THE ALARM TRIGGER
    	digitalWrite(LED_BUILTIN, HIGH);
    } else {
    	digitalWrite(LED_BUILTIN, LOW);
    }
}
