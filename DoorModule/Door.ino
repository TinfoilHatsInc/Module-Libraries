void setup() {
  DoorModule::DoorModule mod = new DoorModule(8, 9);
  mod.Arm();
}

void loop() {
  mod.CheckTrigger();
  delay(10);  
}
