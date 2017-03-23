#if !defined(AFX_CARINFOVIEW_H__1B2A0802_9BA4_40CC_8B84_29F8DA2EDAE9__INCLUDED_)
#define AFX_CARINFOVIEW_H__1B2A0802_9BA4_40CC_8B84_29F8DA2EDAE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarInfoView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarInfoView form view

#include "CarInfoDoc.h"

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCarInfoView : public CFormView
{
//	bool bInitDlg;
protected:
	CCarInfoView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCarInfoView)

// Form Data
public:
	CCarInfoDoc * GetDocument(){return (CCarInfoDoc *)CFormView::GetDocument();};
	//{{AFX_DATA(CCarInfoView)
	enum { IDD = FORM_CAR_INFO };
	CListCtrl	m_lstCtrl;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void ShowData();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarInfoView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCarInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCarInfoView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARINFOVIEW_H__1B2A0802_9BA4_40CC_8B84_29F8DA2EDAE9__INCLUDED_)
