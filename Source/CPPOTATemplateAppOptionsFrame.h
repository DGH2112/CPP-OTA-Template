/**

  This module contains a class which represents an options frame for inserting into the
  RAD Studio IDEs options dialogue.

  @Author  David Hoyle
  @Version 1.0
  @Date    17 Dec 2016

**/
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
