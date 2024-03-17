#include <iostream>
#include "GameManager.h"

GameManager::GameManager() {}

void GameManager::initialize(int difficulty)
{
    board.generate(difficulty);
}

void GameManager::printBoard() const
{
    for (int i = 0; i < 9; ++i)
    {
        if (i % 3 == 0 && i != 0)
        {
            std::cout << "---------------------" << std::endl;
        }
        for (int j = 0; j < 9; ++j)
        {
            if (j % 3 == 0 && j != 0)
            {
                std::cout << "| ";
            }
            if (board.getValue(i, j) == 0)
            {
                std::cout << ". ";
            }
            else
            {
                std::cout << board.getValue(i, j) << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool GameManager::insertNumber(int row, int col, int num)
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9 && num >= 0 && num <= 9)
    {
        if (!board.isFixed(row, col) && board.getValue(row, col) == 0)
        {
            board.setValue(row, col, num);
            return true;
        }
    }
    return false;
}

bool GameManager::removeNumber(int row, int col)
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9)
    {
        if (!board.isFixed(row, col))
        {
            board.setValue(row, col, 0);
            return true;
        }
    }
    return false;
}

bool GameManager::isMoveValid(int row, int col, int num) const
{
    return board.isValid(row, col, num);
}

bool GameManager::isGameOver() const
{
    return board.isFull();
}

void GameManager::resetGame()
{
    board.reset();
}

const BoardGenerator & GameManager::getBoard() const
{
    return board;
}
