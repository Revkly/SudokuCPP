#ifndef SET_COMMAND_H
#define SET_COMMAND_H

#include "Command.h"
#include "board.h"

class SetCommand : public Command
{
public:
    SetCommand(Board &board, int row, int col, int newValue);
    void execute() override;
    void undo() override;

private:
    Board &board;
    int row;
    int col;
    int newValue;
    int oldValue;
};

#endif // SET_COMMAND_H
