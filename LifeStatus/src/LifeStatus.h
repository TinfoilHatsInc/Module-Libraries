#ifndef LifeStatus_h
#define LifeStatus_h

#if(ARDUINO>= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#include <inttypes.h>

class LifeStatus
{
public:
	LifeStatus(uint64_t);
	uint64_t lsinit();
	void initHash(uint64_t);

	uint64_t receivedBroadcast();
	void updateHash(uint64_t);

private:
	int LS_location_sig;
	int LS_location_hash;
};


#endif