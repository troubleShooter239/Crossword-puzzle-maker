#include "AboutProgramForm.h"

System::Void CrosswordPuzzleMaker::AboutProgramForm::githubUrl_LinkClicked(
	System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	System::Diagnostics::Process::Start(githubURL->Text);
}