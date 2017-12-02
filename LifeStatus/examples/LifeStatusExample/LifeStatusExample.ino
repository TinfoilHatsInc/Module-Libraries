#include <LifeStatus.h>

LifeStatus ls(0x1ee7);

void setup() 
{
  ls.lsinit();
  ls.initHash(0x1312);
  ls.receivedBroadcast();
  ls.updateHash(0x23);
}

void loop() {
  // put your main code here, to run repeatedly:

}
