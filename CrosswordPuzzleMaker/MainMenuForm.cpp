#include "MainMenuForm.h"

[System::STAThreadAttribute]
int main(array<System::String^>^ args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	CrosswordPuzzleMaker::MainMenuForm form;
	System::Windows::Forms::Application::Run(% form); // Running main form
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_FormClosing(
	System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	// Fill MessageBox
	System::String^ message = "Are you sure you want to exit?";
	System::String^ caption = "Confirmation of exit";
	System::Windows::Forms::MessageBoxButtons buttons 
		= System::Windows::Forms::MessageBoxButtons::YesNo;
	System::Windows::Forms::MessageBoxIcon icon
		= System::Windows::Forms::MessageBoxIcon::Question;
	// Ask the user if they want to exit
	e->Cancel = (System::Windows::Forms::MessageBox::Show(
		this, message, caption, buttons, icon) ==
				 System::Windows::Forms::DialogResult::No) ? true : false;
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_SizeChanged(
	System::Object^ sender, System::EventArgs^ e)
{
	crosswordTemplateCellsSize(); // Resizing cells
}

System::Void CrosswordPuzzleMaker::MainMenuForm::exitToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::Application::Exit(); // Closing main form
}

System::Void CrosswordPuzzleMaker::MainMenuForm::settingsToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	// Creating Settings form
	SettingsForm^ settingsForm = gcnew SettingsForm(this);
	settingsForm->ShowDialog();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::aboutProgrammToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	// Creating About programm form
	AboutProgramForm^ aboutForm = gcnew AboutProgramForm();
	aboutForm->ShowDialog();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_FormClosed(
	System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	System::Windows::Forms::Application::Exit(); // Closing main form
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_Load(
	System::Object^ sender, System::EventArgs^ e)
{
	creatingCrossword(16, 16); // Creating puzzle field
	puzzleType = "_Crossword";
	fileName->Text = "File name: " + textLogin + puzzleType; // Output file name
	// Timer to update current time
	System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
	timer->Interval = 1000;
	timer->Tick += gcnew System::EventHandler(this, &MainMenuForm::timer_Tick);
	timer->Start();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::timer_Tick(
	System::Object^ sender, System::EventArgs^ e)
{
	// Output current time
	currentTime->Text = "Current time: " + System::DateTime::Now.ToString();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::textBoxColumns_KeyPress(
	System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!System::Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
	{ // If entered character is not a digit and not a backspace
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::textBoxRows_KeyPress(
	System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!System::Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
	{ // If entered character is not a digit and not a backspace
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonChange_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	// Some limitations for optimization
	if (System::Convert::ToInt32(textBoxRows->Text) > 30)
	{ // If number in textBoxRows > 30
		textBoxRows->Text = "30";
	}
	if (System::Convert::ToInt32(textBoxColumns->Text) > 30)
	{ // If number in textBoxColumns > 30
		textBoxColumns->Text = "30";
	}
	// Recreating the field
	creatingCrossword(System::Convert::ToInt32(textBoxRows->Text), 
					  System::Convert::ToInt32(textBoxColumns->Text));
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopNewCrossword_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	clearField();
	puzzleType = "_Crossword";
	createNewField();
	toolTopGenerateCrossword->Enabled = true;
	listViewQuestions->Items->Clear();
	listViewHorizontally->Items->Clear();
	listViewVertically->Items->Clear();
	listViewNotUsed->Items->Clear();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::newAbstractPuzzleToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	clearField();
	puzzleType = "_Abstract";
	createNewField();
	toolTopGenerateCrossword->Enabled = false;
	listViewQuestions->Items->Clear();
	listViewHorizontally->Items->Clear();
	listViewVertically->Items->Clear();
	listViewNotUsed->Items->Clear();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::newCrosswordToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	clearField();
	puzzleType = "_Crossword";
	createNewField();
	toolTopGenerateCrossword->Enabled = true;
	listViewQuestions->Items->Clear();
	listViewHorizontally->Items->Clear();
	listViewVertically->Items->Clear();
	listViewNotUsed->Items->Clear();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::newTemplateToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	clearField();
	puzzleType = "_Template";
	createNewField();
	toolTopGenerateCrossword->Enabled = false;
	listViewQuestions->Items->Clear();
	listViewHorizontally->Items->Clear();
	listViewVertically->Items->Clear();
	listViewNotUsed->Items->Clear();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_EditingControlShowing(
	System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
{
	System::Windows::Forms::TextBox^ tb = dynamic_cast<System::Windows::Forms::TextBox^>
		(e->Control);
	if (tb != nullptr)
	{
		tb->MaxLength = 1;
		tb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(
			this, &MainMenuForm::crosswordTemplateTextBox_KeyPress);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplateTextBox_KeyPress(
	System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!System::Char::IsLetter(e->KeyChar) && e->KeyChar != 0x08)
	{
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_CellDoubleClick(
	System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	// Changing the color of cells
	if (crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor 
		!= System::Drawing::Color::White)
	{
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor 
			= System::Drawing::Color::White;
	}
	else
	{
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value 
			= "";
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor 
			= System::Drawing::Color::Black;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::openToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	openTemplate();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopOpenTemplate_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	openTemplate();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::printToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::PrintDialog^ pd = gcnew System::Windows::Forms::PrintDialog();
	System::Drawing::Printing::PrintDocument^ printDoc = gcnew System::Drawing::Printing::PrintDocument();
	printDoc->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(
		this, &MainMenuForm::printDoc_PrintPage);
	if (pd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		printDoc->Print();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::printDoc_PrintPage(
	System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e)
{
	System::Drawing::Graphics^ g = e->Graphics;
	System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
		crosswordTemplate->Width, crosswordTemplate->Height);
	crosswordTemplate->DrawToBitmap(bmp, crosswordTemplate->ClientRectangle);
	g->DrawImage(bmp, ClientRectangle);
	e->HasMorePages = false;
}

System::Void CrosswordPuzzleMaker::MainMenuForm::howToUseItToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e){
	System::Windows::Forms::MessageBox::Show(
		"The program can create crossword puzzles and templates for them, save, load and print them.\n"
		"Also, in the settings, you can change the background color and text color.\n\n"
		"When creating a crossword puzzle, you are given complete freedom, "
		"you can even make a chainword or sudoku! ^_^",
		"How to use this program..."
	);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_CellFormatting(
	System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e)
{
	if (crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor 
		== System::Drawing::Color::White)
	{
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->ReadOnly 
			= false;
	}
	else
	{
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->ReadOnly 
			= true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_KeyPress(
	System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (puzzleType != "_Template")
	{
		if (System::Char::IsLetter(e->KeyChar))
		{
			crosswordTemplate->ReadOnly = false;
			crosswordTemplate->SelectedCells[0]->Value 
				= e->KeyChar;
			crosswordTemplate->SelectedCells[0]->Style->BackColor 
				= System::Drawing::Color::White;
		}
		crosswordTemplate->ReadOnly = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonAddWord_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxWord->TextLength == 0)
	{
		return;
	}
	System::String ^ text = textBoxWord->Text->ToLower();
	if (isExistsInRichTextBox(text, listViewNotUsed))
	{
		System::Windows::Forms::MessageBox::Show(
			"This word already exists.", "Unable to add word!");
	}
	else
	{
		System::Windows::Forms::ListViewItem^ newItem 
			= gcnew System::Windows::Forms::ListViewItem(text);
		listViewNotUsed->Items->Add(newItem);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::textBoxWord_KeyPress(
	System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!System::Char::IsLetter(e->KeyChar) && e->KeyChar != 0x08)
	{
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonAddQuestion_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxQuestion->TextLength != 0)
	{
		System::String^ text = textBoxQuestion->Text;
		System::Windows::Forms::ListViewItem^ newItem 
			= gcnew System::Windows::Forms::ListViewItem(text);
		listViewQuestions->Items->Add(newItem);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonClearField_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	crosswordTemplate->Rows->Clear();
	creatingCrossword(System::Convert::ToInt32(textBoxRows->Text), 
					  System::Convert::ToInt32(textBoxColumns->Text));
}

System::Void CrosswordPuzzleMaker::MainMenuForm::listViewNotUsed_KeyDown(
	System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	deleteListViewItem(e);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopSave_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (puzzleType == "_Template")
	{
		saveField();
	}
	else
	{
		saveCrossword();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (puzzleType == "_Template")
	{
		 saveField();
	}
	else
	{
		saveCrossword();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveAsToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::SaveFileDialog^ sfd = 
		gcnew System::Windows::Forms::SaveFileDialog();
	sfd->Filter = "Puzzle Files (*.pzl)|*.pzl";
	sfd->FileName = textLogin + puzzleType;
	sfd->FileName;

	if (sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	{
		return;
	}
	if (puzzleType == "_Template")
	{
		saveField(sfd->FileName);
	}
	else
	{
		saveCrossword(sfd->FileName);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::clearField()
{
	crosswordTemplate->Rows->Clear();
	creatingCrossword(System::Convert::ToInt32(textBoxRows->Text), 
					  System::Convert::ToInt32(textBoxColumns->Text));
}

System::Void CrosswordPuzzleMaker::MainMenuForm::generateCrossword()
{
	if (listViewNotUsed->Items->Count < 2)
	{
		System::Windows::Forms::MessageBox::Show(
			"There are not enough words in the dictionary.", "Alert!", 
			System::Windows::Forms::MessageBoxButtons::OK, 
			System::Windows::Forms::MessageBoxIcon::Information);
		return;
	}
	try
	{
		int crosswordSize = crosswordTemplate->RowCount;
		CrosswordAlgorithm^ algorithm = gcnew CrosswordAlgorithm(crosswordSize);

		for each (System::Windows::Forms::ListViewItem ^ item in listViewNotUsed->Items)
		{
			item->Remove();
			System::String^ word = item->Text;
			int startX, startY, direction;
			algorithm->GetStartPosition(word, startX, startY, direction);

			if (direction == static_cast<int>(CrosswordAlgorithm::Direction::Horizontal))
			{
				listViewHorizontally->Items->Add(item);
			}
			else
			{
				listViewVertically->Items->Add(item);
			}
			for (int i = 0; i < word->Length; i++)
			{
				System::Windows::Forms::DataGridViewCell^ cell
					= crosswordTemplate->Rows[startY]->Cells[startX];
				cell->Value = word[i];
				cell->Style->BackColor = System::Drawing::Color::White;
				if (direction == static_cast<int>
					(CrosswordAlgorithm::Direction::Horizontal))
				{
					startX++;
				}
				else
				{
					startY++;
				}
			}
		}
	}
	catch (System::IndexOutOfRangeException^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::defaultTemplateSize()
{
	textBoxRows->Text = "16";
	textBoxColumns->Text = "16";
}

System::Void CrosswordPuzzleMaker::MainMenuForm::creatingCrossword(int rows, int cols)
{
	crosswordTemplate->RowCount = rows;
	crosswordTemplate->ColumnCount = cols;
	crosswordTemplateCellsSize(); // Setting cells size
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplateCellsSize()
{
	for each (System::Windows::Forms::DataGridViewColumn ^ c in crosswordTemplate->Columns)
	{
		c->Width = crosswordTemplate->Width / crosswordTemplate->Columns->Count;
	}

	for each (System::Windows::Forms::DataGridViewRow ^ r in crosswordTemplate->Rows)
	{
		r->Height = crosswordTemplate->Height / crosswordTemplate->Rows->Count;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::createNewField()
{
	fileName->Text = "File name: " + textLogin + puzzleType;
	defaultTemplateSize();
	creatingCrossword(crosswordTemplate->RowCount, 
					  crosswordTemplate->ColumnCount);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveField()
{
	try
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(
			textLogin + puzzleType + ".pzl");
		sw->WriteLine(crosswordTemplate->Rows->Count);
		sw->WriteLine(crosswordTemplate->Columns->Count);

		for (int i = 0; i < crosswordTemplate->RowCount; i++)
		{
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++)
			{
				if (crosswordTemplate->Rows[i]->Cells[j]->Style->BackColor
					== System::Drawing::Color::White)
				{
					sw->Write("W");
				}
				else
				{
					sw->Write("B");
				}
			}
			sw->WriteLine();
		}
		sw->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveField(
	System::String^ path)
{
	try
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(path);
		sw->WriteLine(crosswordTemplate->Rows->Count);
		sw->WriteLine(crosswordTemplate->Columns->Count);

		for (int i = 0; i < crosswordTemplate->RowCount; i++)
		{
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++)
			{
				if (crosswordTemplate->Rows[i]->Cells[j]->Style->BackColor
					== System::Drawing::Color::White)
				{
					sw->Write("W");
				}
				else
				{
					sw->Write("B");
				}
			}
			sw->WriteLine();
		}
		sw->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveCrossword(
	System::String^ path)
{
	try
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(path);
		sw->WriteLine(crosswordTemplate->Rows->Count);
		sw->WriteLine(crosswordTemplate->Columns->Count);

		for (int i = 0; i < crosswordTemplate->RowCount; i++)
		{
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++)
			{
				if (crosswordTemplate->Rows[i]->Cells[j]->Style->BackColor
					== System::Drawing::Color::White)
				{
					sw->Write("W");
				}
				else
				{
					sw->Write("B");
				}
			}
			sw->WriteLine();
		}

		for (int i = 0; i < crosswordTemplate->RowCount; i++)
		{
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++)
			{
				System::Object^ value = crosswordTemplate->Rows[i]->Cells[j]->Value;
				if (crosswordTemplate->Rows[i]->Cells[j]->Value == nullptr)
				{
					sw->Write("0");
				}
				else
				{
					sw->Write(value);
				}
			}
			sw->WriteLine();
		}
		sw->WriteLine(listViewQuestions->Items->Count);
		for (int i = 0; i < listViewQuestions->Items->Count; i++)
		{
			sw->WriteLine(listViewQuestions->Items[i]->Text);
		}
		sw->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::openTemplate()
{
	try
	{
		System::Windows::Forms::OpenFileDialog^ ofd
			= gcnew System::Windows::Forms::OpenFileDialog();
		ofd->Filter = "Puzzle Files|*.pzl";
		if (ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			return;
		}
		System::IO::StreamReader^ reader
			= gcnew System::IO::StreamReader(ofd->FileName);
		textBoxRows->Text = reader->ReadLine();
		textBoxColumns->Text = reader->ReadLine();
		creatingCrossword(System::Convert::ToInt32(textBoxRows->Text),
						  System::Convert::ToInt32(textBoxColumns->Text));
		System::String^ line = reader->ReadLine();
		for (int j = 0; j < System::Convert::ToInt32(textBoxRows->Text); j++)
		{
			for (int i = 0; i < line->Length; i++)
			{
				if (line[i] == 'B')
				{
					crosswordTemplate->Rows[j]->Cells[i]->Style->BackColor
						= System::Drawing::Color::Black;
				}
				else
				{
					crosswordTemplate->Rows[j]->Cells[i]->Style->BackColor
						= System::Drawing::Color::White;
				}
			}
			line = reader->ReadLine();
		}
		reader->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::openCrossword()
{
	try
	{
		System::Windows::Forms::OpenFileDialog^ ofd
			= gcnew System::Windows::Forms::OpenFileDialog();
		ofd->Filter = "Puzzle Files|*.pzl";
		if (ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			return;
		}
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(ofd->FileName);
		textBoxRows->Text = reader->ReadLine();
		textBoxColumns->Text = reader->ReadLine();
		creatingCrossword(System::Convert::ToInt32(textBoxRows->Text),
						  System::Convert::ToInt32(textBoxColumns->Text));
		System::String^ line = reader->ReadLine();
		for (int j = 0; j < System::Convert::ToInt32(textBoxRows->Text); j++)
		{
			for (int i = 0; i < line->Length; i++)
			{
				if (line[i] == 'B')
				{
					crosswordTemplate->Rows[j]->Cells[i]->Style->BackColor =
						System::Drawing::Color::Black;
				}
				else
				{
					crosswordTemplate->Rows[j]->Cells[i]->Style->BackColor =
						System::Drawing::Color::White;
				}
			}
			line = reader->ReadLine();
		}
		for (int j = 0; j < System::Convert::ToInt32(textBoxRows->Text); j++)
		{
			for (int i = 0; i < line->Length; i++)
			{
				if (line[i] != '0')
				{
					crosswordTemplate->Rows[j]->Cells[i]->Value = line[i];
				}
			}
			line = reader->ReadLine();
		}
		if (puzzleType == "_Crossword")
		{
			int length = System::Convert::ToInt32(line);
			for (int i = 0; i < length; i++)
			{
				listViewQuestions->Items->Add(reader->ReadLine());
			}
		}
		reader->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Boolean CrosswordPuzzleMaker::MainMenuForm::isExistsInRichTextBox(
	System::String^ searchText, System::Windows::Forms::ListView^ list)
{
	for (int i = 0; i < list->Items->Count; i++)
	{
		if (list->Items[i]->Text->Equals(searchText))
		{
			return true;
		}
	}
	return false;
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopGenerateCrossword_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	if (puzzleType == "_Crossword")
	{
		generateCrossword();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::deleteListViewItem(
	System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == System::Windows::Forms::Keys::Back 
		|| e->KeyCode == System::Windows::Forms::Keys::Delete)
	{
		if (listViewNotUsed->SelectedItems->Count > 0)
		{
			listViewNotUsed->SelectedItems[0]->Remove();
		}
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::listViewVertically_KeyDown(
	System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	deleteListViewItem(e);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::listViewHorizontally_KeyDown(
	System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	deleteListViewItem(e);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::listViewQuestions_KeyDown(
	System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	deleteListViewItem(e);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveCrossword()
{
	try
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(
			textLogin + puzzleType + ".pzl");
		sw->WriteLine(crosswordTemplate->Rows->Count);
		sw->WriteLine(crosswordTemplate->Columns->Count);

		for (int i = 0; i < crosswordTemplate->RowCount; i++)
		{
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++)
			{
				if (crosswordTemplate->Rows[i]->Cells[j]->Style->BackColor
					== System::Drawing::Color::White)
				{
					sw->Write("W");
				}
				else
				{
					sw->Write("B");
				}
			}
			sw->WriteLine();
		}

		for (int i = 0; i < crosswordTemplate->RowCount; i++)
		{
			for (int j = 0; j < crosswordTemplate->ColumnCount; j++)
			{
				System::Object^ value = crosswordTemplate->Rows[i]->Cells[j]->Value;
				if (crosswordTemplate->Rows[i]->Cells[j]->Value == nullptr)
				{
					sw->Write("0");
				}
				else
				{
					sw->Write(value);
				}
			}
			sw->WriteLine();
		}
		sw->WriteLine(listViewQuestions->Items->Count);
		for (int i = 0; i < listViewQuestions->Items->Count; i++)
		{
			sw->WriteLine(listViewQuestions->Items[i]->Text);
		}
		sw->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show("Error! " + ex->Message);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::openCrosswordToolStripMenuItem_Click(
	System::Object^ sender, System::EventArgs^ e)
{
	openCrossword();
}
