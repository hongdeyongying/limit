// MyODBIIView.cpp : implementation of the CMyODBIIViewLog class
//

#include "stdafx.h"
#include "MyODBII.h"

#include "MyODBIIDoc.h"
#include "MyODBIIViewLog.h"

#include "CODBIIRawdataVector.h"

#include "utility/CBaseEncode.h"
#include "utility/CTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CMyODBIIViewLog

IMPLEMENT_DYNCREATE(CMyODBIIViewLog, CListView)

BEGIN_MESSAGE_MAP(CMyODBIIViewLog, CListView)
	//{{AFX_MSG_MAP(CMyODBIIViewLog)
	ON_WM_TIMER()
	ON_COMMAND(BTN_CAPTURE, OnCapture)
	ON_UPDATE_COMMAND_UI(BTN_CAPTURE, OnUpdateCapture)
	ON_UPDATE_COMMAND_UI(BTN_STOP, OnUpdateStop)
	ON_COMMAND(BTN_STOP, OnStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIViewLog construction/destruction

CMyODBIIViewLog::CMyODBIIViewLog()
{
	// TODO: add construction code here
	m_iIndex = 0;

	m_bCapture = false;
}

CMyODBIIViewLog::~CMyODBIIViewLog()
{
	//KillTimer(1);
}

BOOL CMyODBIIViewLog::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style  |= LVS_REPORT;

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIViewLog drawing

void CMyODBIIViewLog::OnDraw(CDC* pDC)
{
	CMyODBIIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CMyODBIIViewLog::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
///*
	//初始化列表控件和编辑控件
	CListCtrl &t_lstLog = GetListCtrl();
		t_lstLog.SetExtendedStyle
   (t_lstLog.GetExtendedStyle()|LVS_EX_HEADERDRAGDROP|LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
		t_lstLog.InsertColumn (0,"序号",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (1,"请求时间",LVCFMT_LEFT,150);
		t_lstLog.InsertColumn (2,"耗时(ms)",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (3,"状态",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (4,"请求",LVCFMT_LEFT,180);
		t_lstLog.InsertColumn (5,"回应",LVCFMT_LEFT,200);
		t_lstLog.InsertColumn (6,"回应HEX",LVCFMT_LEFT,480);


	

		if(GetDocument()->GetPathName().GetLength() == 0)
		{
			OnCapture() ;
		}
		else
		{
			FillLocalData();
			OnStop();
		}

//*/
		//GetParent()->ShowWindow(SW_SHOWMAXIMIZED);
	//GetParent()->BringWindowToTop( );
	//GetParent()->


/*
// TODO: Add your specialized code here and/or call the base class

CListCtrl& m_list = GetListCtrl();//得到内置的listctrl引用

LONG lStyle;

lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口风格

//lStyle &= ~LVS_TYPEMASK; //清除显示方式位

lStyle |= LVS_REPORT; //设置报表风格

//SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle); //设置窗口风格


DWORD dwStyle = m_list.GetExtendedStyle();

//选中某行使整行高亮（只适用于报表风格的listctrl）

dwStyle |= LVS_EX_FULLROWSELECT;

dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与报表风格的listctrl）

m_list.SetExtendedStyle(dwStyle); //设置扩展风格

m_list.SetBkColor(RGB(200, 200, 200)); //设置背景颜色

m_list.SetTextBkColor(RGB(200, 200, 200)); //设置文本背景颜色

m_list.SetTextColor(RGB(10, 10, 80)); //设置文本颜色


//插入列的标题，为了简单起见，我只插入三列

m_list.InsertColumn( 0, "图像帧号", LVCFMT_CENTER, 80 );

m_list.InsertColumn( 1, "可见性判断", LVCFMT_CENTER, 110 );

m_list.InsertColumn( 2, "置信度结果", LVCFMT_CENTER, 110 );

*/
}

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIViewLog printing

BOOL CMyODBIIViewLog::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyODBIIViewLog::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyODBIIViewLog::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIViewLog diagnostics

#ifdef _DEBUG
void CMyODBIIViewLog::AssertValid() const
{
	CListView::AssertValid();
}

void CMyODBIIViewLog::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMyODBIIDoc* CMyODBIIViewLog::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyODBIIDoc)));
	return (CMyODBIIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIViewLog message handlers

void CMyODBIIViewLog::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CListView::OnTimer(nIDEvent);

	if(nIDEvent == 1)
	{

		CODBIIRawdataVector::const_iterator iter;

		CListCtrl &theCtrl=this->GetListCtrl ();

		if(g_objCODBIIRawdataVector.size() > m_iIndex)
		{			
			GetDocument()->SetModifiedFlag();

			for(iter = g_objCODBIIRawdataVector.begin()+m_iIndex; iter != g_objCODBIIRawdataVector.end();iter++)
			{
				theCtrl.InsertItem (0,MyUtility::CBaseEncode::UIntToString(iter->m_uID).c_str());
				MyUtility::CTime tm(iter->m_uReqTime);
				//theCtrl.SetItemText (0,1,MyUtility::CBaseEncode::UIntToString(iter->m_uReqTime).c_str());
				theCtrl.SetItemText (0,1,tm.Format().c_str());
				theCtrl.SetItemText (0,2,MyUtility::CBaseEncode::UIntToString(iter->m_uSpendTime).c_str());
				theCtrl.SetItemText (0,3,MyUtility::CBaseEncode::IntToString(iter->m_iStatus).c_str());

				theCtrl.SetItemText (0,4,iter->m_sReq.c_str());
				theCtrl.SetItemText (0,5,iter->m_sRes.c_str());
				theCtrl.SetItemText (0,6,MyUtility::CBaseEncode::CharStrToHexStr(iter->m_sRes).c_str());

				m_iIndex++;

				GetDocument()->m_CODBIIRawdataVector.push_back(*iter);
				
			}
		}
		SetTimer(1,500,NULL);
	}
	
}

void CMyODBIIViewLog::OnCapture() 
{
	// TODO: Add your command handler code here
	m_bCapture = true;
	SetTimer(1,1000,NULL);

	m_iIndex = g_objCODBIIRawdataVector.size();

}

void CMyODBIIViewLog::OnUpdateCapture(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_bCapture == true)
	{
		pCmdUI->Enable(FALSE);
	}
	else
	{
		pCmdUI->Enable(TRUE);
	}
}

void CMyODBIIViewLog::OnUpdateStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_bCapture == false)
	{
		pCmdUI->Enable(FALSE);
	}
	else
	{
		pCmdUI->Enable(TRUE);
	}

}

