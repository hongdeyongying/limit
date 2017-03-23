// OBDIIFormat_0114.cpp: implementation of the COBDIIFormat_0114 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat_0114.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



COBDIIFormat_0114::~COBDIIFormat_0114()
{

}

int COBDIIFormat_0114::DoTranslate(const string &in_sReq, string &out_sRes)
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
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size()+2,2).c_str(),NULL,16);
		
		double v = 0.005 * (double) t_iVal ;


		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(v) + "V ";
		if( t_iVal2 != 0xfful)
		{
			double v2 = 100.00/128.00 * (double) (t_iVal2-128) ;

			aa += MyUtility::CBaseEncode::DoubleToString(v2) + "% ";
		}

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0114> t_Factory_COBDIIFormat_0114("COBDIIFormat_0114");
CBaseFormatFactory<COBDIIFormat_0115> t_Factory_COBDIIFormat_0115("COBDIIFormat_0115");
CBaseFormatFactory<COBDIIFormat_0116> t_Factory_COBDIIFormat_0116("COBDIIFormat_0116");
CBaseFormatFactory<COBDIIFormat_0117> t_Factory_COBDIIFormat_0117("COBDIIFormat_0117");
CBaseFormatFactory<COBDIIFormat_0118> t_Factory_COBDIIFormat_0118("COBDIIFormat_0118");
CBaseFormatFactory<COBDIIFormat_0119> t_Factory_COBDIIFormat_0119("COBDIIFormat_0119");
CBaseFormatFactory<COBDIIFormat_011A> t_Factory_COBDIIFormat_011A("COBDIIFormat_011A");
CBaseFormatFactory<COBDIIFormat_011B> t_Factory_COBDIIFormat_011B("COBDIIFormat_011B");



int COBDIIFormat_0124::DoTranslate(const string &in_sReq, string &out_sRes)
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
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size()+4,4).c_str(),NULL,16);
		
		double v =  0.000122*(double)t_iVal2 ;


		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(v) + "V ";
		if( t_iVal2 != 0xfful)
		{
			double v2 =  0.0000305*(double)t_iVal ;

			aa += MyUtility::CBaseEncode::DoubleToString(v2) + "% ";
		}

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0124> t_Factory_COBDIIFormat_0124("COBDIIFormat_0124");
CBaseFormatFactory<COBDIIFormat_0125> t_Factory_COBDIIFormat_0125("COBDIIFormat_0125");
CBaseFormatFactory<COBDIIFormat_0126> t_Factory_COBDIIFormat_0126("COBDIIFormat_0126");
CBaseFormatFactory<COBDIIFormat_0127> t_Factory_COBDIIFormat_0127("COBDIIFormat_0127");
CBaseFormatFactory<COBDIIFormat_0128> t_Factory_COBDIIFormat_0128("COBDIIFormat_0128");
CBaseFormatFactory<COBDIIFormat_0129> t_Factory_COBDIIFormat_0129("COBDIIFormat_0129");
CBaseFormatFactory<COBDIIFormat_012A> t_Factory_COBDIIFormat_012A("COBDIIFormat_012A");
CBaseFormatFactory<COBDIIFormat_012B> t_Factory_COBDIIFormat_012B("COBDIIFormat_012B");



int COBDIIFormat_0134::DoTranslate(const string &in_sReq, string &out_sRes)
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
		unsigned int t_iVal2 = strtol(s_Mid.substr(pos+m_sFilter.size()+4,4).c_str(),NULL,16);
		
		double v =  0.00390625*(double)t_iVal2 ;


		string aa;

		aa = MyUtility::CBaseEncode::DoubleToString(v) + "mA ";
		if( t_iVal2 != 0xfful)
		{
			double v2 =  0.0000305*(double)t_iVal ;

			aa += MyUtility::CBaseEncode::DoubleToString(v2) + "% ";
		}

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}
CBaseFormatFactory<COBDIIFormat_0134> t_Factory_COBDIIFormat_0134("COBDIIFormat_0134");
CBaseFormatFactory<COBDIIFormat_0135> t_Factory_COBDIIFormat_0135("COBDIIFormat_0135");
CBaseFormatFactory<COBDIIFormat_0136> t_Factory_COBDIIFormat_0136("COBDIIFormat_0136");
CBaseFormatFactory<COBDIIFormat_0137> t_Factory_COBDIIFormat_0137("COBDIIFormat_0137");
CBaseFormatFactory<COBDIIFormat_0138> t_Factory_COBDIIFormat_0138("COBDIIFormat_0138");
CBaseFormatFactory<COBDIIFormat_0139> t_Factory_COBDIIFormat_0139("COBDIIFormat_0139");
CBaseFormatFactory<COBDIIFormat_013A> t_Factory_COBDIIFormat_013A("COBDIIFormat_013A");
CBaseFormatFactory<COBDIIFormat_013B> t_Factory_COBDIIFormat_013B("COBDIIFormat_013B");




int COBDIIFormat_013C::DoTranslate(const string &in_sReq, string &out_sRes)
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
		
		double v =  0.1*(double)t_iVal - 40 ;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(v));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_013C> t_Factory_COBDIIFormat_013C("COBDIIFormat_013C");
CBaseFormatFactory<COBDIIFormat_013D> t_Factory_COBDIIFormat_013D("COBDIIFormat_013D");
CBaseFormatFactory<COBDIIFormat_013E> t_Factory_COBDIIFormat_013E("COBDIIFormat_013E");
CBaseFormatFactory<COBDIIFormat_013F> t_Factory_COBDIIFormat_013F("COBDIIFormat_013F");



int COBDIIFormat_0141::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		//再写

		string aa = s_Mid.substr(pos+m_sFilter.size(),m_iLen);


		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}


CBaseFormatFactory<COBDIIFormat_0141> t_Factory_COBDIIFormat_0141("COBDIIFormat_0141");

int COBDIIFormat_0142::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		//再写

		string aa = s_Mid.substr(pos+m_sFilter.size(),m_iLen);

		double a = 0.001 * (double) strtoul(aa.c_str(),NULL,16);


		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(a));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}

CBaseFormatFactory<COBDIIFormat_0142> t_Factory_COBDIIFormat_0142("COBDIIFormat_0142");

int COBDIIFormat_0143::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		//再写

		string aa = s_Mid.substr(pos+m_sFilter.size(),m_iLen);

		double a = 100.00 / 255.00 * (double) strtoul(aa.c_str(),NULL,16);


		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(a));

		pos += m_sFilter.size()+8;

		
	}


	return t_iRetcd;
}

CBaseFormatFactory<COBDIIFormat_0143> t_Factory_COBDIIFormat_0143("COBDIIFormat_0143");


int COBDIIFormat_0144::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41" + m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		//再写

		string aa = s_Mid.substr(pos+m_sFilter.size(),m_iLen);

		double a = 0.0000305 * (double) strtoul(aa.c_str(),NULL,16);


		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(a));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}

CBaseFormatFactory<COBDIIFormat_0144> t_Factory_COBDIIFormat_0144("COBDIIFormat_0144");
