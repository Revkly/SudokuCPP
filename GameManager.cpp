#include "GameManager.h"
#include <iostream>

GameManager::GameManager() : board(), player(board) {}

void GameManager::startGame(Difficulty::Level level)
{
    Difficulty difficulty(level);
    BoardGenerator::generateBoard(board, difficulty);
    board.displayBoard();
    playRound();
}

void GameManager::displayMenu()
{
    std::cout << "Menu:\n";
    std::cout << "1. Set input (row col value)\n";
    std::cout << "2. Remove input (row col)\n";
    std::cout << "3. Check win\n";
    std::cout << "4. Display board\n";
    std::cout << "5. Quit\n";
}

void GameManager::playRound()
{
    while (true)
    {
        displayMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int row, col, value;
            std::cout << "Enter row, col, value: ";
            std::cin >> row >> col >> value;
            player.setInput(row - 1, col - 1, value);
        }
        else if (choice == 2)
        {
            int row, col;
            std::cout << "Enter row and col: ";
            std::cin >> row >> col;
            player.removeInput(row - 1, col - 1);
        }
        else if (choice == 3)
        {
            if (board.checkWin())
            {
                std::cout << "Congratulations! You won!" << std::endl;
                break;
            }
            else
            {
                std::cout << "Keep trying! The board is not yet complete." << std::endl;
            }
        }
        else if (choice == 4)
        {
            board.displayBoard();
        }
        else if (choice == 5)
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid choice! Try again." << std::endl;
        }
    }
}
