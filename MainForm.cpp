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
        generator->GenerateSudoku();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                TableLayoutPanel^ tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(j, i));
                for (int k = 0; k < 3; k++) {
                    for (int p = 0; p < 3; p++) {
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
                        int value = generator->board[i * 3 + k, j * 3 + p];
                        text->Name = L"text_" + (i * 3 + k) + "_" + (j * 3 + p);
                        int row = i * 3 + k;
                        int col = j * 3 + p;
                        text->Tag = gcnew array<int>{row, col};
                        if (value != 0) {
                            text->Text = value.ToString();
                            text->ReadOnly = true;
                            text->Enabled = false;
                            text->BackColor = BackColor.Lime;
                            text->Click += gcnew EventHandler(this, &MainForm::LockedTextBox_Click);
                        }

                        tb->Controls->Add(text, p, k);
                    }
                }
            }
        }
        label1->Text += generator->numberOfSolution;
        label2->Text += generator->tryGen;

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

        // Po zatwierdzeniu cyfry aktualizujemy wartoœæ w board
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
