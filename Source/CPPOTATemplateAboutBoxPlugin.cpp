#pragma hdrstop
#include "CPPOTATemplateAboutBoxPlugin.h"
#include <ToolsAPI.hpp>
#include "CPPOTATemplateFunctions.h"
#include "CPPOTATemplateConstants.h"
#include "CPPOTATemplateMacros.h"
#pragma package(smart_init)

int __fastcall AddAboutBoxPlugin() {
  int iMajor;
  int iMinor;
  int iBugFix;
  int iBuild;
  HBITMAP bmAboutBoxPlugin;
  int iAboutBoxPlugin;
  BuildNumber(iMajor, iMinor, iBugFix, iBuild);
  bmAboutBoxPlugin = LoadBitmap(HInstance, L"CPPOTATemplateSplashScreenBitMap48x48");
  _di_IOTAAboutBoxServices ABServices;
  if (BorlandIDEServices->Supports(ABServices)) {
    String strRev = strRevision[iBugFix];
    iAboutBoxPlugin = ABServices->AddPluginInfo(
      Format(strSplashScreenName, ARRAYOFCONST((iMajor, iMinor, strRev, Application->Title))),
      strAboutBoxDescription,
      bmAboutBoxPlugin,
      false,
      Format(strSplashScreenBuild, ARRAYOFCONST((iMajor, iMinor, iBugFix, iBuild))),
      Format("SKU Build %d.%d.%d.%d", ARRAYOFCONST((iMajor, iMinor, iBugFix, iBuild)))
    );
    return iAboutBoxPlugin;
  }
  return -1;
}

void __fastcall RemoveAboutBoxPlugin(int iPluginIndex) {
  _di_IOTAAboutBoxServices ABServices;
  if (BorlandIDEServices->Supports(ABServices)) {
    if (iPluginIndex > -1)
      ABServices->RemovePluginInfo(iPluginIndex);
  }
}
