#pragma hdrstop
#include "CPPOTATemplateAddinOptions.h"
#include "CPPOTATemplateMacros.h"
#pragma package(smart_init)

TCPPOTATemplateAddInOptions* __fastcall AddOptionsFrameToIDE(TCPPOTATemplateOptions* Options) {
  _di_INTAEnvironmentOptionsServices EnvOpServices;
  if (BorlandIDEServices->Supports(EnvOpServices)) {
    TCPPOTATemplateAddInOptions* IDEOptions =
      new TCPPOTATemplateAddInOptions("TCPPOTATemplateAddInOptions", Options);
    EnvOpServices->RegisterAddInOptions(IDEOptions);
    return IDEOptions;
  }
  return NULL;
}

void __fastcall RemoveOptionsFrameFromIDE(TCPPOTATemplateAddInOptions* IDEOptions) {
  _di_INTAEnvironmentOptionsServices EnvOpServices;
  if (BorlandIDEServices->Supports(EnvOpServices) && (IDEOptions != NULL))  {
    EnvOpServices->UnregisterAddInOptions(IDEOptions);
  }
}

TCPPOTATemplateAddInOptions::TCPPOTATemplateAddInOptions(String strObjectName,
  TCPPOTATemplateOptions* Options) : TDGHNotifierObject(strObjectName) {
  FOptions = Options;
}

UnicodeString __fastcall TCPPOTATemplateAddInOptions::GetArea() {
  return "";
}

UnicodeString __fastcall TCPPOTATemplateAddInOptions::GetCaption() {
  return "C++ OTA Template.AutoSave Options";
}

TCustomFrameClass __fastcall TCPPOTATemplateAddInOptions::GetFrameClass() {
  return __classid(TframeAppOptions);
}

void __fastcall TCPPOTATemplateAddInOptions::FrameCreated(TCustomFrame* AFrame) {
  FAppOptionsFrame = dynamic_cast<TframeAppOptions*>(AFrame);
  if (FAppOptionsFrame != NULL) {
    FAppOptionsFrame->LoadFrame(FOptions);
  }
}

void __fastcall TCPPOTATemplateAddInOptions::DialogClosed(bool Accepted) {
  Accepted = true;
}

bool __fastcall TCPPOTATemplateAddInOptions::ValidateContents() {
  if (FAppOptionsFrame != NULL) {
    FAppOptionsFrame->SaveFrame(FOptions);
  }
  return true;
}

int __fastcall TCPPOTATemplateAddInOptions::GetHelpContext() {
  return 0;
}

bool __fastcall TCPPOTATemplateAddInOptions::IncludeInIDEInsight() {
  return true;
}

void __fastcall TCPPOTATemplateAddInOptions::BeforeSave() {
  inherited::BeforeSave();
}

void __fastcall TCPPOTATemplateAddInOptions::AfterSave() {
  inherited::AfterSave();
}

void __fastcall TCPPOTATemplateAddInOptions::Destroyed() {
  inherited::Destroyed();
}

void __fastcall TCPPOTATemplateAddInOptions::Modified() {
  inherited::Modified();
}

HRESULT __stdcall TCPPOTATemplateAddInOptions::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(INTAAddInOptions, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

ULONG __stdcall TCPPOTATemplateAddInOptions::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TCPPOTATemplateAddInOptions::Release() {
  return inherited::Release();
}

