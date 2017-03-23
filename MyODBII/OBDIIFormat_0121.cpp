// OBDIIFormat_0121.cpp: implementation of the COBDIIFormat_0121 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat_0121.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


int COBDIIFormat_0121::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0122::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);

		double i = 0.079 * (double)t_iVal;
	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(i));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0123::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);

		double i = 10 * (double)t_iVal;
	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(i));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}



CBaseFormatFactory<COBDIIFormat_0121> t_Factory_COBDIIFormat_0121("COBDIIFormat_0121");
CBaseFormatFactory<COBDIIFormat_0122> t_Factory_COBDIIFormat_0122("COBDIIFormat_0122");
CBaseFormatFactory<COBDIIFormat_0123> t_Factory_COBDIIFormat_0123("COBDIIFormat_0123");
