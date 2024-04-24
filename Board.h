#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "difficulty.h"

class Board
{
public:
    Board();
    void initialize(Difficulty difficulty);
    bool isCellEditable(int row, int col);
    bool isValidMove(int row, int col, int value);
    bool checkWin();
    void displayBoard();
    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;

private:
    std::vector<std::vector<int>> grid;
    std::set<std::pair<int, int>> fixedCells;
    void loadTemplate(Difficulty difficulty);
    bool isValidRow(int row, int value);
    bool isValidCol(int col, int value);
    bool isValidRegion(int startRow, int startCol, int value);
};

#endif // BOARD_H
