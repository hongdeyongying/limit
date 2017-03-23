#if !defined(AFX_ERRORCODEDOC_H__7E82086E_E8AE_46B7_9731_AACF6421788E__INCLUDED_)
#define AFX_ERRORCODEDOC_H__7E82086E_E8AE_46B7_9731_AACF6421788E__INCLUDED_


#include "SensorsDataView.h"

#include "CSensorDataVectorMap.h"
#include "utility/CBaseEncode.h"
#include "utility/CTime.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ErrorCodeDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CErrorCodeDoc document

class CErrorCodeDoc : public CDocument
{
protected:
	CErrorCodeDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CErrorCodeDoc)

// Attributes
public:
	CTCDSet m_objCTCDSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CErrorCodeDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CErrorCodeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CErrorCodeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Load(CArchive &ar);
	void Save(CArchive &ar);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERRORCODEDOC_H__7E82086E_E8AE_46B7_9731_AACF6421788E__INCLUDED_)
