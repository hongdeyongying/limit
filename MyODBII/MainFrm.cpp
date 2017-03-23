// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MyODBII.h"

#include "MainFrm.h"

#include "global_var.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#include "utility/CLocalIP.h"

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(MENU_COMM_CONFIG, OnCommConfig)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_OBDII, DispStatus)
//	ON_UPDATE_COMMAND_UI(MENU_ODBII_END, OnUpdateOdbiiEnd)
	//}}AFX_MSG_MAP

	ON_MESSAGE(MYMSG_DISP_CARINFO,OnDispCarInfo)

	
END_MESSAGE_MAP()

#include "CMyMessage.h"

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_OBDII,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
	if(NULL != g_pSettingDlg)
	{
		delete g_pSettingDlg;
	}
}

void CMainFrame::DispStatus(CCmdUI* pCmdUI)
{
	pCmdUI->Enable();


}

void CMainFrame::OnDispCarInfo()
{
	m_wndStatusBar.SetPaneText(3,"aaa");
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	OnCommConfig() ;

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnCommConfig() 
{
	// TODO: Add your command handler code here
	if(NULL == g_pSettingDlg)
	{
		g_pSettingDlg = new CSettingDlg;
		g_pSettingDlg->Create(IDD_DIALOG_SETTING,this);
	}

	g_pSettingDlg->ShowWindow(SW_NORMAL);

	g_pSettingDlg->CenterWindow(this);
	
}
//DEL void CMainFrame::OnOdbiiBegin() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	if(NULL == g_pSettingDlg)
//DEL 	{
//DEL 		g_pSettingDlg = new CSettingDlg;
//DEL 		g_pSettingDlg->Create(IDD_DIALOG_SETTING,this);
//DEL 
//DEL 	}
//DEL 	
//DEL 	if(!m_objMyOBDIICommThread.IsRunning())
//DEL 	{
//DEL 		//g_objCODBIIRawdataVector.clear();
//DEL 		m_objMyOBDIICommThread.StartWork();
//DEL 	}
//DEL 	else
//DEL 		AfxMessageBox(STR_ERR_ALREADY_RUN);
//DEL 
//DEL 
//DEL 
//DEL 	//AfxMessageBox(CLocalIP::GetInstance()->GetIpMap().Join("\r\n",":").c_str());
//DEL }

//DEL void CMainFrame::OnUpdateOdbiiBegin(CCmdUI* pCmdUI) 
//DEL {
//DEL 
//DEL 	
//DEL }

//DEL void CMainFrame::OnOdbiiEnd() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	m_objMyOBDIICommThread.Stop();
//DEL 
//DEL 	g_objCODBIIRawdataVector.clear();
//DEL 	
//DEL }

//DEL void CMainFrame::OnUpdateOdbiiEnd(CCmdUI* pCmdUI) 
//DEL {
//DEL 	// TODO: Add your command update UI handler code here
//DEL 	
//DEL 
//DEL }



//DEL void CMainFrame::OnViewSensors() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnViewTroubleCode() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }
