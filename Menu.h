#pragma once
#include <iostream>
#include <vector>
#include <string>

class Menu
{
private:
	std::vector<std::string> availableGames;
public:
	Menu();
	std::vector<std::string> GetAvailableGames() { return availableGames; }
};