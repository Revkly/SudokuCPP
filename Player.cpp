#include "Player.h"

Player::Player(Board &board) : board(board) {}

void Player::setInput(int row, int col, int value)
{
    if (board.isCellEditable(row, col))
    {
        if (board.isValidMove(row, col, value))
        {
            board.setCell(row, col, value);
            std::cout << "Move set: (" << row + 1 << ", " << col + 1 << ") = " << value << std::endl;
        }
        else
        {
            std::cout << "Invalid move! Try again." << std::endl;
        }
    }
    else
    {
        std::cout << "Cell is not editable!" << std::endl;
    }
}

void Player::removeInput(int row, int col)
{
    if (board.isCellEditable(row, col))
    {
        board.setCell(row, col, 0);
        std::cout << "Input removed: (" << row + 1 << ", " << col + 1 << ")" << std::endl;
    }
    else
    {
        std::cout << "Cell is not editable!" << std::endl;
    }
}
