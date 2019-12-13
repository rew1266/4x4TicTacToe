//---------------------------------------------------
// Purpose:     Implementation of the Tic4 class
//
// Author:      Russell Wacaster - Completed implementation.
//---------------------------------------------------

#include "tic4.h"

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Tic4::Tic4()
{
	ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Tic4::~Tic4()
{
	// Intentionally empty
}

//---------------------------------------------------
// Clear the Tic4 board
//---------------------------------------------------
void Tic4::ClearBoard()
{
	// Initialize Tic4 board
	for (int c = 0; c < SIZE; c++)
		for (int r = 0; r < SIZE; r++)
			board[r][c] = ' ';
	board_count = 0;
}

//---------------------------------------------------
// Set value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::SetBoard(const int row, const int col, const char player)
{
	// Error checking
	if ((row < 0) || (row >= SIZE) ||
		(col < 0) || (col >= SIZE) ||
		(board[row][col] != ' '))
		return false;

	// Set value of board
	board[row][col] = player;
	board_count++;
	return true;
}

//---------------------------------------------------
// Get value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::GetBoard(const int row, const int col, char& player)
{
	// Error checking
	if ((row < 0) || (row >= SIZE) ||
		(col < 0) || (col >= SIZE))
		return false;

	// Get value of board
	player = board[row][col];
	return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Tic4::CheckWin(const char player)
{
	// Check all the rows
	for (int r = 0; r < SIZE; r++)
	{
		// Count player pieces
		int count = 0;
		for (int c = 0; c < SIZE; c++)
			if (board[r][c] == player)
				count++;
		if (count == SIZE)
			return true;
	}

	// Check all the cols
	for (int c = 0; c < SIZE; c++)
	{
		// Count player pieces
		int count = 0;
		for (int r = 0; r < SIZE; r++)
			if (board[r][c] == player)
				count++;
		if (count == SIZE)
			return true;
	}

	// Check first diagonal
	int count = 0;
	for (int r = 0; r < SIZE; r++)
	{
		int c = r;
		if (board[r][c] == player)
			count++;
	}
	if (count == SIZE)
		return true;

	// Check second diagonal
	count = 0;
	for (int r = 0; r < SIZE; r++)
	{
		int c = SIZE - 1 - r;
		if (board[r][c] == player)
			count++;
	}
	if (count == SIZE)
		return true;

	// The player did not win
	return false;
}

//---------------------------------------------------
// Print the Tic4 board
//---------------------------------------------------
void Tic4::PrintBoard()
{
	// Draw column numbers
	cout << "\n     ";
	for (int c = 0; c < SIZE; c++)
		cout << c << "   ";
	cout << "\n";

	// Print the Tic4 board
	for (int r = 0; r < SIZE; r++)
	{
		// Draw dashed line
		cout << "   +";
		for (int c = 0; c < SIZE; c++)
			cout << "---+";
		cout << "\n";

		// Draw board contents
		cout << " " << r << " | ";
		for (int c = 0; c < SIZE; c++)
			cout << board[r][c] << " | ";
		cout << "\n";
	}

	// Draw dashed line
	cout << "   +";
	for (int c = 0; c < SIZE; c++)
		cout << "---+";
	cout << "\n\n";
}

//---------------------------------------------------
// Check if board is full
//---------------------------------------------------
bool Tic4::IsFull()
{
	return (board_count == SIZE * SIZE);
}

//---------------------------------------------------
// Random AI
//---------------------------------------------------
bool Tic4::randomAI(const char player)
{
	int row = -1;
	int col = -1;
	srand(time(0));
	if (!IsFull())
	{
		while (SetBoard(row, col, player) == false)
		{
			row = rand() % 17;
			col = rand() % 17;
		}
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------
// Simple AI
//---------------------------------------------------
bool Tic4::SimpleAI(const char player)
{
	int col = 0;
	int row = 0;
	
	if (!IsFull())
	{
		while (SetBoard(row, col, player) == false)
		{
			if (row < SIZE)
			{
				row;
				col++;
			}
			if (col == SIZE)
			{
				col = 0;
				row++;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------
// Clever AI
//---------------------------------------------------
bool Tic4::CleverAI(const char player)
{
	srand(time(0));
	int row = 0;
	int col = 0;
	bool leftDiagonal = false;
	bool rightDiagonal = false;

	if (!IsFull())
	{
		while (leftDiagonal == false)
		{
			if (row == 4 && col == 4)
			{
				leftDiagonal = true;
			}
			else if (SetBoard(row, col, ' ') == false)
			{
				row++;
				col++;
			}
			else
			{
				SetBoard(row, col, player);
				break;
			}
		}

		row = 0;
		col = 3;
		while (rightDiagonal == false && leftDiagonal == true)
		{
			if (row == 4 && col == -1)
			{
				rightDiagonal = true;
			}
			else if (SetBoard(row, col, ' ') == false)
			{
				row++;
				col--;
			}
			else
			{
				SetBoard(row, col, 'O');
				break;
			}
		}
		if (leftDiagonal == true && rightDiagonal == true)
		{
			while (SetBoard(row, col, 'O') == false)
			{
				row = rand() % 17;
				col = rand() % 17;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------
// Fancy AI
//---------------------------------------------------
bool Tic4::FancyAI(const char player)
{
	srand(time(0));
	int random = rand() % 3;

	if (!IsFull())
	{
		if (random == 0)
		{
			randomAI(player);
		}
		else if (random == 1)
		{
			SimpleAI(player);
		}
		else
		{
			CleverAI(player);
		}
		return true;
	}
	else
	{
		return false;
	}
}
