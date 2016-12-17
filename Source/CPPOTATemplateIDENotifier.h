/**

  This module contains a class which implements the IOTAIDENotifier, IOTAIDENotifier50 and
  IOTAIDENotifier80 interfaces for capturing file notificationevents and compiler events in the
  RAD Studio IDE.

  @Author  David Hoyle
  @Version 1.0
  @Date    17 Dec 2016

**/
#ifndef CPPOTATemplateIDENotifierH
#define CPPOTATemplateIDENotifierH

#include <ToolsAPI.hpp>
#include <CPPOTATemplateNotifierObject.h>

class PACKAGE TCPPOTATemplateIDENotifier : public TDGHNotifierObject, public IOTAIDENotifier80 {
  typedef TDGHNotifierObject inherited;
  public:
    __fastcall TCPPOTATemplateIDENotifier(String strObjectName);
    __fastcall ~TCPPOTATemplateIDENotifier();
    // IOTAIDENotifier
    void __fastcall FileNotification(TOTAFileNotification NotifyCode,
      const System::UnicodeString FileName, bool &Cancel);
    void __fastcall BeforeCompile(const _di_IOTAProject Project, bool &Cancel);
    void __fastcall AfterCompile(bool Succeeded);
    // IOTAIDENotifier50
    void __fastcall BeforeCompile(const _di_IOTAProject Project,
      bool IsCodeInsight, bool &Cancel);
    void __fastcall AfterCompile(bool Succeeded, bool IsCodeInsight);
    // IOTAIDENotifier80
    void __fastcall AfterCompile(const _di_IOTAProject Project,
      bool Succeeded, bool IsCodeInsight);
    // IOTANotifer
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
  protected:
    // IInterface
    virtual HRESULT __stdcall  QueryInterface(const GUID&, void**);
    virtual ULONG __stdcall  AddRef();
    virtual ULONG __stdcall  Release();
  private:
};

int __fastcall AddIDENotifier();
void __fastcall RemoveIDENotifier(int iIDENotifierIndex);
#endif


