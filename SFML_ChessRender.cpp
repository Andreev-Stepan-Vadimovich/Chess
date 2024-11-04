#include "SFML_ChessRender.h"

std::pair<int, int> SFML_ChessRender::SFML_GetStartCoordinates(int WindowHeight, int WindowWidth)
{

	return std::pair<int, int>();
}

void SFML_ChessRender::SFML_DrawChessboard(sf::RenderWindow& window)
{
	sf::Texture BackGroundTexture;
	BackGroundTexture.loadFromFile("Photo/Chess/ChessBoardBlack.jpg");
	sf::Sprite BackGroundSprite;
	BackGroundSprite.setTexture(BackGroundTexture);

	window.clear(sf::Color::Black);
	window.draw(BackGroundSprite);
	window.display();
}