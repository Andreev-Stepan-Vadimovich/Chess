#pragma once
#include <vector>
#include <string>
#include "AppStage.h"

class App {
private:
	std::vector<std::string> Games = { "Chess" };
public:
	AppStage SelectGame();
	void StartApp();
	
};