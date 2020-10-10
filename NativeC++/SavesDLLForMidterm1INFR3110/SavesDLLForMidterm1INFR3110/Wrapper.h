#pragma once
#ifndef  __WRAPPER__
#define __WRAPPER__

#include "PluginSettings.h"
#include "scoreBoard.h"

#ifdef __cplusplus

extern "C"
{

#endif // 
	//PLUGIN_API int GetID();
	//
	//PLUGIN_API void SetID(int id);
	//
	//PLUGIN_API Vector2D GetPosition();
	//
	//PLUGIN_API void SetPosition(float x, float y);
	
	PLUGIN_API playerScoreUnity getInfo(int number);
	PLUGIN_API void setFilePath(char* filepath);
	PLUGIN_API void setScore(playerScoreUnity info);
	PLUGIN_API void startTimer();
	PLUGIN_API void saveCheckPoint(int checkpoint);
	PLUGIN_API void writeToFile();
	PLUGIN_API void loadValues();
	PLUGIN_API double getTime();

#ifdef  __cplusplus
}

#endif //  _cplusplus


#endif // ! __WRAPPER__