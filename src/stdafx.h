﻿#pragma once

//
// MFC
//

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#define _AFX_PORTABLE
#define _FORCENAMELESSUNION
#define _AFX_NO_DAO_SUPPORT
#define _AFX_NO_DHTML_SUPPORT
#define _AFX_NO_OLEDB_SUPPORT
#define _AFX_NO_RICHEDIT_SUPPORT

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#ifndef _UNICODE
#include <direct.h>
#endif
#include <shlwapi.h>

//
// VERSION
//

#include "version.h"

//
// CONFIG
//

// define program version
#define ENCWAVTOAC3_VERSION _T(VER_FILE_VERSION_SHORT_STR)

// default preset name
#define DEFAULT_PRESET_NAME (HaveLangStrings() ? GetLangString(0x00207001) : _T("Default"))

// default text for auto value
#define DEFAULT_TEXT_AUTO (HaveLangStrings() ? GetLangString(0x00207002) : _T("<Auto>"))

// default text for ignored value
#define DEFAULT_TEXT_IGNORED (HaveLangStrings() ? GetLangString(0x00207003) : _T("<Ignored>"))

// default text for same as source file output path value
#define DEFAULT_TEXT_OUTPUT_PATH (HaveLangStrings() ? GetLangString(0x00207004) : _T("<Same as input file path>"))

// default text for same as source file output path value (multi mono input)
#define DEFAULT_TEXT_OUTPUT_FILE (HaveLangStrings() ? GetLangString(0x00207005) : _T("<Same as first input file path + output.ac3>"))

// default directory for roaming data
#ifdef _M_X64
#define DEFAULT_CONFIG_DIRECTORY _T("EncWAVtoAC3-AMD64")
#else
#define DEFAULT_CONFIG_DIRECTORY _T("EncWAVtoAC3")
#endif

// default directory for language files
#ifdef _DEBUG
#define DEFAULT_LANG_DIRECTORY _T("..\\..\\..\\..\\Lang");
#else
#define DEFAULT_LANG_DIRECTORY  _T("Lang");
#endif

// default file name used to enable portable application
#define DEFAULT_PORTABLE_FILE_NAME _T("EncWAVtoAC3.portable")

// default file name for program configuration
#define DEFAULT_CONFIG_FILE_NAME _T("EncWAVtoAC3.config")

// default file name for language configuration
#define DEFAULT_LANG_FILE_NAME _T("EncWAVtoAC3.lang")

// default file name for encoder presets
#define DEFAULT_PRESETS_FILE_NAME _T("EncWAVtoAC3.presets")

// default file name for files list
#define DEFAULT_FILES_FILE_NAME _T("EncWAVtoAC3.files")

// default files list format (0 = *.files, 1 = *.mux)
#define DEFAULT_FILES_FORMAT 0

// default file name for log
#define DEFAULT_LOG_FILE_NAME _T("EncWAVtoAC3.txt")

// default file name for engines
#define DEFAULT_ENGINES_FILE_NAME _T("EncWAVtoAC3.engines")

// program home URL
#define ENCWAVTOAC3_URL_HOME _T("https://github.com/wieslawsoltes/wavtoac3encoder/")

//
// AFTEN
//

// include libaften common headers
#pragma warning(disable:4005)
#include "common.h"
#include "libaften/aften.h"
#pragma warning(default:4005)

// include Aften API wrapper headers
#include "worker\AftenAPI.h"

// include aften wav reader headers
#ifdef __cplusplus
extern "C" {
#endif
#include "pcm.h"
#if defined(__cplusplus)
}
#endif
