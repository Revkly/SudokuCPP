#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <stack>
#include <memory>
#include "Command.h"

class CommandManager
{
public:
    void addCommand(std::shared_ptr<Command> cmd);
    void undo();
    void redo();

private:
    std::stack<std::shared_ptr<Command>> executedCommands;
    std::stack<std::shared_ptr<Command>> undoneCommands;
};

#endif // COMMAND_MANAGER_H
