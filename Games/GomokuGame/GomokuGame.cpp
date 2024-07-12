#include"GomokuBoard.h"
#include"GomokuGame.h"
#include<iostream>
using namespace std;
void GomokuGame::playGame()
{
	GomokuBoard GB;
	while(GB.getGameStatus() == IN_PROGRESS)
	{
		GB.displayBoard();
		int r, c;
		int inputStatus;
		do
		{
			cout << "Player " << (char)GB.getCurrentPlayer() << " Enter Position ( row column ): ";
			cin >> r >> c;
			inputStatus = GB.markBoard(r, c);
			if (inputStatus != 1)
			{
				cout << "Invalid Turn!" << '\n';
			}
		} while (inputStatus!=1);
		if (GB.getGameStatus() == DRAW)
		{
			GB.displayBoard();
			cout << "DRAW!";
		}
		else if (GB.getGameStatus() != IN_PROGRESS)
		{
			GB.displayBoard();
			cout << "Player " << (char)GB.getCurrentPlayer() << " Won!";
		}
		else
		{
			GB.switchPlayerTurn();
		}
	}
}