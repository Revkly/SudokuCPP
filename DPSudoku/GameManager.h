#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "BoardGenerator.h"

class GameManager
{
private:
    BoardGenerator board;

public:
    GameManager();
    void initialize(int difficulty);
    void printBoard() const;
    bool insertNumber(int row, int col, int num);
    bool removeNumber(int row, int col);
    bool isMoveValid(int row, int col, int num) const;
    bool isGameOver() const;
    void resetGame();
    const BoardGenerator &getBoard() const;
};

#endif // GAMEMANAGER_H
