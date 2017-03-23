#if !defined(AFX_CARINFODOC_H__F2C9E9B3_90B9_4574_883E_90C69D061E67__INCLUDED_)
#define AFX_CARINFODOC_H__F2C9E9B3_90B9_4574_883E_90C69D061E67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarInfoDoc.h : header file
//
#include "SensorsDataView.h"

#include "CSensorDataVectorMap.h"
#include "utility/CBaseEncode.h"
#include "utility/CTime.h"
/////////////////////////////////////////////////////////////////////////////
// CCarInfoDoc document

class CCarInfoDoc : public CDocument
{
protected:
	CCarInfoDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCarInfoDoc)

// Attributes
public:
	CECUCarInfoMap m_objCECUCarInfoMap;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarInfoDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	void Read(CArchive &ar);
	void Save(CArchive & ar);
	virtual ~CCarInfoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CCarInfoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARINFODOC_H__F2C9E9B3_90B9_4574_883E_90C69D061E67__INCLUDED_)
