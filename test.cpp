#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Interface for Board
class BoardInterface
{
public:
    virtual void display() const = 0;
    virtual bool setValue(int row, int col, int value) = 0;
    virtual int getValue(int row, int col) const = 0;
    virtual bool isFilled() const = 0;
    virtual bool isValueValid(int row, int col, int value) const = 0;
    virtual void clear() = 0;
    virtual ~BoardInterface() {}
};

// Concrete class for Board
class SudokuBoard : public BoardInterface
{
private:
    int board[9][9];

public:
    SudokuBoard()
    {
        clear();
    }

    void display() const override
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool setValue(int row, int col, int value) override
    {
        if (isValueValid(row, col, value))
        {
            board[row][col] = value;
            return true;
        }
        return false;
    }

    int getValue(int row, int col) const override
    {
        return board[row][col];
    }

    bool isFilled() const override
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValueValid(int row, int col, int value) const override
    {
        // Check row and column
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i] == value || board[i][col] == value)
            {
                return false;
            }
        }

        // Check 3x3 box
        int boxStartRow = 3 * (row / 3);
        int boxStartCol = 3 * (col / 3);
        for (int i = boxStartRow; i < boxStartRow + 3; ++i)
        {
            for (int j = boxStartCol; j < boxStartCol + 3; ++j)
            {
                if (board[i][j] == value)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void clear() override
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                board[i][j] = 0;
            }
        }
    }
};

// Puzzle Generator class
class PuzzleGenerator
{
private:
    SudokuBoard &board;

public:
    PuzzleGenerator(SudokuBoard &b) : board(b) {}

    void generatePuzzle()
    {
        srand(time(0));

        // Generate random puzzle
        for (int i = 0; i < 17; ++i)
        { // Adjust difficulty by changing the number of filled cells
            int row = rand() % 9;
            int col = rand() % 9;
            int value = rand() % 9 + 1;

            // Check if the value is valid at the chosen position
            while (!board.isValueValid(row, col, value) || board.getValue(row, col) != 0)
            {
                row = rand() % 9;
                col = rand() % 9;
                value = rand() % 9 + 1;
            }

            board.setValue(row, col, value);
        }
    }
};

// Player class
class Player
{
private:
    string name;

public:
    Player(const string &n) : name(n) {}

    string getName() const
    {
        return name;
    }
};

// Game Manager class
class GameManager
{
private:
    SudokuBoard board;
    PuzzleGenerator puzzleGenerator;
    Player player;

public:
    GameManager(const string &playerName) : player(playerName), puzzleGenerator(board) {}

    void startGame()
    {
        puzzleGenerator.generatePuzzle();
        playGame();
    }

private:
    void playGame()
    {
        while (!board.isFilled())
        {
            cout << "Current Board:" << endl;
            board.display();

            int row, col, value;
            cout << player.getName() << ", enter row (1-9), column (1-9), and value (1-9): ";
            cin >> row >> col >> value;

            // Adjust user input to array indices
            --row;
            --col;

            if (row >= 0 && row < 9 && col >= 0 && col < 9 && value >= 1 && value <= 9)
            {
                if (board.isValueValid(row, col, value))
                {
                    board.setValue(row, col, value);
                    cout << "Move accepted. Good job!" << endl;
                }
                else
                {
                    cout << "Invalid move. Try again." << endl;
                }
            }
            else
            {
                cout << "Invalid input. Please enter valid row, column, and value." << endl;
            }
        }

        cout << "Congratulations, " << player.getName() << "! You solved the puzzle." << endl;
    }
};

int main()
{
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    GameManager game(playerName);
    game.startGame();

    return 0;
}
