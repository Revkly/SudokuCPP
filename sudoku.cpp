#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 9;

// Fungsi untuk menampilkan papan Sudoku
void displayBoard(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == 0)
            {
                cout << "  ";
            }
            else
            {
                cout << setw(2) << board[i][j] << " ";
            }

            if ((j + 1) % 3 == 0 && j < SIZE - 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < SIZE - 1)
        {
            cout << "------+-------+------" << endl;
        }
    }
    cout << endl;
}

// Fungsi untuk memeriksa apakah suatu angka dapat ditempatkan di baris dan kolom tertentu
bool isSafe(int board[SIZE][SIZE], int row, int col, int num)
{
    // Periksa baris
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    // Periksa kolom
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    // Periksa kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Fungsi untuk memeriksa apakah papan Sudoku telah selesai
bool isBoardFull(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// Fungsi untuk memulai permainan Sudoku
void playSudoku(int board[SIZE][SIZE])
{
    while (!isBoardFull(board))
    {
        cout << "Papan Sudoku saat ini:" << endl;
        displayBoard(board);

        int row, col, num;
        cout << "Masukkan baris (1-9), kolom (1-9), dan angka (1-9) yang ingin Anda masukkan (pisahkan dengan spasi): ";
        cin >> row >> col >> num;

        // Periksa apakah masukan valid
        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
        {
            cout << "Masukan tidak valid. Coba lagi." << endl;
            continue;
        }

        // Konversi ke indeks array (dimulai dari 0)
        row--;
        col--;

        // Periksa apakah sel sudah terisi atau tidak aman
        if (board[row][col] != 0 || !isSafe(board, row, col, num))
        {
            cout << "Tidak dapat memasukkan angka di posisi tersebut. Coba lagi." << endl;
        }
        else
        {
            // Tempatkan angka di sel yang dipilih
            board[row][col] = num;
        }
    }

    cout << "Selamat! Anda telah menyelesaikan Sudoku." << endl;
    displayBoard(board);
}

int main()
{
    int board[SIZE][SIZE] = {0}; // Inisialisasi papan Sudoku

    // Isi beberapa sel awal jika diinginkan
    // Contoh: Letakkan 17 angka pada posisi acak untuk inisialisasi papan
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 20; ++i)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        int num = rand() % 9 + 1;

        // Periksa apakah sel sudah terisi atau tidak aman
        while (board[row][col] != 0 || !isSafe(board, row, col, num))
        {
            row = rand() % SIZE;
            col = rand() % SIZE;
            num = rand() % 9 + 1;
        }

        // Tempatkan angka di sel yang dipilih
        board[row][col] = num;
    }

    cout << "Selamat datang di permainan Sudoku!" << endl;
    playSudoku(board);

    return 0;
}
