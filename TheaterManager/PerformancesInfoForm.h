#pragma once

#include "Performances.h"
#include "PerformanceInfoEditForm.h"

namespace TheaterManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� PerformancesInfoForm
	/// </summary>
	public ref class PerformancesInfoForm : public System::Windows::Forms::Form
	{
	private:
		List<PerformanceInfo^> ^ performancesInfo;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;

		PerformanceInfo ^ selectPerformance;

		property PerformanceInfo ^ SelectPerformance {
			void set(PerformanceInfo ^ selectPerformance)
			{
				this->selectPerformance = selectPerformance;

				if (selectPerformance == nullptr)
				{
					textBoxName->Text = "";
					labelAge->Text = "�������: ";
					richTextBoxInfo->Text = "";

					�������������ToolStripMenuItem->Enabled = false;
					�������ToolStripMenuItem->Enabled = false;
				}
				else
				{
					textBoxName->Text = selectPerformance->Name;
					labelAge->Text = "�������: " + (selectPerformance->Age == Ages::CHILD ? "�������" : "��������");
					richTextBoxInfo->Text = selectPerformance->Info;

					�������������ToolStripMenuItem->Enabled = true;
					�������ToolStripMenuItem->Enabled = true;
				}
			}
			PerformanceInfo ^ get()
			{
				return selectPerformance;
			}
		}

	public:
		PerformancesInfoForm(List<PerformanceInfo^> ^ performancesInfo)
		{
			this->performancesInfo = performancesInfo;

			InitializeComponent();

			ViewItems();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~PerformancesInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBoxItems;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxName;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBoxInfo;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::Label^  labelAge;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBoxItems = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBoxInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelAge = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listBoxItems
			// 
			this->listBoxItems->FormattingEnabled = true;
			this->listBoxItems->Location = System::Drawing::Point(12, 32);
			this->listBoxItems->Name = L"listBoxItems";
			this->listBoxItems->Size = System::Drawing::Size(243, 238);
			this->listBoxItems->TabIndex = 0;
			this->listBoxItems->SelectedIndexChanged += gcnew System::EventHandler(this, &PerformancesInfoForm::listBoxItems_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(288, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"��������";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(276, 49);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(307, 20);
			this->textBoxName->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(288, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"�����";
			// 
			// richTextBoxInfo
			// 
			this->richTextBoxInfo->Location = System::Drawing::Point(276, 130);
			this->richTextBoxInfo->Name = L"richTextBoxInfo";
			this->richTextBoxInfo->Size = System::Drawing::Size(307, 138);
			this->richTextBoxInfo->TabIndex = 4;
			this->richTextBoxInfo->Text = L"";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�����ToolStripMenuItem,
					this->�������������ToolStripMenuItem, this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(596, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &PerformancesInfoForm::�����ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->�������������ToolStripMenuItem->Text = L"�������������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &PerformancesInfoForm::�������������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &PerformancesInfoForm::�������ToolStripMenuItem_Click);
			// 
			// labelAge
			// 
			this->labelAge->AutoSize = true;
			this->labelAge->Location = System::Drawing::Point(288, 83);
			this->labelAge->Name = L"labelAge";
			this->labelAge->Size = System::Drawing::Size(52, 13);
			this->labelAge->TabIndex = 6;
			this->labelAge->Text = L"�������:";
			// 
			// PerformancesInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 282);
			this->Controls->Add(this->labelAge);
			this->Controls->Add(this->richTextBoxInfo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBoxItems);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PerformancesInfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������������� ����������";
			this->Load += gcnew System::EventHandler(this, &PerformancesInfoForm::PerformancesInfoForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void ViewItems()
		{
			SelectPerformance = nullptr;

			listBoxItems->Items->Clear();

			for each (PerformanceInfo ^ perf in performancesInfo)
			{
				listBoxItems->Items->Add(perf->Name);
			}
		}
	private: System::Void PerformancesInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	PerformanceInfo ^ pi = gcnew PerformanceInfo();
	PerformanceInfoEditForm ^ pief = gcnew PerformanceInfoEditForm(pi, true);
	if (pief->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		performancesInfo->Add(pi);
		ViewItems();
	}
}
private: System::Void listBoxItems_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (listBoxItems->SelectedIndex == -1)
		return;

	SelectPerformance = performancesInfo[listBoxItems->SelectedIndex];
}
private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("������� ��������� \"" + selectPerformance->Name + "\"?", "������� ���������?", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == Windows::Forms::DialogResult::OK)
	{
		performancesInfo->Remove(selectPerformance);
		ViewItems();
	}
}
private: System::Void �������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	PerformanceInfoEditForm ^ pief = gcnew PerformanceInfoEditForm(selectPerformance, false);
	if (pief->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		ViewItems();
	}
}
};
}
