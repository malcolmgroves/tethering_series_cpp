//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Caption = Format("App1 : %s", ARRAYOFCONST((TetheringManager1->Identifier)));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    TetheringManager1->AutoConnect();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TetheringManager1PairedToRemote(TObject * const Sender,
		  const TTetheringManagerInfo &AManagerInfo)

{
	Label1->Text = Format("Connected : %s %s",
						  ARRAYOFCONST((AManagerInfo.ManagerIdentifier,
										AManagerInfo.ManagerName)));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TetheringManager1RequestManagerPassword(TObject * const Sender,
		  const UnicodeString ARemoteIdentifier, UnicodeString &Password)

{
	Password = "The wingless dove protects its nest";
}
//---------------------------------------------------------------------------





