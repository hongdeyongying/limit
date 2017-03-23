// MyOBDIICommThread.cpp: implementation of the CMyOBDIICommThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "MyOBDIICommThread.h"

#include "utility/CBaseEncode.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

enum OBDII_STATUS
{
	//com
	OBDII_COM_CLOSE,
	OBDII_COM_OPEN,
	OBDII_COM_ERROR,

	//at
	OBDII_SYS_BEGIN,
	OBDII_SYS_END,

	// 01 
	OBDII_SENSOR_BEGIN,
	OBDII_SENSOR_END,

	// 02 
	OBDII_FRAME_BEGIN,
	OBDII_FRAME_END,

	// 03 07
	OBDII_TC_BEGIN,
	OBDII_TC_END,

	// order list
	OBDII_COMMAND_BEGIN,
	OBDII_COMMAND_END,

	// 09
	OBDII_CARINFO_BEGIN,
	OBDII_CARINFO_END,

	// sleep
	ODBII_LOOP_END


};

CMyOBDIICommThread::CMyOBDIICommThread()
{
	m_iOBDStatus = OBDII_COM_CLOSE ;

	m_iErrorCount = 0;


	//工作模式
	/*
	1 执行手工命令
	*/
	m_iWorkMode = 0; // 自动，读sns 、 tcd 
	

}

CMyOBDIICommThread::~CMyOBDIICommThread()
{

}

void CMyOBDIICommThread::Run()
{
	

	m_eState = THREAD_RUN;

	switch(m_iWorkMode)
	{
	case 0://auto
		RunInAuto();break;
	case 1://cmd
		RunInCmd();break;
	default:
		RunInAuto();
	}

}
void CMyOBDIICommThread::RunInCmd()
{
	m_iWaitLoop = atoi(g_objCConfigEntry.GetService("MAIN").GetVarVal("loop_internal").c_str());

	int t_iRetcd = 0;


	int t_bContinue =true;

	int t_iOBDStatus;
	

	while(t_bContinue)
	{
		switch(m_iOBDStatus)
		{
		case OBDII_COM_CLOSE:
			// 1. init com env
			InitCommEnv();
			break;
		case OBDII_COM_ERROR:
			t_bContinue = false;
			SetReqString("串口错误");
			break;
		case OBDII_COM_OPEN:
			m_iOBDStatus = OBDII_SYS_BEGIN ;
			break;
		case OBDII_SYS_BEGIN:
			//ATZ
			DoSysCommand();				
			break;
			//ATE0
			//ATL0
		case OBDII_SYS_END:
			m_iOBDStatus = OBDII_COMMAND_BEGIN ;
			t_iOBDStatus = OBDII_SENSOR_BEGIN;
			//如果还有，继续
			//m_iOBDStatus = OBDII_SYS_BEGIN ;
			//否则,采集sensors信息
			break;
		case OBDII_COMMAND_BEGIN:
			DoOrderCommand();
			break;
		case OBDII_COMMAND_END:
			AfxGetApp()->PostThreadMessage(MYMSG_ORDER_EXEC_END,0,0);
			SetReqString("命令执行完毕");
			t_bContinue = false;
			break;
		default:
			t_iOBDStatus = m_iOBDStatus;
			m_iOBDStatus = OBDII_COMMAND_BEGIN ;
			//t_bContinue = false;
			break;

			
		}
	}

	m_iOBDStatus = t_iOBDStatus;

	
	m_eState = THREAD_STOP;
	SetResString("退出",0);

}
void CMyOBDIICommThread::RunInAuto()
{
	
	m_iWaitLoop = atoi(g_objCConfigEntry.GetService("MAIN").GetVarVal("loop_internal").c_str());

	int t_iRetcd = 0;

//	m_eState = THREAD_RUN;

	int t_bContinue =true;

	//m_iOBDStatus = OBDII_COM_CLOSE ;

	m_iErrorCount = 0;

	

	while(t_bContinue)
	{
		switch(m_iOBDStatus)
		{
		case OBDII_COM_CLOSE:
			// 1. init com env
			InitCommEnv();
			break;
		case OBDII_COM_ERROR:
			t_bContinue = false;
			break;
		case OBDII_COM_OPEN:
			m_iOBDStatus = OBDII_SYS_BEGIN ;
			break;
		case OBDII_SYS_BEGIN:
			//ATZ
			DoSysCommand();				
			break;
			//ATE0
			//ATL0
		case OBDII_SYS_END:
			//如果还有，继续
			//m_iOBDStatus = OBDII_SYS_BEGIN ;
			//否则,采集sensors信息
			m_iOBDStatus = OBDII_SENSOR_BEGIN ;
			break;
		case OBDII_SENSOR_BEGIN:
			DoSnsCommand();
			break;
		case OBDII_SENSOR_END:
			//如果还有，继续
			//m_iOBDStatus = OBDII_SENSOR_BEGIN ;
			//否则,采集sensors信息
			m_iOBDStatus = OBDII_TC_BEGIN ;
			break;
		case OBDII_TC_BEGIN:
			DoTcdCommand() ;
			break;

		case OBDII_TC_END:
			//0101
			//否则,一轮结束
			m_iOBDStatus = OBDII_CARINFO_BEGIN ;
			break;
		case OBDII_CARINFO_BEGIN:
			DoCarInfoCommand();
			break;
		case OBDII_CARINFO_END:
			m_iOBDStatus = OBDII_FRAME_BEGIN ;
			break;
		case OBDII_FRAME_BEGIN:
			DoFreezeCommand();
			break;
		case OBDII_FRAME_END:
			m_iOBDStatus = ODBII_LOOP_END ;
			break;


		case ODBII_LOOP_END:
			if(m_iWaitLoop > 0)
			{
				SetReqString("一轮结束，休息" + g_objCConfigEntry.GetService("MAIN").GetVarVal("loop_internal") + "ms");

				SetResString("再取",0);
				Sleep(m_iWaitLoop);
				m_iOBDStatus = OBDII_SENSOR_BEGIN ;
			}
			else
			{
				SetResString("采集结束......",0);
				t_bContinue = false;
			}
			
			break;
		default:
			//一般不应该
			t_bContinue = false;
			break;

			
		}
	}

	
	m_eState = THREAD_STOP;
	SetReqString("串口错误");
	SetResString("退出",0);

}

