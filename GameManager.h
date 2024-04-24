#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Board.h"
#include "Difficulty.h"
#include "Player.h"

class GameManager
{
public:
    GameManager();
    void startGame(Difficulty::Level level);

private:
    Board board;
    Player player;
    void displayMenu();
    void playRound();
};

#endif // GAME_MANAGER_H
