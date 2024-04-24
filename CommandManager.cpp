#include "CommandManager.h"

void CommandManager::addCommand(std::shared_ptr<Command> cmd)
{
    cmd->execute();
    executedCommands.push(cmd);
    // Kosongkan tumpukan redo saat ada perintah baru
    while (!undoneCommands.empty())
    {
        undoneCommands.pop();
    }
}

void CommandManager::undo()
{
    if (!executedCommands.empty())
    {
        auto cmd = executedCommands.top();
        cmd->undo();
        executedCommands.pop();
        undoneCommands.push(cmd);
    }
}

void CommandManager::redo()
{
    if (!undoneCommands.empty())
    {
        auto cmd = undoneCommands.top();
        cmd->execute();
        undoneCommands.pop();
        executedCommands.push(cmd);
    }
}
