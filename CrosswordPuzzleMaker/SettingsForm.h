#pragma once

namespace CrosswordPuzzleMaker {

	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	private: System::Diagnostics::PerformanceCounter^ cpuCounter 
		= gcnew System::Diagnostics::PerformanceCounter("Processor", "% Processor Time", "_Total");
	private: System::Diagnostics::PerformanceCounter^ memCounter 
		= gcnew System::Diagnostics::PerformanceCounter("Memory", "Available MBytes");
	private: System::Windows::Forms::Panel^ panelButtons;
	private: System::Windows::Forms::Panel^ panelLabel;
	public:
		SettingsForm(Form^ form)
		{
			InitializeComponent();

			this->BackColor = form->BackColor;
			this->ForeColor = form->ForeColor;
		}
	protected:
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonBackColor;
	private: System::Windows::Forms::Button^ buttonTextColor;
	private: System::Windows::Forms::Label^ labelPerformance;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingsForm::typeid));
			this->buttonBackColor = (gcnew System::Windows::Forms::Button());
			this->buttonTextColor = (gcnew System::Windows::Forms::Button());
			this->labelPerformance = (gcnew System::Windows::Forms::Label());
			this->panelButtons = (gcnew System::Windows::Forms::Panel());
			this->panelLabel = (gcnew System::Windows::Forms::Panel());
			this->panelButtons->SuspendLayout();
			this->panelLabel->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonBackColor
			// 
			this->buttonBackColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
																	   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonBackColor->Location = System::Drawing::Point(12, 58);
			this->buttonBackColor->Name = L"buttonBackColor";
			this->buttonBackColor->Size = System::Drawing::Size(93, 35);
			this->buttonBackColor->TabIndex = 0;
			this->buttonBackColor->Text = L"Back color";
			this->buttonBackColor->UseVisualStyleBackColor = true;
			this->buttonBackColor->Click += gcnew System::EventHandler(this, &SettingsForm::buttonBackColor_Click);
			// 
			// buttonTextColor
			// 
			this->buttonTextColor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonTextColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
																	   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonTextColor->Location = System::Drawing::Point(329, 58);
			this->buttonTextColor->Name = L"buttonTextColor";
			this->buttonTextColor->Size = System::Drawing::Size(93, 35);
			this->buttonTextColor->TabIndex = 1;
			this->buttonTextColor->Text = L"Text color";
			this->buttonTextColor->UseVisualStyleBackColor = true;
			this->buttonTextColor->Click += gcnew System::EventHandler(this, &SettingsForm::buttonTextColor_Click);
			// 
			// labelPerformance
			// 
			this->labelPerformance->AutoSize = true;
			this->labelPerformance->Location = System::Drawing::Point(9, 53);
			this->labelPerformance->Name = L"labelPerformance";
			this->labelPerformance->Size = System::Drawing::Size(72, 13);
			this->labelPerformance->TabIndex = 2;
			this->labelPerformance->Text = L"CPU USAGE:";
			// 
			// panelButtons
			// 
			this->panelButtons->Controls->Add(this->buttonBackColor);
			this->panelButtons->Controls->Add(this->buttonTextColor);
			this->panelButtons->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelButtons->Location = System::Drawing::Point(0, 0);
			this->panelButtons->Name = L"panelButtons";
			this->panelButtons->Size = System::Drawing::Size(434, 112);
			this->panelButtons->TabIndex = 3;
			// 
			// panelLabel
			// 
			this->panelLabel->Controls->Add(this->labelPerformance);
			this->panelLabel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panelLabel->Location = System::Drawing::Point(0, 161);
			this->panelLabel->Name = L"panelLabel";
			this->panelLabel->Size = System::Drawing::Size(434, 100);
			this->panelLabel->TabIndex = 4;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 261);
			this->Controls->Add(this->panelLabel);
			this->Controls->Add(this->panelButtons);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->panelButtons->ResumeLayout(false);
			this->panelLabel->ResumeLayout(false);
			this->panelLabel->PerformLayout();
			this->ResumeLayout(false);
		}

#pragma endregion

	private: System::Void buttonBackColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonTextColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
    };
}
