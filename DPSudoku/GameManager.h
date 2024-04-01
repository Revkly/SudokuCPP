#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Board.h"
#include "Difficulty.h"

using namespace std;

class GameManager
{
private:
    Player player;
    Board board;
    Difficulty difficulty;

public:
    GameManager(const string &playerName, const string &difficultyLevel);
    void startGame();
    bool validateInput(int row, int col, int num);
    void playMove();
    bool checkWin() const;
};

#endif // GAMEMANAGER_H
