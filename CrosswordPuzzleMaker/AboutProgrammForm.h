#pragma once

namespace CrosswordPuzzleMaker {

	public ref class AboutProgrammForm : public System::Windows::Forms::Form
	{
	public:
		AboutProgrammForm(void)
		{
			InitializeComponent();
		}
	protected:
		~AboutProgrammForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::LinkLabel^ githubURL;
	private: System::Windows::Forms::Label^ labelDeveloper;
	protected:


	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutProgrammForm::typeid));
			this->githubURL = (gcnew System::Windows::Forms::LinkLabel());
			this->labelDeveloper = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// githubURL
			// 
			this->githubURL->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->githubURL->AutoSize = true;
			this->githubURL->BackColor = System::Drawing::Color::Transparent;
			this->githubURL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->githubURL->LinkColor = System::Drawing::SystemColors::ActiveCaption;
			this->githubURL->Location = System::Drawing::Point(70, 441);
			this->githubURL->Name = L"githubURL";
			this->githubURL->Size = System::Drawing::Size(444, 29);
			this->githubURL->TabIndex = 0;
			this->githubURL->TabStop = true;
			this->githubURL->Text = L"https://github.com/troubleShooter239";
			this->githubURL->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutProgrammForm::githubUrl_LinkClicked);
			// 
			// labelDeveloper
			// 
			this->labelDeveloper->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelDeveloper->AutoSize = true;
			this->labelDeveloper->BackColor = System::Drawing::Color::Transparent;
			this->labelDeveloper->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDeveloper->Location = System::Drawing::Point(226, 53);
			this->labelDeveloper->Name = L"labelDeveloper";
			this->labelDeveloper->Size = System::Drawing::Size(144, 34);
			this->labelDeveloper->TabIndex = 1;
			this->labelDeveloper->Text = L"Developer:";
			// 
			// AboutProgrammForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(572, 479);
			this->Controls->Add(this->labelDeveloper);
			this->Controls->Add(this->githubURL);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutProgrammForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"About Programm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void githubUrl_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	};
}
