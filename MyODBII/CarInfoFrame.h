#if !defined(AFX_CARINFOFRAME_H__B9DE3812_3037_4C5F_8C1D_9001002A0220__INCLUDED_)
#define AFX_CARINFOFRAME_H__B9DE3812_3037_4C5F_8C1D_9001002A0220__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarInfoFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarInfoFrame frame

class CCarInfoFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CCarInfoFrame)
protected:
	CCarInfoFrame();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarInfoFrame)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCarInfoFrame();

	// Generated message map functions
	//{{AFX_MSG(CCarInfoFrame)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARINFOFRAME_H__B9DE3812_3037_4C5F_8C1D_9001002A0220__INCLUDED_)
