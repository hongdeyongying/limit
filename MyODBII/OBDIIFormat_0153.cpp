// OBDIIFormat_0153.cpp: implementation of the COBDIIFormat_0153 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat_0153.h"

#include "utility/CBaseEncode.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int COBDIIFormat_0153::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),m_iLen).c_str(),NULL,16);
		
		double i=(0.005 * (double)t_iVal);

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(i));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0154::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		int t_iVal = strtol(s_Mid.substr(pos+m_sFilter.size(),m_iLen).c_str(),NULL,16);
		
	//	double i=(0.005 * (double)t_iVal);

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0155::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		int t_iVal = strtol(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		int t_iVal2 = strtol(s_Mid.substr(pos+m_sFilter.size()+2,2).c_str(),NULL,16);
		
		double i=(100.00/128.00 * (double)t_iVal);
		double i2=(100.00/128.00 * (double)t_iVal2);

		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(i) + "% ";
		aa += MyUtility::CBaseEncode::DoubleToString(i2) + "% ";

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}
CBaseFormatFactory<COBDIIFormat_0153> t_Factory_COBDIIFormat_0153("COBDIIFormat_0153");
CBaseFormatFactory<COBDIIFormat_0154> t_Factory_COBDIIFormat_0154("COBDIIFormat_0154");

CBaseFormatFactory<COBDIIFormat_0155> t_Factory_COBDIIFormat_0155("COBDIIFormat_0155");
CBaseFormatFactory<COBDIIFormat_0156> t_Factory_COBDIIFormat_0156("COBDIIFormat_0156");
CBaseFormatFactory<COBDIIFormat_0157> t_Factory_COBDIIFormat_0157("COBDIIFormat_0157");
CBaseFormatFactory<COBDIIFormat_0158> t_Factory_COBDIIFormat_0158("COBDIIFormat_0158");



int COBDIIFormat_0159::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = 10 * strtoul(s_Mid.substr(pos+m_sFilter.size(),m_iLen).c_str(),NULL,16);

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}
CBaseFormatFactory<COBDIIFormat_0159> t_Factory_COBDIIFormat_0159("COBDIIFormat_0159");