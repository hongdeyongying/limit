// MyODBII.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyODBII.h"

#include "MainFrm.h"

#include "ChildFrm.h"

#include "MyODBIIDoc.h"
#include "MyODBIIViewLog.h"
#include "MyOBDIIFrame.h"

#include "SensorsDataFrame.h"
#include "SensorsDataDoc.h"
#include "SensorsDataView.h"

#include "ErrorCodeFrame.h"
#include "ErrorCodeDoc.h"
#include "ErrorCodeView.h"

#include "CarInfoFrame.h"
#include "CarInfoDoc.h"
#include "CarInfoView.h"

#include "ModulePath.h"
#include "utility/CTime.h"

#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIApp

BEGIN_MESSAGE_MAP(CMyODBIIApp, CWinApp)
	//{{AFX_MSG_MAP(CMyODBIIApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(MENU_VIEW_LOG, OnViewLog)
	ON_COMMAND(MENU_VIEW_SENSORS, OnViewSensors)
	ON_COMMAND(MENU_VIEW_TROUBLE_CODE, OnViewTroubleCode)
	ON_COMMAND(MENU_ODBII_BEGIN, OnOdbiiBegin)
	ON_UPDATE_COMMAND_UI(MENU_ODBII_BEGIN, OnUpdateOdbiiBegin)
	ON_COMMAND(MENU_ODBII_END, OnOdbiiEnd)
	ON_UPDATE_COMMAND_UI(MENU_ODBII_END, OnUpdateOdbiiEnd)
	ON_COMMAND(MENU_CLEAR_TCD, OnClearTcd)
	ON_COMMAND(BTN_CAPTURE, OnCapture)
	ON_COMMAND(MENU_VIEW_CAR_INFO, OnViewCarInfo)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)

	ON_MESSAGE(MYMSG_ORDER_EXEC_END,OnOrderExecEnd)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIApp construction

CMyODBIIApp::CMyODBIIApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance

	bNeedRecure = false;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyODBIIApp object


CMyODBIIApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIApp initialization

BOOL CMyODBIIApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	// 
	pDocTemplate = new CMultiDocTemplate(
		IDR_MYODBITYPE,
		RUNTIME_CLASS(CMyODBIIDoc),
	//	RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CMyOBDIIFrame), // custom MDI child frame
		RUNTIME_CLASS(CMyODBIIViewLog));
	AddDocTemplate(pDocTemplate);

	m_pLogDocTemplate = pDocTemplate;

	
	pDocTemplate = new CMultiDocTemplate(
		IDR_SENSORTYPE,
		RUNTIME_CLASS(CSensorsDataDoc),
	//	RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CSensorsDataFrame), // custom MDI child frame
		RUNTIME_CLASS(CSensorsDataView));
	AddDocTemplate(pDocTemplate);

	m_pSsDocTemplate = pDocTemplate;

	pDocTemplate = new CMultiDocTemplate(
		IDR_ERRCDTYPE,
		RUNTIME_CLASS(CErrorCodeDoc),
	//	RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CErrorCodeFrame), // custom MDI child frame
		RUNTIME_CLASS(CErrorCodeView));
	AddDocTemplate(pDocTemplate);

	m_pTcDocTemplate = pDocTemplate;

	pDocTemplate = new CMultiDocTemplate(
		IDR_CARINFOTYPE,
		RUNTIME_CLASS(CCarInfoDoc),
	//	RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CCarInfoFrame), // custom MDI child frame
		RUNTIME_CLASS(CCarInfoView));
	AddDocTemplate(pDocTemplate);

	m_pCIDocTemplate = pDocTemplate;


	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if(cmdInfo.m_nShellCommand==CCommandLineInfo::FileNew) 
	{    
		cmdInfo.m_nShellCommand=CCommandLineInfo::FileNothing;  
	} 

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	//加载配置文件 
	
	string t_sPathName = CModulePath::GetInstance()->m_sCnfDir + "\\index.conf.xml";
	g_objCConfigEntry.LoadConfig(t_sPathName);




	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMyODBIIApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIApp message handlers

void CMyODBIIApp::OnViewLog() 
{
	

	m_pLogDocTemplate->OpenDocumentFile(NULL,TRUE);
}

