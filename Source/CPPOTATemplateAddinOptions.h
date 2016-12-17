#ifndef CPPOTATemplateAddinOptionsH
#define CPPOTATemplateAddinOptionsH

#include <ToolsAPI.hpp>
#include "CPPOTATemplateAppOptionsFrame.h"
#include "CPPOTATemplateAppOptions.h"
#include "CPPOTATemplateNotifierObject.h"

class PACKAGE TCPPOTATemplateAddInOptions : public TDGHNotifierObject, public INTAAddInOptions {
  typedef TDGHNotifierObject inherited;
  private:
    TCPPOTATemplateOptions* FOptions;
    TframeAppOptions* FAppOptionsFrame;
  protected:
    // IOTANotifier
    void __fastcall BeforeSave();
    void __fastcall AfterSave();
    void __fastcall Destroyed();
    void __fastcall Modified();
    // IInterface
    virtual HRESULT __stdcall QueryInterface(const GUID& iid, void** obj);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    // INTAAddinOptions
    UnicodeString __fastcall GetArea();
    UnicodeString __fastcall GetCaption();
    TCustomFrameClass __fastcall GetFrameClass();
    void __fastcall FrameCreated(TCustomFrame* AFrame);
    void __fastcall DialogClosed(bool Accepted);
    bool __fastcall ValidateContents();
    int __fastcall GetHelpContext();
    bool __fastcall IncludeInIDEInsight();
  public:
    TCPPOTATemplateAddInOptions(String strObjectName, TCPPOTATemplateOptions* Options);
};

TCPPOTATemplateAddInOptions* __fastcall AddOptionsFrameToIDE(TCPPOTATemplateOptions* Options);
void __fastcall RemoveOptionsFrameFromIDE(TCPPOTATemplateAddInOptions* IDEOptions);

#endif
