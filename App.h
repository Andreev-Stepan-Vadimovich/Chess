#pragma once
#include <vector>
#include <string>
#include "AppStage.h"
#include <SFML/Graphics.hpp>

class App {
private:
	//Size of window
	static const int WindowHeight = 1200;
	static const int WindowWidth = 1600;

	//List of games
	std::vector<std::string> Games = { "Chess" };
public:
	AppStage SelectGame();
	void StartApp();

	static int Get_WindowHeight();
	static int Get_WindowWidth();
	
	void SFML_DrawMenu(sf::RenderWindow& window);
};