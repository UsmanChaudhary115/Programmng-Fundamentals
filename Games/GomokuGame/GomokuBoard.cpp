#include<iostream>
#include<iomanip>
#include"GomokuBoard.h"
using namespace std;
GomokuBoard::GomokuBoard()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = '.';
		}
	}
}
bool checkRows(char board[][COLS])
{
	bool status = false;
	for (int i = 0; i < ROWS && !status; i++)
	{
		int count = 0;
		char ch;
		for (int j = 0; j < COLS && !status; j++)
		{
			if (board[i][j] != '.')
			{
				ch = board[i][j];
				count++;
			}
			if (count)
			{
				bool innerLoopStatus = true;
				for (int z = 0; z < 4 && innerLoopStatus; z++)
				{
					j++;
					if (board[i][j] == ch)
					{
						count++;
					}
					else
					{
						innerLoopStatus = false;
					}
					if (count == 5)
					{
						status = true;
					}
				}
				count = 0;
				j--;
			}
		}
	}
	return status;
}
bool checkCols(char board[][COLS])
{
	bool status = false;
	for (int j = 0; j < ROWS && !status; j++)
	{
		int count = 0;
		char ch;
		for (int i = 0; i < COLS && !status; i++)
		{
			if (board[i][j] != '.')
			{
				ch = board[i][j];
				count++;
			}
			if (count)
			{
				bool innerLoopStatus = true;
				for (int z = 0; z < 4 && innerLoopStatus; z++)
				{
					i++;
					if (board[i][j] == ch)
					{
						count++;
					}
					else
					{
						innerLoopStatus = false;
					}
					if (count == 5)
					{
						status = true;
					}
				}
				count = 0;
				i--;
			}
		}
	}
	return status;
}
bool checkDiagonals(char board[][COLS])
{
	bool status = false;
	int count = 0;
	char ch;
	for (int i = 0; i < COLS && !status; i++)
	{
		if (board[i][i] != '.')
		{
			ch = board[i][i];
			count++;
		}
		if (count)
		{
			bool innerLoopStatus = true;
			for (int z = 0; z < 4 && innerLoopStatus; z++)
			{
				i++;
				if (board[i][i] == ch)
				{
					count++;
				}
				else
				{
					innerLoopStatus = false;
				}
				if (count == 5)
				{
					status = true;
				}
			}
			count = 0;
			i--;
		}
	}
	for (int i = 0, j = COLS - 1; i < ROWS && !status; i = i + 1, j = j - 1)
	{
		if (board[i][j] != '.')
		{
			ch = board[i][j];
			count++;
		}
		if (count)
		{
			bool innerLoopStatus = true;
			for (int z = 0; (z < 4) && innerLoopStatus && i < ROWS-1; z = z + 1)
			{
				i = i + 1;
				j = j - 1;
				if (board[i][j] == ch)
				{
					count++;
				}
				else
				{
					innerLoopStatus = false;
				}
				if (count == 5)
				{
					status = true;
				}

			}
			count = 0;
		}
	}
	return status;
}
bool isGameWon(char board[][COLS])
{
	bool status = false;
	if (checkCols(board) || checkRows(board) || checkDiagonals(board))
	{
		status = true;
	}
	return status;
}
GameStatus GomokuBoard::getGameStatus()
{
	return gameStatus;
}
int GomokuBoard::getValidMovesCount() 
{
	return validMovesCount;
}
void GomokuBoard::displayBoard()
{
	cout << "   ";
	for (int j = 0; j < 19; j++)
	{
		cout << setw(5) << setfill(' ') << left << (j + 1);
	}
	cout << '\n';
	for (int i = 0; i < 19; i++)
	{
		cout << setw(2) << setfill(' ') << right << (i + 1) << ' ';
		for (int j = 0; j < 19; j++)
		{
			cout << setw(5) << setfill(' ') << left << board[i][j];
		}
		cout << '\n';
	}
}
PlayerTurn GomokuBoard::getCurrentPlayer()
{
	return currentPlayer;
}
void GomokuBoard::switchPlayerTurn()
{
	currentPlayer = (currentPlayer == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;
}
bool GomokuBoard::isAlradyPresent(int r, int c)
{
	bool status = false;
	if (board[r-1][c-1] != '.')
	{
		status = true;
	}
	return status;
}
int GomokuBoard::markBoard(int r, int c)
{
	int status;
	if (r > ROWS || r < 0 || c < 0 || c > COLS)
	{
		status = 0;
	}
	else if (isAlradyPresent(r, c))
	{
		status = -1;
	}
	else
	{
		board[r-1][c-1]= (currentPlayer == FIRST_PLAYER) ? FIRST_PLAYER_SYMBOL : SECOND_PLAYER_SYMBOL;
		validMovesCount++;
		if (isGameWon(board))
		{
			gameStatus = (currentPlayer = FIRST_PLAYER) ? FIRST_PLAYER_WIN : SECOND_PLAYER_WIN;
		}
		else if (validMovesCount == 361)
		{
			gameStatus = DRAW;
		}
		else
		{
			gameStatus = IN_PROGRESS;
		}
		status = 1;
	}
	return status;
}