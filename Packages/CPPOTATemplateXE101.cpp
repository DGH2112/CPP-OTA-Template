#include <System.hpp>
#include <CPPOTATemplateMainWizard.h>

#pragma resource "*.res"
#pragma hdrstop
USEFORM("..\Source\CPPOTATemplateAppOptionsFrame.cpp", frameAppOptions); /* TFrame: File Type */
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------


#pragma argsused
//int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*) {
extern "C" int _libmain(unsigned long reason) {
  return 1;
}


