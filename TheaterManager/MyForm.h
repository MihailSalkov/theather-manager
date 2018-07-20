#pragma once

#include "Performances.h"
#include "PerformancesInfoForm.h"
#include "PerformanceEditForm.h"
#include "ReportForm.h"

namespace TheaterManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Performances ^ performances;
		Performance ^ selectPerformance;



			 PerformanceCollection ^ currentPerformances;

		property DateTime CurrentMonth {
			DateTime get() {
				return performances->CurrentMonth;
			}
			void set(DateTime currentMonth) {
				performances->CurrentMonth = currentMonth;

				ViewPerformances();
			}
		}

		property Performance ^ SelectPerformance {
			void set(Performance ^ selectPerformance)
			{
				this->selectPerformance = selectPerformance;

				if (selectPerformance == nullptr)
				{
					редактироватьToolStripMenuItem->Enabled = false;
					удалитьToolStripMenuItem->Enabled = false;
				}
				else
				{
					редактироватьToolStripMenuItem->Enabled = true;
					удалитьToolStripMenuItem->Enabled = true;
				}
			}
			Performance ^ get()
			{
				return selectPerformance;
			}
		}

		void ViewPerformances()
		{
			SelectPerformance = nullptr;

			currentPerformances = performances->getByCurrentMonth();
			currentPerformances->View(listBoxPerformances);

			labelSoldTickets->Text = "Продано билетов: " + currentPerformances->SoldTickets();
			labelProfit->Text = "Доход: " + currentPerformances->Profit() + " руб.";

			panelNeedWrite->Visible = currentPerformances->getNeedData()->Items->Count > 0;
		}
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			performances = gcnew Performances("performances.db", DateTime::Today);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  спектаклиToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerCurrent;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBoxPerformances;
	private: System::Windows::Forms::ToolStripMenuItem^  добавитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  редактироватьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  удалитьToolStripMenuItem;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelSoldTickets;
	private: System::Windows::Forms::Label^  labelProfit;
	private: System::Windows::Forms::Panel^  panelNeedWrite;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  buttonBeginWrite;
	private: System::Windows::Forms::Button^  buttonReport;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->спектаклиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->редактироватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerCurrent = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBoxPerformances = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelSoldTickets = (gcnew System::Windows::Forms::Label());
			this->labelProfit = (gcnew System::Windows::Forms::Label());
			this->panelNeedWrite = (gcnew System::Windows::Forms::Panel());
			this->buttonBeginWrite = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonReport = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->panelNeedWrite->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->спектаклиToolStripMenuItem,
					this->добавитьToolStripMenuItem, this->редактироватьToolStripMenuItem, this->удалитьToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(509, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// спектаклиToolStripMenuItem
			// 
			this->спектаклиToolStripMenuItem->Name = L"спектаклиToolStripMenuItem";
			this->спектаклиToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->спектаклиToolStripMenuItem->Text = L"Спектакли";
			this->спектаклиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::спектаклиToolStripMenuItem_Click);
			// 
			// добавитьToolStripMenuItem
			// 
			this->добавитьToolStripMenuItem->Name = L"добавитьToolStripMenuItem";
			this->добавитьToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->добавитьToolStripMenuItem->Text = L"Добавить";
			this->добавитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::добавитьToolStripMenuItem_Click);
			// 
			// редактироватьToolStripMenuItem
			// 
			this->редактироватьToolStripMenuItem->Name = L"редактироватьToolStripMenuItem";
			this->редактироватьToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->редактироватьToolStripMenuItem->Text = L"Редактировать";
			this->редактироватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::редактироватьToolStripMenuItem_Click);
			// 
			// удалитьToolStripMenuItem
			// 
			this->удалитьToolStripMenuItem->Name = L"удалитьToolStripMenuItem";
			this->удалитьToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->удалитьToolStripMenuItem->Text = L"Удалить";
			this->удалитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::удалитьToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(133, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Программа";
			// 
			// dateTimePickerCurrent
			// 
			this->dateTimePickerCurrent->CustomFormat = L"   MMM yyyy";
			this->dateTimePickerCurrent->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerCurrent->Location = System::Drawing::Point(406, 2);
			this->dateTimePickerCurrent->Name = L"dateTimePickerCurrent";
			this->dateTimePickerCurrent->Size = System::Drawing::Size(94, 20);
			this->dateTimePickerCurrent->TabIndex = 2;
			this->dateTimePickerCurrent->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePickerCurrent_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->label2->Location = System::Drawing::Point(360, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Месяц:";
			// 
			// listBoxPerformances
			// 
			this->listBoxPerformances->FormattingEnabled = true;
			this->listBoxPerformances->Location = System::Drawing::Point(11, 57);
			this->listBoxPerformances->Name = L"listBoxPerformances";
			this->listBoxPerformances->Size = System::Drawing::Size(306, 264);
			this->listBoxPerformances->TabIndex = 4;
			this->listBoxPerformances->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBoxPerformances_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(354, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Статистика за месяц";
			// 
			// labelSoldTickets
			// 
			this->labelSoldTickets->Location = System::Drawing::Point(326, 61);
			this->labelSoldTickets->Name = L"labelSoldTickets";
			this->labelSoldTickets->Size = System::Drawing::Size(174, 18);
			this->labelSoldTickets->TabIndex = 6;
			this->labelSoldTickets->Text = L"Продано билетов: 0";
			this->labelSoldTickets->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelProfit
			// 
			this->labelProfit->Location = System::Drawing::Point(323, 88);
			this->labelProfit->Name = L"labelProfit";
			this->labelProfit->Size = System::Drawing::Size(177, 20);
			this->labelProfit->TabIndex = 7;
			this->labelProfit->Text = L"Прибыль: 0 руб.";
			this->labelProfit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelNeedWrite
			// 
			this->panelNeedWrite->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panelNeedWrite->Controls->Add(this->buttonBeginWrite);
			this->panelNeedWrite->Controls->Add(this->label4);
			this->panelNeedWrite->Location = System::Drawing::Point(323, 153);
			this->panelNeedWrite->Name = L"panelNeedWrite";
			this->panelNeedWrite->Size = System::Drawing::Size(177, 100);
			this->panelNeedWrite->TabIndex = 8;
			// 
			// buttonBeginWrite
			// 
			this->buttonBeginWrite->Location = System::Drawing::Point(44, 58);
			this->buttonBeginWrite->Name = L"buttonBeginWrite";
			this->buttonBeginWrite->Size = System::Drawing::Size(85, 30);
			this->buttonBeginWrite->TabIndex = 1;
			this->buttonBeginWrite->Text = L"Заполнить";
			this->buttonBeginWrite->UseVisualStyleBackColor = true;
			this->buttonBeginWrite->Click += gcnew System::EventHandler(this, &MyForm::buttonBeginWrite_Click);
			// 
			// label4
			// 
			this->label4->ForeColor = System::Drawing::Color::DarkRed;
			this->label4->Location = System::Drawing::Point(12, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 32);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Необходимо внести данные о продаже билетов!";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonReport
			// 
			this->buttonReport->Location = System::Drawing::Point(347, 275);
			this->buttonReport->Name = L"buttonReport";
			this->buttonReport->Size = System::Drawing::Size(128, 32);
			this->buttonReport->TabIndex = 9;
			this->buttonReport->Text = L"Сформировать отчет";
			this->buttonReport->UseVisualStyleBackColor = true;
			this->buttonReport->Click += gcnew System::EventHandler(this, &MyForm::buttonReport_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 331);
			this->Controls->Add(this->buttonReport);
			this->Controls->Add(this->panelNeedWrite);
			this->Controls->Add(this->labelProfit);
			this->Controls->Add(this->labelSoldTickets);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBoxPerformances);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateTimePickerCurrent);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Theather Manager";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panelNeedWrite->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void спектаклиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		(gcnew PerformancesInfoForm(performances->ItemsInfo))->ShowDialog();
		performances->Save();
		ViewPerformances();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		ViewPerformances();
	}
