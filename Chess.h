#pragma once
#include <vector>

enum class Figure
{
	White_Pawn,
	White_Queen,
	White_King, 
	White_Officer,
	White_Knight,
	White_Rook,
	Black_Pawn,
	Black_Queen,
	Black_King,
	Black_Officer,
	Black_Knight,
	Black_Rook,
	Empty
};

class Chess
{
private:
	std::vector<std::vector<Figure>> Field;
public:
	Chess();
	~Chess();
	void StartChess();
	void PrintField();
private:
	void CreateField();
	int Motion = 1; //1 - white, 2 - black
	bool inPlay = false;

	void UpdateField(int s1, int s2, int e1, int e2);
	void WhiteMotion();
	void BlackMotion();
};