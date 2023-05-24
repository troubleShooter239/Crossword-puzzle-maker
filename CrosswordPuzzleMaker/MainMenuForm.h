#include "SettingsForm.h"
#include "AboutProgrammForm.h"
#include "CrosswordAlgorithm.h"

#pragma once

namespace CrosswordPuzzleMaker
{

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;
	using namespace System::IO;

	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	private: String^ textLogin;
	private: String^ puzzleType;
	private: bool isHide = false;

	private: System::Windows::Forms::ToolStripMenuItem^ howToUseItToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newAbstractPuzzleToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStripBottom;
	private: System::Windows::Forms::ToolStripLabel^ fileName;
	private: System::Windows::Forms::ToolStripLabel^ currentTime;
	private: System::Windows::Forms::ToolStrip^ toolStripTop;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel2;
	private: System::Windows::Forms::ToolStripButton^ toolTopNewCrossword;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
	private: System::Windows::Forms::ToolStripButton^ toolTopOpenTemplate;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator7;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator6;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator8;
	private: System::Windows::Forms::TextBox^ textBoxWord;
	private: System::Windows::Forms::TextBox^ textBoxQuestion;
	private: System::Windows::Forms::Label^ labelHorizontally;
	private: System::Windows::Forms::Label^ labelVertically;
	private: System::Windows::Forms::Label^ labelNotUsed;
	private: System::Windows::Forms::Label^ labelQuestions;
	private: System::Windows::Forms::Button^ buttonAddWord;
	private: System::Windows::Forms::Button^ buttonAddQuestion;
	private: System::Windows::Forms::ListView^ listViewNotUsed;
	private: System::Windows::Forms::ListView^ listViewVertically;
	private: System::Windows::Forms::ListView^ listViewHorizontally;
	private: System::Windows::Forms::ListView^ listViewQuestions;
	private: System::Windows::Forms::Button^ buttonGenerate;
	private: System::Windows::Forms::Button^ buttonClearField;
	private: System::Windows::Forms::ToolStripButton^ toolTopSave;
	public:
		MainMenuForm()
		{
			InitializeComponent();
			textLogin = gcnew String(Environment::UserName);
		}

