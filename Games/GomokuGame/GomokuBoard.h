#ifndef GOMOKUBOARD
#define GOMOKUBOARD
enum PlayerTurn {FIRST_PLAYER = 'W', SECOND_PLAYER='B' };
enum PlayerSymbol{ FIRST_PLAYER_SYMBOL = 'W', SECOND_PLAYER_SYMBOL = 'B' };
enum GameStatus{ FIRST_PLAYER_WIN, SECOND_PLAYER_WIN, DRAW, IN_PROGRESS};
#define ROWS 19
#define COLS 19
class GomokuBoard
{
	char board[ROWS][COLS];
	GameStatus gameStatus = IN_PROGRESS;
	PlayerTurn currentPlayer = FIRST_PLAYER;
	int validMovesCount = 0;
	bool isAlradyPresent(int r, int c);
public:
	GomokuBoard();
	GameStatus getGameStatus();
	int getValidMovesCount();
	void displayBoard();
	PlayerTurn getCurrentPlayer();
	void switchPlayerTurn();
	int markBoard(int r, int c);
};
#endif 
