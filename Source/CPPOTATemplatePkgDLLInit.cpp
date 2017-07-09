#pragma hdrstop

#include <CPPOTATemplatePkgDLLInit.h>
#include <CPPOTATemplateMainWizard.h>
#pragma package(smart_init)

#ifndef DLL
// For Packages...
// We need to declare for a package a Register procedure.
// The NAMESPACE MUST BE the same name as unit Register is declared in and be lower case except
// for first letter.
namespace Cppotatemplatepkgdllinit {
  void __fastcall PACKAGE Register() {
    RegisterPackageWizard(new TCPPOTATemplateWizard("TCPPOTATemplateWizard"));
  }
}
#else
// For DLLs...
// We need to declare a local variable to accept the BorlandIDEServices reference from the
// Wizard creation method below
//: @note Not Required
//: _di_IBorlandIDEServices LocalIDEServices;

// We also need to delcare the wizard entry point that is called by the IDE on loading a DLL
extern "C" bool __stdcall __declspec(dllexport) INITWIZARD0001(
  const _di_IBorlandIDEServices Service,
  TWizardRegisterProc RegisterWizard,
  TWizardTerminateProc&)
{
  //: @note Not Required
  //: LocalIDEServices = Service; // get reference to the BorlandIDEServices
  RegisterWizard(new TCPPOTATemplateWizard("TCPPOTATemplateWizard"));
  return true;
}
#endif
