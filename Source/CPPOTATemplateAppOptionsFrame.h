#ifndef CPPOTATemplateAppOptionsFrameH
#define CPPOTATemplateAppOptionsFrameH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "CPPOTATemplateAppOptions.h"

class TframeAppOptions : public TFrame
{
__published:	// IDE-managed Components
  TCheckBox *chkEnabled;
  TGroupBox *gbxAutoSaveOptions;
  TLabel *lblInterval;
  TEdit *edtInterval;
  TUpDown *udInterval;
  TCheckBox *chkPrompt;
private:// User declarations
public:// User declarations
  __fastcall TframeAppOptions(TComponent* Owner);
  void __fastcall LoadFrame(TCPPOTATemplateOptions* Options);
  void __fastcall SaveFrame(TCPPOTATemplateOptions* Options);
};

extern PACKAGE TframeAppOptions *frameAppOptions;
#endif
