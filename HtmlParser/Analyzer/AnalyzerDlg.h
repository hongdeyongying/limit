// AnalyzerDlg.h : header file
//

#if !defined(AFX_ANALYZERDLG_H__8AFFAFC6_068C_42AE_9768_A09223FFCCD4__INCLUDED_)
#define AFX_ANALYZERDLG_H__8AFFAFC6_068C_42AE_9768_A09223FFCCD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnalyzerDlg dialog
#include "Tracer/Tracer.h"
#include "ModulePath.h"
#include ".\\html\\CHtml.h"
class CAnalyzerDlg : public CDialog
{
private:
// Construction
public:
	int Html2Xml(const CHtml & in,const CNode * rule,string &out);
	int Html2Xml(const string & in,const string & rule,string &out);
	void GenTree(const CNode * root,HTREEITEM & pos);
	CAnalyzerDlg(CWnd* pParent = NULL);	// standard constructor

	CHtml m_Doc;
// Dialog Data
	//{{AFX_DATA(CAnalyzerDlg)
	enum { IDD = IDD_ANALYZER_DIALOG };
	CButton	m_btnFile;
	CButton	m_btnWhole;
	CButton	m_btnMid;
	CButton	m_btnEnd;
	CButton	m_btnBegin;
	CTreeCtrl	m_treeCtrl;
	CString	m_strSource;
	CString	m_strFilePath;
	CString	m_strParam;
	CString	m_strParam2;
	int		m_iTagSearchMode;
	CString	m_strRichSrc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalyzerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnalyzerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnFileParse();
	afx_msg void OnBUTTONbegin();
	afx_msg void OnBUTTONmid();
	afx_msg void OnBUTTONend();
	afx_msg void OnMenuitemVer();
	afx_msg void OnMenuitemOnline();
	afx_msg void OnMenuitemMan();
	afx_msg void OnBUTTONClear();
	afx_msg void OnButtonSTag();
	afx_msg void OnButtonSId();
	afx_msg void OnButtonSName();
	afx_msg void OnNv();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYZERDLG_H__8AFFAFC6_068C_42AE_9768_A09223FFCCD4__INCLUDED_)
