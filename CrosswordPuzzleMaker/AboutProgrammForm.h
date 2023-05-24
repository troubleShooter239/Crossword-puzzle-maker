#pragma once

namespace CrosswordPuzzleMaker {

	using namespace System;
	using namespace System::Windows::Forms;

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
	private: System::Windows::Forms::LinkLabel^ githubUrl;
	private: System::Windows::Forms::Label^ someText;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutProgrammForm::typeid));
			this->githubUrl = (gcnew System::Windows::Forms::LinkLabel());
			this->someText = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// githubUrl
			// 
			this->githubUrl->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->githubUrl->AutoSize = true;
			this->githubUrl->BackColor = System::Drawing::Color::Transparent;
			this->githubUrl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
																 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->githubUrl->LinkColor = System::Drawing::SystemColors::ActiveCaption;
			this->githubUrl->Location = System::Drawing::Point(70, 441);
			this->githubUrl->Name = L"githubUrl";
			this->githubUrl->Size = System::Drawing::Size(444, 29);
			this->githubUrl->TabIndex = 0;
			this->githubUrl->TabStop = true;
			this->githubUrl->Text = L"https://github.com/troubleShooter239";
			this->githubUrl->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutProgrammForm::githubUrl_LinkClicked);
			// 
			// someText
			// 
			this->someText->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->someText->AutoSize = true;
			this->someText->BackColor = System::Drawing::Color::Transparent;
			this->someText->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																static_cast<System::Byte>(0)));
			this->someText->Location = System::Drawing::Point(226, 53);
			this->someText->Name = L"someText";
			this->someText->Size = System::Drawing::Size(144, 34);
			this->someText->TabIndex = 1;
			this->someText->Text = L"Developer:";
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																  static_cast<System::Byte>(204)));
			this->exitButton->Location = System::Drawing::Point(535, -2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(39, 23);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"X";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &AboutProgrammForm::exitButton_Click);
			// 
			// AboutProgrammForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(572, 479);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->someText);
			this->Controls->Add(this->githubUrl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AboutProgrammForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"About Programm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void githubUrl_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
