#include "BoardGenerator.h"
#include <fstream>
#include <iostream>

void BoardGenerator::generateBoard(Board &board, Difficulty difficulty)
{
    board.initialize(difficulty);
}
