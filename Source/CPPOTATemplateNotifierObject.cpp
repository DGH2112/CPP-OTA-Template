#pragma hdrstop
#include "CPPOTATemplateNotifierObject.h"
#include "CPPOTATemplateMacros.h"
#include "Forms.hpp"
#pragma package(smart_init)


/* Notifer Implementation */

__fastcall TDGHNotifierObject::TDGHNotifierObject(String strObjectName) {
  ref_count = 0;
  FObjectName = strObjectName;
}

__fastcall TDGHNotifierObject::~TDGHNotifierObject() {
  // Do nothing destructor
}

ULONG __stdcall TDGHNotifierObject::AddRef() {
  return InterlockedIncrement(&ref_count);
}

ULONG __stdcall TDGHNotifierObject::Release() {
  ULONG result = InterlockedDecrement(&ref_count);
  if (ref_count == 0)
    delete this;
  return result;
}

HRESULT __stdcall TDGHNotifierObject::QueryInterface(const GUID& iid, void** obj) {
  QUERY_INTERFACE(IInterface, iid, obj);
  QUERY_INTERFACE(IOTANotifier, iid, obj);
  return E_NOINTERFACE;
}

void __fastcall TDGHNotifierObject::AfterSave() {
  DoNotification(FObjectName + "::AfterSave");
};

void __fastcall TDGHNotifierObject::BeforeSave() {
  DoNotification(FObjectName + "::BeforeSave");
};

void __fastcall TDGHNotifierObject::Destroyed() {
  DoNotification(FObjectName + "::Destroyed");
};

void __fastcall TDGHNotifierObject::Modified() {
  DoNotification(FObjectName + "::Modified");
};

void __fastcall TDGHNotifierObject::DoNotification(String strMessage) {
  _di_IOTAMessageServices MsgServices;
  if (BorlandIDEServices->Supports(MsgServices)) {
    // Make sure messages are not added when the IDE is being destroyed.
    if (Application->MainForm->Visible) {
      _di_IOTAMessageGroup MsgGrp = MsgServices->AddMessageGroup("C++ OTA Template");
      MsgServices->ShowMessageView(MsgGrp);
      MsgServices->AddTitleMessage(FObjectName + strMessage, MsgGrp);
    }
  }
}
