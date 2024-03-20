#pragma once

#include <iostream>

#define NUM_ROWS 7
#define NUM_COLUMNS 7
const int MAX_COINS = (int)(NUM_ROWS * NUM_COLUMNS) * 0.2; // The maximum amount of coins is the 20% of the total number of cells
const int MAX_STONES = (int)(NUM_ROWS * NUM_COLUMNS) * 0.3; // The maximum amount of rocks is the 30% of the total number of cells

// Types of movement that the player can do
enum class Movement { INVALID, UP, DOWN, LEFT, RIGHT };

// Types of elements that can be in the board
enum class Element { EMPTY, PLAYER, COIN, STONE };

struct Game;

struct Player {

	Game* game_ptr; // Pointer to Game for accessing the parent

	std::pair<int, int>
		position; // Position of the player <row, col> in the board matrix

	int score; // Score of the player

	Player(Game* game) {
		game_ptr = game;
		score = 0;
	}

	// Returns true if the given movement is legal in relation to the player
	bool checkMovement(Movement mov);

	// Adds one to the player's score
	void addScore();

	// Sets the player's position to the given row and column
	void setPos(int row, int col);

	// Returns true if the given movements leads the player to a coin
	bool existsCoin(Movement mov);
};

struct Game {

	Player player = Player(this); // The player initialized with a pointer to this Game

	int num_coins;  // Number of coins in the board
	int num_stones; // Number of stones in the board

	Element board[NUM_ROWS][NUM_COLUMNS]; // The board of the game

	// Initializes the board with the player, coins and stones
	void initializeBoard();

	// Moves the player with the mov direction
	void movePlayer(Movement mov);

	// Returns true if the game is over
	bool gameOver();

	// Prints the board
	void printBoard();

	// Asks the input to the player
	Movement askInput();

	void titleScreen();
};