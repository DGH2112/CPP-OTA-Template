/**

  This module contains macros for use through the application to help with casting Delphi interfaces
  and getting a reference to the BorlandIDEServices variable.

  @Author  David Hoyle
  @Version 1.0
  @Date    17 Dec 2016

**/
#ifndef CPPOTATemplateMacrosH
#define CPPOTATemplateMacrosH

#include <ToolsAPI.hpp>

#ifdef DLL
#define BorlandIDEServices LocalIDEServices
extern _di_IBorlandIDEServices LocalIDEServices;
#endif

#define QUERY_INTERFACE(T, iid, obj)   \
  if ((iid) == __uuidof(T)) {          \
    *(obj) = static_cast<T*>(this);    \
    static_cast<T*>(*(obj))->AddRef(); \
    return S_OK;                       \
  }

#endif