//DEL BOOL CMyODBIIApp::SaveAllModified() 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 
//DEL 	CDocTemplate* pDocTemplate;
//DEL 
//DEL 	POSITION pos = GetFirstDocTemplatePosition();
//DEL 
//DEL 	while( pos != NULL)
//DEL 	{
//DEL 		pDocTemplate = GetNextDocTemplate(  pos ) ;
//DEL 
//DEL 		if(pDocTemplate == m_pLogDocTemplate)
//DEL 		{
//DEL 			std::string t_svlog = CModulePath::GetInstance()->m_sCnfDir + "\\" + MyUtility::CTime::GetCurrentTime().Format("yyyymmdd") +".myobdii";
//DEL 
//DEL 			POSITION docPos = m_pLogDocTemplate->GetFirstDocPosition();
//DEL 
//DEL 			while(docPos != NULL)
//DEL 			{
//DEL 				m_pLogDocTemplate->GetNextDoc(docPos)->SetPathName(t_svlog.c_str(),TRUE);
//DEL 				m_pLogDocTemplate->GetNextDoc(docPos)->SaveModified();
//DEL 			}
//DEL 			
//DEL 		}
//DEL 
//DEL 
//DEL 	}
//DEL 	
//DEL 	return CWinApp::SaveAllModified();
//DEL }

//DEL void CMyODBIIApp::OnSaveAll() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	SaveAllModified();
//DEL }

void CMyODBIIApp::OnViewSensors() 
{
	// TODO: Add your command handler code here
	m_pSsDocTemplate->OpenDocumentFile(NULL,TRUE);
}

void CMyODBIIApp::OnViewTroubleCode() 
{
	// TODO: Add your command handler code here
	m_pTcDocTemplate->OpenDocumentFile(NULL,TRUE);
}

CDocument* CMyODBIIApp::OpenDocumentFile(LPCTSTR lpszFileName) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWinApp::OpenDocumentFile(lpszFileName);
}

//DEL void CMyODBIIApp::OnFileOpen() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	CString filepath;
//DEL 
//DEL 	CString fname = this->GetDocument()->GetTitle();
//DEL 
//DEL 	char *szFilter = "CSV逗号分隔 文件 (*.csv)|*.csv | All Files (*.*)|*.*||";
//DEL 	CFileDialog fileDlg(FALSE,".csv",fname,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
//DEL 
//DEL 	if(fileDlg.DoModal() != IDOK)
//DEL 	{
//DEL 		return;
//DEL 	}
//DEL 
//DEL 	filepath = fileDlg.GetPathName();
//DEL 	
//DEL }

void CMyODBIIApp::OnOdbiiBegin() 
{
	if(NULL == g_pSettingDlg)
	{
		g_pSettingDlg = new CSettingDlg;
		g_pSettingDlg->Create(IDD_DIALOG_SETTING,GetMainWnd());

	}
	
	if(!m_objMyOBDIICommThread.IsRunning())
	{
		g_objCODBIIRawdataVector.clear();

		OnViewLog();
		m_objMyOBDIICommThread.SetWorkMode(0);
		m_objMyOBDIICommThread.StartWork();
	}
	else
		AfxMessageBox(STR_ERR_ALREADY_RUN);
	
}

void CMyODBIIApp::OnUpdateOdbiiBegin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_objMyOBDIICommThread.IsRunning())
	{
		pCmdUI->Enable(FALSE);
		
		
	}
	else
	{
		pCmdUI->Enable(TRUE);
	}

}

void CMyODBIIApp::OnOdbiiEnd() 
{
	// TODO: Add your command handler code here
	m_objMyOBDIICommThread.Stop();

	g_objCODBIIRawdataVector.clear();
}

void CMyODBIIApp::OnUpdateOdbiiEnd(CCmdUI* pCmdUI) 
{
	if(!m_objMyOBDIICommThread.IsRunning())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}
void CMyODBIIApp::OnOrderExecEnd()
{
	if(bNeedRecure)
	{
		m_objMyOBDIICommThread.SetWorkMode(0);
		m_objMyOBDIICommThread.StartWork();
	}

	bNeedRecure = false;
}
void CMyODBIIApp::OnClearTcd() 
{
	// TODO: Add your command handler code here
	if(m_objMyOBDIICommThread.IsRunning())
	{
		m_objMyOBDIICommThread.Stop();

		bNeedRecure = true;
	}
	else
	{
		bNeedRecure = false;
	}

	m_objMyOBDIICommThread.SetWorkMode(1);

	g_cmdCODBIIRawdataVector.clear();

	g_cmdCODBIIRawdataVector.push_back(CODBIIRawdata("04"));

	m_objMyOBDIICommThread.StartWork();
	
}

//DEL void CMyODBIIApp::SaveEnv()
//DEL {
//DEL 	
//DEL 
//DEL 
//DEL 	
//DEL }

void CMyODBIIApp::OnCapture() 
{
	// TODO: Add your command handler code here
	
}

void CMyODBIIApp::OnViewCarInfo() 
{
	// TODO: Add your command handler code here
	m_pCIDocTemplate->OpenDocumentFile(NULL,TRUE);
}
