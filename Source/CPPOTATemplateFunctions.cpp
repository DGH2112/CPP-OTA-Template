#pragma hdrstop
#include "CPPOTATemplateFunctions.h"
#include "windows.h"
#include "SysInit.hpp"
#include "SysUtils.hpp"
#pragma package(smart_init)

void __fastcall BuildNumber(int &iMajor, int &iMinor, int &iBugFix, int &iBuild) {
  DWORD iVerHandle = NULL;
  String strFileName = GetModuleName(unsigned(HInstance));
  DWORD iVerInfoSize = GetFileVersionInfoSizeW(strFileName.c_str(), &iVerHandle);
  if (iVerInfoSize) {
    LPSTR VerInfo = new char [iVerInfoSize];
    try {
      if (GetFileVersionInfoW(strFileName.c_str(), iVerHandle, iVerInfoSize, VerInfo)) {
        unsigned int iVerValueSize = 0;
        LPBYTE lpBuffer = NULL;
        if (VerQueryValue(VerInfo, TEXT("\\"), (VOID FAR* FAR*)&lpBuffer, &iVerValueSize)) {
          if (iVerValueSize) {
            VS_FIXEDFILEINFO *VerValue = (VS_FIXEDFILEINFO *)lpBuffer;
            iMajor = VerValue->dwFileVersionMS >> 16;
            iMinor = VerValue->dwFileVersionMS & 0xFFFF;
            iBugFix = VerValue->dwFileVersionLS >> 16;
            iBuild = VerValue->dwFileVersionLS & 0xFFFF;
          }
        }
      }
    } __finally {
      delete[] VerInfo;
    }
  };
}


