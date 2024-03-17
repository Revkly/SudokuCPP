#ifndef PLAYER_H
#define PLAYER_H

#include "BoardGenerator.h"

class Player
{
public:
    int makeMove(const BoardGenerator &board);
    int removeNumber();
};

#endif // PLAYER_H
