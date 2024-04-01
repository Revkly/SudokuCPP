#include "Player.h"

Player::Player(const string &playerName) : name(playerName) {}

string Player::getName() const
{
    return name;
}
