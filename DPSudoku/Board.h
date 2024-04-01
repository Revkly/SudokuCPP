#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
private:
    std::vector<std::vector<int>> cells;

public:
    Board();
    void initializeBoard(const std::vector<std::vector<int>> &initialSetup);
    bool isFilled() const;
    bool isValidMove(int row, int col, int num) const;
    bool placeNumber(int row, int col, int num);
    void removeNumber(int row, int col);
    void displayBoard() const;
};

#endif // BOARD_H
