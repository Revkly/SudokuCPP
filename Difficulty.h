#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <string>

class Difficulty
{
public:
    enum Level
    {
        EASY,
        MEDIUM,
        HARD
    };

    Difficulty(Level level = EASY);
    std::string getTemplateFile() const;

private:
    Level difficultyLevel;
};

#endif // DIFFICULTY_H