	protected:
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newTemplateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutProgrammToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBoxColumns;
	private: System::Windows::Forms::TextBox^ textBoxRows;
	private: System::Windows::Forms::Label^ labelColumns;
	private: System::Windows::Forms::Label^ labelRows;
	private: System::Windows::Forms::Button^ buttonChange;
	private: System::Windows::Forms::DataGridView^ crosswordTemplate;
	private: System::Windows::Forms::Panel^ toolsPanel;
	private: System::Windows::Forms::ToolStripMenuItem^ newCrosswordToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openCrosswordToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ printToolStripMenuItem;
	private:System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenuForm::typeid));
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->newCrosswordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->newAbstractPuzzleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->newTemplateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->openCrosswordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->aboutProgrammToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->howToUseItToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->textBoxColumns = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxRows = (gcnew System::Windows::Forms::TextBox());
			   this->labelColumns = (gcnew System::Windows::Forms::Label());
			   this->labelRows = (gcnew System::Windows::Forms::Label());
			   this->buttonChange = (gcnew System::Windows::Forms::Button());
			   this->crosswordTemplate = (gcnew System::Windows::Forms::DataGridView());
			   this->toolsPanel = (gcnew System::Windows::Forms::Panel());
			   this->buttonClearField = (gcnew System::Windows::Forms::Button());
			   this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			   this->toolStripBottom = (gcnew System::Windows::Forms::ToolStrip());
			   this->fileName = (gcnew System::Windows::Forms::ToolStripLabel());
			   this->currentTime = (gcnew System::Windows::Forms::ToolStripLabel());
			   this->toolStripTop = (gcnew System::Windows::Forms::ToolStrip());
			   this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			   this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			   this->toolTopNewCrossword = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->toolTopOpenTemplate = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->toolTopSave = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->textBoxWord = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxQuestion = (gcnew System::Windows::Forms::TextBox());
			   this->labelHorizontally = (gcnew System::Windows::Forms::Label());
			   this->labelVertically = (gcnew System::Windows::Forms::Label());
			   this->labelNotUsed = (gcnew System::Windows::Forms::Label());
			   this->labelQuestions = (gcnew System::Windows::Forms::Label());
			   this->buttonAddWord = (gcnew System::Windows::Forms::Button());
			   this->buttonAddQuestion = (gcnew System::Windows::Forms::Button());
			   this->listViewNotUsed = (gcnew System::Windows::Forms::ListView());
			   this->listViewVertically = (gcnew System::Windows::Forms::ListView());
			   this->listViewHorizontally = (gcnew System::Windows::Forms::ListView());
			   this->listViewQuestions = (gcnew System::Windows::Forms::ListView());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->crosswordTemplate))->BeginInit();
			   this->toolsPanel->SuspendLayout();
			   this->toolStripBottom->SuspendLayout();
			   this->toolStripTop->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			   {
				   this->fileToolStripMenuItem,
					   this->helpToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1324, 24);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(15)
			   {
				   this->newCrosswordToolStripMenuItem,
					   this->newAbstractPuzzleToolStripMenuItem, this->newTemplateToolStripMenuItem, this->toolStripSeparator1, this->openCrosswordToolStripMenuItem,
					   this->openToolStripMenuItem, this->toolStripSeparator2, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator3,
					   this->printToolStripMenuItem, this->toolStripSeparator4, this->settingsToolStripMenuItem, this->toolStripSeparator5, this->exitToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // newCrosswordToolStripMenuItem
			   // 
			   this->newCrosswordToolStripMenuItem->Name = L"newCrosswordToolStripMenuItem";
			   this->newCrosswordToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			   this->newCrosswordToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->newCrosswordToolStripMenuItem->Text = L"New crossword";
			   this->newCrosswordToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::newCrosswordToolStripMenuItem_Click);
			   // 
			   // newAbstractPuzzleToolStripMenuItem
			   // 
			   this->newAbstractPuzzleToolStripMenuItem->Name = L"newAbstractPuzzleToolStripMenuItem";
			   this->newAbstractPuzzleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
																												   | System::Windows::Forms::Keys::N));
			   this->newAbstractPuzzleToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->newAbstractPuzzleToolStripMenuItem->Text = L"New abstract puzzle";
			   this->newAbstractPuzzleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::newAbstractPuzzleToolStripMenuItem_Click);
			   // 
			   // newTemplateToolStripMenuItem
			   // 
			   this->newTemplateToolStripMenuItem->Name = L"newTemplateToolStripMenuItem";
			   this->newTemplateToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
																											 | System::Windows::Forms::Keys::N));
			   this->newTemplateToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->newTemplateToolStripMenuItem->Text = L"New template";
			   this->newTemplateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::newTemplateToolStripMenuItem_Click);
			   // 
			   // toolStripSeparator1
			   // 
			   this->toolStripSeparator1->Name = L"toolStripSeparator1";
			   this->toolStripSeparator1->Size = System::Drawing::Size(251, 6);
			   // 
			   // openCrosswordToolStripMenuItem
			   // 
			   this->openCrosswordToolStripMenuItem->Name = L"openCrosswordToolStripMenuItem";
			   this->openCrosswordToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			   this->openCrosswordToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->openCrosswordToolStripMenuItem->Text = L"Open crossword";
			   // 
			   // openToolStripMenuItem
			   // 
			   this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			   this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
																									  | System::Windows::Forms::Keys::O));
			   this->openToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->openToolStripMenuItem->Text = L"Open template";
			   this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::openToolStripMenuItem_Click);
			   // 
			   // toolStripSeparator2
			   // 
			   this->toolStripSeparator2->Name = L"toolStripSeparator2";
			   this->toolStripSeparator2->Size = System::Drawing::Size(251, 6);
			   // 
			   // saveToolStripMenuItem
			   // 
			   this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			   this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			   this->saveToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->saveToolStripMenuItem->Text = L"Save";
			   this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::saveToolStripMenuItem_Click);
			   // 
			   // saveAsToolStripMenuItem
			   // 
			   this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			   this->saveAsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
																										| System::Windows::Forms::Keys::S));
			   this->saveAsToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->saveAsToolStripMenuItem->Text = L"Save as...";
			   this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::saveAsToolStripMenuItem_Click);
			   // 
			   // toolStripSeparator3
			   // 
			   this->toolStripSeparator3->Name = L"toolStripSeparator3";
			   this->toolStripSeparator3->Size = System::Drawing::Size(251, 6);
			   // 
			   // printToolStripMenuItem
			   // 
			   this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
			   this->printToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			   this->printToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->printToolStripMenuItem->Text = L"Print...";
			   this->printToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::printToolStripMenuItem_Click);
			   // 
			   // toolStripSeparator4
			   // 
			   this->toolStripSeparator4->Name = L"toolStripSeparator4";
			   this->toolStripSeparator4->Size = System::Drawing::Size(251, 6);
			   // 
			   // settingsToolStripMenuItem
			   // 
			   this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			   this->settingsToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->settingsToolStripMenuItem->Text = L"Settings";
			   this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::settingsToolStripMenuItem_Click);
			   // 
			   // toolStripSeparator5
			   // 
			   this->toolStripSeparator5->Name = L"toolStripSeparator5";
			   this->toolStripSeparator5->Size = System::Drawing::Size(251, 6);
			   // 
			   // exitToolStripMenuItem
			   // 
			   this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			   this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			   this->exitToolStripMenuItem->Size = System::Drawing::Size(254, 22);
			   this->exitToolStripMenuItem->Text = L"Exit";
			   this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::exitToolStripMenuItem_Click);
			   // 
			   // helpToolStripMenuItem
			   // 
			   this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			   {
				   this->aboutProgrammToolStripMenuItem,
					   this->howToUseItToolStripMenuItem
			   });
			   this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			   this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			   this->helpToolStripMenuItem->Text = L"Help";
			   // 
			   // aboutProgrammToolStripMenuItem
			   // 
			   this->aboutProgrammToolStripMenuItem->Name = L"aboutProgrammToolStripMenuItem";
			   this->aboutProgrammToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			   this->aboutProgrammToolStripMenuItem->Text = L"About programm";
			   this->aboutProgrammToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::aboutProgrammToolStripMenuItem_Click);
			   // 
			   // howToUseItToolStripMenuItem
			   // 
			   this->howToUseItToolStripMenuItem->Name = L"howToUseItToolStripMenuItem";
			   this->howToUseItToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			   this->howToUseItToolStripMenuItem->Text = L"How to use it";
			   this->howToUseItToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::howToUseItToolStripMenuItem_Click);
			   // 
			   // textBoxColumns
			   // 
			   this->textBoxColumns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->textBoxColumns->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																		 static_cast<System::Byte>(204)));
			   this->textBoxColumns->Location = System::Drawing::Point(99, 14);
			   this->textBoxColumns->MaxLength = 2;
			   this->textBoxColumns->Name = L"textBoxColumns";
			   this->textBoxColumns->Size = System::Drawing::Size(48, 26);
			   this->textBoxColumns->TabIndex = 3;
			   this->textBoxColumns->Text = L"16";
			   this->textBoxColumns->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainMenuForm::textBoxColumns_KeyPress);
			   // 
			   // textBoxRows
			   // 
			   this->textBoxRows->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->textBoxRows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	  static_cast<System::Byte>(204)));
			   this->textBoxRows->Location = System::Drawing::Point(224, 14);
			   this->textBoxRows->MaxLength = 2;
			   this->textBoxRows->Name = L"textBoxRows";
			   this->textBoxRows->Size = System::Drawing::Size(48, 26);
			   this->textBoxRows->TabIndex = 4;
			   this->textBoxRows->Text = L"16";
			   this->textBoxRows->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainMenuForm::textBoxRows_KeyPress);
			   // 
			   // labelColumns
			   // 
			   this->labelColumns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->labelColumns->AutoSize = true;
			   this->labelColumns->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	   static_cast<System::Byte>(204)));
			   this->labelColumns->Location = System::Drawing::Point(3, 16);
			   this->labelColumns->Name = L"labelColumns";
			   this->labelColumns->Size = System::Drawing::Size(90, 24);
			   this->labelColumns->TabIndex = 5;
			   this->labelColumns->Text = L"Columns:";
			   // 
			   // labelRows
			   // 
			   this->labelRows->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->labelRows->AutoSize = true;
			   this->labelRows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	static_cast<System::Byte>(204)));
			   this->labelRows->Location = System::Drawing::Point(156, 16);
			   this->labelRows->Name = L"labelRows";
			   this->labelRows->Size = System::Drawing::Size(62, 24);
			   this->labelRows->TabIndex = 6;
			   this->labelRows->Text = L"Rows:";
			   // 
			   // buttonChange
			   // 
			   this->buttonChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->buttonChange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																	   static_cast<System::Byte>(204)));
			   this->buttonChange->Location = System::Drawing::Point(294, 7);
			   this->buttonChange->Name = L"buttonChange";
			   this->buttonChange->Size = System::Drawing::Size(76, 40);
			   this->buttonChange->TabIndex = 8;
			   this->buttonChange->Text = L"Change";
			   this->buttonChange->UseVisualStyleBackColor = true;
			   this->buttonChange->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonChange_Click);
			   // 
			   // crosswordTemplate
			   // 
			   this->crosswordTemplate->AllowUserToAddRows = false;
			   this->crosswordTemplate->AllowUserToDeleteRows = false;
			   this->crosswordTemplate->AllowUserToResizeColumns = false;
			   this->crosswordTemplate->AllowUserToResizeRows = false;
			   dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			   dataGridViewCellStyle1->BackColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			   this->crosswordTemplate->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			   this->crosswordTemplate->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->crosswordTemplate->BackgroundColor = System::Drawing::Color::Black;
			   this->crosswordTemplate->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			   dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
																		   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->crosswordTemplate->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			   this->crosswordTemplate->ColumnHeadersVisible = false;
			   dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			   dataGridViewCellStyle3->BackColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																		   static_cast<System::Byte>(204)));
			   dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			   dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(1);
			   dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::LightGray;
			   dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::ControlDarkDark;
			   dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			   this->crosswordTemplate->DefaultCellStyle = dataGridViewCellStyle3;
			   this->crosswordTemplate->Location = System::Drawing::Point(403, 200);
			   this->crosswordTemplate->MultiSelect = false;
			   this->crosswordTemplate->Name = L"crosswordTemplate";
			   dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle4->BackColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
																		   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->crosswordTemplate->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			   this->crosswordTemplate->RowHeadersVisible = false;
			   dataGridViewCellStyle5->BackColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Black;
			   this->crosswordTemplate->RowsDefaultCellStyle = dataGridViewCellStyle5;
			   this->crosswordTemplate->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			   this->crosswordTemplate->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::Black;
			   this->crosswordTemplate->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
			   this->crosswordTemplate->ScrollBars = System::Windows::Forms::ScrollBars::None;
			   this->crosswordTemplate->Size = System::Drawing::Size(500, 500);
			   this->crosswordTemplate->TabIndex = 9;
			   this->crosswordTemplate->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainMenuForm::crosswordTemplate_CellDoubleClick);
			   this->crosswordTemplate->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &MainMenuForm::crosswordTemplate_CellFormatting);
			   this->crosswordTemplate->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MainMenuForm::crosswordTemplate_EditingControlShowing);
			   this->crosswordTemplate->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainMenuForm::crosswordTemplate_KeyPress);
			   // 
			   // toolsPanel
			   // 
			   this->toolsPanel->Controls->Add(this->buttonClearField);
			   this->toolsPanel->Controls->Add(this->buttonGenerate);
			   this->toolsPanel->Controls->Add(this->buttonChange);
			   this->toolsPanel->Controls->Add(this->labelRows);
			   this->toolsPanel->Controls->Add(this->textBoxRows);
			   this->toolsPanel->Controls->Add(this->labelColumns);
			   this->toolsPanel->Controls->Add(this->textBoxColumns);
			   this->toolsPanel->Location = System::Drawing::Point(0, 67);
			   this->toolsPanel->Name = L"toolsPanel";
			   this->toolsPanel->Size = System::Drawing::Size(803, 50);
			   this->toolsPanel->TabIndex = 10;
			   // 
			   // buttonClearField
			   // 
			   this->buttonClearField->Location = System::Drawing::Point(403, 17);
			   this->buttonClearField->Name = L"buttonClearField";
			   this->buttonClearField->Size = System::Drawing::Size(83, 23);
			   this->buttonClearField->TabIndex = 10;
			   this->buttonClearField->Text = L"Clear field";
			   this->buttonClearField->UseVisualStyleBackColor = true;
			   this->buttonClearField->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonClearField_Click);
			   // 
			   // buttonGenerate
			   // 
			   this->buttonGenerate->Location = System::Drawing::Point(675, 17);
			   this->buttonGenerate->Name = L"buttonGenerate";
			   this->buttonGenerate->Size = System::Drawing::Size(114, 23);
			   this->buttonGenerate->TabIndex = 9;
			   this->buttonGenerate->Text = L"Generate crossword";
			   this->buttonGenerate->UseVisualStyleBackColor = true;
			   this->buttonGenerate->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonGenerate_Click);
			   // 
			   // toolStripBottom
			   // 
			   this->toolStripBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->toolStripBottom->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																		  static_cast<System::Byte>(204)));
			   this->toolStripBottom->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			   {
				   this->fileName, this->currentTime
			   });
			   this->toolStripBottom->Location = System::Drawing::Point(0, 745);
			   this->toolStripBottom->Name = L"toolStripBottom";
			   this->toolStripBottom->Size = System::Drawing::Size(1324, 25);
			   this->toolStripBottom->TabIndex = 11;
			   // 
			   // fileName
			   // 
			   this->fileName->Name = L"fileName";
			   this->fileName->Size = System::Drawing::Size(0, 22);
			   // 
			   // currentTime
			   // 
			   this->currentTime->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			   this->currentTime->Name = L"currentTime";
			   this->currentTime->Size = System::Drawing::Size(0, 22);
			   // 
			   // toolStripTop
			   // 
			   this->toolStripTop->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	   static_cast<System::Byte>(204)));
			   this->toolStripTop->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8)
			   {
				   this->toolStripLabel1,
					   this->toolStripLabel2, this->toolTopNewCrossword, this->toolStripSeparator7, this->toolTopOpenTemplate, this->toolStripSeparator6,
					   this->toolTopSave, this->toolStripSeparator8
			   });
			   this->toolStripTop->Location = System::Drawing::Point(0, 24);
			   this->toolStripTop->Name = L"toolStripTop";
			   this->toolStripTop->Size = System::Drawing::Size(1324, 25);
			   this->toolStripTop->TabIndex = 12;
			   // 
			   // toolStripLabel1
			   // 
			   this->toolStripLabel1->Name = L"toolStripLabel1";
			   this->toolStripLabel1->Size = System::Drawing::Size(0, 22);
			   // 
			   // toolStripLabel2
			   // 
			   this->toolStripLabel2->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			   this->toolStripLabel2->Name = L"toolStripLabel2";
			   this->toolStripLabel2->Size = System::Drawing::Size(0, 22);
			   // 
			   // toolTopNewCrossword
			   // 
			   this->toolTopNewCrossword->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolTopNewCrossword->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolTopNewCrossword.Image")));
			   this->toolTopNewCrossword->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolTopNewCrossword->Name = L"toolTopNewCrossword";
			   this->toolTopNewCrossword->Size = System::Drawing::Size(23, 22);
			   this->toolTopNewCrossword->Text = L"toolStripButton1";
			   this->toolTopNewCrossword->ToolTipText = L"New crossword";
			   this->toolTopNewCrossword->Click += gcnew System::EventHandler(this, &MainMenuForm::toolTopNewCrossword_Click);
			   // 
			   // toolStripSeparator7
			   // 
			   this->toolStripSeparator7->Name = L"toolStripSeparator7";
			   this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
			   // 
			   // toolTopOpenTemplate
			   // 
			   this->toolTopOpenTemplate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolTopOpenTemplate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolTopOpenTemplate.Image")));
			   this->toolTopOpenTemplate->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolTopOpenTemplate->Name = L"toolTopOpenTemplate";
			   this->toolTopOpenTemplate->Size = System::Drawing::Size(23, 22);
			   this->toolTopOpenTemplate->Text = L"Open template";
			   this->toolTopOpenTemplate->Click += gcnew System::EventHandler(this, &MainMenuForm::toolTopOpenTemplate_Click);
			   // 
			   // toolStripSeparator6
			   // 
			   this->toolStripSeparator6->Name = L"toolStripSeparator6";
			   this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
			   // 
			   // toolTopSave
			   // 
			   this->toolTopSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolTopSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolTopSave.Image")));
			   this->toolTopSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolTopSave->Name = L"toolTopSave";
			   this->toolTopSave->Size = System::Drawing::Size(23, 22);
			   this->toolTopSave->Text = L"Save";
			   this->toolTopSave->Click += gcnew System::EventHandler(this, &MainMenuForm::toolTopSave_Click);
			   // 
			   // toolStripSeparator8
			   // 
			   this->toolStripSeparator8->Name = L"toolStripSeparator8";
			   this->toolStripSeparator8->Size = System::Drawing::Size(6, 25);
			   // 
			   // textBoxWord
			   // 
			   this->textBoxWord->Location = System::Drawing::Point(12, 680);
			   this->textBoxWord->Name = L"textBoxWord";
			   this->textBoxWord->Size = System::Drawing::Size(150, 20);
			   this->textBoxWord->TabIndex = 16;
			   this->textBoxWord->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainMenuForm::textBoxWord_KeyPress);
			   // 
			   // textBoxQuestion
			   // 
			   this->textBoxQuestion->Location = System::Drawing::Point(1021, 624);
			   this->textBoxQuestion->Multiline = true;
			   this->textBoxQuestion->Name = L"textBoxQuestion";
			   this->textBoxQuestion->Size = System::Drawing::Size(291, 76);
			   this->textBoxQuestion->TabIndex = 17;
			   // 
			   // labelHorizontally
			   // 
			   this->labelHorizontally->AutoSize = true;
			   this->labelHorizontally->Location = System::Drawing::Point(17, 151);
			   this->labelHorizontally->Name = L"labelHorizontally";
			   this->labelHorizontally->Size = System::Drawing::Size(64, 13);
			   this->labelHorizontally->TabIndex = 18;
			   this->labelHorizontally->Text = L"Horizontally:";
			   // 
			   // labelVertically
			   // 
			   this->labelVertically->AutoSize = true;
			   this->labelVertically->Location = System::Drawing::Point(17, 267);
			   this->labelVertically->Name = L"labelVertically";
			   this->labelVertically->Size = System::Drawing::Size(52, 13);
			   this->labelVertically->TabIndex = 19;
			   this->labelVertically->Text = L"Vertically:";
			   // 
			   // labelNotUsed
			   // 
			   this->labelNotUsed->AutoSize = true;
			   this->labelNotUsed->Location = System::Drawing::Point(17, 407);
			   this->labelNotUsed->Name = L"labelNotUsed";
			   this->labelNotUsed->Size = System::Drawing::Size(53, 13);
			   this->labelNotUsed->TabIndex = 21;
			   this->labelNotUsed->Text = L"Not used:";
			   // 
			   // labelQuestions
			   // 
			   this->labelQuestions->AutoSize = true;
			   this->labelQuestions->Location = System::Drawing::Point(1029, 151);
			   this->labelQuestions->Name = L"labelQuestions";
			   this->labelQuestions->Size = System::Drawing::Size(57, 13);
			   this->labelQuestions->TabIndex = 22;
			   this->labelQuestions->Text = L"Questions:";
			   // 
			   // buttonAddWord
			   // 
			   this->buttonAddWord->Location = System::Drawing::Point(12, 706);
			   this->buttonAddWord->Name = L"buttonAddWord";
			   this->buttonAddWord->Size = System::Drawing::Size(150, 23);
			   this->buttonAddWord->TabIndex = 23;
			   this->buttonAddWord->Text = L"Add word";
			   this->buttonAddWord->UseVisualStyleBackColor = true;
			   this->buttonAddWord->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonAddWord_Click);
			   // 
			   // buttonAddQuestion
			   // 
			   this->buttonAddQuestion->Location = System::Drawing::Point(1021, 706);
			   this->buttonAddQuestion->Name = L"buttonAddQuestion";
			   this->buttonAddQuestion->Size = System::Drawing::Size(291, 23);
			   this->buttonAddQuestion->TabIndex = 24;
			   this->buttonAddQuestion->Text = L"Add question";
			   this->buttonAddQuestion->UseVisualStyleBackColor = true;
			   this->buttonAddQuestion->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonAddQuestion_Click);
			   // 
			   // listViewNotUsed
			   // 
			   this->listViewNotUsed->HideSelection = false;
			   this->listViewNotUsed->Location = System::Drawing::Point(12, 423);
			   this->listViewNotUsed->Name = L"listViewNotUsed";
			   this->listViewNotUsed->Size = System::Drawing::Size(150, 251);
			   this->listViewNotUsed->TabIndex = 27;
			   this->listViewNotUsed->UseCompatibleStateImageBehavior = false;
			   this->listViewNotUsed->View = System::Windows::Forms::View::Tile;
			   this->listViewNotUsed->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainMenuForm::listViewNotUsed_KeyDown);
			   // 
			   // listViewVertically
			   // 
			   this->listViewVertically->HideSelection = false;
			   this->listViewVertically->Location = System::Drawing::Point(12, 283);
			   this->listViewVertically->Name = L"listViewVertically";
			   this->listViewVertically->Size = System::Drawing::Size(150, 100);
			   this->listViewVertically->TabIndex = 28;
			   this->listViewVertically->UseCompatibleStateImageBehavior = false;
			   this->listViewVertically->View = System::Windows::Forms::View::Tile;
			   // 
			   // listViewHorizontally
			   // 
			   this->listViewHorizontally->HideSelection = false;
			   this->listViewHorizontally->Location = System::Drawing::Point(12, 164);
			   this->listViewHorizontally->Name = L"listViewHorizontally";
			   this->listViewHorizontally->Size = System::Drawing::Size(150, 100);
			   this->listViewHorizontally->TabIndex = 29;
			   this->listViewHorizontally->UseCompatibleStateImageBehavior = false;
			   this->listViewHorizontally->View = System::Windows::Forms::View::Tile;
			   // 
			   // listViewQuestions
			   // 
			   this->listViewQuestions->HideSelection = false;
			   this->listViewQuestions->Location = System::Drawing::Point(1021, 167);
			   this->listViewQuestions->Name = L"listViewQuestions";
			   this->listViewQuestions->Size = System::Drawing::Size(291, 451);
			   this->listViewQuestions->TabIndex = 30;
			   this->listViewQuestions->UseCompatibleStateImageBehavior = false;
			   this->listViewQuestions->View = System::Windows::Forms::View::Tile;
			   // 
			   // MainMenuForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::Control;
			   this->ClientSize = System::Drawing::Size(1324, 770);
			   this->Controls->Add(this->listViewQuestions);
			   this->Controls->Add(this->listViewHorizontally);
			   this->Controls->Add(this->listViewVertically);
			   this->Controls->Add(this->listViewNotUsed);
			   this->Controls->Add(this->buttonAddQuestion);
			   this->Controls->Add(this->buttonAddWord);
			   this->Controls->Add(this->labelQuestions);
			   this->Controls->Add(this->labelNotUsed);
			   this->Controls->Add(this->labelVertically);
			   this->Controls->Add(this->labelHorizontally);
			   this->Controls->Add(this->textBoxQuestion);
			   this->Controls->Add(this->textBoxWord);
			   this->Controls->Add(this->toolStripTop);
			   this->Controls->Add(this->toolStripBottom);
			   this->Controls->Add(this->toolsPanel);
			   this->Controls->Add(this->crosswordTemplate);
			   this->Controls->Add(this->menuStrip1);
			   this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
														 static_cast<System::Byte>(204)));
			   this->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"MainMenuForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Crossword Puzzle Maker";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainMenuForm::MainMenuForm_FormClosing);
			   this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainMenuForm::MainMenuForm_FormClosed);
			   this->Load += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Load);
			   this->SizeChanged += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_SizeChanged);
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->crosswordTemplate))->EndInit();
			   this->toolsPanel->ResumeLayout(false);
			   this->toolsPanel->PerformLayout();
			   this->toolStripBottom->ResumeLayout(false);
			   this->toolStripBottom->PerformLayout();
			   this->toolStripTop->ResumeLayout(false);
			   this->toolStripTop->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

