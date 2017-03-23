// MyODBIIViewLog.h : interface of the CMyODBIIViewLog class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYODBIIVIEWLOG_H__BF1A86D1_915E_4935_A834_37FAF5F1B7DF__INCLUDED_)
#define AFX_MYODBIIVIEWLOG_H__BF1A86D1_915E_4935_A834_37FAF5F1B7DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyODBIIViewLog : public CListView
{
protected: // create from serialization only
	CMyODBIIViewLog();
	DECLARE_DYNCREATE(CMyODBIIViewLog)

// Attributes
public:
	CMyODBIIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyODBIIViewLog)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyODBIIViewLog();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyODBIIViewLog)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCapture();
	afx_msg void OnUpdateCapture(CCmdUI* pCmdUI);
	afx_msg void OnUpdateStop(CCmdUI* pCmdUI);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FillLocalData();
	bool m_bCapture;
	int m_iIndex;
};

#ifndef _DEBUG  // debug version in MyODBIIView.cpp
inline CMyODBIIDoc* CMyODBIIViewLog::GetDocument()
   { return (CMyODBIIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYODBIIVIEWLOG_H__BF1A86D1_915E_4935_A834_37FAF5F1B7DF__INCLUDED_)
