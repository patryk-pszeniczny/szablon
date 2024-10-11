#include "MainForm.h"
#include "SudokuGenerate.h"
#include <iostream>
#include <string>
#include <algorithm>


namespace szablon {
    MainForm::MainForm(void) {
        InitializeComponent();
        rand = gcnew Random();
        listOfTab = gcnew array<TableLayoutPanel^>(9);
        generator = gcnew SudokuGenerate();
        generator->fillArrays();
        generator->GenerateSudoku();
        generator->removeDigits(51);
        this->CreateTextBoxes();

    }
    void MainForm::CreateTextBoxes() {
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                TableLayoutPanel^ tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(blockCol, blockRow));
                for (int rowOffset = 0; rowOffset < 3; rowOffset++) {
                    for (int colOffset = 0; colOffset < 3; colOffset++) {
                        int globalRow = blockRow * 3 + rowOffset;
                        int globalCol = blockCol * 3 + colOffset;
                        CreateTextBox(tb, globalRow, globalCol);
                    }
                }
            }
        }
        label1->Text += generator->numberOfSolution;
        label2->Text += generator->tryGen;
    }
    void MainForm::CreateTextBox(TableLayoutPanel^ parentTable, int row, int col) {
        TextBox^ text = gcnew TextBox();
        text->Padding = System::Windows::Forms::Padding(0);
        text->Margin = System::Windows::Forms::Padding(0);
        text->Width = 57;
        text->Height = 57;
        text->AutoSize = false;
        text->MaxLength = 1;
        text->Font = gcnew System::Drawing::Font(text->Font->FontFamily, 20);
        text->TextAlign = HorizontalAlignment::Center;
        text->KeyPress += gcnew KeyPressEventHandler(this, &MainForm::TextBox_KeyPress);

        int value = generator->board[row, col];
        text->Name = L"text_" + row + "_" + col;
        text->Tag = gcnew array<int>{ row, col };

        if (value != 0) {
            text->Text = value.ToString();
            text->ReadOnly = true;
            text->Enabled = false;
            text->BackColor = BackColor.Lime;
            text->Click += gcnew EventHandler(this, &MainForm::LockedTextBox_Click);
        }

        parentTable->Controls->Add(text, col % 3, row % 3);
    }
    void MainForm::printBoard(array<int, 2>^ b) {
        
    }
    void MainForm::TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
    {
        if (!Char::IsDigit(e->KeyChar) || e->KeyChar == '0') {
            if (e->KeyChar != (char)Keys::Back) {
                e->Handled = true;
                return;
            }
        }
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);

        if (textBox != nullptr && e->KeyChar != (char)Keys::Back) {
        
            int value = e->KeyChar - '0'; 
            array<int>^ coordinates = dynamic_cast<array<int>^>(textBox->Tag);

            if (coordinates != nullptr) {
                int row = coordinates[0];
                int col = coordinates[1];
                generator->board[row, col] = value;
                int valueCheck = generator->copy_board[row, col];
                if (value == valueCheck) {
                    textBox->BackColor = BackColor.Yellow;
                    textBox->Enabled = false;
                    generator->copy_board[row, col] = 0;
                    return;
                }
            }
        }
    }

    void MainForm::LockedTextBox_Click(Object^ sender, EventArgs^ e)
    {

        MessageBox::Show("To pole jest zablokowane!", "Informacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }


}
