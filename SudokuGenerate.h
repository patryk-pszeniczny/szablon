#pragma once

using namespace System;
using namespace System::Collections::Generic;
namespace szablon {

    public ref class SudokuGenerate {
    public:
        array<int, 2>^ board;
        array<int, 2>^ copy_board;
        Random^ rand;
        SudokuGenerate();
        void GenerateSudoku();
        bool fillValues();
        void fillArrays();
        int numberOfSolution;
        int tryGen;
        bool solveSudoku();
        bool checkSudoku();
        bool hasEmptyCell();
        void removeDigits(int i);
    private:
        bool CheckIfSafe(int row, int col, int num);
        
       
        
       
    };
}
