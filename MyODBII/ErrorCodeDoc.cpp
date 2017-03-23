// ErrorCodeDoc.cpp : implementation file
//

#include "stdafx.h"
#include "MyODBII.h"
#include "ErrorCodeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeDoc

IMPLEMENT_DYNCREATE(CErrorCodeDoc, CDocument)

CErrorCodeDoc::CErrorCodeDoc()
{
}

BOOL CErrorCodeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CErrorCodeDoc::~CErrorCodeDoc()
{
}


BEGIN_MESSAGE_MAP(CErrorCodeDoc, CDocument)
	//{{AFX_MSG_MAP(CErrorCodeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeDoc diagnostics

#ifdef _DEBUG
void CErrorCodeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CErrorCodeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeDoc serialization

void CErrorCodeDoc::Serialize(CArchive& ar)
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
// CErrorCodeDoc commands

void CErrorCodeDoc::Save(CArchive &ar)
{
	ar << m_objCTCDSet.size();

	CTCDSet::const_iterator iter;


	for(iter = m_objCTCDSet.begin();iter != m_objCTCDSet.end();iter++)
	{
		CString aa = (*iter).c_str();
		
		ar << aa;

	}
}

void CErrorCodeDoc::Load(CArchive &ar)
{
	int cnt = 0;

	ar >> cnt;

	m_objCTCDSet.clear();

	
	for(int i=0;i<cnt;i++)
	{
		CString tt;

		ar >> tt;

		string aa ((LPCTSTR)tt);

		m_objCTCDSet.insert(aa);

	}
}
