#include <iostream>
#include "Chess.h"

Chess::Chess()
{
}

Chess::~Chess()
{
}

void Chess::StartChess()
{
	this->CreateField();
	this->PrintField();
	inPlay = true;
	while (inPlay) 
	{
		switch (Motion)
		{
		case 1:
		{
			WhiteMotion();
			PrintField();
			continue;
		}
		case 2:
		{
			BlackMotion();
			PrintField();
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

void Chess::UpdateField(int s1, int s2, int e1, int e2)
{
	Field[e1][e2] = Field[s1][s2];
	Field[s1][s2] = Figure::Empty;
}

void Chess::WhiteMotion()
{
	std::string start, end;
	std::cin >> start >> end;
	int s1 = start[0] - 97, s2 = start[1] - 49;
	int e1 = end[0] - 97, e2 = end[1] - 49;
	s1 = abs(s1 - 7); s2 = abs(s2 - 7);
	e1 = abs(e1 - 7); e2 = abs(e2 - 7);
	std::cout << s1 << ' ' << s2 << '\n';
	std::cout << e1 << ' ' << e2 << '\n' << '\n';
	UpdateField(s1, s2, e1, e2);
}

void Chess::BlackMotion()
{
	std::string start, end;
	std::cin >> start >> end;
	int s1 = start[0] - 97, s2 = start[1] - 49;
	int e1 = end[0] - 97, e2 = end[1] - 49;
	std::cout << s1 << ' ' << s2 << '\n';
	std::cout << e1 << ' ' << e2 << '\n' << '\n';
	UpdateField(s1, s2, e1, e2);
}
