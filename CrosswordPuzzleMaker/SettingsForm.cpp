#include "SettingsForm.h"

System::Void CrosswordPuzzleMaker::SettingsForm::buttonBackColor_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::ColorDialog^ cd 
		= gcnew System::Windows::Forms::ColorDialog();
	if (cd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		for each (System::Windows::Forms::Form ^ form 
				  in System::Windows::Forms::Application::OpenForms)
		{
			form->BackColor = cd->Color;
		}
	}
}

System::Void CrosswordPuzzleMaker::SettingsForm::buttonTextColor_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::ColorDialog^ cd 
		= gcnew System::Windows::Forms::ColorDialog();
	if (cd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		for each (System::Windows::Forms::Form ^ form 
				  in System::Windows::Forms::Application::OpenForms)
		{
			form->ForeColor = cd->Color;
		}
	}
}

System::Void CrosswordPuzzleMaker::SettingsForm::SettingsForm_Load(
	System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
	timer->Interval = 500;
	timer->Tick += gcnew System::EventHandler(this, &SettingsForm::timer_Tick);
	timer->Start();
}

System::Void CrosswordPuzzleMaker::SettingsForm::timer_Tick(
	System::Object^ sender, System::EventArgs^ e)
{
	float cpuUsage = cpuCounter->NextValue(), availableMemory = memCounter->NextValue();
	labelPerformance->Text = System::String::Format("CPU Usage: {0:F2}%", cpuUsage)
		+ "\n" + System::String::Format("Available memory: {0:F2} MB", availableMemory);
}