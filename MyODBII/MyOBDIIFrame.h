#if !defined(AFX_MYOBDIIFRAME_H__24CAB0E9_203C_4D88_AE62_42F9FE4D8F9A__INCLUDED_)
#define AFX_MYOBDIIFRAME_H__24CAB0E9_203C_4D88_AE62_42F9FE4D8F9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyOBDIIFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyOBDIIFrame frame
#include "SettingDlg.h"
class CMyOBDIIFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CMyOBDIIFrame)
public:
	CMyOBDIIFrame();           // protected constructor used by dynamic creation

	virtual ~CMyOBDIIFrame();
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyOBDIIFrame)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolBar    m_wndToolBar;

	// Generated message map functions
	//{{AFX_MSG(CMyOBDIIFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYOBDIIFRAME_H__24CAB0E9_203C_4D88_AE62_42F9FE4D8F9A__INCLUDED_)