int CMyOBDIICommThread::InitCommEnv()
{
	if(g_objCConfigEntry.GetService("MAIN").GetType() == "virtual" )
	{
		m_iOBDStatus = OBDII_COM_OPEN ;
		return 0;
	}
	//g_objCConfigEntry.GetService("MAIN").GetVarVal("cmd");


	SetReqString("关闭串口");

	m_objCSerial.Close();

	SetResString();

	SetReqString("打开串口");

	BOOL bRes = m_objCSerial.Open(g_pSettingDlg->m_iCom,g_pSettingDlg->m_iBoundrate);

	if(bRes)
	{		
		m_iOBDStatus = OBDII_COM_OPEN ;
		SetResString("成功",0);

		//m_iErrorCount = 0;
		return 0;
	}
	else
	{
		m_iOBDStatus = OBDII_COM_ERROR ;
		SetResString("失败",-1);
	//	AfxMessageBox(STR_ERR_COMM_OPEN);
		return 1;
	}
}

int CMyOBDIICommThread::DoCommand(const string &req, string &res)
{

	if(g_objCConfigEntry.GetService("MAIN").GetType() == "virtual" )
	{
		res = g_objCConfigEntry.GetService("VCMD").GetVarVal(req);
		return 0;
	}
	//


	int t_iRetcd =-1;

	int t_iRecv = 0;

	string t_req = req + "\r";

	int t_iSend = m_objCSerial.SendData(t_req.data(),t_req.size());

	char t_szTemp[102400] ;

	for(int i=0;i<atoi(g_objCConfigEntry.GetService("MAIN").GetVarVal("retry_times").c_str() );i++)  // g_objCConfigEntry.GetService("MAIN").GetVarVal("loop_internal") 
	{

		memset(t_szTemp,0,sizeof(t_szTemp));

		t_iRecv = m_objCSerial.ReadData(t_szTemp,sizeof(t_szTemp));


		if(t_iRecv != 0)
		{
			res.append(t_szTemp,t_iRecv);
			
			if( res.find('>') != string::npos)
			{
				t_iRetcd = 0;
				break;
			}
			
			if( res.size() > 10240)
			{
				t_iRetcd = -2;
				break;
			}
		}
		else
		{
			t_iRetcd = -3;
		}
		Sleep(atoi(g_objCConfigEntry.GetService("MAIN").GetVarVal("retry_times").c_str() )); // 需要延迟，否则反映不过来

	}

	if(t_iRetcd != 0)
	{
		m_iErrorCount++;

		if(m_iErrorCount < 3)
			m_iOBDStatus = OBDII_COM_CLOSE ;
		else
			m_iOBDStatus = OBDII_COM_ERROR ;

	}
	else
	{
		m_iErrorCount = 0;
	}

	
	return t_iRetcd;
	
}

