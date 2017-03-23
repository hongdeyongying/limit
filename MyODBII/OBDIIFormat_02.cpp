// OBDIIFormat_02.cpp: implementation of the COBDIIFormat_02 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat_02.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int COBDIIFormat_02::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;

	//
	string::size_type pos = 0;

	int t_iEcuNo = 1;

	CECUSensorDataVectorMap::iterator iter;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		if(g_objCECUSensorDataVectorMap_freeze.find(t_iEcuNo) == g_objCECUSensorDataVectorMap_freeze.end())
			g_objCECUSensorDataVectorMap_freeze[t_iEcuNo].clear();

		iter = g_objCECUSensorDataVectorMap_freeze.find(t_iEcuNo);

		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size() ,8).c_str(),NULL,16);

		unsigned int t_iPos = 0x80000000ul;

		MyUtility::CStringVector vs;

		for(int i=0;i<32;i++)
		{
			if(t_iVal & (t_iPos>>i))
			{
				if(iter->second.find(i+1+m_iPidFrom) == iter->second.end())
				{
					iter->second[i+1+m_iPidFrom].clear();
				}

				vs.push_back(MyUtility::CBaseEncode::UIntToHexString(i+1+m_iPidFrom));

			}
		}

		//t_iEcuNo++;

		out_sRes = vs.Join(",");

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(out_sRes));

		pos += m_sFilter.size() + 8;
	}




	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_02> t_Factory_COBDIIFormat_0200("COBDIIFormat_0200");


int COBDIIFormat_0201::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		unsigned int t_iMIL = 128;

		if(t_iVal & t_iMIL) 
			out_sRes = "MIL:ON;";
		else
			out_sRes = "MIL:OFF;";


		t_iVal &= 127;

		out_sRes += "TCD个数："+MyUtility::CBaseEncode::UIntToString(t_iVal);

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size() + 2;
		
	}


	return t_iRetcd;
}

CBaseFormatFactory<COBDIIFormat_0201> t_Factory_COBDIIFormat_0201("COBDIIFormat_0201");



int COBDIIFormat_0202::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);

		
		unsigned int t_iHead = t_iVal & 0xC000ul;
		t_iHead >>=14;

		unsigned int t_iValue= t_iVal & 0x3FFFul;

		char code_letter[] = "PCBU";

		string val ("");

		val += code_letter[t_iHead];

		val += MyUtility::CBaseEncode::UIntToHexString(t_iValue,4);


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(val));

		pos += m_sFilter.size()+4;

		
	}

	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0202> t_Factory_COBDIIFormat_0202("COBDIIFormat_0202");



int COBDIIFormat_0203::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_uStatus1 = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		unsigned int t_uStatus2 = strtoul(s_Mid.substr(pos+m_sFilter.size()+2,2).c_str(),NULL,16);

		unsigned int t_uBit0 = 0x01ul;


		string str;


		if(t_uStatus1 & t_uBit0)
		{
			str += "1#开路（不具备条件） ";
		}
		if(t_uStatus1 & (t_uBit0<<1))
		{
			str += "1#闭环（氧传感器回馈控制） ";
		}
		if(t_uStatus1 & (t_uBit0<<2))
		{
			str += "1#开路（因行驶环境） ";
		}
		if(t_uStatus1 & (t_uBit0<<3))
		{
			str += "1#开路（故障） ";
		}
		if(t_uStatus1 & (t_uBit0<<4))
		{
			str += "1#闭环（但至少一个氧传感器故障） ";
		}

		
		if(t_uStatus2 & t_uBit0)
		{
			str += "2#开路（不具备条件） ";
		}
		if(t_uStatus2 & (t_uBit0<<1))
		{
			str += "2#闭环（氧传感器回馈控制） ";
		}
		if(t_uStatus2 & (t_uBit0<<2))
		{
			str += "2#开路（因行驶环境） ";
		}
		if(t_uStatus2 & (t_uBit0<<3))
		{
			str += "2#开路（故障） ";
		}
		if(t_uStatus2 & (t_uBit0<<4))
		{
			str += "2#闭环（但至少一个氧传感器故障） ";
		}


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(str));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0203> t_Factory_COBDIIFormat_0203("COBDIIFormat_0203");


