//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	Caption = Format("App2 : %s", ARRAYOFCONST((TetheringManager1->Identifier)));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TetheringManager1PairedFromLocal(TObject * const Sender, const TTetheringManagerInfo &AManagerInfo)

{
	Label1->Text = Format("Connected : %s %s",
						  ARRAYOFCONST((AManagerInfo.ManagerIdentifier,
						  				AManagerInfo.ManagerName)));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TetheringAppProfile1Resources0ResourceReceived(TObject * const Sender,
		  TRemoteResource * const AResource)
{
	Label2->Text = AResource->Value.AsString;
}
//---------------------------------------------------------------------------