void CMyOBDIICommThread::SetReqString(const string & req)
{
	m_objCODBIIRawdata.Clear();

	m_objCODBIIRawdata.m_sReq = req;
	m_objCODBIIRawdata.m_uID = g_objCODBIIRawdataVector.size();
	m_objCODBIIRawdata.m_uReqTime = time(NULL);

	m_objCODBIIRawdata.m_uSpendTime = GetTickCount();
}

void CMyOBDIICommThread::SetResString(const string & res,int sts)
{
	if(res != "")
		m_objCODBIIRawdata.m_sRes = res;

	m_objCODBIIRawdata.m_iStatus = sts;

	m_objCODBIIRawdata.m_uSpendTime = GetTickCount() - m_objCODBIIRawdata.m_uSpendTime;

	
	g_objCODBIIRawdataVector.push_back(m_objCODBIIRawdata);



	//m_objCODBIIRawdata.Clear();
}

int CMyOBDIICommThread::DoSysCommand()
{
	const MyConfig::CVariableVector &t_vCmdList =	g_objCConfigEntry.GetService("SYSCMD").GetVarVectorObj("cmd");

	static int i = 0;

	if(i < t_vCmdList.size())
	{
		SetReqString(t_vCmdList.at(i++).GetValue());

	//	SetReqString("ATZ");
		int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);

		if(t_iRetcd == 0)	
		{
			//m_iOBDStatus = OBDII_SYS_END ;
			t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
			SetResString("",t_iRetcd );
		}
		else
		{
			i =0;
		}
		
	}
	else
	{
		i =0;
		m_iOBDStatus = OBDII_SYS_END ;
	}

	return t_vCmdList.size()-i-1;
}

int CMyOBDIICommThread::ParseCommand(const string &req,const string & res,string * mid)
{
	int t_iRetcd = 0;

	string m_sFormatMethod = g_objCConfigEntry.GetService("FORMAT").GetVarVal(req);
	string m_sFormatMethod_Para = g_objCConfigEntry.GetService("FORMAT").GetVarObj(req).GetDesc();

	string m_sMid;
	
	CBaseFormat *pCBaseFormat = g_Factory.GetSingletonInstance(m_sFormatMethod,m_sFormatMethod_Para);
		
	if(pCBaseFormat != NULL)
	{
		t_iRetcd = pCBaseFormat->DoTranslate(res,m_sMid);
		 
		if(mid != NULL)
			*mid = m_sMid;

	}


	return t_iRetcd;
}

