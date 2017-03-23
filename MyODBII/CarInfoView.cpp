// CarInfoView.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "CarInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarInfoView

IMPLEMENT_DYNCREATE(CCarInfoView, CFormView)

CCarInfoView::CCarInfoView()
	: CFormView(CCarInfoView::IDD)
{
	//{{AFX_DATA_INIT(CCarInfoView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	bInitDlg = true;
}

CCarInfoView::~CCarInfoView()
{
}

void CCarInfoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCarInfoView)
	DDX_Control(pDX, IDC_LIST_DAT_CI, m_lstCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCarInfoView, CFormView)
	//{{AFX_MSG_MAP(CCarInfoView)
	ON_WM_SIZE()
	ON_COMMAND(MENU_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarInfoView diagnostics

#ifdef _DEBUG
void CCarInfoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCarInfoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCarInfoView message handlers

void CCarInfoView::ShowData()
{
	//g_objCECUCarInfoMap

	//pid的描述配置信息
	//const MyConfig::CVariableVector &t_vCmdList =	g_objCConfigEntry.GetService("SNSINFO");//.GetVarObj("01");
	CString aa = GetDocument()->GetPathName() ;
	if(aa == "")
	{
		GetDocument()->m_objCECUCarInfoMap =g_objCECUCarInfoMap; ;
		GetDocument()->SetModifiedFlag();
	}
	
	CListCtrl &theCtrl = m_lstCtrl;
	theCtrl.DeleteAllItems();


	CECUCarInfoMap::const_iterator iterECU ;
	CCarInfoMap::const_iterator iterPID ;

	int index = 0;

	for(iterECU = GetDocument()->m_objCECUCarInfoMap.begin();
		iterECU != GetDocument()->m_objCECUCarInfoMap.end();
		iterECU++)
	{
		for(iterPID= iterECU->second.begin();iterPID != iterECU->second.end(); iterPID++)
		{
			
			theCtrl.InsertItem (index,MyUtility::CBaseEncode::UIntToString(iterECU->first).c_str());
			
			theCtrl.SetItemText (index,1,MyUtility::CBaseEncode::UIntToHexString(iterPID->first).c_str());

			string name = g_objCConfigEntry.GetService("CARINFO").GetVarObj(MyUtility::CBaseEncode::IntToHexString(iterPID->first)).GetValue();
			string bal = g_objCConfigEntry.GetService("CARINFO").GetVarObj(MyUtility::CBaseEncode::IntToHexString(iterPID->first)).GetDesc();
			theCtrl.SetItemText (index,2,name.c_str());
			theCtrl.SetItemText (index,3,bal.c_str());
			

			theCtrl.SetItemText (index,4,iterPID->second.c_str());


			index++;

		}
	}
}

void CCarInfoView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	CListCtrl &theCtrl = m_lstCtrl;
	// TODO: Add your specialized code here and/or call the base class

	theCtrl.SetExtendedStyle
   (theCtrl.GetExtendedStyle()|LVS_EX_HEADERDRAGDROP|LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
		theCtrl.InsertColumn (0,"ECU",LVCFMT_LEFT,50);
		theCtrl.InsertColumn (1,"PID",LVCFMT_LEFT,50);
		theCtrl.InsertColumn (2,"名称",LVCFMT_LEFT,250);
		theCtrl.InsertColumn (3,"单位",LVCFMT_LEFT,50);
		theCtrl.InsertColumn (4,"值",LVCFMT_LEFT,350);


		ShowData();

		//bInitDlg = false;

		
	CRect rc;
	GetWindowRect (&rc);
	//theCtrl.MoveWindow (0,0,rc.Width (),rc.Height ());

	OnSize(0,rc.Width (),rc.Height ());


	
}

void CCarInfoView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);


	// TODO: Add your message handler code here

	//if(m_Button.GetSafeHwnd()   !=   NULL) 

	//if(!bInitDlg)
	if(m_lstCtrl.GetSafeHwnd()   !=   NULL) 
	{
		//m_edt.MoveWindow (140,0,cx-(140+10),100);
		m_lstCtrl.MoveWindow (0,0,cx,cy);
	}
	//SetScrollSizes(MM_TEXT,CSize(cx,cy)); 
	Invalidate(TRUE);
	
}

void CCarInfoView::OnRefresh() 
{
	// TODO: Add your command handler code here
	//取快照
	GetDocument()->m_objCECUCarInfoMap =g_objCECUCarInfoMap; 
	GetDocument()->SetModifiedFlag();

	

	ShowData();
}
