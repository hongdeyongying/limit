#if !defined(AFX_SENSORSDATADOC_H__AE2A8FF5_52CD_46F0_AB9F_C36EA29B757C__INCLUDED_)
#define AFX_SENSORSDATADOC_H__AE2A8FF5_52CD_46F0_AB9F_C36EA29B757C__INCLUDED_

#include "CSensorDataVectorMap.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SensorsDataDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSensorsDataDoc document

class CSensorsDataDoc : public CDocument
{
protected:
	CSensorsDataDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSensorsDataDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSensorsDataDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	CECUSensorDataVectorMap m_objCECUSensorDataVectorMap;
	virtual ~CSensorsDataDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSensorsDataDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Save(CArchive &av);
	void Load(CArchive &av);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENSORSDATADOC_H__AE2A8FF5_52CD_46F0_AB9F_C36EA29B757C__INCLUDED_)
