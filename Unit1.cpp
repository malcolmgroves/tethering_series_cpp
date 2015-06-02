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
void __fastcall TForm1::EditButton1Click(TObject *Sender)
{
	TetheringAppProfile1->Resources->FindByName("SomeText")->Value = TResourceValue::_op_Implicit(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {
		ImageControl1->LoadFromFile(OpenDialog1->FileName);

		TMemoryStream* LStream = new TMemoryStream;
		ImageControl1->Bitmap->SaveToStream(LStream);
		LStream->Position = 0;

		TetheringAppProfile1->Resources->FindByName("SomeImage")->Value = TResourceValue::_op_Implicit(LStream);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TetheringAppProfile1ResourceReceived(TObject * const Sender,
          TRemoteResource * const AResource)
{
	if (AResource->Hint == "ReplyText") {
		Label2->Text = AResource->Value.AsString;
	} else if (AResource->Hint == "ReplyImage") {
		AResource->Value.AsStream->Position = 0;
		ImageControl2->Bitmap->LoadFromStream(AResource->Value.AsStream);
	};
}
//---------------------------------------------------------------------------



