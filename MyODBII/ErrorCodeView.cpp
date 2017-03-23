// ErrorCodeView.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "ErrorCodeView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeView

IMPLEMENT_DYNCREATE(CErrorCodeView, CListView)

CErrorCodeView::CErrorCodeView()
{
}

CErrorCodeView::~CErrorCodeView()
{
}


BEGIN_MESSAGE_MAP(CErrorCodeView, CListView)
	//{{AFX_MSG_MAP(CErrorCodeView)
	ON_COMMAND(MENU_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeView drawing

void CErrorCodeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeView diagnostics

#ifdef _DEBUG
void CErrorCodeView::AssertValid() const
{
	CListView::AssertValid();
}

void CErrorCodeView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeView message handlers

void CErrorCodeView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CListCtrl &t_lstLog = GetListCtrl();
		t_lstLog.SetExtendedStyle
   (t_lstLog.GetExtendedStyle()|LVS_EX_HEADERDRAGDROP|LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
		t_lstLog.InsertColumn (0,"序号",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (1,"DTC",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (2,"DTC含义",LVCFMT_LEFT,250);
		t_lstLog.InsertColumn (3,"原因与办法",LVCFMT_LEFT,550);



		ShowData();
}

void CErrorCodeView::ShowData()
{

	CString aa = GetDocument()->GetPathName() ;
	if(aa == "")
	{
		GetDocument()->m_objCTCDSet =g_objCTCDSet; ;
		GetDocument()->SetModifiedFlag();
	}

	CListCtrl &theCtrl = GetListCtrl();

	theCtrl.DeleteAllItems();

	CTCDSet &m_objCTCDSet = GetDocument()->m_objCTCDSet;

	CTCDSet::const_iterator iter;

	int t_index =0;

	for(iter = m_objCTCDSet.begin();iter != m_objCTCDSet.end();iter++)
	{
		theCtrl.InsertItem (t_index,MyUtility::CBaseEncode::IntToString(t_index).c_str());

		string aa = *iter;
		
		theCtrl.SetItemText (t_index,1,(*iter).c_str());

		string name = g_objCConfigEntry.GetService("TCDINFO").GetVarObj(aa).GetValue();

		theCtrl.SetItemText (t_index,2,name.c_str());

		string desc = g_objCConfigEntry.GetService("TCDINFO").GetVarObj(aa).GetDesc();

		theCtrl.SetItemText (t_index,3,desc.c_str());

		t_index++;

	}
}

BOOL CErrorCodeView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style  |= LVS_REPORT;	

	return CListView::PreCreateWindow(cs);
}

CErrorCodeDoc * CErrorCodeView::GetDocument()
{
	return (CErrorCodeDoc *)m_pDocument;
}

void CErrorCodeView::OnRefresh() 
{
	// TODO: Add your command handler code here
		GetDocument()->m_objCTCDSet =g_objCTCDSet; ;
		GetDocument()->SetModifiedFlag();

		ShowData();
}
