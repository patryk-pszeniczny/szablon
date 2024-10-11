#include "SudokuGenerate.h"
#include <algorithm> 
#include <vector>

namespace szablon {

    SudokuGenerate::SudokuGenerate() {
        board = gcnew array<int, 2>(9, 9);
        copy_board = gcnew array<int, 2>(9, 9);
        rand = gcnew Random(static_cast<int>(DateTime::Now.Ticks));
        this->numberOfSolution = 1;
        this->tryGen = 0;
    }
    void SudokuGenerate::GenerateSudoku() {
        while (fillValues()) {}
    }
    void SudokuGenerate::fillArrays() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                board[row, col] = 0;
                copy_board[row, col] = 0;
            }
        }
    }
    bool SudokuGenerate::solveSudoku() {
        int row, col;
        if (!hasEmptyCell()) {
            return true;
        }
        for (int value = 1; value <= 9; value++) {
            if (!CheckIfSafe(row, col, value)) {
                continue;
            }
            board[row, col] = value;
            if (solveSudoku()) {
                return true;
            }
            board[row, col] = 0;
        }
        return false;
    }

    bool SudokuGenerate::fillValues() {
        this->tryGen++;
        std::vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        for (int i = values.size() - 1; i > 0; --i) {
            int j = rand->Next(0, i+1);
            std::swap(values[i], values[j]);
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i, j] != 0) {
                    continue;
                }
                for (int value : values) {
                    if (!CheckIfSafe(i, j, value)) {
                        continue;
                    }
                    board[i, j] = value;
                    if (!hasEmptyCell() || fillValues()) {
                        return true;
                    }
                    board[i, j] = 0;
                }
                return false;
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

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int r = startRow; r < startRow + 3; r++) {
            for (int c = startCol; c < startCol + 3; c++) {
                if (board[r, c] == num)
                    return false;
            }
        }
        return true;
    }

    bool SudokuGenerate::checkSudoku() {
        for (int row = 0; row < 9; row++) {
            array<bool>^ rowCheck = gcnew array<bool>(9);
            array<bool>^ colCheck = gcnew array<bool>(9);
            for (int col = 0; col < 9; col++) {
                int rowValue = board[row, col];
                int colValue = board[col, row];
                if (rowValue < 1 || rowValue > 9 || rowCheck[rowValue - 1]) return false;
                if (colValue < 1 || colValue > 9 || colCheck[colValue - 1]) return false;
                rowCheck[rowValue - 1] = true;
                colCheck[colValue - 1] = true;
            }
        }
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                array<bool>^ blockCheck = gcnew array<bool>(9);
                for (int r = blockRow * 3; r < blockRow * 3 + 3; r++) {
                    for (int c = blockCol * 3; c < blockCol * 3 + 3; c++) {
                        int value = board[r, c];
                        if (value < 1 || value > 9 || blockCheck[value - 1]) {
                            return false;
                        }
                        blockCheck[value - 1] = true;
                    }
                }
            }
        }

        return true;
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
