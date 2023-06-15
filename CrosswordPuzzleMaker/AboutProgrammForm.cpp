#include "AboutProgrammForm.h"


System::Void CrosswordPuzzleMaker::AboutProgrammForm::githubUrl_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	System::Diagnostics::Process::Start(githubUrl->Text);
}


System::Void CrosswordPuzzleMaker::AboutProgrammForm::exitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
