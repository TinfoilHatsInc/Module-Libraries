#include "TripwireModule.h"

TripwireModule::TripwireModule(int InputPin, int TDistance){
    UltrasonicSensorPin = InputPin;
    TriggerDistance = TDistance;
    unsigned long PulseDuration = 0;
    int CentimeterDistance;
    Serial.begin(9600);
    pinMode(UltrasonicSensorPin, OUTPUT);
    //TEST INDICATOR
    pinMode(LED_BUILTIN, OUTPUT);
}

void TripwireModule::MeasureDistance(){
    // set pin to send a pulse
    pinMode(UltrasonicSensorPin, OUTPUT);
    digitalWrite(UltrasonicSensorPin, LOW);
    delayMicroseconds(5);

    // send pulse
    digitalWrite(UltrasonicSensorPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(UltrasonicSensorPin, LOW);

    // set pin to read incoming pulse
    pinMode(UltrasonicSensorPin, INPUT);

    // measure incoming pulse
    PulseDuration = pulseIn(UltrasonicSensorPin, HIGH);
}

void TripwireModule::CheckTrigger(){
    MeasureDistance();
    // convert into centimeters
    PulseDuration = PulseDuration/2;
    CentimeterDistance = int(PulseDuration/29);

    // check is inferior than TriggeredDistance
    if (CentimeterDistance <= TriggerDistance) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}