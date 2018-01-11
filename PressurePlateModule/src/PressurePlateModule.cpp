
#include "PressurePlateModule.h"


PressurePlateModule::PressurePlateModule(int OutputPin, int InputPin){
    SensorOutputPin = OutputPin;
    SensorInputPin = InputPin;
    Armed = FALSE;
    pinMode(SensorOutputPin,OUTPUT);
    pinMode(SensorInputPin,INPUT);
    //TEST INDICATOR
    pinMode(LED_BUILTIN, OUTPUT);
}

void PressurePlateModule::Arm(){
	if (Armed == FALSE){
		digitalWrite(SensorOutputPin,HIGH);
    	Armed = TRUE;
	}
}

void PressurePlateModule::Disarm(){
	if (Armed == TRUE){
		digitalWrite(SensorOutputPin,LOW);
		Armed = FALSE;
	}
}

void PressurePlateModule::CheckTrigger(){
    if ((Armed == TRUE)&&(digitalRead(sensorInputPin) == HIGH)){
    	//TO REPLACE WITH THE ALARM TRIGGER
    	digitalWrite(LED_BUILTIN, HIGH);
    } else {
    	digitalWrite(LED_BUILTIN, LOW);
    }
}