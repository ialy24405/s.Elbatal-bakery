#include "Register.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace test;
[STAThreadAttribute]
void main2(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	test::Register form;
	Application::Run(%form);
}