int COBDIIFormat_0204::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = i*100.00/255.00;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0204> t_Factory_COBDIIFormat_0204("COBDIIFormat_0204");


int COBDIIFormat_0205::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;
	int len = 2;
	double sc = 1.0;
	double off = 40.0;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];

		if(sv.size() > 3)
		{
			len = atoi(sv[3].c_str());
		}

		if(sv.size() > 4)
		{
			sc = atof(sv[4].c_str());
		}

		if(sv.size() > 5)
		{
			off = atof(sv[5].c_str());
		}
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),len).c_str(),NULL,16);

		
		double i = t_iVal;

		i = i*sc-off;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(i));

		pos += m_sFilter.size()+len;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0205> t_Factory_COBDIIFormat_0205("COBDIIFormat_0205");


int COBDIIFormat_0206::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = (i-128)*100/128;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0206> t_Factory_COBDIIFormat_0206("COBDIIFormat_0206");




int COBDIIFormat_020A::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);


		t_iVal = t_iVal * 3;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_020A> t_Factory_COBDIIFormat_020A("COBDIIFormat_020A");


int COBDIIFormat_020B::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);


		//t_iVal = t_iVal * 3;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_020B> t_Factory_COBDIIFormat_020B("COBDIIFormat_020B");

int COBDIIFormat_020C::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);


		double t_iVal = (double)t_iVal2/4.0;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_020C> t_Factory_COBDIIFormat_020C("COBDIIFormat_020C");



int COBDIIFormat_020E::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		double i = t_iVal;

		i= (i-128)/2;

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_020E> t_Factory_COBDIIFormat_020E("COBDIIFormat_020E");


int COBDIIFormat_0210::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
		
		double i=0.01 * (double)t_iVal;

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(i));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0210> t_Factory_COBDIIFormat_0210("COBDIIFormat_0210");


int COBDIIFormat_0212::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		int up = t_iVal & 0x01;
		int down = t_iVal & 0x02;
		int off = t_iVal & 0x04;

		string aa;

		if(up)
		{
			aa = "上游催化转化器";
		}

		if(down)
		{
			aa = "下游催化转化器";
		}

		if(off)
		{
			aa = "大气压";
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0212> t_Factory_COBDIIFormat_0212("COBDIIFormat_0212");


int COBDIIFormat_0213::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		int bit = 0x01;

		string aa;

		for(int i=0;i<8;i++)
		{
			if(t_iVal & (bit << i))
			{
				aa+= "B" + MyUtility::CBaseEncode::IntToString(i/4 + 1) + "S" + MyUtility::CBaseEncode::IntToString(i%4 + 1);
				aa+= " ";
			}
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0213> t_Factory_COBDIIFormat_0213("COBDIIFormat_0213");


int COBDIIFormat_0214::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size()+2,2).c_str(),NULL,16);
		
		double v = 0.005 * (double) t_iVal ;


		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(v) + "V ";
		if( t_iVal2 != 0xfful)
		{
			double v2 = 100.00/128.00 * (double) (t_iVal2-128) ;

			aa += MyUtility::CBaseEncode::DoubleToString(v2) + "% ";
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+4;

		
	}

	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0214> t_Factory_COBDIIFormat_0214("COBDIIFormat_0214");


int COBDIIFormat_021C::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		

		string aa;


		switch (t_iVal)
		{
			case 0x01:
				aa = ( "OBD-II (California ARB)");
				break;
			case 0x02:
				aa = ("OBD (Federal EPA)");
				break;
			case 0x03:
				aa = ("OBD and OBD-II");
				break;
			case 0x04:
				aa = ("OBD-I");
				break;
			case 0x05:
				aa = ("Not OBD compliant");
				break;
			case 0x06:
				aa = ("EOBD (Europe)");
				break;
			case 0x07:
				aa = ("EOBD and OBD-II");
				break;
			case 0x08:
				aa = ("EOBD and OBD");
				break;
			case 0x09:
				aa = ("EOBD, OBD and OBD-II");
				break;
			case 0x0A:
				aa = ("JOBD (Japan)");
				break;
			case 0x0B:
				aa = ("JOBD and OBD-II");
				break;
			case 0x0C:
				aa = ("JOBD and EOBD");
				break;
			case 0x0D:
				aa = ("JOBD, EOBD, and OBD-II");
				break;
			case 0x0E:
				aa = ("EURO IV B1");
				break;
			case 0x0F:
				aa = ("EURO V B2");
				break;
			case 0x10:
				aa = ("EURO C");
				break;
			case 0x11:
				aa = ("EMD");
				break;
			default:
				aa = ("Unknown: " + s_Mid.substr(pos+m_sFilter.size(),2));
				break;
	   }


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}
	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_021C> t_Factory_COBDIIFormat_021C("COBDIIFormat_021C");


