#include "Player.h"
#include "SetCommand.h"
#include "CommandManager.h"
#include <iostream>

Player::Player(Board &board) : board(board), commandManager(std::make_shared<CommandManager>()) {}

void Player::setInput(int row, int col, int value)
{
    if (board.isCellEditable(row, col))
    {
        if (board.isValidMove(row, col, value))
        {
            auto command = std::make_shared<SetCommand>(board, row, col, value);
            commandManager->addCommand(command);
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
        auto command = std::make_shared<SetCommand>(board, row, col, 0);
        commandManager->addCommand(command);
        std::cout << "Input removed: (" << row + 1 << ", " << col + 1 << ")" << std::endl;
    }
    else
    {
        std::cout << "Cell is not editable!" << std::endl;
    }
}
