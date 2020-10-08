#include "Wrapper.h"
#include "scoreBoard.h"

scoreBoard ScoreBoard;

PLUGIN_API playerScore getInfo(int number) {
	return ScoreBoard.getInfo(number);
}
PLUGIN_API void setFilePath(std::string filepath) {
	ScoreBoard.setFilePath(filepath);
}
PLUGIN_API void setScore(playerScore info) {
	ScoreBoard.setScore(info);
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




