// OBDIIFormat_0130.cpp: implementation of the COBDIIFormat_0130 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat_0130.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



int COBDIIFormat_0130::DoTranslate(const string &in_sReq, string &out_sReq) 
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}

CBaseFormatFactory<COBDIIFormat_0130> t_Factory_COBDIIFormat_0130("COBDIIFormat_0130");
CBaseFormatFactory<COBDIIFormat_0133> t_Factory_COBDIIFormat_0133("COBDIIFormat_0133");