int COBDIIFormat_021D::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		int bit = 0x01;

		string aa;

		for(int i=0;i<8;i++)
		{
			if(t_iVal & (bit << i))
			{
				aa+= "B" + MyUtility::CBaseEncode::IntToString(i/4 + 1) + "S" + MyUtility::CBaseEncode::IntToString(i%2 + 1);
				aa+= " ";
			}
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_021D> t_Factory_COBDIIFormat_021D("COBDIIFormat_021D");



int COBDIIFormat_021E::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		int bit = 0x01;

		string aa;

	
		{
			if(t_iVal & (bit  ))
			{
				aa= "PTO ON";
			}
			else
			{
				aa = "PTO OFF";
			}
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_021E> t_Factory_COBDIIFormat_021E("COBDIIFormat_021E");




int COBDIIFormat_021F::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);


		//t_iVal = t_iVal * 3;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_021F> t_Factory_COBDIIFormat_021F("COBDIIFormat_021F");


int COBDIIFormat_0222::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);


		double t_iVal = (double)t_iVal2 * 0.079;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0222> t_Factory_COBDIIFormat_0222("COBDIIFormat_0222");


int COBDIIFormat_0223::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);


		double t_iVal = (double)t_iVal2 * 10;


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0223> t_Factory_COBDIIFormat_0223("COBDIIFormat_0223");



int COBDIIFormat_0224::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size()+4,4).c_str(),NULL,16);
		
		double v =  0.000122*(double)t_iVal2 ;


		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(v) + "V ";
		if( t_iVal2 != 0xfful)
		{
			double v2 =  0.0000305*(double)t_iVal ;

			aa += MyUtility::CBaseEncode::DoubleToString(v2) + "% ";
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0224> t_Factory_COBDIIFormat_0224("COBDIIFormat_0224");




int COBDIIFormat_0232::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		int t_iVal = strtol(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);

		double a = 0.25 * (double) t_iVal;
	
		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(a));

		pos += m_sFilter.size()+4;

		
	}



	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0232> t_Factory_COBDIIFormat_0232("COBDIIFormat_0232");


int COBDIIFormat_0234::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];
	}
	else
	{
		return -1;
	}


	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
		unsigned int t_iVal2 = strtol(s_Mid.substr(pos+m_sFilter.size()+4,4).c_str(),NULL,16);
		
		double v =  0.00390625*(double)t_iVal2 ;


		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(v) + "mA ";
		if( t_iVal2 != 0xfful)
		{
			double v2 =  0.0000305*(double)t_iVal ;

			aa += MyUtility::CBaseEncode::DoubleToString(v2) + "% ";
		}

		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+8;

		
	}



	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0234> t_Factory_COBDIIFormat_0234("COBDIIFormat_0234");

int COBDIIFormat_0241::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;
	int len;

	double sc,off;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];

		if(sv.size() > 3)
		{
			len = atoi(sv[3].c_str());
		}

		if(sv.size() > 4)
		{
			sc = atof(sv[4].c_str());
		}

		if(sv.size() > 5)
		{
			off = atof(sv[5].c_str());
		}
	}
	else
	{
		return -1;
	}



	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;




	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		//再写

		string aa = s_Mid.substr(pos+m_sFilter.size(),len);


		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+len;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0241> t_Factory_COBDIIFormat_0241("COBDIIFormat_0241");
