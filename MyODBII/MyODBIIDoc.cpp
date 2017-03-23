// MyODBIIDoc.cpp : implementation of the CMyODBIIDoc class
//

#include "stdafx.h"
#include "MyODBII.h"

#include "MyODBIIDoc.h"

#include "CBaseEncode.h"

#include "ModulePath.h"
#include "utility/CTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIDoc

IMPLEMENT_DYNCREATE(CMyODBIIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyODBIIDoc, CDocument)
	//{{AFX_MSG_MAP(CMyODBIIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIDoc construction/destruction

CMyODBIIDoc::CMyODBIIDoc()
{
	// TODO: add one-time construction code here
	m_iOrgSize = 0;
}

CMyODBIIDoc::~CMyODBIIDoc()
{
}

BOOL CMyODBIIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyODBIIDoc serialization

void CMyODBIIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		SaveLog(ar);
	}
	else
	{
		// TODO: add loading code here
		
		ReadLog(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIDoc diagnostics

#ifdef _DEBUG
void CMyODBIIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyODBIIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyODBIIDoc commands

void CMyODBIIDoc::SaveLog(CArchive &av)
{
	CODBIIRawdataVector::const_iterator iter;

	av << m_CODBIIRawdataVector.size();

	CString res ,req;

		
	for(iter = m_CODBIIRawdataVector.begin(); iter != m_CODBIIRawdataVector.end();iter++)
	{
		res = MyUtility::CBaseEncode::CharStrToHexStr(iter->m_sRes).c_str();
		req = MyUtility::CBaseEncode::CharStrToHexStr(iter->m_sReq).c_str();

		av << iter->m_iStatus 
			<< res
			<< req
			<< iter->m_uID 
			<< iter->m_uReqTime 
			<<  iter->m_uSpendTime ;
	}
}

void CMyODBIIDoc::ReadLog(CArchive &av)
{
	CODBIIRawdata t_CODBIIRawdata;

	m_CODBIIRawdataVector.clear();

	unsigned int t_Row = 0;

	av >> t_Row;

	CString res ,req;

		
	for(int i=0;i<t_Row;i++)
	{

		av >> t_CODBIIRawdata.m_iStatus 
			>> res
			>> req
			>> t_CODBIIRawdata.m_uID 
			>> t_CODBIIRawdata.m_uReqTime 
			>> t_CODBIIRawdata.m_uSpendTime ;

		t_CODBIIRawdata.m_sReq =MyUtility::CBaseEncode::HexStrToCharStr((LPCTSTR)req);
		t_CODBIIRawdata.m_sRes =MyUtility::CBaseEncode::HexStrToCharStr((LPCTSTR)res);

		m_CODBIIRawdataVector.push_back(t_CODBIIRawdata);
		t_CODBIIRawdata.Clear();
	}

	m_iOrgSize = t_Row;
}

BOOL CMyODBIIDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDocument::OnSaveDocument(lpszPathName);
}

//DEL void CMyODBIIDoc::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	std::string t_svlog;
//DEL 
//DEL 	if(lpszPathName == NULL)
//DEL 	{
//DEL 		t_svlog = CModulePath::GetInstance()->m_sCnfDir + "\\" + MyUtility::CTime::GetCurrentTime().Format("yyyymmdd") +".myobdii";
//DEL 
//DEL 		lpszPathName = t_svlog.c_str();
//DEL 	}
//DEL 	
//DEL 	CDocument::SetPathName(lpszPathName, bAddToMRU);
//DEL }
