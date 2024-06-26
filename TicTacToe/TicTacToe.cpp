//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "TicTacToe.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

String currentPlayerSymbol = "x";

bool TForm1::CheckIsWinner() {
	if (!Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button2->Text == Button3->Text) {
		return true;
	}
	if (!Button4->Text.IsEmpty() && Button4->Text == Button5->Text && Button5->Text == Button6->Text) {
		return true;
	}
	if (!Button7->Text.IsEmpty() && Button7->Text == Button8->Text && Button8->Text == Button9->Text) {
		return true;
	}
	if (!Button1->Text.IsEmpty() && Button1->Text == Button4->Text && Button4->Text == Button7->Text) {
		return true;
	}
	if (!Button2->Text.IsEmpty() && Button2->Text == Button5->Text && Button5->Text == Button8->Text) {
		return true;
	}
	if (!Button3->Text.IsEmpty() && Button3->Text == Button6->Text && Button6->Text == Button9->Text) {
		return true;
	}
	if (!Button1->Text.IsEmpty() && Button1->Text == Button5->Text && Button5->Text == Button9->Text) {
		return true;
	}
	if (!Button3->Text.IsEmpty() && Button3->Text == Button5->Text && Button5->Text == Button7->Text) {
		return true;
	}
	return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	currentPlayerSymbolLabel->Text = currentPlayerSymbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	TButton* clickedButton = dynamic_cast<TButton*>(Sender);
	clickedButton->Text = currentPlayerSymbol;

	if (CheckIsWinner()) {
		winnerLabel->Text = currentPlayerSymbol + " won!";
		return;
	}

	if (currentPlayerSymbol == "x") {
		currentPlayerSymbol ="o";
	} else {
		currentPlayerSymbol = "x";
	}

	currentPlayerSymbolLabel->Text = currentPlayerSymbol;
}

