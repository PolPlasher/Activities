#include "header.h"

// **********************************
//           GAME FUNCTIONS
// **********************************

// Initializes the board with the player, coins and stones
void Game::initializeBoard() {

	// Initialize all the positions to empty
	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLUMNS; j++)
			board[i][j] = Element::EMPTY;

	num_stones = rand() % MAX_STONES + 1; // Generate a random number of stones
	// Place the stones randomly on the board
	for (int i = 0; i < num_stones; i++) {

		int random_row, random_col;
		bool empty; // If the random position is empty
		do {
			// Generate a random position for each coin
			random_row = rand() % NUM_ROWS;
			random_col = rand() % NUM_COLUMNS;

			if (board[random_row][random_col] == Element::EMPTY)
				empty = true;
			else
				empty = false;
		} while (!empty); // Loop until an empty position is found

		board[random_row][random_col] =
			Element::STONE; // Assign the coin to the random position
	}

	num_coins = rand() % MAX_COINS + 1; // Generate a random number of coins
	// Place the coins randomly on the board
	for (int i = 0; i < num_coins; i++) {

		int random_row, random_col;
		bool empty; // If the random position is empty
		do {
			// Generate a random position for each coin
			random_row = rand() % NUM_ROWS;
			random_col = rand() % NUM_COLUMNS;

			if (board[random_row][random_col] == Element::EMPTY)
				empty = true;
			else
				empty = false;
		} while (!empty); // Loop until an empty position is found

		board[random_row][random_col] =
			Element::COIN; // Assign the coin to the random position
	}

	// Initialize the player in a random position
	int player_row, player_col;

	srand(time(NULL));

	player_row = rand() % NUM_ROWS;    // Random row within NUM_COLS
	player_col = rand() % NUM_COLUMNS; // Random column within NUM_COLUMNS
	player.score = 0;                  // Set the player's score to 0
	player.game_ptr = this;            // Set the game pointer to this object

	player.setPos(player_row, player_col); // Apply the player's position
}

// Moves the player with the mov direction
void Game::movePlayer(Movement mov) {

	// Check if the movement is legal
	if (!player.checkMovement(mov)) {
		std::cout << "Illegal movement!" << std::endl;
		return;
	}

	// Adds score if a coin is in the final position
	if (player.existsCoin(mov)) {
		player.addScore();
	}

	switch (mov) {
	case Movement::UP:
		player.setPos(player.position.first - 1, player.position.second);
		break;
	case Movement::DOWN:
		player.setPos(player.position.first + 1, player.position.second);
		break;
	case Movement::LEFT:
		player.setPos(player.position.first, player.position.second - 1);
		break;
	case Movement::RIGHT:
		player.setPos(player.position.first, player.position.second + 1);
		break;
	case Movement::INVALID:
		break;
	}
}

// Returns true if the game is over
bool Game::gameOver() {
	if (player.score >= num_coins)
		return true;
	else
		return false;
}

// Prints the board
void Game::printBoard() {

	// Clear the screen
	std::cout << "\033[H" << "\033[J";

	// Print the score
	std::cout << "        [SCORE: " << player.score << "]" << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			std::cout << "[";

			switch (board[i][j]) {
			case Element::EMPTY:
				std::cout << "\033[48;5;0m" << " ";
				break;
			case Element::PLAYER:
				std::cout << "\033[48;5;1m" << "P";
				break;
			case Element::COIN:
				std::cout << "\033[48;5;94m" << "C";
				break;
			case Element::STONE:
				std::cout << "\033[48;5;235m" << "S";
			}
			std::cout << "\033[48;5;0m"; // Restart the background print color
			std::cout << "] ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

// Asks the input to the player
Movement Game::askInput() {

	char input;
	std::cout << std::endl
		<< "             [W]" << std::endl
		<< "          [A][S][D]   " << std::endl;
	std::cin >> input;

	switch (input) {
	case 'w':
	case 'W':
		return Movement::UP;
		break;
	case 'a':
	case 'A':
		return Movement::LEFT;
		break;
	case 's':
	case 'S':
		return Movement::DOWN;
		break;
	case 'd':
	case 'D':
		return Movement::RIGHT;
		break;
	default:
		std::cout << "Invalid input!" << std::endl;
		return Movement::INVALID;
	}
}

void Game::titleScreen() {

	std::cout << std::endl
		<< "***************************************************"
		<< std::endl
		<< std::endl
		<< "                  AA1_03_AGameBoard" << std::endl
		<< std::endl
		<< "     By Pol Lleida & Pol Blesa | For Manish <3" << std::endl
		<< std::endl
		<< "***************************************************"
		<< std::endl
		<< std::endl
		<< "Enter any character for starting the game: ";

	char input;
	std::cin >> input;
}