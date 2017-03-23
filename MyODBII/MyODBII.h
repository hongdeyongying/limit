// MyODBII.h : main header file for the MYODBII application
//

#if !defined(AFX_MYODBII_H__D98263D9_C6B8_4B6F_B968_291B0AB91036__INCLUDED_)
#define AFX_MYODBII_H__D98263D9_C6B8_4B6F_B968_291B0AB91036__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIApp:
// See MyODBII.cpp for the implementation of this class
//

#include "global_var.h"

#include "MyOBDIICommThread.h"

class CMyODBIIApp : public CWinApp
{
private:
	CDocTemplate* m_pLogDocTemplate;
	CDocTemplate* m_pSsDocTemplate;
	CDocTemplate* m_pTcDocTemplate;
	CDocTemplate* m_pCIDocTemplate;

	bool bNeedRecure;

	CMyOBDIICommThread m_objMyOBDIICommThread;
public:
	CMyODBIIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyODBIIApp)
	public:
	virtual BOOL InitInstance();
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyODBIIApp)
	afx_msg void OnAppAbout();
	afx_msg void OnViewLog();
	afx_msg void OnViewSensors();
	afx_msg void OnViewTroubleCode();
	afx_msg void OnOdbiiBegin();
	afx_msg void OnUpdateOdbiiBegin(CCmdUI* pCmdUI);
	afx_msg void OnOdbiiEnd();
	afx_msg void OnUpdateOdbiiEnd(CCmdUI* pCmdUI);
	afx_msg void OnClearTcd();
	afx_msg void OnCapture();
	afx_msg void OnViewCarInfo();
	//}}AFX_MSG

	afx_msg void OnOrderExecEnd();
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYODBII_H__D98263D9_C6B8_4B6F_B968_291B0AB91036__INCLUDED_)
