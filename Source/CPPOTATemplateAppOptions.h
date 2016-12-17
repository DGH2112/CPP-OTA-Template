/**

  This module contains a class which handles ALL the applications options.

  @Author  David Hoyle
  @Version 1.0
  @Date    17 Dec 2017

**/
#ifndef CPPOTATemplateAppOptionsH
#define CPPOTATemplateAppOptionsH

#include <IniFiles.hpp>

class PACKAGE TCPPOTATemplateOptions {
  private:
    String FIniFileName;
    TMemIniFile* FIniFile;
    bool FEnabled;
    int FInterval;
    bool FPromptOn;
  protected:
    void __fastcall LoadSettings();
    void __fastcall SaveSettings();
  public:
    __fastcall TCPPOTATemplateOptions();
    virtual __fastcall ~TCPPOTATemplateOptions();
    __property bool EnableAutoSave = {read = FEnabled, write = FEnabled};
    __property int AutoSaveInterval = {read = FInterval, write = FInterval};
    __property bool PromptOnAutoSave = {read = FPromptOn, write = FPromptOn};
};
#endif

