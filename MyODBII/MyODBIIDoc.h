// MyODBIIDoc.h : interface of the CMyODBIIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYODBIIDOC_H__9CDF6C8E_E512_4D14_9067_B1140ED1D362__INCLUDED_)
#define AFX_MYODBIIDOC_H__9CDF6C8E_E512_4D14_9067_B1140ED1D362__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CODBIIRawdataVector.h"

class CMyODBIIDoc : public CDocument
{
protected: // create from serialization only
	CMyODBIIDoc();
	DECLARE_DYNCREATE(CMyODBIIDoc)

// Attributes
public:
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyODBIIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_iOrgSize;
	CODBIIRawdataVector m_CODBIIRawdataVector;
	virtual ~CMyODBIIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyODBIIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SaveLog(CArchive &av);
	void ReadLog(CArchive &av);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYODBIIDOC_H__9CDF6C8E_E512_4D14_9067_B1140ED1D362__INCLUDED_)
