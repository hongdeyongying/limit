// OBDIIFormat_09.cpp: implementation of the COBDIIFormat_09 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat_09.h"

#include "utility/CBaseEncode.h"
#include "utility/CStringVector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COBDIIFormat_09::COBDIIFormat_09()
{

}

COBDIIFormat_09::~COBDIIFormat_09()
{

}

int COBDIIFormat_09::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string m_sFilter("4900");

	int m_iPidFrom = 0;
	//
	string::size_type pos = 0;

	int t_iEcuNo = 0;

	CECUCarInfoMap::iterator iter;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{


		unsigned int t_iIndex = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size()+2,8).c_str(),NULL,16);
		if(t_iIndex == 1)
		{
			t_iEcuNo++;
		}

		if(g_objCECUCarInfoMap.find(t_iEcuNo) == g_objCECUCarInfoMap.end())
			g_objCECUCarInfoMap[t_iEcuNo].clear();

		iter = g_objCECUCarInfoMap.find(t_iEcuNo);

		unsigned int t_iPos = 0x80000000ul;

		MyUtility::CStringVector vs;

		for(int i=0;i<32;i++)
		{
			if(t_iVal & (t_iPos>>i))
			{
				if(iter->second.find(i+1+m_iPidFrom) == iter->second.end())
				{
					iter->second[i+1+m_iPidFrom]="";
				}

				vs.push_back(MyUtility::CBaseEncode::UIntToHexString(i+1+m_iPidFrom));

			}
		}

		//t_iEcuNo++;

		out_sRes = vs.Join(",");


		g_objCECUCarInfoMap[t_iEcuNo][m_iPidFrom]=out_sRes;

		pos += m_sFilter.size() +2 + 8;
		

		
	}




	return t_iRetcd;
}

int COBDIIFormat_0901::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	// SERVICE  
	string req_svr,res_svr,infotype;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		infotype = sv[2];
	}
	else
	{
		return -1;
	}


	string m_sFilter = res_svr + infotype;

	//
	string::size_type pos = 0;

	int t_iEcuNo = 1;

	CECUCarInfoMap::iterator iter;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		g_objCECUCarInfoMap[t_iEcuNo++][strtoul(infotype.c_str(),NULL,16)]
			= MyUtility::CBaseEncode::UIntToString(t_iVal);

		pos += m_sFilter.size() +2 ;
	}




	return t_iRetcd;
}

int COBDIIFormat_0902::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	// SERVICE  
	string req_svr,res_svr,infotype;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		infotype = sv[2];
	}
	else
	{
		return -1;
	}


	string m_sFilter = res_svr + infotype;

	//
	string::size_type pos = 0;

	int t_iEcuNo = 0;

	int t_iInfoType = strtoul(infotype.c_str(),NULL,16);


	CECUCarInfoMap::iterator iter;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		unsigned int t_iIndex = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		string aa = s_Mid.substr(pos+m_sFilter.size()+2,8);

		if(t_iIndex == 1)
		{
			t_iEcuNo++;
			g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType]="";

			aa = MyUtility::CBaseEncode::TrimLeft(aa,"0");
		}
			
		aa = MyUtility::CBaseEncode::HexStrToCharStr(aa);


		g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType] += aa;

		pos += m_sFilter.size() +10 ;
	}

	AfxGetMainWnd()->PostMessage(MYMSG_DISP_CARINFO);




	return t_iRetcd;
}

int COBDIIFormat_0906::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	// SERVICE  
	string req_svr,res_svr,infotype;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		infotype = sv[2];
	}
	else
	{
		return -1;
	}


	string m_sFilter = res_svr + infotype;

	//
	string::size_type pos = 0;

	int t_iEcuNo = 0;

	int t_iInfoType = strtoul(infotype.c_str(),NULL,16);


	CECUCarInfoMap::iterator iter;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		unsigned int t_iIndex = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		string aa = s_Mid.substr(pos+m_sFilter.size()+2,8);

		if(t_iIndex == 1)
		{
			t_iEcuNo++;
			g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType]="";

			//aa = MyUtility::CBaseEncode::TrimLeft(aa,"0");
		}
			
		//aa = MyUtility::CBaseEncode::HexStrToCharStr(aa);


		g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType] += aa;

		pos += m_sFilter.size() +10 ;
	}




	return t_iRetcd;
}

int COBDIIFormat_0908::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	// SERVICE  
	string req_svr,res_svr,infotype;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		infotype = sv[2];
	}
	else
	{
		return -1;
	}


	string m_sFilter = res_svr + infotype;

	//
	string::size_type pos = 0;

	int t_iEcuNo = 0;

	int t_iInfoType = strtoul(infotype.c_str(),NULL,16);


	CECUCarInfoMap::iterator iter;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		unsigned int t_iIndex = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		string aa = s_Mid.substr(pos+m_sFilter.size()+2,64);

		if(t_iIndex == 1)
		{
			t_iEcuNo++;

			g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType]="";

			//aa = MyUtility::CBaseEncode::TrimLeft(aa,"0");
		}
			
		//aa = MyUtility::CBaseEncode::HexStrToCharStr(aa);


		g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType] += aa;

		pos += m_sFilter.size() +66 ;
	}




	return t_iRetcd;
}

int COBDIIFormat_090A::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	// SERVICE  
	string req_svr,res_svr,infotype;

	MyUtility::CStringVector sv;
	sv.Split(m_sPara,",");

	if(sv.size() >= 3)
	{
		req_svr = sv[0];
		res_svr = sv[1];
		infotype = sv[2];
	}
	else
	{
		return -1;
	}


	string m_sFilter = res_svr + infotype;

	//
	string::size_type pos = 0;

	int t_iEcuNo = 0;

	int t_iInfoType = strtoul(infotype.c_str(),NULL,16);


	CECUCarInfoMap::iterator iter;


	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		unsigned int t_iIndex = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		string aa = s_Mid.substr(pos+m_sFilter.size()+2,40);

		if(t_iIndex == 1)
		{
			t_iEcuNo++;

			g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType]="";

		}
			
		aa = MyUtility::CBaseEncode::HexStrToCharStr(aa);


		g_objCECUCarInfoMap[t_iEcuNo][t_iInfoType] += aa;

		pos += m_sFilter.size() +10 ;
	}




	return t_iRetcd;
}
CBaseFormatFactory<COBDIIFormat_09> t_Factory_COBDIIFormat_0900("COBDIIFormat_0900");
CBaseFormatFactory<COBDIIFormat_0901> t_Factory_COBDIIFormat_0901("COBDIIFormat_0901");
CBaseFormatFactory<COBDIIFormat_0902> t_Factory_COBDIIFormat_0902("COBDIIFormat_0902");
CBaseFormatFactory<COBDIIFormat_0906> t_Factory_COBDIIFormat_0906("COBDIIFormat_0906");
CBaseFormatFactory<COBDIIFormat_0908> t_Factory_COBDIIFormat_0908("COBDIIFormat_0908");
CBaseFormatFactory<COBDIIFormat_090A> t_Factory_COBDIIFormat_090A("COBDIIFormat_090A");