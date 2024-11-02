#pragma once
#include <vector>
#include <string>
#include "AppStage.h"
#include <SFML/Graphics.hpp>

class App {
private:
	std::vector<std::string> Games = { "Chess" };
public:
	AppStage SelectGame();
	void StartApp();
	
};