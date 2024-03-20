#include "header.h"

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
        break;
    case Movement::INVALID:
        return false;
    }

    if (game_ptr->board[check_position.first][check_position.second] ==
        Element::COIN) // Check if the check position on the board contains COIN
        return true;
    else
        return false;
}