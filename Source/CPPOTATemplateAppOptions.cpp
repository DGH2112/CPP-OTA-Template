#pragma hdrstop
#include "CPPOTATemplateAppOptions.h"
#pragma package(smart_init)

#include <SysUtils.hpp>

__fastcall TCPPOTATemplateOptions::TCPPOTATemplateOptions() {
  String strModuleFileName = GetModuleName(unsigned(HInstance));
  FIniFileName = ChangeFileExt(strModuleFileName, ".ini");
  FIniFile = new TMemIniFile(FIniFileName);
  LoadSettings();
}

__fastcall TCPPOTATemplateOptions::~TCPPOTATemplateOptions() {
  SaveSettings();
  delete FIniFile;
}

void __fastcall TCPPOTATemplateOptions::LoadSettings() {
  FEnabled = FIniFile->ReadBool("AutoSave", "Enabled", false);
  FInterval = FIniFile->ReadInteger("AutoSave", "Interval", 300);
  FPromptOn = FIniFile->ReadBool("AutoSave", "PromptOn", true);
}

void __fastcall TCPPOTATemplateOptions::SaveSettings() {
  FIniFile->WriteBool("AutoSave", "Enabled", FEnabled);
  FIniFile->WriteInteger("AutoSave", "Interval", FInterval);
  FIniFile->WriteBool("AutoSave", "PromptOn", FPromptOn);
  FIniFile->UpdateFile();
}


