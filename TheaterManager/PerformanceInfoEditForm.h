#pragma once

#include "PerformanceInfo.h"

namespace TheaterManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PerformanceInfoEditForm
	/// </summary>
	public ref class PerformanceInfoEditForm : public System::Windows::Forms::Form
	{
	private:
		PerformanceInfo ^ pi;

	public:
		PerformanceInfoEditForm(PerformanceInfo ^ pi, bool isAdd)
		{
			this->pi = pi;

			InitializeComponent();

			if (isAdd)
			{
				buttonConfirm->Text = "Создать";
				Text = "Новый спектакль";
			}
			else
			{
				buttonConfirm->Text = "Сохранить";
				Text = "Редактирование спектакля";

				textBoxName->Text = pi->Name;
				comboBoxAge->SelectedIndex = (int)pi->Age;
				richTextBoxInfo->Text = pi->Info;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PerformanceInfoEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxName;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBoxInfo;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonConfirm;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxAge;

	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBoxInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxAge = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(10, 29);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(259, 20);
			this->textBoxName->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(123, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Афиша";
			// 
			// richTextBoxInfo
			// 
			this->richTextBoxInfo->Location = System::Drawing::Point(13, 130);
			this->richTextBoxInfo->Name = L"richTextBoxInfo";
			this->richTextBoxInfo->Size = System::Drawing::Size(259, 168);
			this->richTextBoxInfo->TabIndex = 3;
			this->richTextBoxInfo->Text = L"";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonConfirm);
			this->panel1->Controls->Add(this->buttonCancel);
			this->panel1->Location = System::Drawing::Point(13, 304);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(259, 35);
			this->panel1->TabIndex = 4;
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonConfirm->Location = System::Drawing::Point(181, 3);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(75, 29);
			this->buttonConfirm->TabIndex = 0;
			this->buttonConfirm->Text = L"Сохранить";
			this->buttonConfirm->UseVisualStyleBackColor = true;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &PerformanceInfoEditForm::buttonConfirm_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(3, 3);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 29);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Отмена";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(76, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Возрастное ограничение";
			// 
			// comboBoxAge
			// 
			this->comboBoxAge->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAge->FormattingEnabled = true;
			this->comboBoxAge->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Детский", L"Взрослый" });
			this->comboBoxAge->Location = System::Drawing::Point(79, 78);
			this->comboBoxAge->Name = L"comboBoxAge";
			this->comboBoxAge->Size = System::Drawing::Size(121, 21);
			this->comboBoxAge->TabIndex = 6;
			// 
			// PerformanceInfoEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 348);
			this->Controls->Add(this->comboBoxAge);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->richTextBoxInfo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label1);
			this->Name = L"PerformanceInfoEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Редактирование спектакля";
			this->Load += gcnew System::EventHandler(this, &PerformanceInfoEditForm::PerformanceInfoEditForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonConfirm_Click(System::Object^  sender, System::EventArgs^  e) {
		pi->Name = textBoxName->Text;
		pi->Age = (Ages) comboBoxAge->SelectedIndex;
		pi->Info = richTextBoxInfo->Text;
	}
private: System::Void PerformanceInfoEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
