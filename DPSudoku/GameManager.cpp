#include "GameManager.h"
#include "BoardFactory.h"
#include <iostream>

GameManager::GameManager(const std::string &playerName, const std::string &difficultyLevel) : player(playerName)
{
    // Menggunakan BoardFactory untuk membuat board berdasarkan tingkat kesulitan
    board = BoardFactory::createBoard(difficultyLevel);
}

void GameManager::startGame()
{
    if (!board.isValid())
    {
        std::cerr << "Failed to initialize board. Exiting game..." << std::endl;
        return;
    }

    std::cout << "Welcome, " << player.getName() << "!" << std::endl;
    board.display();
    while (!checkWin())
    {
        playMove();
    }
    std::cout << "Congratulations, " << player.getName() << "! You've won!" << std::endl;
}

bool GameManager::validateInput(int row, int col, int num) const
{
    if (row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9)
    {
        return false;
    }
    if (!board.isEmpty(row, col))
    {
        return false;
    }
    return true;
}

void GameManager::playMove()
{
    int row, col, num;
    std::cout << "Enter row, column, and number (1-9) to place (e.g., 1 2 3): ";
    std::cin >> row >> col >> num;

    // Periksa validitas input
    if (!validateInput(row - 1, col - 1, num))
    {
        std::cout << "Invalid move! Please try again." << std::endl;
        return;
    }

    // Tempatkan nomor pada board
    board.placeNumber(row - 1, col - 1, num);

    // Tampilkan board setelah pemain memasukkan nomor
    board.display();
}

bool GameManager::checkWin() const
{
    return board.isFilled();
}
