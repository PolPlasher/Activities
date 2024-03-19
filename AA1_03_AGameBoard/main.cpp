#include "header.h"
#include <iostream>

// **********************************
//           GAME FUNCTIONS
// **********************************

// Initializes the board with the player, coins and stones
void Game::initializeBoard() {

    // Initialize all the positions to empty
    for (int i = 0; i < NUM_ROWS; i++)
        for (int j = 0; j < NUM_COLUMNS; j++)
            board[i][j] = Element::EMPTY;

    num_coins = rand() % MAX_COINS + 1; // Generate a random number of coins
    // Place the coins randomly on the board
    for (int i = 0; i < num_coins; i++) {

        // Generate a random position for each coin
        int random_row = rand() % NUM_ROWS;
        int random_col = rand() % NUM_COLUMNS;

        bool empty; // If the random position is empty
        do {
            if (board[random_row][random_col] == Element::EMPTY)
                empty = true;
            else
                empty = false;
        } while (!empty); // Loop until an empty position is found

        board[random_row][random_col] =
            Element::COIN; // Assign the coin to the random position
    }

    num_stones = rand() % MAX_STONES + 1; // Generate a random number of stones
    // Place the stones randomly on the board
    for (int i = 0; i < num_stones; i++) {
        // Generate a random position for each stone
        int random_row = rand() % NUM_ROWS;
        int random_col = rand() % NUM_COLUMNS;

        bool empty; // If the random position is empty
        do {
            if (board[random_row][random_col] == Element::EMPTY)
                empty = true;
            else
                empty = false;
        } while (!empty); // Loop until an empty position is found

        board[random_row][random_col] =
            Element::STONE; // Assign the coin to the random position
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
        num_coins--;
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
    if (num_coins <= 0)
        return true;
    else
        return false;
}

// Prints the board
void Game::printBoard() {

    // Print the score
    std::cout << "        [SCORE: " << player.score << "]" << std::endl;

    std::cout << std::endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {

            std::cout << "[";
            switch (board[i][j]) {
            case Element::EMPTY:
                std::cout << " ";
                break;
            case Element::PLAYER:
                std::cout << "P";
                break;
            case Element::COIN:
                std::cout << "C";
                break;
            case Element::STONE:
                std::cout << "S";
            }
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
        << std::endl;
}

// ****************+********************
//           PLAYER FUNCTIONS
// *******************+*****************

// Returns true if the given movement is legal in relation to the player
bool Player::checkMovement(Movement mov) {

    std::pair<int, int> check_position; // Row and column of the position to check

    // Check each case from Player::position
    switch (mov) {
    case Movement::UP:
        check_position.first = position.first - 1;
        check_position.second = position.second;
        break;
    case Movement::DOWN:
        check_position.first = position.first + 1;
        check_position.second = position.second;
        break;
    case Movement::LEFT:
        check_position.first = position.first;
        check_position.second = position.second - 1;
        break;
    case Movement::RIGHT:
        check_position.first = position.first;
        check_position.second = position.second + 1;
        break;
    case Movement::INVALID:
        return false;
    }

    if (check_position.first >= NUM_ROWS || check_position.first < 0 ||
        check_position.second >= NUM_COLUMNS ||
        check_position.second < 0) // If the check_position is out of bounds
        return false;
    else if (game_ptr->board[check_position.first][check_position.second] ==
        Element::STONE) // If the check_position is in a STONE
        return false;
    else
        return true; // Else, the movement is legal
}

// Adds one to the player's score
void Player::addScore() { score++; }

// Sets the player's position to the given row and column
void Player::setPos(int row, int col) {

    // Check if the position is valid
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLUMNS) {
        std::cout << std::endl << "Invalid position!" << std::endl;
        return;
    }

    // Set the previous position to empty
    game_ptr->board[position.first][position.second] = Element::EMPTY;

    // Update new row and column
    position.first = row;
    position.second = col;

    // Set the updated position to player
    game_ptr->board[position.first][position.second] = Element::PLAYER;
}

// Returns true if the given Movement leads the player to a coin
bool Player::existsCoin(Movement mov) {

    std::pair<int, int> check_position; // Row and column of the position to check

    // Check each case from Player::position
    switch (mov) {
    case Movement::UP:
        check_position.first = position.first - 1;
        check_position.second = position.second;
        break;
    case Movement::DOWN:
        check_position.first = position.first + 1;
        check_position.second = position.second;
        break;
    case Movement::LEFT:
        check_position.first = position.first;
        check_position.second = position.second - 1;
        break;
    case Movement::RIGHT:
        check_position.first = position.first;
        check_position.second = position.second + 1;
    case Movement::INVALID:
        return false;
    }

    if (game_ptr->board[check_position.first][check_position.second] ==
        Element::COIN) // Check if the check position on the board contains COIN
        return true;
    else
        return false;
}

// *************************
//           MAIN
// *************************

int main() {

    static Game game;

    game.titleScreen();

    game.initializeBoard();
    do {
        game.printBoard();
        game.movePlayer(game.askInput());

    } while (!game.gameOver());

    game.printBoard();
    game.askInput();
    game.titleScreen();

    return 0;
}