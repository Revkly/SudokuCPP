#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <string>
#include <vector>

using namespace std;

class Difficulty
{
private:
    string level;

public:
    Difficulty(const string &difficultyLevel);
    string getLevel() const;
    vector<vector<int>> loadTemplate() const;
};

#endif // DIFFICULTY_H
