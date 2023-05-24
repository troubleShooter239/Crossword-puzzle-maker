#include "MainMenuForm.h"

[System::STAThreadAttribute]
int main(array<System::String^>^ args){
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	CrosswordPuzzleMaker::MainMenuForm form;
	System::Windows::Forms::Application::Run(% form); // Running main form
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e){
	// Fill MessageBox
	String^ message = "Are you sure you want to exit?";
	String^ caption = "Confirmation of exit";
	MessageBoxButtons buttons = MessageBoxButtons::YesNo;
	MessageBoxIcon icon = MessageBoxIcon::Question;

	// Ask the user if they want to exit
	e->Cancel = (MessageBox::Show(this, message, caption, buttons, icon) == System::Windows::Forms::DialogResult::No) ? true : false;
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_SizeChanged(System::Object^ sender, System::EventArgs^ e){
	crosswordTemplateCellsSize(); // Resizing cells
}

System::Void CrosswordPuzzleMaker::MainMenuForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	Application::Exit(); // Closing main form
}

System::Void CrosswordPuzzleMaker::MainMenuForm::settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	// Creating Settings form
	SettingsForm^ settingsForm = gcnew SettingsForm(this);
	settingsForm->ShowDialog();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::aboutProgrammToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	// Creating About programm form
	AboutProgrammForm^ aboutForm = gcnew AboutProgrammForm();
	aboutForm->ShowDialog();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e){
	Application::Exit(); // Closing main form
}

