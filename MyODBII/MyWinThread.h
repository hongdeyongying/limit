// MyWinThread.h: interface for the CMyWinThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWINTHREAD_H__B5EDFE69_40AC_4A95_B9EB_0DC23AC863BC__INCLUDED_)
#define AFX_MYWINTHREAD_H__B5EDFE69_40AC_4A95_B9EB_0DC23AC863BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum CMyWinThread_WORK_STATE
{
	THREAD_IDLE,THREAD_RUN,THREAD_STOP
};

class CMyWinThread  
{
public:
	bool IsRunning();
	int m_iCmd;
	int Stop();
	void StartWork();
	CMyWinThread();
	virtual ~CMyWinThread();

	virtual enum CMyWinThread_WORK_STATE GetState(){return m_eState;};

protected:
	virtual void Run() =0;
	static UINT WorkThread( LPVOID pParam );

	enum CMyWinThread_WORK_STATE m_eState;
private:

	CWinThread *m_pCWinThread;
};

#endif // !defined(AFX_MYWINTHREAD_H__B5EDFE69_40AC_4A95_B9EB_0DC23AC863BC__INCLUDED_)
