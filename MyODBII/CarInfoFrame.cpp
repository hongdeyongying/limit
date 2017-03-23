// CarInfoFrame.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "CarInfoFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarInfoFrame

IMPLEMENT_DYNCREATE(CCarInfoFrame, CMDIChildWnd)

CCarInfoFrame::CCarInfoFrame()
{
}

CCarInfoFrame::~CCarInfoFrame()
{
}


BEGIN_MESSAGE_MAP(CCarInfoFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CCarInfoFrame)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarInfoFrame message handlers

void CCarInfoFrame::OnSize(UINT nType, int cx, int cy) 
{
	CMDIChildWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}
