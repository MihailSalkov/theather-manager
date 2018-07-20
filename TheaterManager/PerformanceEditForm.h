#pragma once

#include "Performance.h"
#include "PerformanceInfo.h"

namespace TheaterManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PerformanceEditForm
	/// </summary>
	public ref class PerformanceEditForm : public System::Windows::Forms::Form
	{
	private:
		Performance ^ p;
	private: System::Windows::Forms::Label^  labelSoldTickets;

	private: System::Windows::Forms::TextBox^  textBoxSoldTickets;
			 List<PerformanceInfo^> ^ itemsInfo;

	public:
		PerformanceEditForm(Performance ^ p, List<PerformanceInfo^> ^ itemsInfo, bool isAdd)
		{
			this->p = p;
			this->itemsInfo = itemsInfo;

			InitializeComponent();

			for each (PerformanceInfo ^ pi in itemsInfo)
			{
				comboBoxPerformanceInfo->Items->Add(pi->Name);
			}

			if (isAdd)
			{
				buttonConfirm->Text = "Создать";
				Text = "Новое событие";

				labelSoldTickets->Hide();
				textBoxSoldTickets->Hide();
			}
			else
			{
				buttonConfirm->Text = "Сохранить";
				Text = "Редактирование события";

				comboBoxPerformanceInfo->SelectedIndex = itemsInfo->IndexOf(p->Info);
				dateTimePicker1->Value = p->Date;
				textBoxSoldTickets->Text = p->SoldTickets.ToString();
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PerformanceEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBoxPerformanceInfo;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonConfirm;

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
			this->comboBoxPerformanceInfo = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->labelSoldTickets = (gcnew System::Windows::Forms::Label());
			this->textBoxSoldTickets = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// comboBoxPerformanceInfo
			// 
			this->comboBoxPerformanceInfo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxPerformanceInfo->FormattingEnabled = true;
			this->comboBoxPerformanceInfo->Location = System::Drawing::Point(29, 35);
			this->comboBoxPerformanceInfo->Name = L"comboBoxPerformanceInfo";
			this->comboBoxPerformanceInfo->Size = System::Drawing::Size(220, 21);
			this->comboBoxPerformanceInfo->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(106, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Спектакль";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"dd MMM yyyy г. HH:mm";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(68, 108);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(143, 20);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(116, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Дата";
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(29, 206);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 29);
			this->buttonCancel->TabIndex = 3;
			this->buttonCancel->Text = L"Отмена";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->Location = System::Drawing::Point(174, 206);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(75, 29);
			this->buttonConfirm->TabIndex = 3;
			this->buttonConfirm->Text = L"Создать";
			this->buttonConfirm->UseVisualStyleBackColor = true;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &PerformanceEditForm::buttonConfirm_Click);
			// 
			// labelSoldTickets
			// 
			this->labelSoldTickets->AutoSize = true;
			this->labelSoldTickets->Location = System::Drawing::Point(86, 151);
			this->labelSoldTickets->Name = L"labelSoldTickets";
			this->labelSoldTickets->Size = System::Drawing::Size(95, 13);
			this->labelSoldTickets->TabIndex = 4;
			this->labelSoldTickets->Text = L"Продано билетов";
			// 
			// textBoxSoldTickets
			// 
			this->textBoxSoldTickets->Location = System::Drawing::Point(82, 173);
			this->textBoxSoldTickets->Name = L"textBoxSoldTickets";
			this->textBoxSoldTickets->Size = System::Drawing::Size(100, 20);
			this->textBoxSoldTickets->TabIndex = 5;
			this->textBoxSoldTickets->Text = L"0";
			// 
			// PerformanceEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 247);
			this->Controls->Add(this->textBoxSoldTickets);
			this->Controls->Add(this->labelSoldTickets);
			this->Controls->Add(this->buttonConfirm);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxPerformanceInfo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"PerformanceEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Новое событие";
			this->Load += gcnew System::EventHandler(this, &PerformanceEditForm::PerformanceEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PerformanceEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void buttonConfirm_Click(System::Object^  sender, System::EventArgs^  e) {
	List<String^> ^ errors = gcnew List<String^>();

	if (comboBoxPerformanceInfo->SelectedIndex == -1)
		errors->Add("Не выбран спектакль");
	int tickets = -1;
	if (!p->SoldTickets.TryParse(textBoxSoldTickets->Text, tickets) || tickets < 0)
		errors->Add("Некорректная стоимость");

	if (errors->Count > 0)
	{
		MessageBox::Show(String::Join("\n", errors), "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	p->Info = itemsInfo[comboBoxPerformanceInfo->SelectedIndex];
	p->Date = dateTimePicker1->Value;
	p->SoldTickets = tickets;

	DialogResult = Windows::Forms::DialogResult::OK;
}
};
}
