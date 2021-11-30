#include "MyForm.h"
#include "List.h"
#include "Circle.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Laba41::MyForm form;
	Application::Run(% form);
}
