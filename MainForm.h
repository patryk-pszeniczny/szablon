#pragma once
#include "SudokuGenerate.h"
namespace szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		array<TableLayoutPanel^>^ listOfTab = gcnew array<TableLayoutPanel^>(9);
	private: System::Windows::Forms::Button^ button2;
	public:
		Random^ rand;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	public:

	public:
		SudokuGenerate^ generator;
		MainForm(void);
	private:
		void printBoard(array<int, 2>^ b);
		void TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e);
		void LockedTextBox_Click(Object^ sender, EventArgs^ e);

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TableLayoutPanel^ table;
	private: System::Windows::Forms::TableLayoutPanel^ table_2_2;
	private: System::Windows::Forms::TableLayoutPanel^ table_2_1;
	private: System::Windows::Forms::TableLayoutPanel^ table_2_0;
	private: System::Windows::Forms::TableLayoutPanel^ table_1_2;
	private: System::Windows::Forms::TableLayoutPanel^ table_1_1;
	private: System::Windows::Forms::TableLayoutPanel^ table_1_0;
	private: System::Windows::Forms::TableLayoutPanel^ table_0_2;
	private: System::Windows::Forms::TableLayoutPanel^ table_0_1;
	private: System::Windows::Forms::TableLayoutPanel^ table_0_0;

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->table = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_2_2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_2_1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_2_0 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_1_2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_1_1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_1_0 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_0_2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_0_1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_0_0 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->table->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(479, 26);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(262, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Zamknij";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// table
			// 
			this->table->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->table->ColumnCount = 3;
			this->table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->Controls->Add(this->table_2_2, 2, 2);
			this->table->Controls->Add(this->table_2_1, 1, 2);
			this->table->Controls->Add(this->table_2_0, 0, 2);
			this->table->Controls->Add(this->table_1_2, 2, 1);
			this->table->Controls->Add(this->table_1_1, 1, 1);
			this->table->Controls->Add(this->table_1_0, 0, 1);
			this->table->Controls->Add(this->table_0_2, 2, 0);
			this->table->Controls->Add(this->table_0_1, 1, 0);
			this->table->Controls->Add(this->table_0_0, 0, 0);
			this->table->Location = System::Drawing::Point(59, 26);
			this->table->Margin = System::Windows::Forms::Padding(0);
			this->table->Name = L"table";
			this->table->RowCount = 3;
			this->table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->Size = System::Drawing::Size(385, 417);
			this->table->TabIndex = 3;
			// 
			// table_2_2
			// 
			this->table_2_2->ColumnCount = 3;
			this->table_2_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_2_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_2->Location = System::Drawing::Point(258, 280);
			this->table_2_2->Margin = System::Windows::Forms::Padding(2);
			this->table_2_2->Name = L"table_2_2";
			this->table_2_2->RowCount = 3;
			this->table_2_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_2->Size = System::Drawing::Size(122, 132);
			this->table_2_2->TabIndex = 8;
			// 
			// table_2_1
			// 
			this->table_2_1->ColumnCount = 3;
			this->table_2_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_2_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_1->Location = System::Drawing::Point(131, 280);
			this->table_2_1->Margin = System::Windows::Forms::Padding(2);
			this->table_2_1->Name = L"table_2_1";
			this->table_2_1->RowCount = 3;
			this->table_2_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_1->Size = System::Drawing::Size(121, 132);
			this->table_2_1->TabIndex = 7;
			// 
			// table_2_0
			// 
			this->table_2_0->ColumnCount = 3;
			this->table_2_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_2_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_0->Location = System::Drawing::Point(4, 280);
			this->table_2_0->Margin = System::Windows::Forms::Padding(2);
			this->table_2_0->Name = L"table_2_0";
			this->table_2_0->RowCount = 3;
			this->table_2_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_0->Size = System::Drawing::Size(121, 132);
			this->table_2_0->TabIndex = 6;
			// 
			// table_1_2
			// 
			this->table_1_2->ColumnCount = 3;
			this->table_1_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_1_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_2->Location = System::Drawing::Point(258, 142);
			this->table_1_2->Margin = System::Windows::Forms::Padding(2);
			this->table_1_2->Name = L"table_1_2";
			this->table_1_2->RowCount = 3;
			this->table_1_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_2->Size = System::Drawing::Size(122, 132);
			this->table_1_2->TabIndex = 5;
			// 
			// table_1_1
			// 
			this->table_1_1->ColumnCount = 3;
			this->table_1_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_1_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_1->Location = System::Drawing::Point(131, 142);
			this->table_1_1->Margin = System::Windows::Forms::Padding(2);
			this->table_1_1->Name = L"table_1_1";
			this->table_1_1->RowCount = 3;
			this->table_1_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_1->Size = System::Drawing::Size(121, 132);
			this->table_1_1->TabIndex = 4;
			// 
			// table_1_0
			// 
			this->table_1_0->ColumnCount = 3;
			this->table_1_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_1_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_0->Location = System::Drawing::Point(4, 142);
			this->table_1_0->Margin = System::Windows::Forms::Padding(2);
			this->table_1_0->Name = L"table_1_0";
			this->table_1_0->RowCount = 3;
			this->table_1_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_0->Size = System::Drawing::Size(121, 132);
			this->table_1_0->TabIndex = 3;
			// 
			// table_0_2
			// 
			this->table_0_2->ColumnCount = 3;
			this->table_0_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_0_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_2->Location = System::Drawing::Point(258, 4);
			this->table_0_2->Margin = System::Windows::Forms::Padding(2);
			this->table_0_2->Name = L"table_0_2";
			this->table_0_2->RowCount = 3;
			this->table_0_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_2->Size = System::Drawing::Size(122, 132);
			this->table_0_2->TabIndex = 2;
			// 
			// table_0_1
			// 
			this->table_0_1->ColumnCount = 3;
			this->table_0_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_0_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_1->Location = System::Drawing::Point(131, 4);
			this->table_0_1->Margin = System::Windows::Forms::Padding(2);
			this->table_0_1->Name = L"table_0_1";
			this->table_0_1->RowCount = 3;
			this->table_0_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_1->Size = System::Drawing::Size(121, 132);
			this->table_0_1->TabIndex = 1;
			// 
			// table_0_0
			// 
			this->table_0_0->ColumnCount = 3;
			this->table_0_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_0_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_0->Location = System::Drawing::Point(4, 4);
			this->table_0_0->Margin = System::Windows::Forms::Padding(2);
			this->table_0_0->Name = L"table_0_0";
			this->table_0_0->RowCount = 3;
			this->table_0_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_0->Size = System::Drawing::Size(121, 132);
			this->table_0_0->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(479, 79);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(262, 49);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Sprawdz";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(476, 212);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Rozwi¹zania:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(476, 244);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Try: ";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(479, 132);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(262, 49);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Pomoc";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(750, 488);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->table);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->table->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->generator->checkSudoku()) {
			MessageBox::Show("BRAWO", "Wygra³eœ talon :3");
		}
		else {
			MessageBox::Show("Next time braku", ":(");
		}

	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			TableLayoutPanel^ tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(j, i));
			for (int k = 0; k < 3; k++) {
				for (int p = 0; p < 3; p++) {
					int row = i * 3 + k;
					int col = j * 3 + p;
					int value = this->generator->copy_board[row, col];
					if (value != 0) {
						TextBox^ text1 = dynamic_cast<TextBox^>(tb->GetControlFromPosition(p, k));
						if (text1 != nullptr) {
							text1->BackColor = BackColor.Orange;
							text1->Text = value.ToString();
							text1->Enabled = false;
						}
						this->generator->board[row, col] = value;
						this->generator->copy_board[row, col] = 0;
						return;
					}
					}
				}
			}
		}
	}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	std::cout >> "Obecnie all œmiga :P" << endl;
}
};
}
