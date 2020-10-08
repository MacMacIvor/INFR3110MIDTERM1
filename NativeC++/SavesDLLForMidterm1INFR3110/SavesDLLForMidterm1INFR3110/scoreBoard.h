#pragma once
#ifndef __SCOREBOARD__
#define __SCOREBOARD__

#include "PluginSettings.h"
#include "playerScore.h"
#include <chrono>
#include <string>
#include <fstream>

class PLUGIN_API scoreBoard
{
public:
	scoreBoard();
	playerScore getInfo(int number);
	void setFilePath(std::string filepath);
	void setScore(playerScore info);
	void startTimer();
	void saveCheckPoint(int checkpoint);
	void writeToFile();
	void loadValues();
private:
	playerScore playerScores[3];
	playerScore tempScore;
	std::chrono::steady_clock::time_point startTime;
	std::string filePath;
};


#endif // !