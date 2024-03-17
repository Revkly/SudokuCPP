#include "BoardGenerator.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

BoardGenerator::BoardGenerator()
{
    // Initialize the board with empty cells
    board.resize(9, std::vector<Board>(9));
}

void BoardGenerator::setValue(int row, int col, int val)
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9)
    {
        board[row][col].setValue(val);
    }
}

int BoardGenerator::getValue(int row, int col) const
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9)
    {
        return board[row][col].getValue();
    }
    return 0; // Return 0 if coordinates are out of bounds
}

void BoardGenerator::setFixed(int row, int col, bool fix)
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9)
    {
        board[row][col].setFixed(fix);
    }
}

bool BoardGenerator::isFixed(int row, int col) const
{
    if (row >= 0 && row < 9 && col >= 0 && col < 9)
    {
        return board[row][col].isFixed();
    }
    return false; // Return false if coordinates are out of bounds
}

bool BoardGenerator::isValid(int row, int col, int num) const
{
    // Check row and column
    for (int i = 0; i < 9; ++i)
    {
        if (board[row][i].getValue() == num || board[i][col].getValue() == num)
        {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i)
    {
        for (int j = startCol; j < startCol + 3; ++j)
        {
            if (board[i][j].getValue() == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool BoardGenerator::solve()
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            if (board[row][col].getValue() == 0)
            {
                for (int num = 1; num <= 9; ++num)
                {
                    if (isValid(row, col, num))
                    {
                        board[row][col].setValue(num);
                        if (solve())
                        {
                            return true;
                        }
                        board[row][col].setValue(0);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void BoardGenerator::generate()
{
    // Generate an empty board
    solve();
    // Randomly remove cells to create the puzzle
    srand(time(nullptr));
    for (int i = 0; i < 81; ++i)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if (!board[row][col].isFixed())
        {
            board[row][col].setValue(0);
        }
    }
}

void BoardGenerator::generate(int difficulty)
{
    // Generate an empty board
    solve();
    // Randomly remove cells based on difficulty
    srand(time(nullptr));
    int cellsToRemove = 0;
    switch (difficulty)
    {
    case Difficulty::EASY:
        cellsToRemove = 40;
        break;
    case Difficulty::MEDIUM:
        cellsToRemove = 50;
        break;
    case Difficulty::HARD:
        cellsToRemove = 60;
        break;
    default:
        cellsToRemove = 40;
        break;
    }
    for (int i = 0; i < cellsToRemove; ++i)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if (!board[row][col].isFixed())
        {
            board[row][col].setValue(0);
        }
    }
}

bool BoardGenerator::isFull() const
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j].getValue() == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void BoardGenerator::reset()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            board[i][j].setValue(0);
        }
    }
}

const std::vector<std::vector<Board>> &BoardGenerator::getBoard() const
{
    return board;
}
