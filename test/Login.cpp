#include "Login.h"
using namespace test;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	test::Login form;
	Application::Run(%form);
}
