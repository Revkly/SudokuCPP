#include "Board.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Board::Board()
{
    cells = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

void Board::initializeBoard(const std::vector<std::vector<int>> &initialSetup)
{
    cells = initialSetup;
}

bool Board::isFilled() const
{
    for (const auto &row : cells)
    {
        for (int num : row)
        {
            if (num == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::isValidMove(int row, int col, int num) const
{
    // Check row and column
    for (int i = 0; i < 9; ++i)
    {
        if (cells[row][i] == num || cells[i][col] == num)
        {
            return false;
        }
    }

    // Check region
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i)
    {
        for (int j = startCol; j < startCol + 3; ++j)
        {
            if (cells[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool Board::placeNumber(int row, int col, int num)
{
    if (isValidMove(row, col, num))
    {
        cells[row][col] = num;
        return true;
    }
    return false;
}

void Board::removeNumber(int row, int col)
{
    if (cells[row][col] != 0)
    {
        cells[row][col] = 0;
    }
}

void Board::displayBoard() const
{
    std::cout << std::endl;
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
            std::cout << cells[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
