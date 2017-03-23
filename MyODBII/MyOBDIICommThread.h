// MyOBDIICommThread.h: interface for the CMyOBDIICommThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYOBDIICOMMTHREAD_H__5C81A0AE_A5C0_40CD_96B7_B6C0CD148257__INCLUDED_)
#define AFX_MYOBDIICOMMTHREAD_H__5C81A0AE_A5C0_40CD_96B7_B6C0CD148257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyWinThread.h"

#include "SettingDlg.h"

#include "CSerial.h"

#include  "global_var.h"


#include <string>
using namespace std;

#include "CODBIIRawdataVector.h"

#include "BaseFormat.h"

class CMyOBDIICommThread:public CMyWinThread  
{
public:
	int DoFreezeCommand();
	int DoCarInfoCommand();
	void SetWorkMode(int mode);
	CMyOBDIICommThread();
	virtual ~CMyOBDIICommThread();

protected:
	int DoOrderCommand();
	int DoTcdCommand();
	int DoSnsCommand();
	int DoSysCommand();
	int DoCommand(const string & req,string &res);
	int InitCommEnv();
	virtual void Run();

	void RunInAuto();
	void RunInCmd();

private:
	int m_iWorkMode;
	int ParseCommand(const string & req,const string & res,string * mid = NULL);
	int m_iErrorCount,m_iWaitLoop;
	void SetResString(const string &res="" ,int sts = 0);
	inline void SetReqString(const string &req="" );
	int m_iOBDStatus;
	CSerial m_objCSerial;

	CODBIIRawdata m_objCODBIIRawdata;
};

#endif // !defined(AFX_MYOBDIICOMMTHREAD_H__5C81A0AE_A5C0_40CD_96B7_B6C0CD148257__INCLUDED_)
