#include "Difficulty.h"

Difficulty::Difficulty(Level level) : difficultyLevel(level) {}

std::string Difficulty::getTemplateFile() const
{
    switch (difficultyLevel)
    {
    case EASY:
        return "templates/easy.txt";
    case MEDIUM:
        return "templates/medium.txt";
    case HARD:
        return "templates/hard.txt";
    default:
        return "templates/easy.txt";
    }
}
