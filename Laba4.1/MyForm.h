#pragma once
#include "List.h"
#include "Circle.h"

namespace Laba41 { 

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(653, 432);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 456);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
		 List<Circle> lst;
		 bool ctrl = false;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		for (int i = 0; i < lst.GetSize(); i++)
			lst[i].draw(e);
	}
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		bool collision = false;
		Circle a;
		for (int i = lst.GetSize()-1; i >= 0; i--) {
			if (lst[i].checkCollision(e->X, e->Y)) {
				if (!ctrl && lst[i].GetSelect()) {
					for (int i = 0; i < lst.GetSize(); i++)
						lst[i].SetSelect(false);
					collision = true;
					//break;
				}
				else if (!ctrl) {		
					for (int i = 0; i < lst.GetSize(); i++)
						lst[i].SetSelect(false);
					lst[i].SetSelect();
					lst.push_back(lst[i]);
					lst.removeAt(i);
					collision = true;
					//break;
				}
				if (ctrl) {
					collision = true;
					a = lst[i];
					if (lst[i].GetSelect()) {
						lst[i].SetSelect(false);
					}
					else lst[i].SetSelect();
				}
				break;
			}
		}
		if (!collision) {
			for(int i = 0; i< lst.GetSize(); i++)
			    lst[i].SetSelect(false);
			Circle a(e->X, e->Y, 100);
			lst.push_back(a);
		}
		
		panel1->Invalidate();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == 46) {
			for (int i = 0; i < lst.GetSize();) {
				if (lst[i].GetSelect()) {
					lst.removeAt(i);
				}
				else {
					i++;
				}
			}
			panel1->Invalidate();
		}
		else if (e->KeyValue == 17) {
			ctrl = true;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == 17) {
			ctrl = false;
		}
	}
};
}