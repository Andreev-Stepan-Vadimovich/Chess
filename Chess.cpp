#include <iostream>
#include "Chess.h"
#include <set>
#include "App.h"
#include "SFML_ChessRender.h"

Chess::Chess()
{
	White_figures.insert(Figure::White_King);
	White_figures.insert(Figure::White_Knight);
	White_figures.insert(Figure::White_Officer);
	White_figures.insert(Figure::White_Pawn);
	White_figures.insert(Figure::White_Queen);
	White_figures.insert(Figure::White_Rook);

	Black_figures.insert(Figure::Black_King);
	Black_figures.insert(Figure::Black_Knight);
	Black_figures.insert(Figure::Black_Officer);
	Black_figures.insert(Figure::Black_Pawn);
	Black_figures.insert(Figure::Black_Queen);
	Black_figures.insert(Figure::Black_Rook);
}

Chess::~Chess()
{
}

void Chess::StartChess(sf::RenderWindow& window)
{
	this->CreateField();
	SFML_ChessRender::SFML_DrawChessboard(window, Field);
	this->PrintField();
	inPlay = true;
	while (inPlay) 
	{
		switch (Motion)
		{
		case 1:
		{
			//Close controller - bad realization
			/*sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}*/

			WhiteMotion(window);
			PrintField();
			SFML_ChessRender::SFML_DrawChessboard(window, Field);
			Motion = 2;
			continue;
		}
		case 2:
		{
			//Close controller - bad realization
			/*sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}*/
			BlackMotion(window);
			PrintField();
			SFML_ChessRender::SFML_DrawChessboard(window, Field);
			Motion = 1;
			continue;
		}
		default:
			return;
		}
	}
}

