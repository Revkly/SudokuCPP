#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
private:
    string name;

public:
    Player(const string &playerName);
    string getName() const;
};

#endif // PLAYER_H
