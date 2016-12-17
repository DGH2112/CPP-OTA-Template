#pragma hdrstop
#include <CPPOTATemplateMainWizard.h>
#include <Dialogs.hpp>
#include <CPPOTATemplatePkgDLLInit.h>
#include <CPPOTATemplateSplashScreen.h>
#include <CPPOTATemplateAboutBoxPlugin.h>
#include "CPPOTATemplateMacros.h"
#pragma package(smart_init)

/* TCPPOTATemplateWizard Implementation */

__fastcall TCPPOTATemplateWizard::TCPPOTATemplateWizard(String strObjectName) :
  TDGHNotifierObject(strObjectName) {
  #ifndef DLL
  AddSplashScreen();
  #endif
  FAboutBoxPlugin = AddAboutBoxPlugin();
  FIDENotifier = AddIDENotifier();
  FAppOptions = new TCPPOTATemplateOptions();
  FIDEOptions = AddOptionsFrameToIDE(FAppOptions);
  FTimerCounter = 0;
  FAutoSaveTimer = new TTimer(NULL);
  FAutoSaveTimer->Interval = 1000;
  FAutoSaveTimer->OnTimer = AutoSaveTimerEvent;
  FAutoSaveTimer->Enabled = true;
}

__fastcall TCPPOTATemplateWizard::~TCPPOTATemplateWizard() {
  RemoveOptionsFrameFromIDE(FIDEOptions);
  delete FAppOptions;
  delete FAutoSaveTimer;
  RemoveAboutBoxPlugin(FAboutBoxPlugin);
  RemoveIDENotifier(FIDENotifier);
}

ULONG __stdcall TCPPOTATemplateWizard::AddRef() {
  return inherited::AddRef();
}

ULONG __stdcall TCPPOTATemplateWizard::Release() {
  return inherited::Release();
}

HRESULT __stdcall TCPPOTATemplateWizard::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IOTAMenuWizard, iid, obj);
  QUERY_INTERFACE(IOTAWizard, iid, obj);
  return inherited::QueryInterface(iid, obj);
}

UnicodeString __fastcall TCPPOTATemplateWizard::GetIDString() {
  return "CPP.OTA.Template.Wizard";
}

UnicodeString __fastcall TCPPOTATemplateWizard::GetName() {
  return "CPP OTA Temaple";
}

TWizardState  __fastcall TCPPOTATemplateWizard::GetState() {
  TWizardState result;
  result << wsEnabled;
  return result;
}

void __fastcall TCPPOTATemplateWizard::Execute() {
  DoNotification("... Hello Dave!");
  MessageDlg("Hello Dave... How are you...", mtInformation, TMsgDlgButtons() << mbOK, 0);
}

UnicodeString __fastcall TCPPOTATemplateWizard::GetMenuText() {
  return "My CPP OTA Template Menu";
}

void __fastcall TCPPOTATemplateWizard::BeforeSave() {
  inherited::BeforeSave();
}

void __fastcall TCPPOTATemplateWizard::AfterSave() {
  inherited::AfterSave();
}

void __fastcall TCPPOTATemplateWizard::Destroyed() {
  inherited::Destroyed();
}

void __fastcall TCPPOTATemplateWizard::Modified() {
  inherited::Modified();
}

void __fastcall TCPPOTATemplateWizard::AutoSaveTimerEvent(TObject* Sender) {
  FTimerCounter++;
  if (FTimerCounter >= FAppOptions->AutoSaveInterval) {
    FAutoSaveTimer->Enabled = false;
    try {
      FTimerCounter = 0;
      if (FAppOptions->EnableAutoSave) {
        SaveModifiedFiles();
      }
    } __finally {
      FAutoSaveTimer->Enabled = true;
    }
  }
}

void __fastcall TCPPOTATemplateWizard::SaveModifiedFiles() {
  _di_IOTAEditBufferIterator Iterator;
  _di_IOTAEditorServices EditorServices;
  if (BorlandIDEServices->Supports(EditorServices)) {
    if (EditorServices->GetEditBufferIterator(Iterator)) {
      for (int i = 0; i < Iterator->Count; i++) {
        if (Iterator->EditBuffers[i]->IsModified) {
          if (Iterator->EditBuffers[i]->Module->Save(false, !FAppOptions->PromptOnAutoSave)) {
            DoNotification(
              Format("... Auto Saved: %s",
                ARRAYOFCONST((ExtractFileName(Iterator->EditBuffers[i]->FileName)))
              )
            );
          }
        }
      }
    }
  }
}

