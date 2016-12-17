#include <vcl.h>
#pragma hdrstop
#include "CPPOTATemplateAppOptionsFrame.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

__fastcall TframeAppOptions::TframeAppOptions(TComponent* Owner) : TFrame(Owner) {
}

void __fastcall TframeAppOptions::LoadFrame(TCPPOTATemplateOptions* Options) {
  chkEnabled->Checked = Options->EnableAutoSave;
  udInterval->Position = Options->AutoSaveInterval;
  chkPrompt->Checked = Options->PromptOnAutoSave;
}

void __fastcall TframeAppOptions::SaveFrame(TCPPOTATemplateOptions* Options) {
  Options->EnableAutoSave = chkEnabled->Checked;
  Options->AutoSaveInterval = udInterval->Position;
  Options->PromptOnAutoSave = chkPrompt->Checked;
}