int CMyOBDIICommThread::DoSnsCommand()
{
	const MyConfig::CVariableVector &t_vCmdList =	g_objCConfigEntry.GetService("SNSCMD").GetVarVectorObj("cmd");

	static int i = 0;

	if(i < t_vCmdList.size())
	{
		SetReqString(t_vCmdList.at(i++).GetValue());

	//	SetReqString("ATZ");
		int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);

		if(t_iRetcd == 0)	
		{
			//m_iOBDStatus = OBDII_SYS_END ;
			t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
			SetResString("",t_iRetcd );
		}
		else
		{
			i =0;
		}
		
	}
	else
	{
		CECUSensorDataVectorMap::const_iterator iterECU ;
		static CSensorDataVectorMap::const_iterator iterPID;

		set<unsigned int> t_su;

		for(iterECU=g_objCECUSensorDataVectorMap.begin();iterECU != g_objCECUSensorDataVectorMap.end();iterECU++)
		{
			for(iterPID = iterECU->second.begin();iterPID != iterECU->second.end();iterPID++)
			{
				if(t_su.find(iterPID->first) != t_su.end())
					continue;
				else
					t_su.insert(iterPID->first);
				//
				string t_sReqFix("01");
				SetReqString(t_sReqFix+MyUtility::CBaseEncode::IntToHexString(iterPID->first));

			//	SetReqString("ATZ");
				int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
				

				if(t_iRetcd == 0)	
				{
					//m_iOBDStatus = OBDII_SYS_END ;
					t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
					SetResString("",t_iRetcd );
				}
				else
				{
					i =0;
					//g_objCECUSensorDataVectorMap.clear();

				}
			}
		}

		{
			i =0;
			m_iOBDStatus = OBDII_SENSOR_END ;
		}
	}

	return t_vCmdList.size()-i-1;
}

int CMyOBDIICommThread::DoTcdCommand()
{
	int t_iRetcd = 0;

	bool t_bDo = false;

	/*CECUSensorDataVectorMap::const_iterator iterECU ;
	static CSensorDataVectorMap::const_iterator iterPID;

	for(iterECU=g_objCECUSensorDataVectorMap.begin();iterECU != g_objCECUSensorDataVectorMap.end();iterECU++)
	{
		for(iterPID = iterECU->second.begin();iterPID != iterECU->second.end();iterPID++)
		{

		}
	}*/
	//
	SetReqString("03");

	t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);	

	if(t_iRetcd == 0)	
	{
		//m_iOBDStatus = OBDII_SYS_END ;
		t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
		SetResString("",t_iRetcd );

		m_iOBDStatus = OBDII_TC_END ;
	}

	//
	SetReqString("07");

	t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);	

	if(t_iRetcd == 0)	
	{
		//m_iOBDStatus = OBDII_SYS_END ;
		t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
		SetResString("",t_iRetcd );

		m_iOBDStatus = OBDII_TC_END ;
	}

	return t_iRetcd;
}

int CMyOBDIICommThread::DoOrderCommand()
{
	int t_iRetcd = 0;


	
	CODBIIRawdataVector::iterator iter = g_cmdCODBIIRawdataVector.begin();

	for(iter;iter!= g_cmdCODBIIRawdataVector.end();iter++)
	{
		//
		if(iter->m_uReqTime > 100) continue;

		string res("");

		SetReqString(iter->m_sReq);

		t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);	

		if(t_iRetcd == 0)	
		{
			//m_iOBDStatus = OBDII_SYS_END ;
			t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes,&res);
			SetResString("",t_iRetcd );

			*iter = m_objCODBIIRawdata;

			if(res.size() >= 1)
				iter->m_sRes = res;

		}
		else
		{
			iter->m_sRes = "出现错误";
		}
	}

	m_iOBDStatus = OBDII_COMMAND_END ;





	return t_iRetcd;
}

void CMyOBDIICommThread::SetWorkMode(int mode)
{
	m_iWorkMode = mode;
}

