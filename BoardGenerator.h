#ifndef BOARD_GENERATOR_H
#define BOARD_GENERATOR_H

#include "Difficulty.h"
#include "Board.h"

class BoardGenerator
{
public:
    static void generateBoard(Board &board, Difficulty difficulty);
};

#endif // BOARD_GENERATOR_H
