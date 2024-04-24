#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player
{
public:
    Player(Board &board);
    void setInput(int row, int col, int value);
    void removeInput(int row, int col);

private:
    Board &board; // Referensi ke objek Board
};

#endif // PLAYER_H