int CMyOBDIICommThread::DoCarInfoCommand()
{
	const MyConfig::CVariableVector &t_vCmdList =	g_objCConfigEntry.GetService("INFCMD").GetVarVectorObj("cmd");

	static int i = 0;
	
	set<unsigned int> t_su;

	t_su.insert(0);

	if(i < t_vCmdList.size())
	{
		SetReqString(t_vCmdList.at(i++).GetValue());

	//	SetReqString("ATZ");
		int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);

		//t_su.insert(m_objCODBIIRawdata.m_sReq);

		if(t_iRetcd == 0)	
		{
			//m_iOBDStatus = OBDII_SYS_END ;
			t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
			SetResString("",t_iRetcd );
		}
		else
		{
			i =0;
		}
		
	}
	else
	{
		CECUCarInfoMap::const_iterator iterECU ;
		CCarInfoMap::const_iterator iterPID;


		for(iterECU=g_objCECUCarInfoMap.begin();iterECU != g_objCECUCarInfoMap.end();iterECU++)
		{
			for(iterPID = iterECU->second.begin();iterPID != iterECU->second.end();iterPID++)
			{
				if(t_su.find(iterPID->first) != t_su.end())
					continue;
				else
					t_su.insert(iterPID->first);
				//
				string t_sReqFix("09");
				SetReqString(t_sReqFix+MyUtility::CBaseEncode::IntToHexString(iterPID->first));

			//	SetReqString("ATZ");
				

				int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);

				//t_su.insert(m_objCODBIIRawdata.m_sReq);
				

				if(t_iRetcd == 0)	
				{
					//m_iOBDStatus = OBDII_SYS_END ;
					t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
					SetResString("",t_iRetcd );
				}
				else
				{
					i =0;
					//g_objCECUSensorDataVectorMap.clear();

				}
			}
		}

		{
			i =0;
			m_iOBDStatus = OBDII_CARINFO_END;
		}
	}

	return t_vCmdList.size()-i-1;
}

int CMyOBDIICommThread::DoFreezeCommand()
{

	const MyConfig::CVariableVector &t_vCmdList =	g_objCConfigEntry.GetService("FRMCMD").GetVarVectorObj("cmd");

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");

	static int i = 0;

	set<unsigned int> t_su;

	t_su.insert(0);

	if(i < t_vCmdList.size())
	{
		SetReqString(t_vCmdList.at(i++).GetValue() + frm);

	//	SetReqString("ATZ");
		int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);

		if(t_iRetcd == 0)	
		{
			//m_iOBDStatus = OBDII_SYS_END ;
			t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq.substr(0,4),m_objCODBIIRawdata.m_sRes);
			SetResString("",t_iRetcd );
		}
		else
		{
			i =0;
		}
		
	}
	else
	{
		CECUSensorDataVectorMap::const_iterator iterECU ;
		static CSensorDataVectorMap::const_iterator iterPID;


		for(iterECU=g_objCECUSensorDataVectorMap_freeze.begin();iterECU != g_objCECUSensorDataVectorMap_freeze.end();iterECU++)
		{
			for(iterPID = iterECU->second.begin();iterPID != iterECU->second.end();iterPID++)
			{
				if(t_su.find(iterPID->first) != t_su.end())
					continue;
				else
					t_su.insert(iterPID->first);
				//
				string t_sReqFix("02");
				SetReqString(t_sReqFix+MyUtility::CBaseEncode::IntToHexString(iterPID->first) + frm);

			//	SetReqString("ATZ");
				int t_iRetcd = DoCommand(m_objCODBIIRawdata.m_sReq,m_objCODBIIRawdata.m_sRes);
				

				if(t_iRetcd == 0)	
				{
					//m_iOBDStatus = OBDII_SYS_END ;
					t_iRetcd = ParseCommand(m_objCODBIIRawdata.m_sReq.substr(0,4),m_objCODBIIRawdata.m_sRes);
					SetResString("",t_iRetcd );
				}
				else
				{
					i =0;
					//g_objCECUSensorDataVectorMap.clear();

				}
			}
		}

		{
			i =0;
			m_iOBDStatus = OBDII_FRAME_END ;
		}
	}

	return t_vCmdList.size()-i-1;
}