void CMyODBIIViewLog::OnStop() 
{
	// TODO: Add your command handler code here
	m_bCapture = false;
	KillTimer(1);

}

void CMyODBIIViewLog::FillLocalData()
{
	CODBIIRawdataVector::const_iterator iter;

	CListCtrl &theCtrl=this->GetListCtrl ();

	for(iter = GetDocument()->m_CODBIIRawdataVector.begin()+m_iIndex; iter != GetDocument()->m_CODBIIRawdataVector.end();iter++)
	{
		theCtrl.InsertItem (0,MyUtility::CBaseEncode::UIntToString(iter->m_uID).c_str());
		MyUtility::CTime tm(iter->m_uReqTime);
		//theCtrl.SetItemText (0,1,MyUtility::CBaseEncode::UIntToString(iter->m_uReqTime).c_str());
		theCtrl.SetItemText (0,1,tm.Format().c_str());
		theCtrl.SetItemText (0,2,MyUtility::CBaseEncode::UIntToString(iter->m_uSpendTime).c_str());
		theCtrl.SetItemText (0,3,MyUtility::CBaseEncode::IntToString(iter->m_iStatus).c_str());

		theCtrl.SetItemText (0,4,iter->m_sReq.c_str());
		theCtrl.SetItemText (0,5,iter->m_sRes.c_str());
		theCtrl.SetItemText (0,6,MyUtility::CBaseEncode::CharStrToHexStr(iter->m_sRes).c_str());

		
	}
}

//DEL void CMyODBIIViewLog::OnViewToolbar() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 
//DEL 	
//DEL }
