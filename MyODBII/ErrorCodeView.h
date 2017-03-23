#if !defined(AFX_ERRORCODEVIEW_H__E056D8EA_73E4_4E7A_ACA3_808422FA50A5__INCLUDED_)
#define AFX_ERRORCODEVIEW_H__E056D8EA_73E4_4E7A_ACA3_808422FA50A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ErrorCodeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeView view

#include "ErrorCodeDoc.h"

class CErrorCodeView : public CListView
{
protected:
	CErrorCodeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CErrorCodeView)

// Attributes
public:

// Operations
public:
	CErrorCodeDoc * GetDocument();
	void ShowData();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CErrorCodeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CErrorCodeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CErrorCodeView)
	afx_msg void OnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERRORCODEVIEW_H__E056D8EA_73E4_4E7A_ACA3_808422FA50A5__INCLUDED_)
