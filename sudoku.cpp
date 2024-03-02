#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class: Sudoku
class Sudoku
{
protected:
    int mat[9][9];
    int N;
    int K;

public:
    Sudoku(int size, int filledCells) : N(size), K(filledCells)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                mat[i][j] = 0;
            }
        }
    }

    void fillValues()
    {
        srand(time(0));
        int count = K;
        while (count > 0)
        {
            int i = rand() % N;
            int j = rand() % N;
            int num = rand() % N + 1;

            if (mat[i][j] == 0 && isValidMove(i, j, num))
            {
                mat[i][j] = num;
                count--;
            }
        }
    }

    bool solveSudoku();

    bool isValidMove(int row, int col, int num)
    {
        for (int x = 0; x < N; ++x)
        {
            if (mat[row][x] == num || mat[x][col] == num)
            {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (mat[i + startRow][j + startCol] == num)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void printSudoku()
    {
        cout << "Sudoku Board:\n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void inputValue(int row, int col, int num)
    {
        if (row >= 0 && row < N && col >= 0 && col < N && num >= 1 && num <= 9)
        {
            mat[row][col] = num;
        }
        else
        {
            cout << "Invalid input. Please enter valid row, column, and number.\n";
        }
    }

    friend class SudokuSolver;
};

// Derived class: EnhancedSudoku
class EnhancedSudoku : public Sudoku
{
public:
    EnhancedSudoku(int size, int filledCells) : Sudoku(size, filledCells) {}

    void generateRandomPuzzle()
    {
        // Panggil metode fillValues() untuk mengisi beberapa sel pada awal permainan
        fillValues();

        // Tambahkan logika tambahan jika diperlukan
        // ...

        cout << "Random puzzle generated!\n";
    }

    // Additional methods or features can be added here
};

class SudokuSolver
{
public:
    SudokuSolver() {}

    void fillValues(Sudoku &sudoku)
    {
        // Leave this empty if you're using the Sudoku::fillValues() method
        sudoku.fillValues();
    }

    bool solveSudoku(Sudoku &sudoku)
    {
        int row, col;

        if (!findEmptyCell(sudoku, row, col))
        {
            return true; // No empty cell, Sudoku is solved
        }

        for (int num = 1; num <= 9; ++num)
        {
            if (isSafe(sudoku, row, col, num))
            {
                sudoku.mat[row][col] = num;

                if (solveSudoku(sudoku))
                {
                    return true; // Successfully solved
                }

                sudoku.mat[row][col] = 0; // Backtrack if placing the number doesn't lead to a solution
            }
        }

        return false; // No number can be placed, backtrack
    }

    bool findEmptyCell(Sudoku &sudoku, int &row, int &col)
    {
        for (row = 0; row < 9; ++row)
        {
            for (col = 0; col < 9; ++col)
            {
                if (sudoku.mat[row][col] == 0)
                {
                    return true; // Found an empty cell
                }
            }
        }
        return false; // No empty cell found
    }

    bool isSafe(Sudoku &sudoku, int row, int col, int num)
    {
        for (int x = 0; x < 9; ++x)
        {
            if (sudoku.mat[row][x] == num || sudoku.mat[x][col] == num)
            {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (sudoku.mat[i + startRow][j + startCol] == num)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

bool Sudoku::solveSudoku()
{
    SudokuSolver solver;
    return solver.solveSudoku(*this);
}

int main()
{
    int N = 9;
    int K = 50;

    EnhancedSudoku sudoku(N, K);
    sudoku.generateRandomPuzzle(); // Utilizing the additional method
    sudoku.printSudoku();

    cout << "Enter row, column, and number (e.g., 1 2 3 to place 3 in the cell at row 1, column 2):\n";

    int row, col, num;
    while (true)
    {
        cin >> row >> col >> num;

        if (row == -1 || col == -1 || num == -1)
        {
            break; // Enter -1 to exit the loop
        }

        sudoku.inputValue(row - 1, col - 1, num); // Adjust to 0-based indexing
        sudoku.printSudoku();
    }

    return 0;
}