void Chess::PrintField()
{
	for (int i = 0; i < 8; ++i) {
		std::cout << 8-i << "\t";
		for (int j = 0; j < 8; ++j) {
			if (Field[i][j] == Figure::Empty)
			{
				std::cout << 0 << '\t';
				continue;
			}
			if (Field[i][j] == Figure::Black_Rook)
			{
				std::cout << "BR" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::White_Rook) 
			{
				std::cout << "WR" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::Black_Knight)
			{
				std::cout << "BKn" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::White_Knight)
			{
				std::cout << "WKn" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::Black_Officer)
			{
				std::cout << "BO" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::White_Officer)
			{
				std::cout << "WO" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::Black_Queen)
			{
				std::cout << "BQ" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::White_Queen)
			{
				std::cout << "WQ" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::Black_King)
			{
				std::cout << "BKg" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::White_King)
			{
				std::cout << "WKg" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::Black_Pawn)
			{
				std::cout << "BP" << '\t';
				continue;
			}
			if (Field[i][j] == Figure::White_Pawn)
			{
				std::cout << "WP" << '\t';
				continue;
			}
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\ta\tb\tc\td\te\tf\tg\th\t\n\n";
}

void Chess::CreateField()
{
	Field.resize(8);
	for (int i = 0; i < 8; ++i) Field[i].resize(16);
	Field[0][0] = Figure::Black_Rook;
	Field[0][7] = Figure::Black_Rook;
	Field[0][1] = Figure::Black_Knight;
	Field[0][6] = Figure::Black_Knight;
	Field[0][2] = Figure::Black_Officer;
	Field[0][5] = Figure::Black_Officer;
	Field[0][3] = Figure::Black_Queen;
	Field[0][4] = Figure::Black_King;
	for (int i = 0; i < 8; ++i) Field[1][i] = Figure::Black_Pawn;
	for (int i = 2; i < 6; ++i) {
		for (int j = 0; j < 16; ++j) {
			Field[i][j] = Figure::Empty;
		}
	}
	for (int i = 0; i < 8; ++i) Field[6][i] = Figure::White_Pawn;
	Field[7][0] = Figure::White_Rook;
	Field[7][7] = Figure::White_Rook;
	Field[7][1] = Figure::White_Knight;
	Field[7][6] = Figure::White_Knight;
	Field[7][2] = Figure::White_Officer;
	Field[7][5] = Figure::White_Officer;
	Field[7][3] = Figure::White_Queen;
	Field[7][4] = Figure::White_King;
}

int Chess::DefineColor(Figure figure)
{
	//0 == Empty, 1 == White, 2 == Black
	int color = 0;
	for (auto x : White_figures) if (x == figure) color = 1;
	for (auto x : Black_figures) if (x == figure) color = 2;
	return color;
}

std::pair<std::set<std::pair<int, int>>, std::set<std::pair<int, int>>> Chess::GetPossibleMoves(int x, int y)
{
	std::set<std::pair<int, int>> moves, pawn_transform;
	Figure figure = Field[y][x];
	
	int color = DefineColor(figure);

	if (figure == Figure::White_Officer || figure == Figure::Black_Officer) {
		for (int i = x, j = y; i < 8 && j < 8; ++i, ++j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x, j = y; i < 8 && j >= 0; ++i, --j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x, j = y; i >= 0 && j < 8; --i, ++j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
	}
	else if (figure == Figure::White_Rook || figure == Figure::Black_Rook) {
		for (int i = x; i < 8; ++i) {
			if (i == x) continue;
			if (color == DefineColor(Field[y][i])) continue;
			moves.insert(std::make_pair(i, y));
			if (Field[y][i] != Figure::Empty && i != x) break;
		}
		for (int i = x; i >= 0; --i) {
			if (i == x) continue;
			if (color == DefineColor(Field[y][i])) continue;
			moves.insert(std::make_pair(i, y));
			if (Field[y][i] != Figure::Empty && i != x) break;
		}
		for (int i = y; i < 8; ++i) {
			if (i == y) continue;
			if (color == DefineColor(Field[i][x])) continue;
			moves.insert(std::make_pair(x, i));
			if (Field[i][x] != Figure::Empty && i != y) break;
		}
		for (int i = y; i >= 0; --i) {
			if (i == y) continue;
			if (color == DefineColor(Field[i][x])) continue;
			moves.insert(std::make_pair(x, i));
			if (Field[i][x] != Figure::Empty && i != y) break;
		}
	}
	else if (figure == Figure::White_Queen || figure == Figure::Black_Queen) {
		for (int i = x, j = y; i < 8 && j < 8; ++i, ++j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x, j = y; i < 8 && j >= 0; ++i, --j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x, j = y; i >= 0 && j < 8; --i, ++j) {
			if (i == x && j == y) continue;
			if (color == DefineColor(Field[j][i])) break;
			moves.insert(std::make_pair(i, j));
			if (Field[j][i] != Figure::Empty) break;
		}
		for (int i = x; i < 8; ++i) {
			if (i == x) continue;
			if (color == DefineColor(Field[y][i])) continue;
			moves.insert(std::make_pair(i, y));
			if (Field[y][i] != Figure::Empty && i != x) break;
		}
		for (int i = x; i >= 0; --i) {
			if (i == x) continue;
			if (color == DefineColor(Field[y][i])) continue;
			moves.insert(std::make_pair(i, y));
			if (Field[y][i] != Figure::Empty && i != x) break;
		}
		for (int i = y; i < 8; ++i) {
			if (i == y) continue;
			if (color == DefineColor(Field[i][x])) continue;
			moves.insert(std::make_pair(x, i));
			if (Field[i][x] != Figure::Empty && i != y) break;
		}
		for (int i = y; i >= 0; --i) {
			if (i == y) continue;
			if (color == DefineColor(Field[i][x])) continue;
			moves.insert(std::make_pair(x, i));
			if (Field[i][x] != Figure::Empty && i != y) break;
		}
	}
	else if (figure == Figure::White_King || figure == Figure::Black_King) {
		if ((x + 1 <= 7) && (color != DefineColor(Field[y][x + 1]))) {
			moves.insert(std::make_pair(x + 1, y));
		}
		if ((x - 1 >= 0) && (color != DefineColor(Field[y][x - 1]))) {
			moves.insert(std::make_pair(x - 1, y));
		}
		if ((y + 1 <= 7) && (color != DefineColor(Field[y + 1][x]))) {
			moves.insert(std::make_pair(x, y + 1));
		}
		if ((y - 1 >= 0) && (color != DefineColor(Field[y - 1][x]))) {
			moves.insert(std::make_pair(x, y - 1));
		}

		if ((x + 1 <= 7) && (y + 1 <= 7) && (color != DefineColor(Field[y + 1][x + 1]))) {
			moves.insert(std::make_pair(x + 1, y + 1));
		}
		if ((x - 1 >= 0) && (y - 1 >= 0) && (color != DefineColor(Field[y - 1][x - 1]))) {
			moves.insert(std::make_pair(x - 1, y - 1));
		}
		if ((y + 1 <= 7) && (x - 1 >= 0) && (color != DefineColor(Field[y + 1][x - 1]))) {
			moves.insert(std::make_pair(x - 1, y + 1));
		}
		if ((y - 1 >= 0) && (x + 1 <= 7) && (color != DefineColor(Field[y - 1][x + 1]))) {
			moves.insert(std::make_pair(x + 1, y - 1));
		}
	}
	else if (figure == Figure::White_Knight || figure == Figure::Black_Knight) {
		if ((x + 1 <= 7) && (y + 2 <= 7) && (color != DefineColor(Field[y + 2][x + 1]))) {
			moves.insert(std::make_pair(x + 1, y + 2));
		}
		if ((x + 1 <= 7) && (y - 2 >= 0) && (color != DefineColor(Field[y - 2][x + 1]))) {
			moves.insert(std::make_pair(x + 1, y - 2));
		}
		if ((x - 1 >= 0) && (y + 2 <= 7) && (color != DefineColor(Field[y + 2][x - 1]))) {
			moves.insert(std::make_pair(x - 1, y + 2));
		}
		if ((x - 1 >= 0) && (y - 2 >= 0) && (color != DefineColor(Field[y - 2][x - 1]))) {
			moves.insert(std::make_pair(x - 1, y - 2));
		}

		if ((x + 2 <= 7) && (y + 1 <= 7) && (color != DefineColor(Field[y + 1][x + 2]))) {
			moves.insert(std::make_pair(x + 2, y + 1));
		}
		if ((x + 2 <= 7) && (y - 1 >= 0) && (color != DefineColor(Field[y - 1][x + 2]))) {
			moves.insert(std::make_pair(x + 2, y - 1));
		}
		if ((x - 2 >= 0) && (y + 1 <= 7) && (color != DefineColor(Field[y + 1][x - 2]))) {
			moves.insert(std::make_pair(x - 2, y + 1));
		}
		if ((x - 2 >= 0) && (y - 1 >= 0) && (color != DefineColor(Field[y - 1][x - 2]))) {
			moves.insert(std::make_pair(x - 2, y - 1));
		}
	}
	else if (figure == Figure::White_Pawn) {
		if ((y - 1 > 0) && Field[y - 1][x] == Figure::Empty) moves.insert(std::make_pair(x, y - 1));
		if ((y - 1 > 0) && (x + 1 <= 7) && (color != DefineColor(Field[y - 1][x + 1]))) moves.insert(std::make_pair(x + 1, y - 1));
		if ((y - 1 > 0) && (x - 1 >= 0) && (color != DefineColor(Field[y - 1][x - 1]))) moves.insert(std::make_pair(x - 1, y - 1));
	}
	else if (figure == Figure::Black_Pawn) {
		if ((y + 1 < 7) && Field[y + 1][x] == Figure::Empty) moves.insert(std::make_pair(x, y + 1));
		if ((y + 1 < 7) && (x + 1 <= 7) && (color != DefineColor(Field[y + 1][x + 1]))) moves.insert(std::make_pair(x + 1, y + 1));
		if ((y + 1 < 7) && (x - 1 >= 0) && (color != DefineColor(Field[y + 1][x - 1]))) moves.insert(std::make_pair(x - 1, y + 1));
		if (y + 1 == 7)
		{
			if (Field[y + 1][x] == Figure::Empty) pawn_transform.insert(std::make_pair(x, y + 1));
			if ((x + 1 <= 7) && (color != DefineColor(Field[y + 1][x + 1]))) pawn_transform.insert(std::make_pair(x + 1, y + 1));
			if ((x - 1 >= 0) && (color != DefineColor(Field[y + 1][x - 1]))) pawn_transform.insert(std::make_pair(x - 1, y + 1));
		}
	}
	
	return std::pair<std::set<std::pair<int, int>>, std::set<std::pair<int, int>>>(moves, pawn_transform);
}

bool Chess::CheckForCheck(std::vector<std::vector<Figure>> field)
{

	return false;
}

bool Chess::CheckSelectField(int s1, int s2, int e1, int e2)
{
	//Movies.first - movies for all figures, Movies.second - transform for pawns
	std::pair<std::set<std::pair<int, int>>, std::set<std::pair<int, int>>> movies = GetPossibleMoves(s1, s2);
	for (auto x : movies.first)
	{
		std::cout << x.first << ' ' << x.second << '\n';
		if (x.first == e1 && x.second == e2) return true;
	}
	if (Field[s2][s1] == Figure::White_Pawn || Field[s2][s1] == Figure::Black_Pawn)
	{
		for (auto x : movies.second)
		{
			std::cout << x.first << ' ' << x.second << '\n';
			if (x.first == e1 && x.second == e2) return true;
		}
	}
	return false;
}

bool Chess::CheckSelectFigure(int s1, int s2, int color)
{
	if (Field[s2][s1] == Figure::Empty) return false;
	if (color == 1)
	{
		if (Field[s2][s1] == Figure::Black_King || Field[s2][s1] == Figure::Black_Knight ||
			Field[s2][s1] == Figure::Black_Officer || Field[s2][s1] == Figure::Black_Pawn ||
			Field[s2][s1] == Figure::Black_Queen || Field[s2][s1] == Figure::Black_Rook)
			return false;
	}
	else if (color == 2)
	{
		if (Field[s2][s1] == Figure::White_King || Field[s2][s1] == Figure::White_Knight ||
			Field[s2][s1] == Figure::White_Officer || Field[s2][s1] == Figure::White_Pawn ||
			Field[s2][s1] == Figure::White_Queen || Field[s2][s1] == Figure::White_Rook)
			return false;
	}

	return true;
}

void Chess::UpdateField(int s1, int s2, int e1, int e2)
{
	Field[e2][e1] = Field[s2][s1];
	Field[s2][s1] = Figure::Empty;
}

std::pair<int, int> Chess::SelectFigureByMouse(sf::RenderWindow& window)
{
	std::pair<int, int> StartCoordinates = SFML_ChessRender::SFML_GetStartCoordinates(App::Get_WindowHeight(), App::Get_WindowWidth());
	StartCoordinates = { 400, 215 };
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				if (event.mouseButton.button == sf::Mouse::Left) {
					mousePos.x -= StartCoordinates.first;
					mousePos.y -= StartCoordinates.second;
					mousePos.x /= 100;
					mousePos.y /= 100;
					std::cout << mousePos.x << "   " << mousePos.y << '\n';
					std::pair<int, int> ans = { mousePos.x, mousePos.y };
					return ans;
				}
				/*else if (event.mouseButton.button == sf::Mouse::Right) {
					std::cout << "Right mouse button pressed at ("
						<< mousePos.x << ", "
						<< mousePos.y << ")" << std::endl;
				}*/
			}
		}
	}
}

