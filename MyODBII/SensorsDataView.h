#if !defined(AFX_SENSORSDATAVIEW_H__16C738E3_94BB_4C68_B4F5_6846549F2390__INCLUDED_)
#define AFX_SENSORSDATAVIEW_H__16C738E3_94BB_4C68_B4F5_6846549F2390__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SensorsDataView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataView view

#include "SensorsDataDoc.h"

class CSensorsDataView : public CListView
{
protected:
	CSensorsDataView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSensorsDataView)

// Attributes
public:

// Operations
public:
	CSensorsDataDoc * GetDocument();
	void CalVal(const CSensorDataVector & v,string &cur,string &alv,string &min,string &max,string &cnt,string &btim,string &etime);
	void ShowData();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSensorsDataView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSensorsDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSensorsDataView)
	afx_msg void OnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENSORSDATAVIEW_H__16C738E3_94BB_4C68_B4F5_6846549F2390__INCLUDED_)
