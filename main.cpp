#include <iostream>
#include "GameManager.h"
#include "Difficulty.h"

int main()
{
    std::cout << "Welcome to Sudoku!" << std::endl;
    std::cout << "Please select difficulty level:" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    Difficulty::Level level;

    // Tentukan tingkat kesulitan berdasarkan pilihan pengguna
    if (choice == 1)
    {
        level = Difficulty::EASY;
    }
    else if (choice == 2)
    {
        level = Difficulty::MEDIUM;
    }
    else if (choice == 3)
    {
        level = Difficulty::HARD;
    }
    else
    {
        std::cout << "Invalid choice! Defaulting to Easy difficulty." << std::endl;
        level = Difficulty::EASY;
    }

    // Buat objek GameManager dan mulai permainan
    GameManager gameManager;
    gameManager.startGame(level);

    std::cout << "Thank you for playing Sudoku!" << std::endl;
    return 0;
}
