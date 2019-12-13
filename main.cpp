//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      Russell Wacaster - Completed implementation.
//---------------------------------------------------

#include "tic4.h"

//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
int main()
{
	// Declare variables
	Tic4 game;
	int row, col;
	int num_players;

	// Play game
	cout << "\nWelcome to 4x4 tic-tac-toe\n";
	cout << "How many players are playing?: ";
	cin >> num_players;
	while (num_players < 1 || num_players > 2)
	{
		cout << "Enter either 1 or 2 players: ";
		cin >> num_players;
	}
	game.PrintBoard();
	while (!game.IsFull())
	{
		if (num_players == 2)
		{
			// Get X move
			cout << "Enter X move: ";
			cin >> row >> col;
			while (game.SetBoard(row, col, 'X') == false)
			{
				cout << "Enter X move: ";
				cin >> row >> col;
			}
			game.PrintBoard();

			// Check if X wins
			if (game.CheckWin('X'))
			{
				cout << "X wins!\n\n";
				return 0;
			}

			// Get O move
			cout << "Enter O move: ";
			cin >> row >> col;
			while (game.SetBoard(row, col, 'O') == false)
			{
				cout << "Enter O move: ";
				cin >> row >> col;
			}
			game.PrintBoard();

			// Check if O wins
			if (game.CheckWin('O'))
			{
				cout << "O wins!\n\n";
				return 0;
			}
		}
		else
		{
			// Get X move
			cout << "Enter X move: ";
			cin >> row >> col;
			while (game.SetBoard(row, col, 'X') == false)
			{
				cout << "Enter X move: ";
				cin >> row >> col;
			}
			game.PrintBoard();

			// Check if X wins
			if (game.CheckWin('X'))
			{
				cout << "X wins!\n\n";
				return 0;
			}
			
			game.FancyAI('O');

			game.PrintBoard();

			// Check if O wins
			if (game.CheckWin('O'))
			{
				cout << "O wins!\n\n";
				return 0;
			}
		}
	}
	cout << "Sorry, nobody wins.\n\n";
	return 0;
}
