// SensorsDataView.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "SensorsDataView.h"

#include "CSensorDataVectorMap.h"
#include "utility/CBaseEncode.h"
#include "utility/CTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataView

IMPLEMENT_DYNCREATE(CSensorsDataView, CListView)

CSensorsDataView::CSensorsDataView()
{
}

CSensorsDataView::~CSensorsDataView()
{
}


BEGIN_MESSAGE_MAP(CSensorsDataView, CListView)
	//{{AFX_MSG_MAP(CSensorsDataView)
	ON_COMMAND(MENU_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataView drawing

void CSensorsDataView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataView diagnostics

#ifdef _DEBUG
void CSensorsDataView::AssertValid() const
{
	CListView::AssertValid();
}

void CSensorsDataView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataView message handlers

void CSensorsDataView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	CListCtrl &t_lstLog = GetListCtrl();
		t_lstLog.SetExtendedStyle
   (t_lstLog.GetExtendedStyle()|LVS_EX_HEADERDRAGDROP|LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
		t_lstLog.InsertColumn (0,"ECU",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (1,"PID",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (2,"名称",LVCFMT_LEFT,250);
		t_lstLog.InsertColumn (3,"单位",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (4,"当前值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (5,"平均值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (6,"最小值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (7,"最大值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (8,"取样数量",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (9,"取样开始时间",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (10,"取样结束时间",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (11,"服务名",LVCFMT_LEFT,50);



		ShowData();
	
}

BOOL CSensorsDataView::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.style  |= LVS_REPORT;	
	return CListView::PreCreateWindow(cs);
}

void CSensorsDataView::ShowData()
{
	//pid的描述配置信息
	//const MyConfig::CVariableVector &t_vCmdList =	g_objCConfigEntry.GetService("SNSINFO");//.GetVarObj("01");
	CString aa = GetDocument()->GetPathName() ;
	if(aa == "")
	{
		GetDocument()->m_objCECUSensorDataVectorMap =g_objCECUSensorDataVectorMap; ;
		GetDocument()->SetModifiedFlag();
	}
	
	CListCtrl &theCtrl = GetListCtrl();
	theCtrl.DeleteAllItems();


	CECUSensorDataVectorMap::const_iterator iterECU ;
	CSensorDataVectorMap::const_iterator iterPID ;

	int index = 0;

	for(iterECU = GetDocument()->m_objCECUSensorDataVectorMap.begin();
		iterECU != GetDocument()->m_objCECUSensorDataVectorMap.end();
		iterECU++)
	{
		for(iterPID= iterECU->second.begin();iterPID != iterECU->second.end(); iterPID++)
		{
			
			theCtrl.InsertItem (index,MyUtility::CBaseEncode::UIntToString(iterECU->first).c_str());
			
			theCtrl.SetItemText (index,1,MyUtility::CBaseEncode::UIntToHexString(iterPID->first).c_str());

			string name = g_objCConfigEntry.GetService("SNSINFO").GetVarObj(MyUtility::CBaseEncode::IntToHexString(iterPID->first)).GetValue();
			string bal = g_objCConfigEntry.GetService("SNSINFO").GetVarObj(MyUtility::CBaseEncode::IntToHexString(iterPID->first)).GetDesc();
			theCtrl.SetItemText (index,2,name.c_str());
			theCtrl.SetItemText (index,3,bal.c_str());
			/*
			t_lstLog.InsertColumn (0,"ECU",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (1,"PID",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (2,"名称",LVCFMT_LEFT,250);
		t_lstLog.InsertColumn (3,"单位",LVCFMT_LEFT,50);
		t_lstLog.InsertColumn (4,"当前值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (5,"平均值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (6,"最小值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (7,"最大值",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (8,"取样数量",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (9,"取样开始时间",LVCFMT_LEFT,100);
		t_lstLog.InsertColumn (10,"取样结束时间",LVCFMT_LEFT,100);
			*/

			string cur,alv,min,max,cnt,btime,etime;

			CalVal(iterPID->second,cur,alv,min,max,cnt,btime,etime);

			theCtrl.SetItemText (index,4,cur.c_str());
			theCtrl.SetItemText (index,5,alv.c_str());
			theCtrl.SetItemText (index,6,min.c_str());
			theCtrl.SetItemText (index,7,max.c_str());
			theCtrl.SetItemText (index,8,cnt.c_str());
			theCtrl.SetItemText (index,9,btime.c_str());
			theCtrl.SetItemText (index,10,etime.c_str());
			theCtrl.SetItemText (index,11,"01");


			index++;

		}
	}

	//theCtrl.InsertItem(0,"VIN");

	//theCtrl.SetItemText(0,3,::g_objCECUCarInfoMap[1][1].c_str());

	//theCtrl.SetItemText(0,2,::g_objCECUCarInfoMap[1][2].c_str());
}

void CSensorsDataView::OnRefresh() 
{
	// TODO: Add your command handler code here
	
	//取快照
	GetDocument()->m_objCECUSensorDataVectorMap =g_objCECUSensorDataVectorMap; ;
	GetDocument()->SetModifiedFlag();

	

	ShowData();
}

//DEL string CSensorsDataView::GetCurrent(CSensorDataVector &v)
//DEL {
//DEL 	string res("");
//DEL 	if(v.size() != 0)
//DEL 	{
//DEL 		res = v.at(v.size() -1 ).m_sValue;
//DEL 	}
//DEL 
//DEL 	return res;
//DEL }

void CSensorsDataView::CalVal(const CSensorDataVector &v, string &cur, string &salv, string &smin, string &smax, string &cnt, string &btime, string &etime)
{
	if(v.size() == 0)
		return;

	cur = v.at(v.size() -1).m_sValue ;

	cnt = MyUtility::CBaseEncode::UIntToString(v.size());

	MyUtility::CTime btm(v.at(v.size() -1).m_uTime),etm(v.at(0).m_uTime);

	btime = btm.Format();
	etime = etm.Format();

	double sum = 0,tmp=0,min=0,max=0;

	for(int i=0;i<v.size();i++)
	{
		tmp = MyUtility::CBaseEncode::StringToInt(v.at(i).m_sValue);

		if(i == 0) {min = tmp;max=tmp;}

		if(tmp > max) max = tmp;

		if(tmp < min) min = tmp;

		sum += tmp;


	}
	salv = MyUtility::CBaseEncode::IntToString(sum/v.size());
	smin = MyUtility::CBaseEncode::IntToString(min);
	smax = MyUtility::CBaseEncode::IntToString(max);

}

CSensorsDataDoc * CSensorsDataView::GetDocument()
{
	//ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSensorsDataDoc)));
	return (CSensorsDataDoc*)m_pDocument;
}