private: System::Void добавитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Performance ^ p = gcnew Performance();

	if ((gcnew PerformanceEditForm(p, performances->ItemsInfo, true))->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		performances->AddPerformance(p);
		ViewPerformances();
	}
}
private: System::Void удалитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Удалить событие \"" + selectPerformance->ShortName + "\"?", "Удалить событие?",
			MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == Windows::Forms::DialogResult::OK)
	{
		performances->RemovePerformance(selectPerformance);
		ViewPerformances();
	}
}
private: System::Void редактироватьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((gcnew PerformanceEditForm(selectPerformance, performances->ItemsInfo, false))->ShowDialog()
			== Windows::Forms::DialogResult::OK)
	{
		performances->Save();
		ViewPerformances();
	}
}
private: System::Void dateTimePickerCurrent_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	CurrentMonth = dateTimePickerCurrent->Value;
}
private: System::Void listBoxPerformances_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	SelectPerformance = listBoxPerformances->SelectedIndex == -1
		? nullptr : currentPerformances->Items[listBoxPerformances->SelectedIndex];
}
private: System::Void buttonBeginWrite_Click(System::Object^  sender, System::EventArgs^  e) {
	for each (Performance ^ p in currentPerformances->getNeedData()->Items)
	{
		while (1)
		{
			(gcnew PerformanceEditForm(p, performances->ItemsInfo, false))->ShowDialog();

			if (p->IsNeedData() &&
				MessageBox::Show("Ввести снова?", "Ошибка", MessageBoxButtons::RetryCancel, MessageBoxIcon::Warning)
						== Windows::Forms::DialogResult::Retry)
				continue;

			break;
		}
	}

	performances->Save();
	ViewPerformances();
}
private: System::Void buttonReport_Click(System::Object^  sender, System::EventArgs^  e) {
	(gcnew ReportForm(currentPerformances->getReport()))->ShowDialog();
}
};
}
