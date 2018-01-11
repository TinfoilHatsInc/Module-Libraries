TinfoilModules library
===================

This library is used to specify the behavior of each module and allow communication between them and the TinfoilCHUB.

## Library explaination

The following folders and according classes in this library can be uploaded on an Arduino to set a specific module behavior:
* **DoorModule**
* **MotionModule**
* **PressurePlateModule**
* **TripwireModule**
* SirenModule

Each of the modules in bold text is able to detect a specific kind of intrusion and to trigger the global alarm system thanks to the *CheckTrigger()* function. Some of them can be disabed (to avoid a waste of energy when the user don't want to monitor his house) and enabled again thanks to the *Disarm()/Arm()* functions. 

The SirenModule is an optionnal component which can produce a huge noise when the alarm gets triggered by using the *turnOnSiren()* function. The sound signal can later be turned off using the *turnOffSiren()* function. 
The first two classes are **not** be used in clients as they are only applicable in APIs (Tinfoil HAPI) for processing 

Those two other folders and derivating classes are used globally to enable communication between the modules and the TinfoilCHUB and insure that the plugged in modules are genuine Tinfoil Modules:
* Communication
* LifeStatus