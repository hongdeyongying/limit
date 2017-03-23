// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog


CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
	m_iBoundrate = 38400;
	m_iCom = 3;
	//}}AFX_DATA_INIT

	ReadEnv();
}


void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
	DDX_Text(pDX, IDC_EDIT_BOUNDRATE, m_iBoundrate);
	DDV_MinMaxInt(pDX, m_iCom, 1, 100);
	DDX_Text(pDX, IDC_EDIT_COM, m_iCom);
	DDV_MinMaxInt(pDX, m_iBoundrate, 9600, 38400);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

void CSettingDlg::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData(TRUE);
	
	CDialog::OnOK();
}

void CSettingDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	UpdateData(FALSE);
	
	CDialog::OnCancel();
}

CSettingDlg * g_pSettingDlg = NULL;

#include "ModulePath.h"
void CSettingDlg::SaveEnv()
{
	string t_sFilePath = CModulePath::GetInstance()->m_sDatDir + "\\env.dat";

	CFile t_CFile;

	char buf[1024];

	if(!t_CFile.Open(t_sFilePath.c_str(),
		CFile::modeCreate | CFile::modeWrite))
	{
		return;
	}




	CArchive av(&t_CFile,CArchive::store,sizeof(buf),buf);

	av << m_iCom << m_iBoundrate;

	av.Close();

	t_CFile.Close();
}

void CSettingDlg::ReadEnv()
{
	string t_sFilePath = CModulePath::GetInstance()->m_sDatDir + "\\env.dat";

	CFile t_CFile;

	char buf[1024];

	if(!t_CFile.Open(t_sFilePath.c_str(),
		CFile::modeRead))
	{
		return;
	}




	CArchive av(&t_CFile,CArchive::load,sizeof(buf),buf);

	av >> m_iCom >> m_iBoundrate;

	av.Close();

	t_CFile.Close();
}
