#if !defined(AFX_SETTINGDLG_H__FC521B2F_E03B_4905_8B39_853C24EA2766__INCLUDED_)
#define AFX_SETTINGDLG_H__FC521B2F_E03B_4905_8B39_853C24EA2766__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog

class CSettingDlg : public CDialog
{
// Construction
public:
	void ReadEnv();
	void SaveEnv();
	virtual ~CSettingDlg(){SaveEnv();};
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_DIALOG_SETTING };
	int		m_iBoundrate;
	int		m_iCom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CSettingDlg * g_pSettingDlg;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.




#endif // !defined(AFX_SETTINGDLG_H__FC521B2F_E03B_4905_8B39_853C24EA2766__INCLUDED_)
