#pragma hdrstop
#include <CPPOTATemplateIDENotifier.h>
#include "CPPOTATemplateMacros.h"
#include <SysUtils.hpp>
#pragma package(smart_init)

int __fastcall AddIDENotifier() {
  _di_IOTAServices IDEServices;
  if (BorlandIDEServices->Supports(IDEServices)) {
    return IDEServices->AddNotifier(new TCPPOTATemplateIDENotifier("TCPPOTATemplateIDENotifier"));
  }
  return -1;
}

void __fastcall RemoveIDENotifier(int iIDENotifierIndex) {
  _di_IOTAServices IDEServices;
  if (BorlandIDEServices->Supports(IDEServices)) {
    if (iIDENotifierIndex > -1) {
      IDEServices->RemoveNotifier(iIDENotifierIndex);
    }
  }
}

__fastcall TCPPOTATemplateIDENotifier::TCPPOTATemplateIDENotifier(String strObjectName) :
  TDGHNotifierObject(strObjectName) {
  // Do nothing constructor
}

__fastcall TCPPOTATemplateIDENotifier::~TCPPOTATemplateIDENotifier() {
  // Do nothing deconstructor
}

void __fastcall TCPPOTATemplateIDENotifier::FileNotification(
  TOTAFileNotification NotifyCode, const System::UnicodeString FileName, bool &Cancel) {
  const String strNotifyCode[11] = {
    "ofnFileOpening",
    "ofnFileOpened",
    "ofnFileClosing",
    "ofnDefaultDesktopLoad",
    "ofnDefaultDesktopSave",
    "ofnProjectDesktopLoad",
    "ofnProjectDesktopSave",
    "ofnPackageInstalled",
    "ofnPackageUninstalled",
    "ofnActiveProjectChanged",
    "ofnProjectOpenedFromTemplate"
  };
  DoNotification(
    Format("FileNotification: NotifyCode(%d): %s, FileName: %s",
      ARRAYOFCONST((
        NotifyCode,
        strNotifyCode[NotifyCode],
        ExtractFileName(FileName)
      ))
    )
  );
}

void __fastcall TCPPOTATemplateIDENotifier::BeforeCompile(const _di_IOTAProject Project,
  bool &Cancel) {
  DoNotification(
    Format("::BeforeCompile: Project: %s",
      ARRAYOFCONST((ExtractFileName(Project->FileName)))
    )
  );
}

void __fastcall TCPPOTATemplateIDENotifier::AfterCompile(bool Succeeded) {
  DoNotification(
    Format("::AfterCompile: %s",
      ARRAYOFCONST((
        Succeeded ? "True" : "False"
      ))
    )
  );
}

void __fastcall TCPPOTATemplateIDENotifier::BeforeCompile(const _di_IOTAProject Project,
  bool IsCodeInsight, bool &Cancel) {
  DoNotification(
    Format("50::BeforeCompile: Project: %s, IsCodeInsight: %s",
      ARRAYOFCONST((
        ExtractFileName(Project->FileName),
        IsCodeInsight ? "True" : "False"
      ))
    )
  );
}

void __fastcall TCPPOTATemplateIDENotifier::AfterCompile(bool Succeeded,
  bool IsCodeInsight) {
  DoNotification(
    Format("50::AfterCompile: Succeeded: %s, IsCodeInsight: %s",
      ARRAYOFCONST((
        Succeeded ? "True" : "False",
        IsCodeInsight ? "True" : "False"
      ))
    )
  );
}

void __fastcall TCPPOTATemplateIDENotifier::AfterCompile(const _di_IOTAProject Project,
  bool Succeeded, bool IsCodeInsight) {
  DoNotification(
    Format("80::AfterCompile: Project: %s, Succeeded: %s, IsCodeInsigh: %s",
      ARRAYOFCONST((
        ExtractFileName(Project->FileName),
        Succeeded ? "True" : "False",
        IsCodeInsight ? "True" : "False"
      ))
    )
  );
}

void __fastcall TCPPOTATemplateIDENotifier::BeforeSave() {
  inherited::BeforeSave();
  DoNotification("::BeforeSave");
}

void __fastcall TCPPOTATemplateIDENotifier::AfterSave() {
  inherited::AfterSave();
  DoNotification("::AfterSave");
}

void __fastcall TCPPOTATemplateIDENotifier::Destroyed() {
  inherited::Destroyed();
  DoNotification("::Destroyed");
}

void __fastcall TCPPOTATemplateIDENotifier::Modified() {
  inherited::Modified();
  DoNotification("::Modified");
}

HRESULT __stdcall TCPPOTATemplateIDENotifier::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAIDENotifier50, iid, obj);
  QUERY_INTERFACE(IOTAIDENotifier80, iid, obj);
  QUERY_INTERFACE(IOTAIDENotifier, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

ULONG __stdcall TCPPOTATemplateIDENotifier::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TCPPOTATemplateIDENotifier::Release() {
  return inherited::Release();
}

