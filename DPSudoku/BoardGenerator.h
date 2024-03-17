#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>
#include "Difficulty.h"
#include "Board.h"

class BoardGenerator
{
private:
    std::vector<std::vector<Board>> board;

public:
    BoardGenerator();
    void setValue(int row, int col, int val);
    int getValue(int row, int col) const;
    void setFixed(int row, int col, bool fix);
    bool isFixed(int row, int col) const;
    bool isValid(int row, int col, int num) const;
    bool solve();
    void generate();
    void generate(int difficulty);
    bool isFull() const;
    void reset();
    const std::vector<std::vector<Board>> &getBoard() const;
};

#endif
