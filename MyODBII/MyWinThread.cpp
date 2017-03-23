// MyWinThread.cpp: implementation of the CMyWinThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "MyWinThread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyWinThread::CMyWinThread()
{
	m_pCWinThread = NULL;
	m_eState = THREAD_IDLE;
}

CMyWinThread::~CMyWinThread()
{

}

UINT CMyWinThread::WorkThread(LPVOID pParam)
{
	CMyWinThread *pCMyWinThread = (CMyWinThread *) pParam;

	pCMyWinThread->Run();

	return 0;
}

void CMyWinThread::StartWork()
{
		m_pCWinThread =  AfxBeginThread(CMyWinThread::WorkThread, this); 

		m_eState = THREAD_RUN;
}

int CMyWinThread::Stop()
{
	if((m_pCWinThread != NULL) &&(m_eState != THREAD_STOP))
	{
		DWORD t_dwExit = 0;
		TerminateThread(m_pCWinThread-> m_hThread,t_dwExit); 
		m_eState = THREAD_STOP;
	}
	return 0;
}

bool CMyWinThread::IsRunning()
{
	return (m_eState == THREAD_RUN);
}
