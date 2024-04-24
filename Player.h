#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "CommandManager.h"

class Player
{
public:
    Player(Board &board);
    void setInput(int row, int col, int value);
    void removeInput(int row, int col);
    std::shared_ptr<CommandManager> getCommandManager() const;

private:
    Board &board; // Referensi ke objek Board
    std::shared_ptr<CommandManager> commandManager;
};

#endif // PLAYER_H
