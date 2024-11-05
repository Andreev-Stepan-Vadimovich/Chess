#include "SFML_ChessRender.h"
#include "App.h"

std::pair<int, int> SFML_ChessRender::SFML_GetStartCoordinates(int WindowWidth, int WindowHeight)
{
	return std::pair<int, int>(WindowWidth * 0.19, WindowHeight * 0.1);
}

void SFML_ChessRender::SFML_DrawFigures(sf::RenderWindow& window, std::vector<std::vector<Figure>>& Field, std::pair<int, int>& StartCoordinates)
{
	
	std::pair<int, int> StartFigureCoordinates = StartCoordinates;
	StartFigureCoordinates.second += 10;
	sf::Texture figures;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Field[i][j] == Figure::Black_Rook) {
				figures.loadFromFile("Photo/Chess/Black_Rook.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.4, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::White_Rook) {
				figures.loadFromFile("Photo/Chess/White_Rook.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.4, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::Black_Pawn) {
				figures.loadFromFile("Photo/Chess/Black_Pawn.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.4, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::White_Pawn) {
				figures.loadFromFile("Photo/Chess/White_Pawn.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.4, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::Black_King) {
				figures.loadFromFile("Photo/Chess/Black_King.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::White_King) {
				figures.loadFromFile("Photo/Chess/White_King.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::Black_Queen) {
				figures.loadFromFile("Photo/Chess/Black_Queen.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::White_Queen) {
				figures.loadFromFile("Photo/Chess/White_Queen.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::Black_Knight) {
				figures.loadFromFile("Photo/Chess/Black_Knight.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::White_Knight) {
				figures.loadFromFile("Photo/Chess/White_Knight.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::Black_Officer) {
				figures.loadFromFile("Photo/Chess/Black_Officer.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
			else if (Field[i][j] == Figure::White_Officer) {
				figures.loadFromFile("Photo/Chess/White_Officer.png");
				sf::Sprite s;
				s.setTexture(figures);
				s.scale(0.36, 0.33);
				s.move(StartFigureCoordinates.first + 100 + 100 * j, StartFigureCoordinates.second + 100 + 100 * i);
				window.draw(s);
			}
		}
	}
}

void SFML_ChessRender::SFML_DrawChessboard(sf::RenderWindow& window, std::vector<std::vector<Figure>>& Field)
{
	sf::Texture BackGroundTexture;
	BackGroundTexture.loadFromFile("Photo/Chess/ChessBoardBlack.jpg");
	sf::Sprite BackGroundSprite;
	BackGroundSprite.setTexture(BackGroundTexture);

	std::pair<int, int> StartCoordinates = SFML_GetStartCoordinates(App::Get_WindowWidth(), App::Get_WindowHeight());
	BackGroundSprite.move(StartCoordinates.first, StartCoordinates.second);

	window.clear(sf::Color::Black);
	window.draw(BackGroundSprite);
	SFML_DrawFigures(window, Field, StartCoordinates);
	window.display();
}