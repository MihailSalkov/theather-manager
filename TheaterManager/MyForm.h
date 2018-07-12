#pragma once

#include "Performances.h"
#include "PerformancesInfoForm.h"

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
	private: System::Windows::Forms::ToolStripMenuItem^  добавитьToolStripMenuItem;
			 PerformanceCollection ^ currentPerformances;

		void ViewPerformances()
		{
			currentPerformances = performances->getByCurrentMonth();

			listBoxPerformances->Items->Clear();

			for each (Performance ^ perf in currentPerformances->Items)
			{
				listBoxPerformances->Items->Add(perf->Date.ToString() + " " + perf->Info->Name);
			}
		}
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			performances = gcnew Performances("performances.db", DateTime(DateTime::Today.Year, DateTime::Today.Month, 1));
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerCurrent = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBoxPerformances = (gcnew System::Windows::Forms::ListBox());
			this->добавитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->спектаклиToolStripMenuItem,
					this->добавитьToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(682, 24);
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
			this->dateTimePickerCurrent->Location = System::Drawing::Point(566, 2);
			this->dateTimePickerCurrent->Name = L"dateTimePickerCurrent";
			this->dateTimePickerCurrent->Size = System::Drawing::Size(114, 20);
			this->dateTimePickerCurrent->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->label2->Location = System::Drawing::Point(520, 6);
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
			// 
			// добавитьToolStripMenuItem
			// 
			this->добавитьToolStripMenuItem->Name = L"добавитьToolStripMenuItem";
			this->добавитьToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->добавитьToolStripMenuItem->Text = L"Добавить";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 331);
			this->Controls->Add(this->listBoxPerformances);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateTimePickerCurrent);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Theather Manager";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void спектаклиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		PerformancesInfoForm ^ pif = gcnew PerformancesInfoForm(performances->ItemsInfo);
		pif->ShowDialog();
		performances->Save();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		ViewPerformances();
	}
};
}
