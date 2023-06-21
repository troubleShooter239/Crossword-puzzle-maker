#include "AboutProgrammForm.h"

System::Void CrosswordPuzzleMaker::AboutProgrammForm::githubUrl_LinkClicked(
	System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	System::Diagnostics::Process::Start(githubURL->Text);
}