System::Void CrosswordPuzzleMaker::MainMenuForm::MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e){
	creatingCrossword(16, 16); // Creating puzzle field
	puzzleType = "_Crossword";
	fileName->Text = "File name: " + textLogin + puzzleType; // Output file name

	// Timer to update current time
	System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
	timer->Interval = 1000;
	timer->Tick += gcnew System::EventHandler(this, &MainMenuForm::timer_Tick);
	timer->Start();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::timer_Tick(System::Object^ sender, System::EventArgs^ e){
	currentTime->Text = "Current time: " + DateTime::Now.ToString(); // Output current time
}

System::Void CrosswordPuzzleMaker::MainMenuForm::textBoxColumns_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08){ // If entered character is not a digit and not a backspace
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::textBoxRows_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08){ // If entered character is not a digit and not a backspace
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonChange_Click(System::Object^ sender, System::EventArgs^ e){
	// Some limitations for optimization
	if (Convert::ToInt32(textBoxRows->Text) > 30){ // If number in textBoxRows > 30
		textBoxRows->Text = "30";
	}

	if (Convert::ToInt32(textBoxColumns->Text) > 30){ // If number in textBoxColumns > 30
		textBoxColumns->Text = "30";
	}

	// Recreating the field
	creatingCrossword(Convert::ToInt32(textBoxRows->Text), Convert::ToInt32(textBoxColumns->Text));
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopNewCrossword_Click(System::Object^ sender, System::EventArgs^ e){
	puzzleType = "_Crossword";
	createNewField();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::newAbstractPuzzleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	puzzleType = "_Abstract";
	createNewField();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::newCrosswordToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	puzzleType = "_Crossword";
	createNewField();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::newTemplateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	puzzleType = "_Template";
	createNewField();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e){
	TextBox^ tb = dynamic_cast<TextBox^>(e->Control);

	if (tb != nullptr){
		tb->CharacterCasing = CharacterCasing::Upper;
		tb->MaxLength = 1;
		tb->KeyPress += gcnew KeyPressEventHandler(this, &MainMenuForm::crosswordTemplateTextBox_KeyPress);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplateTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	if (!Char::IsLetter(e->KeyChar) && e->KeyChar != 0x08){
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e){
	// Changing the color of cells
	if (crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor != Color::White){
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor = Color::White;
	}
	else{
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = "";
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor = Color::Black;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	openTemplate();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopOpenTemplate_Click(System::Object^ sender, System::EventArgs^ e){
	openTemplate();
}

System::Void CrosswordPuzzleMaker::MainMenuForm::printToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	PrintDialog^ pd = gcnew PrintDialog();
	PrintDocument^ printDoc = gcnew PrintDocument();

	printDoc->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MainMenuForm::printDoc_PrintPage);

	if (pd->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		printDoc->Print();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::printDoc_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e){
	Graphics^ g = e->Graphics;
	Bitmap^ bmp = gcnew Bitmap(crosswordTemplate->Width, crosswordTemplate->Height);

	crosswordTemplate->DrawToBitmap(bmp, crosswordTemplate->ClientRectangle);
	g->DrawImage(bmp, ClientRectangle);

	e->HasMorePages = false;
}

System::Void CrosswordPuzzleMaker::MainMenuForm::howToUseItToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	MessageBox::Show(
		"The program can create crossword puzzles and templates for them, save, load and print them.\n"
		"Also, in the settings, you can change the background color and text color.\n\n"
		"When creating a crossword puzzle, you are given complete freedom, you can even make a chainword or sudoku!",
		"How to use this program..."
	);
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e){
	if (crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor == Color::White){
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->ReadOnly = false;
	}
	else{
		crosswordTemplate->Rows[e->RowIndex]->Cells[e->ColumnIndex]->ReadOnly = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::crosswordTemplate_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	if (Char::IsLetter(e->KeyChar)){
		crosswordTemplate->ReadOnly = false;
		crosswordTemplate->SelectedCells[0]->Value = e->KeyChar;
		crosswordTemplate->SelectedCells[0]->Style->BackColor = Color::White;
	}

	crosswordTemplate->ReadOnly = true;
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonAddWord_Click(System::Object^ sender, System::EventArgs^ e){
	if (textBoxWord->TextLength != 0){
		String^ text = textBoxWord->Text->ToLower();

		if (isExistsInRichTextBox(text, listViewNotUsed)){
			MessageBox::Show("This word already exists.", "Unable to add word!");
		}
		else{
			ListViewItem^ newItem = gcnew ListViewItem(text);

			listViewNotUsed->Items->Add(newItem);
		}
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::textBoxWord_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	if (!Char::IsLetter(e->KeyChar) && e->KeyChar != (char)Keys::Back && e->KeyChar != (char)Keys::Delete){
		e->Handled = true;
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonAddQuestion_Click(System::Object^ sender, System::EventArgs^ e){
	if (textBoxQuestion->TextLength != 0){
		String^ text = textBoxQuestion->Text;
		ListViewItem^ newItem = gcnew ListViewItem(text);

		listViewQuestions->Items->Add(newItem);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e){
	if (listViewNotUsed->Items->Count > 2){
		clearField();

		// Организуем алгоритм для размещения слов на кроссворде
		int crosswordSize = crosswordTemplate->RowCount;
		CrosswordAlgorithm^ algorithm = gcnew CrosswordAlgorithm(crosswordSize);

		for each (ListViewItem ^ item in listViewNotUsed->Items){
			String^ word = item->Text;

			// Получаем позицию (начальные координаты) для слова
			int startX, startY, direction;
			algorithm->GetStartPosition(word, startX, startY, direction);

			// Разбиваем слово на символы
			array<Char>^ characters = word->ToCharArray();

			// Помещаем каждый символ слова в соответствующую ячейку DataGridView
			for (int i = 0; i < characters->Length; i++){
				// Рассчитываем координаты текущей ячейки
				int x = (direction == static_cast<int>(CrosswordAlgorithm::Direction::Horizontal)) ? startX + i : startX;
				int y = (direction == static_cast<int>(CrosswordAlgorithm::Direction::Vertical)) ? startY + i : startY;

				// Проверяем, чтобы координаты не выходили за пределы кроссворда
				if (x >= 0 && x < crosswordSize && y >= 0 && y < crosswordSize)
				{
					// Получаем ячейку DataGridView по координатам
					DataGridViewCell^ cell = crosswordTemplate->Rows[y]->Cells[x];

					// Устанавливаем значение ячейки равным символу
					cell->Value = characters[i].ToString();
					cell->Style->BackColor = Color::White;
				}
			}
		}
	}
	else{
		MessageBox::Show("There are not enough words in the dictionary.", "Alert!", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::buttonClearField_Click(System::Object^ sender, System::EventArgs^ e){
	crosswordTemplate->Rows->Clear();

	creatingCrossword(Convert::ToInt32(textBoxRows->Text), Convert::ToInt32(textBoxColumns->Text));
}

System::Void CrosswordPuzzleMaker::MainMenuForm::listViewNotUsed_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
	if (e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete){
		if (listViewNotUsed->SelectedItems->Count > 0){
			listViewNotUsed->SelectedItems[0]->Remove();
		}
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::toolTopSave_Click(System::Object^ sender, System::EventArgs^ e){
	if (puzzleType == "_Abstract"){ //////////////////////////////////////////////////////// NEED TO SAVE THE DATA TO!!!
		saveField();
	}
	else if (puzzleType == "_Crossword"){

	}
	else{
		saveField();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	if (puzzleType == "_Abstract"){ //////////////////////////////////////////////////////// NEED TO SAVE THE DATA TO!!!
		saveField();
	}
	else if (puzzleType == "_Crossword"){

	}
	else{
		saveField();
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e){
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = "Puzzle Files (*.pzl)|*.pzl";
	sfd->FileName = textLogin + puzzleType;

	if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		if (puzzleType == "_Abstract"){//////////////////////////////////////////////////////// NEED TO SAVE THE DATA TO!!!
			saveField();
		}
		else if (puzzleType == "_Crossword"){

		}
		else{
			saveField();
		}
	}
}

System::Void CrosswordPuzzleMaker::MainMenuForm::clearField(){
	crosswordTemplate->Rows->Clear();
	creatingCrossword(Convert::ToInt32(textBoxRows->Text), Convert::ToInt32(textBoxColumns->Text));
}
