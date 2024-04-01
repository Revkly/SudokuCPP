// BoardFactory.h
#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H

#include "Board.h"
#include "Difficulty.h"

class BoardFactory
{
public:
    static Board createBoard(const std::string &difficultyLevel);
};

#endif // BOARDFACTORY_H
