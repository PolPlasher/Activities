#include "header.h"

// *************************
//           MAIN
// *************************

int main() {

	// GAME SETUP
	static Game game;	// Initialize a game
	srand(time(NULL));	// Set random seed

	// GAME START
	game.titleScreen();
	game.initializeBoard();
	game.printBoard();

	// GAME LOOP
	do {
		game.movePlayer(game.askInput());
		game.printBoard();

	} while (!game.gameOver());

	// GAME END
	game.printBoard();
	game.askInput();
	game.titleScreen();

	system("pause");

	return 0;
}