#include "scoreBoard.h"

scoreBoard::scoreBoard()
{
	playerScore defaultValues = { "a", 0, 0, 0, 0, 0, 0, 0 };
	playerScores1 = defaultValues;
	playerScores2 = defaultValues;
	playerScores3 = defaultValues;
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
	bool isDone = false;
	//Need to not only check if it beat a score but also update and move down the array
	playerScore temp = info;
	for (int i = 0; i < 3; i++) {
		playerScore buff;
		if (i == 0) {
			if (isDone == false) {
				if (playerScores1.name == "a") {
					playerScores1 = temp;
					i = 10;
					isDone = true;
				}
				else if (playerScores1.totalTime > temp.totalTime) {
					buff = playerScores1;

					playerScores1 = temp;

					temp = buff;
				}
			}
		}
		else if (i == 1) {
			if (isDone == false) {
				if (playerScores2.name == "a") {
					playerScores2 = temp;
					i = 10;
					isDone = true;
				}
				else if (playerScores2.totalTime > temp.totalTime) {
					buff = playerScores2;

					playerScores2 = temp;

					temp = buff;
				}
			}
		}
		else if (i == 2) {
			if (isDone == false) {
				if (playerScores3.name == "a") {
					playerScores3 = temp;
					i = 10;
					isDone = true;
				}
				else if (playerScores3.totalTime > temp.totalTime) {
					buff = playerScores3;

					playerScores3 = temp;

					temp = buff;
				}
			}
		}
		
	}
	writeToFile();
}

void scoreBoard::writeToFile()
{
	std::ofstream file;
	file.open(filePath);
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			file << playerScores1.name;
			file << "\n";
			file << std::to_string(playerScores1.timeCheckPoint1);
			file << "\n" +
				std::to_string(playerScores1.timeCheckPoint2) + "\n" + std::to_string(playerScores1.timeCheckPoint3) + "\n" +
				std::to_string(playerScores1.timeCheckPoint4) + "\n" + std::to_string(playerScores1.timeCheckPoint5) + "\n" +
				std::to_string(playerScores1.totalTime) + "\n" + std::to_string(playerScores1.timesDied) + "\n";
		}
		else if (i == 1) {
			file << playerScores2.name;
			file << "\n";
			file << std::to_string(playerScores2.timeCheckPoint1);
			file << "\n" +
				std::to_string(playerScores2.timeCheckPoint2) + "\n" + std::to_string(playerScores2.timeCheckPoint3) + "\n" +
				std::to_string(playerScores2.timeCheckPoint4) + "\n" + std::to_string(playerScores2.timeCheckPoint5) + "\n" +
				std::to_string(playerScores2.totalTime) + "\n" + std::to_string(playerScores2.timesDied) + "\n";
		}
		else if (i == 2) {
			file << playerScores3.name;
			file << "\n";
			file << std::to_string(playerScores3.timeCheckPoint1);
			file << "\n" +
				std::to_string(playerScores3.timeCheckPoint2) + "\n" + std::to_string(playerScores3.timeCheckPoint3) + "\n" +
				std::to_string(playerScores3.timeCheckPoint4) + "\n" + std::to_string(playerScores3.timeCheckPoint5) + "\n" +
				std::to_string(playerScores3.totalTime) + "\n" + std::to_string(playerScores3.timesDied) + "\n";
		}

		
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
			playerScores1.name = workd;
			break;
		case 1:
			playerScores1.timeCheckPoint1 = std::stof(workd);
			break;
		case 2:
			playerScores1.timeCheckPoint2 = std::stof(workd);
			break;
		case 3:
			playerScores1.timeCheckPoint3 = std::stof(workd);
			break;
		case 4:
			playerScores1.timeCheckPoint4 = std::stof(workd);
			break;
		case 5:
			playerScores1.timeCheckPoint5 = std::stof(workd);
			break;
		case 7:
			playerScores1.timesDied = std::stof(workd);
			break;
		case 6:
			playerScores1.totalTime = std::stof(workd);
			break;
		case 8:
			playerScores2.name = workd;
			break;
		case 9:
			playerScores2.timeCheckPoint1 = std::stof(workd);
			break;
		case 10:
			playerScores2.timeCheckPoint2 = std::stof(workd);
			break;
		case 11:
			playerScores2.timeCheckPoint3 = std::stof(workd);
			break;
		case 12:
			playerScores2.timeCheckPoint4 = std::stof(workd);
			break;
		case 13:
			playerScores2.timeCheckPoint5 = std::stof(workd);
			break;
		case 14:
			playerScores2.totalTime = std::stof(workd);
			break;
		case 15:
			playerScores2.timesDied = std::stof(workd);
			break;
		case 16:
			playerScores3.name = workd;
			break;
		case 17:
			playerScores3.timeCheckPoint1 = std::stof(workd);
			break;
		case 18:
			playerScores3.timeCheckPoint2 = std::stof(workd);
			break;
		case 19:
			playerScores3.timeCheckPoint3 = std::stof(workd);
			break;
		case 20:
			playerScores3.timeCheckPoint4 = std::stof(workd);
			break;
		case 21:
			playerScores3.timeCheckPoint5 = std::stof(workd);
			break;
		case 22:
			playerScores3.totalTime = std::stof(workd);
			break;
		case 23:
			playerScores3.timesDied = std::stof(workd);
			break;
		}
		counter++;
	}
	files.close();
}

double scoreBoard::getTime()
{
	std::chrono::duration<double> timePassed = (std::chrono::steady_clock::now() - startTime);
	return timePassed.count();
}

playerScore scoreBoard::getInfo(int number)
{
	if (number == 0) {
		return playerScores1;
	}
	else if (number == 1) {
		return playerScores2;
	}
	else if (number == 2) {
		return playerScores3;
	}
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
	float section5 = 0;

	switch (checkpoint) {
	case 0:
		std::chrono::duration<float> timePassed = (std::chrono::steady_clock::now() - startTime);
		tempScore.timeCheckPoint1 = timePassed.count();
		break;

	case 1:
		std::chrono::duration<float> timePassed2 = (std::chrono::steady_clock::now() - startTime);
		section = timePassed2.count() - tempScore.timeCheckPoint1;
		tempScore.timeCheckPoint2 = section;
		break;
	case 2:
		std::chrono::duration<float> timePassed3 = (std::chrono::steady_clock::now() - startTime);
		section2 = timePassed3.count() - tempScore.timeCheckPoint2;
		tempScore.timeCheckPoint3 = section2;
		break;
	case 3:
		std::chrono::duration<float> timePassed4 = (std::chrono::steady_clock::now() - startTime);
		section3 = timePassed4.count() - tempScore.timeCheckPoint3;
		tempScore.timeCheckPoint4 = section3;
		break;
	case 4:
		std::chrono::duration<float> timePassed5 = (std::chrono::steady_clock::now() - startTime);
		section4 = timePassed5.count() - tempScore.timeCheckPoint4;
		tempScore.timeCheckPoint5 = section4;
	case 5:
		std::chrono::duration<float> timePassed6 = (std::chrono::steady_clock::now() - startTime);
		section5 = timePassed6.count() - tempScore.timeCheckPoint5;
		tempScore.totalTime = tempScore.timeCheckPoint1 + tempScore.timeCheckPoint2 + tempScore.timeCheckPoint3 + tempScore.timeCheckPoint4 + tempScore.timeCheckPoint5 + section5;
		tempScore.name = "player";
		setScore(tempScore);
		break;
		
	}
}


