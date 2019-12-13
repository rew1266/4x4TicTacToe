//---------------------------------------------------
// Purpose:     Header file for the Tic4 class
//
// Author:      Russell Wacaster - Completed implementation.
//---------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#ifndef TIC4
#define TIC4

// Global constants 
const int SIZE = 4;

// Class definition
class Tic4
{
public:
	// Constructor and destructor
	Tic4();
	~Tic4();

	// Public methods
	void ClearBoard();
	bool SetBoard(const int row, const int col, const char player);
	bool GetBoard(const int row, const int col, char& player);
	bool CheckWin(const char player);
	void PrintBoard();
	bool IsFull();
	bool randomAI(const char player);
	bool SimpleAI(const char player);
	bool CleverAI(const char player);
	bool FancyAI(const char player);

private:
	// Private variables
	char board[SIZE][SIZE];
	int board_count;
};

#endif
