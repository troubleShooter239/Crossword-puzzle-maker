#include "SettingsForm.h"


System::Void CrosswordPuzzleMaker::SettingsForm::buttonBackColor_Click(System::Object^ sender, System::EventArgs^ e)
{
	ColorDialog^ cd = gcnew ColorDialog();

	if (cd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		for each (Form ^ form in Application::OpenForms)
		{
			form->BackColor = cd->Color;
		}
	}
}


System::Void CrosswordPuzzleMaker::SettingsForm::buttonTextColor_Click(System::Object^ sender, System::EventArgs^ e)
{
	ColorDialog^ cd = gcnew ColorDialog();

	if (cd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		for each (Form ^ form in Application::OpenForms)
		{
			form->ForeColor = cd->Color;
		}
	}
}


System::Void CrosswordPuzzleMaker::SettingsForm::SettingsForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	Timer^ timer = gcnew Timer();
	timer->Interval = 500;
	timer->Tick += gcnew EventHandler(this, &SettingsForm::timer_Tick);

	timer->Start();
}


System::Void CrosswordPuzzleMaker::SettingsForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	float cpuUsage = cpuCounter->NextValue(), availableMemory = memCounter->NextValue();

	labelPerformance->Text = String::Format("CPU Usage: {0:F2}%", cpuUsage)
		+ "\n" + String::Format("Available memory: {0:F2} MB", availableMemory);
}