int COBDIIFormat_024F::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;
	int len;

	double sc,off;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];

		if(sv.size() > 3)
		{
			len = atoi(sv[3].c_str());
		}

		if(sv.size() > 4)
		{
			sc = atof(sv[4].c_str());
		}

		if(sv.size() > 5)
		{
			off = atof(sv[5].c_str());
		}
	}
	else
	{
		return -1;
	}



	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;




	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int rt = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		unsigned int v = strtoul(s_Mid.substr(pos+m_sFilter.size()+2,2).c_str(),NULL,16);
		unsigned int am = strtoul(s_Mid.substr(pos+m_sFilter.size()+4,2).c_str(),NULL,16);
		unsigned int kpa = 10 * strtoul(s_Mid.substr(pos+m_sFilter.size()+6,2).c_str(),NULL,16);

		string aa ;

		aa = MyUtility::CBaseEncode::UIntToString(rt) + "% ";
		aa = MyUtility::CBaseEncode::UIntToString(v) + "V ";
		aa = MyUtility::CBaseEncode::UIntToString(am) + "mA ";
		aa = MyUtility::CBaseEncode::UIntToString(kpa) + "kPa ";
	
		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+len;

		
	}

	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_024F> t_Factory_COBDIIFormat_024F("COBDIIFormat_024F");



int COBDIIFormat_0251::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");


	// SERVICE  
	string req_svr,res_svr,pid;
	int len;

	double sc,off;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];

		if(sv.size() > 3)
		{
			len = atoi(sv[3].c_str());
		}

		if(sv.size() > 4)
		{
			sc = atof(sv[4].c_str());
		}

		if(sv.size() > 5)
		{
			off = atof(sv[5].c_str());
		}
	}
	else
	{
		return -1;
	}



	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;




	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int type = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		string aa;

		switch(type)
		{
		case 0x01:
			aa = "01 GAS 汽油/汽油";break;
		case 0x02:
			aa = "02 METH 甲醇";break;
		case 0x03:
			aa = "03 ETH 乙醇";break;
		case 0x04:
			aa = "04 DSL 柴油";break;
		case 0x05:
			aa = "05 LPG 液化石油气（LPG）";break;
		case 0x06:
			aa = "06 CNG 压缩天然气（CNG）";break;
		case 0x07:
			aa = "07 PROP 丙烷";break;
		case 0x08:
			aa = "08 ELEC 电池/电";break;
		case 0x09:
			aa = "09 BI_GAS 双燃料车用汽油";break;
		case 0x0A:
			aa = "0A BI_METH  双燃料车用甲醇";break;
		case 0x0B:
			aa = "0B BI_ETH 双燃料车用乙醇";break;
		case 0x0C:
			aa = "0C BI_LPG 的双燃料汽车使用石油气";break;
		case 0x0D:
			aa = "0D BI_CNG 双燃料汽车使用天然气";break;
		case 0x0E:
			aa = "0E BI_PROP 双燃料车使用丙烷";break;
		case 0x0F:
			aa = "0F BI_ELEC 双燃料汽车用电池";break;
		default:
			aa = "ISO/SAE 保留"; break;
		}

	
		g_objCECUSensorDataVectorMap_freeze[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+len;

		
	}

	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0251> t_Factory_COBDIIFormat_0251("COBDIIFormat_0251");



int COBDIIFormat_0255::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string frm = g_objCConfigEntry.GetService("FRMCMD").GetVarVal("frame");
int len;

	double sc,off;

	// SERVICE  
	string req_svr,res_svr,pid;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		pid = sv[2];

		if(sv.size() > 3)
		{
			len = atoi(sv[3].c_str());
		}

		if(sv.size() > 4)
		{
			sc = atof(sv[4].c_str());
		}

		if(sv.size() > 5)
		{
			off = atof(sv[5].c_str());
		}
	}
	else
	{
		return -1;
	}



	unsigned int m_iPidFrom = strtoul(pid.c_str(),NULL,16);
	string m_sFilter = res_svr + pid + frm;


	string::size_type pos = 0;

	int t_iEcuNo = 1;




	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		int t_iVal = strtol(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		int t_iVal2 = strtol(s_Mid.substr(pos+m_sFilter.size()+2,2).c_str(),NULL,16);
		
		double i=(100.00/128.00 * (double)t_iVal);
		double i2=(100.00/128.00 * (double)t_iVal2);

		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(i) + "% ";
		aa += MyUtility::CBaseEncode::DoubleToString(i2) + "% ";

		g_objCECUSensorDataVectorMap[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(aa));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0255> t_Factory_COBDIIFormat_0255("COBDIIFormat_0255");