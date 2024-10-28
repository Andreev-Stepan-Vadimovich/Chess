#pragma once
#include <vector>
#include <map>
#include <set>

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
	//The chessboard
	std::vector<std::vector<Figure>> Field;
	std::set<Figure> White_figures;
public:
	//Constructors and distructors
	Chess();
	~Chess();

	//A function for starting and controlling the game
	void StartChess();

	//A function for displaying a chessboard in the console
	void PrintField();
private:
	//A function for initialization of a chessboard
	void CreateField();

	//A variable for determining who is walking
	int Motion = 1; //1 - white, 2 - black

	//A function for getting color of figure
	int DefineColor(Figure figure);

	//A flag for finishing of game
	bool inPlay = false;

	//A function for getting possible moves for any figure
	std::set<std::pair<int, int>> GetPossibleMoves(int x, int y);

	//A function for determining of Check
	bool CheckForCheck(std::vector<std::vector<Figure>> field);

	//A function for determining of Checkmate

	//Functions for checking the possibility of a move 
	bool CheckSelectField(int s1, int s2, int e1, int e2);
	bool CheckSelectFigure(int s1, int s2, int color);

	//A function for update the chessboard after motion
	void UpdateField(int s1, int s2, int e1, int e2);

	//Functions for making a move
	void WhiteMotion();
	void BlackMotion();
};