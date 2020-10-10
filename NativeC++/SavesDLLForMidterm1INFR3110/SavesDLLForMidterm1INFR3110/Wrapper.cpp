#include "Wrapper.h"
#include "scoreBoard.h"

scoreBoard ScoreBoard;

PLUGIN_API playerScoreUnity getInfo(int number) {
	playerScoreUnity temp = { ScoreBoard.getInfo(number).timeCheckPoint1, ScoreBoard.getInfo(number).timeCheckPoint2, ScoreBoard.getInfo(number).timeCheckPoint3, ScoreBoard.getInfo(number).timeCheckPoint4, ScoreBoard.getInfo(number).timeCheckPoint5,
	ScoreBoard.getInfo(number).timesDied, ScoreBoard.getInfo(number).totalTime};
	return temp;
}
PLUGIN_API void setFilePath(char* filepath) {
	ScoreBoard.setFilePath(filepath);
}
PLUGIN_API void setScore(playerScoreUnity info) {
	playerScore temp = {"player", info.timeCheckPoint1, info.timeCheckPoint2, info.timeCheckPoint3, info.timeCheckPoint4, info.timeCheckPoint5, info.totalTime, info.timesDied };
	ScoreBoard.setScore(temp);
}
PLUGIN_API void startTimer() {
	ScoreBoard.startTimer();
}
PLUGIN_API void saveCheckPoint(int checkpoint) {
	ScoreBoard.saveCheckPoint(checkpoint);
}
PLUGIN_API void writeToFile() {
	ScoreBoard.writeToFile();
}
PLUGIN_API void loadValues() {
	ScoreBoard.loadValues();
}
PLUGIN_API double getTime() {
	return ScoreBoard.getTime();
}