#pragma endregion

	// Event triggered when the application is closing
	private: System::Void MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	// Event triggered when the main menu size is changed
	private: System::Void MainMenuForm_SizeChanged(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when the user click on exitToolStrip
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when the user click on settingsToolStrip
	private: System::Void settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when the user click on aboutProgrammToolStrip
	private: System::Void aboutProgrammToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when main form is closed
	private: System::Void MainMenuForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	// Event triggered when main form is load
	private: System::Void MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when timer ticks
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when user enters numbers in textBoxColumns
	private: System::Void textBoxColumns_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	// Event triggered when user enters numbers in textBoxRows
	private: System::Void textBoxRows_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	// Event triggered when user clicl on buttonChange
	private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolTopNewCrossword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void newAbstractPuzzleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void newCrosswordToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void newTemplateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	// Event triggered if ReadOnly is false and the user inputs data into cells
	private: System::Void crosswordTemplate_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);
	// Event triggered when the user inputs data into cells
	private: System::Void crosswordTemplateTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	// Event triggered when the user double clicks on a cell
	private: System::Void crosswordTemplate_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolTopOpenTemplate_Click(System::Object^ sender, System::EventArgs^ e);
	// Event triggered when user click on Print...
	private: System::Void printToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void printDoc_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e);
	// Event triggered when user click on How to use it
	private: System::Void howToUseItToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void crosswordTemplate_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e);
	private: System::Void crosswordTemplate_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void buttonAddWord_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxWord_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void buttonAddQuestion_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonClearField_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listViewNotUsed_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void toolTopSave_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void clearField();

	// Void method setting default values for field size
	private: System::Void defaultTemplateSize(){
		textBoxRows->Text = "16";
		textBoxColumns->Text = "16";
	}
	// Void method that creates field
	private: System::Void creatingCrossword(int rows, int cols){
		crosswordTemplate->RowCount = rows;
		crosswordTemplate->ColumnCount = cols;

		crosswordTemplateCellsSize(); // Setting cells size
	}
	// Void method that automatically sets the cell sizes
	private: System::Void crosswordTemplateCellsSize(){
		for each (DataGridViewColumn ^ c in crosswordTemplate->Columns){
			c->Width = crosswordTemplate->Width / crosswordTemplate->Columns->Count;
		}

		for each (DataGridViewRow ^ r in crosswordTemplate->Rows){
			r->Height = crosswordTemplate->Height / crosswordTemplate->Rows->Count;
		}
	}
	private: System::Void createNewField(){
		fileName->Text = "File name: " + textLogin + puzzleType;

		defaultTemplateSize();
		creatingCrossword(crosswordTemplate->RowCount, crosswordTemplate->ColumnCount);
	}
	private: System::Void hideComponentsForCrossword(){
		labelHorizontally->Visible = false;
		labelVertically->Visible = false;
		listViewHorizontally->Visible = false;
		listViewVertically->Visible = false;
		labelNotUsed->Visible = false;
		listViewNotUsed->Visible = false;
		textBoxWord->Visible = false;
		buttonAddWord->Visible = false;
		labelQuestions->Visible = false;
		listViewQuestions->Visible = false;
		textBoxQuestion->Visible = false;
		buttonAddQuestion->Visible = false;

		isHide = true;
	}
	private: System::Void saveField(){
		StreamWriter^ sw = gcnew StreamWriter(textLogin + puzzleType + ".pzl");
		sw->WriteLine(crosswordTemplate->Rows->Count);
		sw->WriteLine(crosswordTemplate->Columns->Count);

		for (int i = 0; i < crosswordTemplate->RowCount; i++){
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++){
				if (crosswordTemplate->Rows[i]->Cells[j]->Style->BackColor == Color::White){
					sw->Write("W");
				}
				else{
					sw->Write("B");
				}
			}
			sw->WriteLine();
		}
		sw->Close();
	}
	private: System::Void openTemplate(){
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Puzzle Files|*.pzl";

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			StreamReader^ reader = gcnew StreamReader(ofd->FileName);
			textBoxRows->Text = reader->ReadLine();
			textBoxColumns->Text = reader->ReadLine();

			creatingCrossword(Convert::ToInt32(textBoxRows->Text), Convert::ToInt32(textBoxColumns->Text));

			String^ line;
			int rowIndex = 0;

			while ((line = reader->ReadLine()) != nullptr){
				for (int i = 0; i < line->Length; i++){
					if (line[i] == 'B'){
						crosswordTemplate->Rows[rowIndex]->Cells[i]->Style->BackColor = Color::Black;
					}
					else{
						crosswordTemplate->Rows[rowIndex]->Cells[i]->Style->BackColor = Color::White;
					}
				}
				rowIndex++;
			}
			reader->Close();
		}
	}
	private: System::Boolean isExistsInRichTextBox(String ^ searchText, ListView ^ list)
	{
		for (int i = 0; i < list->Items->Count; i++){
			if (list->Items[i]->Text->Equals(searchText)){
				return true;
			}
		}
		return false;
	}
};
} 