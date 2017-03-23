// MyOBDIIFrame.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "MyOBDIIFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyOBDIIFrame

IMPLEMENT_DYNCREATE(CMyOBDIIFrame, CMDIChildWnd)

CMyOBDIIFrame::CMyOBDIIFrame()
{
}

CMyOBDIIFrame::~CMyOBDIIFrame()
{
}


BEGIN_MESSAGE_MAP(CMyOBDIIFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CMyOBDIIFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyOBDIIFrame message handlers

BOOL CMyOBDIIFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CMDIChildWnd::PreCreateWindow(cs);
}

//DEL BOOL CMyOBDIIFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CMDIFrameWnd::OnCreateClient(lpcs, pContext);
//DEL }

 //CToolBar * CMyOBDIIFrame::m_pwndToolBar = NULL;

int CMyOBDIIFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MYODBITYPE))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);

	// TODO: Add your specialized creation code here
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	
	return 0;
}

//DEL void CMyOBDIIFrame::OnViewToolbar() 
//DEL {
//DEL 
//DEL 	m_pwndToolBar->ShowWindow(SW_NORMAL);	
//DEL 
//DEL 	CMDIChildWnd::OnViewToolbar();
//DEL }

//DEL void CMyOBDIIFrame::OnViewToolbar() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL m_pwndToolBar->ShowWindow(SW_SHOW);	
//DEL 	
//DEL }

//DEL void CMyOBDIIFrame::OnUpdateViewToolbar(CCmdUI* pCmdUI) 
//DEL {
//DEL 	// TODO: Add your command update UI handler code here
//DEL 
//DEL 	
//DEL }

//DEL void CMyOBDIIFrame::OnViewToolbar() 
//DEL {
//DEL 	static bool t_bShow = true;
//DEL 
//DEL 	// TODO: Add your command handler code here
//DEL 
//DEL 	if(t_bShow == false)
//DEL 	{
//DEL 		t_bShow = true;
//DEL 		m_pwndToolBar->ShowWindow(SW_SHOW);
//DEL 	}
//DEL 	else
//DEL 	{
//DEL 		t_bShow = false;
//DEL 		m_pwndToolBar->ShowWindow(SW_HIDE);
//DEL 	}
//DEL 
//DEL 	m_pwndToolBar->EnableDocking(CBRS_ALIGN_ANY);
//DEL 	((CMDIFrameWnd *)AfxGetMainWnd())->DockControlBar(m_pwndToolBar);
//DEL 
//DEL 	//AfxGetMainWnd()->PostMessage(ID_VIEW_TOOLBAR);
//DEL }
