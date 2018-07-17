#pragma once

#include "PerformanceCollection.h"

namespace TheaterManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ReportForm
	/// </summary>
	public ref class ReportForm : public System::Windows::Forms::Form
	{
	private:
		ReportCollection ^ rc;
	public:
		ReportForm(ReportCollection ^ rc)
		{
			this->rc = rc;

			InitializeComponent();

			rc->SortByProfit();
			rc->View(dataGridView1);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonPopularity;
	private: System::Windows::Forms::Button^  buttonProfit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Спектакль;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonPopularity = (gcnew System::Windows::Forms::Button());
			this->buttonProfit = (gcnew System::Windows::Forms::Button());
			this->Спектакль = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Спектакль,
					this->Column3, this->Column1, this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 48);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(544, 264);
			this->dataGridView1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Сортировать по:";
			// 
			// buttonPopularity
			// 
			this->buttonPopularity->Location = System::Drawing::Point(127, 8);
			this->buttonPopularity->Name = L"buttonPopularity";
			this->buttonPopularity->Size = System::Drawing::Size(99, 23);
			this->buttonPopularity->TabIndex = 2;
			this->buttonPopularity->Text = L"Популярности";
			this->buttonPopularity->UseVisualStyleBackColor = true;
			this->buttonPopularity->Click += gcnew System::EventHandler(this, &ReportForm::buttonPopularity_Click);
			// 
			// buttonProfit
			// 
			this->buttonProfit->Location = System::Drawing::Point(232, 8);
			this->buttonProfit->Name = L"buttonProfit";
			this->buttonProfit->Size = System::Drawing::Size(75, 23);
			this->buttonProfit->TabIndex = 3;
			this->buttonProfit->Text = L"Доходу";
			this->buttonProfit->UseVisualStyleBackColor = true;
			this->buttonProfit->Click += gcnew System::EventHandler(this, &ReportForm::buttonProfit_Click);
			// 
			// Спектакль
			// 
			this->Спектакль->HeaderText = L"Название";
			this->Спектакль->Name = L"Спектакль";
			this->Спектакль->Width = 200;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Спектаклей";
			this->Column3->Name = L"Column3";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Билетов";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Доход";
			this->Column2->Name = L"Column2";
			// 
			// ReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(575, 324);
			this->Controls->Add(this->buttonProfit);
			this->Controls->Add(this->buttonPopularity);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"ReportForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Отчет";
			this->Load += gcnew System::EventHandler(this, &ReportForm::ReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ReportForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void buttonPopularity_Click(System::Object^  sender, System::EventArgs^  e) {
	rc->SortByPopularity();
	rc->View(dataGridView1);
}
private: System::Void buttonProfit_Click(System::Object^  sender, System::EventArgs^  e) {
	rc->SortByProfit();
	rc->View(dataGridView1);
}
};
}
