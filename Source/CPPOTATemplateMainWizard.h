/**

  This module contains a class that implements the IOTAWizard and IOTAMenuWizard interfaces
  to provide a main wizard interfaces for this OTA project which installs and Open Tools
  API wizard / expert / plug-in into the RAD Studio IDE.

  This clas manages ALL objects created and used by this application.

  @Author  David Hoyle
  @Version 1.0
  @date    17 Dec 2016

**/
#ifndef CPPOTATemplateMainWizardH
#define CPPOTATemplateMainWizardH

#include <ToolsAPI.hpp>
#include <CPPOTATemplateNotifierObject.h>
#include "CPPOTATemplateAppOptions.h"
#include <CPPOTATemplateIDENotifier.h>
#include "CPPOTATemplateAddinOptions.h"
#include <ExtCtrls.hpp>

class PACKAGE TCPPOTATemplateWizard : public TDGHNotifierObject, public IOTAMenuWizard {
  typedef TDGHNotifierObject inherited;
  private:
    int FAboutBoxPlugin;
    int FIDENotifier;
    TCPPOTATemplateOptions* FAppOptions;
    TTimer* FAutoSaveTimer;
    int FTimerCounter;
    TCPPOTATemplateAddInOptions* FIDEOptions;
  protected:
    // IOTAWizard
    virtual UnicodeString __fastcall GetIDString();
    virtual UnicodeString __fastcall GetName();
    virtual TWizardState  __fastcall GetState();
    virtual void __fastcall Execute();
    // IOTAMenuWizard
    virtual UnicodeString __fastcall GetMenuText();
    // IOTANotifer
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // IInterface
    virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    // Non-interface methods
    void __fastcall AutoSaveTimerEvent(TObject* Sender);
    void __fastcall SaveModifiedFiles();
  public:
    __fastcall TCPPOTATemplateWizard(String strObjectName);
    __fastcall ~TCPPOTATemplateWizard();
};
#endif

