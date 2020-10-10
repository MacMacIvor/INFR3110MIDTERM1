#pragma once
#ifndef __PLAYERSCORE__
#define __PLAYERSCORE__

#include <string>

struct playerScore {
	std::string name;
	float timeCheckPoint1;
	float timeCheckPoint2;
	float timeCheckPoint3;
	float timeCheckPoint4;
	float timeCheckPoint5;
	float totalTime;
	float timesDied;
};
struct playerScoreUnity {
	float timeCheckPoint1;
	float timeCheckPoint2;
	float timeCheckPoint3;
	float timeCheckPoint4;
	float timeCheckPoint5;
	float totalTime;
	float timesDied;
};


#endif