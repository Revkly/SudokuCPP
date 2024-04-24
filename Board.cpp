#include "board.h"
#include <iostream>
#include <fstream>
#include <set>
#include <utility>

Board::Board() : grid(9, std::vector<int>(9, 0)) {}

void Board::initialize(Difficulty difficulty)
{
    loadTemplate(difficulty);
}

void Board::loadTemplate(Difficulty difficulty)
{
    std::ifstream file(difficulty.getTemplateFile());
    if (!file.is_open())
    {
        std::cerr << "Error loading template file!" << std::endl;
        return;
    }

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            file >> grid[row][col];
            if (grid[row][col] != 0)
            {
                fixedCells.insert({row, col});
            }
        }
    }

    file.close();
}

bool Board::isCellEditable(int row, int col)
{
    return fixedCells.find({row, col}) == fixedCells.end();
}

bool Board::isValidMove(int row, int col, int value)
{
    return isValidRow(row, value) && isValidCol(col, value) && isValidRegion(row - row % 3, col - col % 3, value);
}

bool Board::isValidRow(int row, int value)
{
    std::set<int> seen;
    for (int col = 0; col < 9; ++col)
    {
        int cellValue = grid[row][col];
        if (cellValue == value)
        {
            return false;
        }
    }
    return true;
}

bool Board::isValidCol(int col, int value)
{
    std::set<int> seen;
    for (int row = 0; row < 9; ++row)
    {
        int cellValue = grid[row][col];
        if (cellValue == value)
        {
            return false;
        }
    }
    return true;
}

bool Board::isValidRegion(int startRow, int startCol, int value)
{
    std::set<int> seen;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            int cellValue = grid[startRow + row][startCol + col];
            if (cellValue == value)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkWin()
{
    // Periksa setiap baris, kolom, dan region
    for (int i = 0; i < 9; ++i)
    {
        std::set<int> seenRow;
        std::set<int> seenCol;

        for (int j = 0; j < 9; ++j)
        {
            // Periksa baris
            int cellValueRow = grid[i][j];
            if (cellValueRow < 1 || cellValueRow > 9 || seenRow.find(cellValueRow) != seenRow.end())
            {
                return false;
            }
            seenRow.insert(cellValueRow);

            // Periksa kolom
            int cellValueCol = grid[j][i];
            if (cellValueCol < 1 || cellValueCol > 9 || seenCol.find(cellValueCol) != seenCol.end())
            {
                return false;
            }
            seenCol.insert(cellValueCol);
        }
    }

    // Periksa setiap region
    for (int startRow = 0; startRow < 9; startRow += 3)
    {
        for (int startCol = 0; startCol < 9; startCol += 3)
        {
            std::set<int> seenRegion;
            for (int row = 0; row < 3; ++row)
            {
                for (int col = 0; col < 3; ++col)
                {
                    int cellValue = grid[startRow + row][startCol + col];
                    if (cellValue < 1 || cellValue > 9 || seenRegion.find(cellValue) != seenRegion.end())
                    {
                        return false;
                    }
                    seenRegion.insert(cellValue);
                }
            }
        }
    }
    return true;
}

void Board::displayBoard()
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::setCell(int row, int col, int value)
{
    if (isCellEditable(row, col))
    {
        grid[row][col] = value;
    }
}

int Board::getCell(int row, int col) const
{
    return grid[row][col];
}
