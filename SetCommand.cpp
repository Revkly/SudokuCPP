#include "SetCommand.h"

SetCommand::SetCommand(Board &board, int row, int col, int newValue)
    : board(board), row(row), col(col), newValue(newValue)
{
    oldValue = board.getCell(row, col);
}

void SetCommand::execute()
{
    board.setCell(row, col, newValue);
}

void SetCommand::undo()
{
    board.setCell(row, col, oldValue);
}
