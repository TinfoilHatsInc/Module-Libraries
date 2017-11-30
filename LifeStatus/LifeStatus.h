#ifndef LifeStatus_h
#define LifeStatus_h

#include <inttypes.h>

class LifeStatus
{
public:
	LifeStatus(uint64_t signiture);
	uint64_t init();
	void initHash(uint64_t);

	void listenToBroadcast();
	void updateHashes();

		


private:
	uint64_t LS_signiture;
	uint64_t LS_Alive_Hash;

	void respondToBroadcast();

};


#endif