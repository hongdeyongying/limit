// CarInfoDoc.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "CarInfoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarInfoDoc

IMPLEMENT_DYNCREATE(CCarInfoDoc, CDocument)

CCarInfoDoc::CCarInfoDoc()
{
}

BOOL CCarInfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CCarInfoDoc::~CCarInfoDoc()
{
}


BEGIN_MESSAGE_MAP(CCarInfoDoc, CDocument)
	//{{AFX_MSG_MAP(CCarInfoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarInfoDoc diagnostics

#ifdef _DEBUG
void CCarInfoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCarInfoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCarInfoDoc serialization

void CCarInfoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		Save(ar);
	}
	else
	{
		// TODO: add loading code here
		Read(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCarInfoDoc commands

void CCarInfoDoc::Save(CArchive &ar)
{
	CECUCarInfoMap::const_iterator iterECU ;
	CCarInfoMap::const_iterator iterPID ;

	ar << m_objCECUCarInfoMap.size();

	for(iterECU = m_objCECUCarInfoMap.begin();
		iterECU != m_objCECUCarInfoMap.end();
		iterECU++)
	{
		ar << iterECU->first << iterECU->second.size();

		for(iterPID= iterECU->second.begin();iterPID != iterECU->second.end(); iterPID++)
		{
			ar << iterPID->first ;

			CString aa = iterPID->second.c_str();

			ar << aa;

		}
	}
}

void CCarInfoDoc::Read(CArchive &ar)
{
	unsigned int row;

	ar >> row;

	for(int i=0;i<row;i++)
	{
		unsigned int ecu,sz;

		ar >> ecu >> sz;

		for(int j=0;j<sz;j++)
		{
			unsigned int pid ;CString val;

			ar >> pid >> val;

			m_objCECUCarInfoMap[ecu][pid] = val;
		}
	}
}
