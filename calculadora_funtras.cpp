#include "calculadora_funtras.h"

using namespace System;
using namespace System :: Windows :: Forms;
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Calculadora::calculadora_funtras form;
	Application::Run(% form);
}
