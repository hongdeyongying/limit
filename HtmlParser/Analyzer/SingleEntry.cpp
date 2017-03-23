// SingleEntry.cpp: implementation of the CSingleEntry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SingleEntry.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSingleEntry::CSingleEntry()
{
	m_pMutex = new CMutex (
		TRUE,                                            // Initially owned
		_T ("2A4F4F41-2FC1-11D2-8E53-006008A82731")      // Mutex name
	);
	
	m_pMutex->Lock();
		

}
CSingleEntry::CSingleEntry(const char * sid)
{
	m_pMutex = new CMutex (
		TRUE,                                            // Initially owned
		sid      // Mutex name
	);
	
	m_pMutex->Lock();
}

CSingleEntry::~CSingleEntry()
{
	m_pMutex->Unlock();

	delete m_pMutex;
}
