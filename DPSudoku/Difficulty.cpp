#include "Difficulty.h"
#include <fstream>
#include <vector>

using namespace std;

Difficulty::Difficulty(const string &difficultyLevel) : level(difficultyLevel) {}

string Difficulty::getLevel() const
{
    return level;
}

vector<vector<int>> Difficulty::loadTemplate() const
{
    string filename = level + ".txt";
    ifstream file(filename);
    vector<vector<int>> templateBoard;

    if (file.is_open())
    {
        templateBoard.resize(9, vector<int>(9));
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                file >> templateBoard[i][j];
            }
        }
        file.close();
    }

    return templateBoard;
}
