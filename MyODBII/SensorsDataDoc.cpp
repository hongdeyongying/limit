// SensorsDataDoc.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "SensorsDataDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataDoc

IMPLEMENT_DYNCREATE(CSensorsDataDoc, CDocument)

CSensorsDataDoc::CSensorsDataDoc()
{
}

BOOL CSensorsDataDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CSensorsDataDoc::~CSensorsDataDoc()
{
}


BEGIN_MESSAGE_MAP(CSensorsDataDoc, CDocument)
	//{{AFX_MSG_MAP(CSensorsDataDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataDoc diagnostics

#ifdef _DEBUG
void CSensorsDataDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSensorsDataDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataDoc serialization

void CSensorsDataDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		Save(ar);
	}
	else
	{
		// TODO: add loading code here
		Load(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataDoc commands

void CSensorsDataDoc::Save(CArchive &ar)
{
	CECUSensorDataVectorMap::const_iterator iterECU ;
	CSensorDataVectorMap::const_iterator iterPID ;
	CSensorDataVector::const_iterator iterPIDValue ;

	ar << g_objCECUSensorDataVectorMap.size();

	for(iterECU = m_objCECUSensorDataVectorMap.begin();
		iterECU != m_objCECUSensorDataVectorMap.end();
		iterECU++)
	{
		ar << iterECU->first << iterECU->second.size();

		for(iterPID= iterECU->second.begin();iterPID != iterECU->second.end(); iterPID++)
		{
			ar << iterPID->first << iterPID->second.size();

			for(iterPIDValue = iterPID->second.begin();
			iterPIDValue != iterPID->second.end();
			iterPIDValue++)
			{
				ar << iterPIDValue->m_uTime ;
				CString str = iterPIDValue->m_sValue.c_str();

				ar << str;
			}

		}
	}
}


void CSensorsDataDoc::Load(CArchive &ar)
{
	m_objCECUSensorDataVectorMap.clear();

	int ecuNum = 0;
	int ecuId = 0;
	int ecuPIDNum = 0;
	int PID = 0;
	int PIDValueNum = 0;

	CString val;
	unsigned int tm;

	ar >> ecuNum;

	for(int i=0;i<ecuNum;i++)
	{
		ar >> ecuId >> ecuPIDNum;
		m_objCECUSensorDataVectorMap[ecuId].clear();

		for(int j=0;j<ecuPIDNum;j++)
		{
			ar >> PID >> PIDValueNum;

			m_objCECUSensorDataVectorMap[ecuId][PID].clear();

			for(int k = 0;k<PIDValueNum;k++)
			{
				ar >> tm >> val;

				string a((LPCTSTR)val);

				m_objCECUSensorDataVectorMap[ecuId][PID].push_back(CSensorData(tm,a));

			}

		}
	}
}