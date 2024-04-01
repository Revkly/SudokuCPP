#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
    string playerName;
    cout << "Enter player name: ";
    cin >> playerName;

    string difficultyLevel;
    cout << "Choose difficulty level (easy, medium, hard): ";
    cin >> difficultyLevel;

    GameManager game(playerName, difficultyLevel);
    game.startGame();

    return 0;
}
