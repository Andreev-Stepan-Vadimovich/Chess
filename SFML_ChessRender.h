#pragma once
#include <SFML/Graphics.hpp>


class SFML_ChessRender
{
public:
	static void SFML_DrawChessboard(sf::RenderWindow& window);

	std::pair<int, int> SFML_GetStartCoordinates(int WindowHeight, int WindowWidth);

	void SFML_DrawFigures(sf::RenderWindow& window);

};