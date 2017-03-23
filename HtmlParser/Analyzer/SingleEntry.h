// SingleEntry.h: interface for the CSingleEntry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEENTRY_H__8886CC04_E4C0_4705_956F_79A53800AA18__INCLUDED_)
#define AFX_SINGLEENTRY_H__8886CC04_E4C0_4705_956F_79A53800AA18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxmt.h>

class CSingleEntry  
{
	
	CMutex * m_pMutex;
public:
	CSingleEntry(const char * sid);
	CSingleEntry();
	virtual ~CSingleEntry();

};

#endif // !defined(AFX_SINGLEENTRY_H__8886CC04_E4C0_4705_956F_79A53800AA18__INCLUDED_)
