#include "BoardFactory.h"
#include "Board.h"
#include <fstream>
#include <iostream>

Board BoardFactory::createBoard(const std::string &difficultyLevel)
{
    if (difficultyLevel == "easy")
    {
        std::string easyTemplateFilename = "easy.txt";
        return createBoard(easyTemplateFilename);
    }
    else if (difficultyLevel == "medium")
    {
        std::string mediumTemplateFilename = "medium.txt";
        return createBoard(mediumTemplateFilename);
    }
    else if (difficultyLevel == "hard")
    {
        std::string hardTemplateFilename = "hard.txt";
        return createBoard(hardTemplateFilename);
    }
    else
    {
        std::cerr << "Invalid difficulty level!" << std::endl;
        // Jika tingkat kesulitan tidak valid, kembalikan board kosong
        return Board();
    }
}

Board BoardFactory::createBoard(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        // Jika file gagal dibuka, kembalikan board kosong
        return Board();
    }

    std::vector<std::vector<int>> templateBoard;
    templateBoard.resize(9, std::vector<int>(9));
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            file >> templateBoard[i][j];
        }
    }
    file.close();

    // Buat board baru menggunakan template
    return Board(templateBoard);
}
