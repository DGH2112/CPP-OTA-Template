#pragma hdrstop
#include "CPPOTATemplateSplashScreen.h"
#include "windows.h";
#include "CPPOTATemplateConstants.h"

#include "SysInit.hpp"
#include <ToolsAPI.hpp>
#include "SysUtils.hpp"
#include "Forms.hpp"
#include "CPPOTATemplateFunctions.h"

#pragma package(smart_init)

#ifndef DLL
void __fastcall AddSplashScreen() {
  int iMajor;
  int iMinor;
  int iBugFix;
  int iBuild;
  HBITMAP bmSplashScreen;
  BuildNumber(iMajor, iMinor, iBugFix, iBuild);
  bmSplashScreen = LoadBitmap(HInstance, L"CPPOTATemplateSplashScreenBitMap24x24");
  _di_IOTASplashScreenServices SSServices;
  if (SplashScreenServices->Supports(SSServices)) {
    String strRev = strRevision[iBugFix];
    SSServices->AddPluginBitmap(
      Format(strSplashScreenName, ARRAYOFCONST((iMajor, iMinor, strRev, Application->Title))),
      bmSplashScreen,
      False,
      Format(strSplashScreenBuild, ARRAYOFCONST((iMajor, iMinor, iBugFix, iBuild)))
    );
    Sleep(1000); //: @debug Here to pause splash screen to check icon
  }
}
#endif
