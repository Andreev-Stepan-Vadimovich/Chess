#pragma once
#include <SFML/Graphics.hpp>
#include "Chess.h"

class SFML_ChessRender
{
public:
	static void SFML_DrawChessboard(sf::RenderWindow& window, std::vector<std::vector<Figure>>& Field);

	static std::pair<int, int> SFML_GetStartCoordinates(int WindowHeight, int WindowWidth);

	static void SFML_DrawFigures(sf::RenderWindow& window, std::vector<std::vector<Figure>>& Field, std::pair<int, int>& StartCoordinates);
};