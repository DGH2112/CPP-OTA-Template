#ifndef CPPOTATemplateNotifierObjectH
#define CPPOTATemplateNotifierObjectH

#include <ToolsAPI.hpp>

class PACKAGE TDGHNotifierObject : public IOTANotifier {
  private:
    long ref_count;
    String FObjectName;
  protected:
    void __fastcall DoNotification(String strMessage);
    // IOTANotifier
    void __fastcall AfterSave();
    void __fastcall BeforeSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // IInterface
    virtual HRESULT __stdcall QueryInterface(const GUID&, void**);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
  public:
    __fastcall TDGHNotifierObject(String strObjectName);
    virtual __fastcall ~TDGHNotifierObject();
 };
#endif

