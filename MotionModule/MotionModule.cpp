#include "DoorModule.h"

DoorModule::DoorModule(int InputPin){
    SensorAnalogPin = InputPin;
    Serial.begin(9600);
    Threshold = 450;
    //TEST INDICATOR
    pinMode(LED_BUILTIN, OUTPUT);
}

void DoorModule::CheckTrigger(){
    int analogValue = analogRead(analogPin);
    if (analogValue < Threshold) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}