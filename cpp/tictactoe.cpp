//basic Tic-Tac-Toe game in c++
//ai mode coming soon!
#include <iostream>
using namespace std;

bool gameRunning;
char player1, player2;
char gameBoard[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '},
};
char currentTurn;

void initGame() {
	gameRunning = true;
	player1 = 'x';
	player2 = 'o';
	currentTurn = player1;
}
void drawBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 1 or j == 2) {
				cout << " | ";
			}
			cout << gameBoard[i][j];
		}
		cout << endl;
	}
}
int getMove() {
	int move;
	cout << currentTurn << "\'s move (1-9): ";
	cin >> move;
	if (move <= 0 or move > 9) {
		cout << "Your move must be from 1-9" << endl;
		gameRunning = false;
	}
	else {
		return move;
	}
}
bool checkWinner(char letter) {
	if (
		(gameBoard[0][0] == letter and
		 gameBoard[1][0] == letter and
		 gameBoard[2][0] == letter) or
		(gameBoard[0][1] == letter and
		 gameBoard[1][1] == letter and
		 gameBoard[2][1] == letter) or
		(gameBoard[0][2] == letter and
		 gameBoard[1][2] == letter and
		 gameBoard[2][2] == letter) or
		
		(gameBoard[0][0] == letter and
		 gameBoard[0][1] == letter and
		 gameBoard[0][2] == letter) or
		(gameBoard[1][0] == letter and
		 gameBoard[1][1] == letter and
		 gameBoard[1][2] == letter) or
		(gameBoard[2][0] == letter and
		 gameBoard[2][1] == letter and
		 gameBoard[2][2] == letter) or
		
		(gameBoard[0][0] == letter and
		 gameBoard[1][1] == letter and
		 gameBoard[2][2] == letter) or
		(gameBoard[0][2] == letter and
		 gameBoard[1][1] == letter and
		 gameBoard[2][0] == letter)
	)
		return true;
	else
		return false;
}
void updateBoard(char letter) {
	int move = getMove();
	switch (move) {
		case 1:
			if (gameBoard[0][0] == ' ') gameBoard[0][0] = letter; break;
		case 2:
			if (gameBoard[0][1] == ' ') gameBoard[0][1] = letter; break;
		case 3:
			if (gameBoard[0][2] == ' ') gameBoard[0][2] = letter; break;
		case 4:
			if (gameBoard[1][0] == ' ') gameBoard[1][0] = letter; break;
		case 5:
			if (gameBoard[1][1] == ' ') gameBoard[1][1] = letter; break;
		case 6:
			if (gameBoard[1][2] == ' ') gameBoard[1][2] = letter; break;
		case 7:
			if (gameBoard[2][0] == ' ') gameBoard[2][0] = letter; break;
		case 8:
			if (gameBoard[2][1] == ' ') gameBoard[2][1] = letter; break;
		case 9:
			if (gameBoard[2][2] == ' ') gameBoard[2][2] = letter; break;
	}
	if (checkWinner(letter)) {
		gameRunning = false;
		cout << letter << " won the game!";
	}
	else { drawBoard(); }
}
void gameLogic() {
	if (currentTurn == player1) {
		updateBoard(player1);
		currentTurn = player2;
	}
	else {
		updateBoard(player2);
		currentTurn = player1;
	}
}
int main() {
	initGame();
	while (gameRunning) {
		gameLogic();
	}
	return 0;
}