void Chess::WhiteMotion(sf::RenderWindow& window)
{
	std::pair<int, int> coordinatesStart, coordinatesEnd;
	while (true) {
		std::cout << "<-- White motion -->\n";
		while (true)
		{
			std::cout << "Select figure: ";
			coordinatesStart = SelectFigureByMouse(window);
			if (CheckSelectFigure(coordinatesStart.first, coordinatesStart.second, 1)) break;
			else
			{
				std::cout << "Uncorrect chose! Try again!\n";
				continue;
			}
		}
		while (true)
		{
			std::cout << "Select field: ";
			coordinatesEnd = SelectFigureByMouse(window);
			if (CheckSelectField(coordinatesStart.first, coordinatesStart.second, coordinatesEnd.first, coordinatesEnd.second)) break;
			else
			{
				std::cout << "Uncorrect field! Try again!\n";
				continue;
			}
		}
		UpdateField(coordinatesStart.first, coordinatesStart.second, coordinatesEnd.first, coordinatesEnd.second);
		return;
	}
}

void Chess::BlackMotion(sf::RenderWindow& window)
{
	std::pair<int, int> coordinatesStart, coordinatesEnd;
	while (true) {
		std::cout << "<-- Black motion -->\n";
		while (true)
		{
			std::cout << "Select figure: ";
			coordinatesStart = SelectFigureByMouse(window);
			if (CheckSelectFigure(coordinatesStart.first, coordinatesStart.second, 2)) break;
			else
			{
				std::cout << "Uncorrect chose! Try again!\n";
				continue;
			}
		}
		int e1, e2;
		while (true)
		{
			std::cout << "Select field: ";
			coordinatesEnd = SelectFigureByMouse(window);
			if (CheckSelectField(coordinatesStart.first, coordinatesStart.second, coordinatesEnd.first, coordinatesEnd.second)) break;
			else
			{
				std::cout << "Uncorrect field! Try again!\n";
				continue;
			}
		}
		UpdateField(coordinatesStart.first, coordinatesStart.second, coordinatesEnd.first, coordinatesEnd.second);
		return;
	}
}
