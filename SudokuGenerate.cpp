#include "SudokuGenerate.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm> 
#include <random> 
#include <vector> 
#include <chrono>

namespace szablon {

    SudokuGenerate::SudokuGenerate() {
        board = gcnew array<int, 2>(9, 9);
        copy_board = gcnew array<int, 2>(9, 9);
        rand = gcnew Random(static_cast<int>(DateTime::Now.Ticks));
        this->numberOfSolution = 1;
        this->tryGen = 0;
    }
    void SudokuGenerate::GenerateSudoku() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                board[row, col] = 0;
                copy_board[row, col] = 0;
            }
        }
        while (fillValues()) {}

        removeDigits(25);
        srand(static_cast<unsigned>(time(0)));
    }
    bool SudokuGenerate::solveSudoku(bool visualize) {
        int row, col;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                row = i;
                col = j;
                if (board[row, col] == 0) {
                    for (int value = 1; value <= 9; value++) {
                        if (CheckIfSafe(row, col, value)) {
                            board[row, col] = value;
                            if (!hasEmptyCell()) {
                                numberOfSolution++;
                                break;
                            }
                            else if (solveSudoku(visualize)) {
                                return true;
                            }
                        }
                    }
                    break;
                }
            }
        }
        board[row, col] = 0;
        return false;
    }
    bool SudokuGenerate::fillValues() {
        this->tryGen++;
        std::vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(values.begin(), values.end(), std::default_random_engine(seed));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i, j] == 0) {
                    for (int value : values) {
                        if (CheckIfSafe(i, j, value)) {
                            board[i, j] = value;
                            if (!hasEmptyCell() || fillValues()) {
                                return true;
                            }
                            board[i, j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
    bool SudokuGenerate::hasEmptyCell() {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r, c] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool SudokuGenerate::CheckIfSafe(int row, int col, int num) {
        for (int c = 0; c < 9; c++) {
            if (board[row, c] == num) {
                return false;
            }
        }

        for (int r = 0; r < 9; r++) {
            if (board[r, col] == num) {
                return false;
            }
        }

        int startRow = floor(row / 3) * 3, startCol = floor(col / 3) * 3;
        for (int r = startRow; r < startRow + 3; r++) {
            for (int c = startCol; c < startCol + 3; c++) {
                if (board[r, c] == num)
                    return false;
            }
        }
        return true;
    }

    bool SudokuGenerate::checkSudoku() {
        // Sprawdzenie wierszy
        for (int row = 0; row < 9; row++) {
            array<bool>^ rowCheck = gcnew array<bool>(9);
            for (int col = 0; col < 9; col++) {
                int value = board[row, col];
                if (value < 1 || value > 9) return false;  // Sprawdzenie poprawnoœci zakresu liczby
                if (rowCheck[value - 1]) {
                    return false;
                }
                rowCheck[value - 1] = true;
            }
        }

        // Sprawdzenie kolumn
        for (int col = 0; col < 9; col++) {
            array<bool>^ colCheck = gcnew array<bool>(9);
            for (int row = 0; row < 9; row++) {
                int value = board[row, col];
                if (value < 1 || value > 9) return false;  // Sprawdzenie poprawnoœci zakresu liczby
                if (colCheck[value - 1]) {
                    return false;
                }
                colCheck[value - 1] = true;
            }
        }

        // Sprawdzenie bloków 3x3
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                array<bool>^ blockCheck = gcnew array<bool>(9);
                for (int row = blockRow * 3; row < blockRow * 3 + 3; row++) {
                    for (int col = blockCol * 3; col < blockCol * 3 + 3; col++) {
                        int value = board[row, col];
                        if (value < 1 || value > 9) return false;  // Sprawdzenie poprawnoœci zakresu liczby
                        if (blockCheck[value - 1]) {
                            return false;
                        }
                        blockCheck[value - 1] = true;
                    }
                }
            }
        }

        return true;  // Jeœli wszystko jest poprawne, zwracamy true
    }

    void SudokuGenerate::removeDigits(int count) {
        while (count > 0) {
            int cellId = rand->Next(0, 81);
            int row = cellId / 9;
            int col = cellId % 9;

            if (board[row, col] != 0) {
                copy_board[row, col] = board[row, col];
                board[row, col] = 0;
                count--;
            }
        }
    }
}
