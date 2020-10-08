#include "scoreBoard.h"

scoreBoard::scoreBoard()
{
	playerScore defaultValues = { " ", 0, 0, 0, 0, 0, 0, 0 };
	playerScores[0] = defaultValues;
	playerScores[1] = defaultValues;
	playerScores[2] = defaultValues;
	tempScore = defaultValues;
}


void scoreBoard::setFilePath(std::string filepath)
{
	filePath = filepath;
}

void scoreBoard::setScore(playerScore info)
{
	bool wasPlaced = false;
	bool wasReplaced = false;
	//Need to not only check if it beat a score but also update and move down the array
	playerScore temp = info;
	for (int i = 0; i < 3; i++) {
		if (playerScores[i].name == " ") {
			playerScores[i] = temp;
			i = 10;
		}
		else if (playerScores[i].totalTime > temp.totalTime) {
			playerScore buff = playerScores[i];
			
			playerScores[i] = temp;

			temp = playerScores[i];
		}
	}
	writeToFile();
}

void scoreBoard::writeToFile()
{
	std::ofstream file;
	file.open(filePath);
	for (int i = 0; i < 3; i++) {
		file << playerScores[i].name << "\n" << std::to_string(playerScores[i].timeCheckPoint1) << "\n" <<
			std::to_string(playerScores[i].timeCheckPoint2) << "\n" << std::to_string(playerScores[i].timeCheckPoint3) << "\n" <<
			std::to_string(playerScores[i].timeCheckPoint4) << "\n" << std::to_string(playerScores[i].timeCheckPoint5) << "\n" <<
			std::to_string(playerScores[i].timesDied) << "\n" << std::to_string(playerScores[i].totalTime) << "\n";
	}
	file.close();
}

void scoreBoard::loadValues()
{
	std::ifstream files;
	files.open(filePath);
	std::string workd;
	int counter = 0;
	int i = 0;
	while (std::getline(files, workd)) {
		switch (counter) {
		case 0:
			playerScores[i].name = workd;
			break;
		case 1:
			playerScores[i].timeCheckPoint1 = std::stof(workd);
			break;
		case 2:
			playerScores[i].timeCheckPoint2 = std::stof(workd);
			break;
		case 3:
			playerScores[i].timeCheckPoint3 = std::stof(workd);
			break;
		case 4:
			playerScores[i].timeCheckPoint4 = std::stof(workd);
			break;
		case 5:
			playerScores[i].timeCheckPoint5 = std::stof(workd);
			break;
		case 6:
			playerScores[i].timesDied = std::stof(workd);
			break;
		case 7:
			playerScores[i].totalTime = std::stof(workd);
			break;
		}
		counter++;
		if (counter > 7) {
			counter = 0;
			i++;
		}
	}
	files.close();
}

playerScore scoreBoard::getInfo(int number)
{
	return playerScores[number];
}


void scoreBoard::startTimer()
{
	startTime = std::chrono::steady_clock::now();
}

void scoreBoard::saveCheckPoint(int checkpoint)
{
	float section = 0;
	float section2 = 0;
	float section3 = 0;
	float section4 = 0;

	switch (checkpoint) {
	case 1:
		std::chrono::duration<float> timePassed = (std::chrono::steady_clock::now() - startTime);
		tempScore.timeCheckPoint1 = timePassed.count();
		break;

	case 2:
		std::chrono::duration<float> timePassed2 = (std::chrono::steady_clock::now() - startTime);
		section = timePassed2.count() - tempScore.timeCheckPoint1;
		tempScore.timeCheckPoint1 = section;
		break;
	case 3:
		std::chrono::duration<float> timePassed3 = (std::chrono::steady_clock::now() - startTime);
		section2 = timePassed3.count() - tempScore.timeCheckPoint2;
		tempScore.timeCheckPoint1 = section2;
		break;
	case 4:
		std::chrono::duration<float> timePassed4 = (std::chrono::steady_clock::now() - startTime);
		section3 = timePassed4.count() - tempScore.timeCheckPoint3;
		tempScore.timeCheckPoint1 = section3;
		break;
	case 5:
		std::chrono::duration<float> timePassed5 = (std::chrono::steady_clock::now() - startTime);
		section4 = timePassed5.count() - tempScore.timeCheckPoint4;
		tempScore.timeCheckPoint1 = section4;
		tempScore.totalTime = tempScore.timeCheckPoint1 + tempScore.timeCheckPoint2 + tempScore.timeCheckPoint3 + tempScore.timeCheckPoint4 + tempScore.timeCheckPoint5;
		tempScore.name = "player";
		setScore(tempScore);
		break;
		
	}
}


