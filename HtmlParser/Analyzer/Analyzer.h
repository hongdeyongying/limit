// Analyzer.h : main header file for the ANALYZER application
//

#if !defined(AFX_ANALYZER_H__D5DDE790_5532_4875_A69D_13BDA4633864__INCLUDED_)
#define AFX_ANALYZER_H__D5DDE790_5532_4875_A69D_13BDA4633864__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnalyzerApp:
// See Analyzer.cpp for the implementation of this class
//

class CAnalyzerApp : public CWinApp
{
public:
	CAnalyzerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalyzerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnalyzerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYZER_H__D5DDE790_5532_4875_A69D_13BDA4633864__INCLUDED_)
