// OBDIIFormat.cpp: implementation of the COBDIIFormat class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "OBDIIFormat.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////




COBDIIFormat::~COBDIIFormat()
{

}
int COBDIIFormat::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

//	out_sRes = in_sReq;

	string::const_iterator iter;

	for(iter = in_sReq.begin(); iter != in_sReq.end();iter++)
	{
		if((*iter) <= ' ' )
		{
			switch(*iter)
			{
			case '\n':
			case '\r':
				if((out_sRes.size() == 0) || (out_sRes.at(out_sRes.size()-1) != '\t'))
					out_sRes.append(1,'\t');

				break;
			default:
				break;

			}
		}
		else
		{
			out_sRes.append(1,*iter);
		}
	}

	return t_iRetcd;
}

int COBDIIFormat_0100::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	//
	string::size_type pos = 0;

	int t_iEcuNo = 1;

	CECUSensorDataVectorMap::iterator iter;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		if(g_objCECUSensorDataVectorMap.find(t_iEcuNo) == g_objCECUSensorDataVectorMap.end())
			g_objCECUSensorDataVectorMap[t_iEcuNo].clear();

		iter = g_objCECUSensorDataVectorMap.find(t_iEcuNo);

		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),8).c_str(),NULL,16);

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

		g_objCECUSensorDataVectorMap[t_iEcuNo++][m_iPidFrom].push_back(CSensorData(out_sRes));

		pos += m_sFilter.size() + 8;
	}




	return t_iRetcd;
}
int COBDIIFormat_0120::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0x20;

	m_sFilter = "4120";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}
int COBDIIFormat_0140::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0x40;

	m_sFilter = "4140";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}
int COBDIIFormat_0160::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0x60;

	m_sFilter = "4160";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}
int COBDIIFormat_0180::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0x80;

	m_sFilter = "4180";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}
int COBDIIFormat_01A0::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0xA0;

	m_sFilter = "41A0";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}

int COBDIIFormat_01C0::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0xC0;

	m_sFilter = "41C0";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}

int COBDIIFormat_01E0::DoTranslate(const string &in_sReq, string &out_sRes)
{
	m_iPidFrom = 0xE0;

	m_sFilter = "41E0";
	
	return COBDIIFormat_0100::DoTranslate(in_sReq,out_sRes);

}
int COBDIIFormat_0101::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4101";

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

		g_objCECUSensorDataVectorMap[t_iEcuNo++][1].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size() + 2;
		
	}


	return t_iRetcd;
}

int COBDIIFormat_03::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "43";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal[3] ;
		t_iVal[0] = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
		t_iVal[1] = strtoul(s_Mid.substr(pos+m_sFilter.size()+4,4).c_str(),NULL,16);
		t_iVal[2] = strtoul(s_Mid.substr(pos+m_sFilter.size()+4+4,4).c_str(),NULL,16);

		
		for(int ii =0;ii<3;ii++)
		{

			unsigned int t_iHead = t_iVal[ii] & 0xC000ul;
			t_iHead >>=14;

			unsigned int t_iValue= t_iVal[ii] & 0x3FFFul;

			char code_letter[] = "PCBU";

			string val ("");

			val += code_letter[t_iHead];

			val += MyUtility::CBaseEncode::UIntToHexString(t_iValue,4);


			g_objCTCDSet.insert(val);

			out_sRes = val;
		}

		pos += m_sFilter.size()+12;

		
	}


	return t_iRetcd;
}


int COBDIIFormat_04::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "44";
	
	string aa;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{

		aa += MyUtility::CBaseEncode::IntToString(t_iEcuNo++) + "# ECU 错误码清理成功； ";
	
		pos += m_sFilter.size();

		
	}


	if(t_iEcuNo == (g_objCECUSensorDataVectorMap.size()+1) )
	{
		aa = ("清理成功\r\n") + aa;
	}
	else
	{
		if(aa.size() > 1)
			aa = "部分清理成功\r\n" +aa;	
		else
			aa= "清理失败";	
	}

	out_sRes = aa;
	AfxMessageBox(aa.c_str());	

	return t_iRetcd;
}

int COBDIIFormat_07::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "47";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal[3] ;
		t_iVal[0] = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
		t_iVal[1] = strtoul(s_Mid.substr(pos+m_sFilter.size()+4,4).c_str(),NULL,16);
		t_iVal[2] = strtoul(s_Mid.substr(pos+m_sFilter.size()+4+4,4).c_str(),NULL,16);

		
		for(int ii =0;ii<3;ii++)
		{

			unsigned int t_iHead = t_iVal[ii] & 0xC000ul;
			t_iHead >>=14;

			unsigned int t_iValue= t_iVal[ii] & 0x3FFFul;

			char code_letter[] = "PCBU";

			string val ("");

			val += code_letter[t_iHead];

			val += MyUtility::CBaseEncode::UIntToHexString(t_iValue,4);


			g_objCTCDSet.insert(val);
		}

		pos += m_sFilter.size()+12;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_010A::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "410A";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);


		t_iVal = t_iVal * 3;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x0A].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}


int COBDIIFormat_010B::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "410B";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);


//		t_iVal = t_iVal * 3;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x0B].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_010C::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "410C";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal2 = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);


		double t_iVal = (double)t_iVal2/4.0;

	//	val = "TCD个数："+MyUtility::CBaseEncode::UIntToString(t_iVal);

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x0c].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


int COBDIIFormat_0104::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4104";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = i*100.00/255.00;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x04].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0105::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = i-40;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x05].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0102::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);

	string m_sFilter = "4102";

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


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x02].push_back(CSensorData(val));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0106::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = (i-128)*100/128;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0107::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4107";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtol(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = (i-128)*100/128;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x07].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0108::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4108";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = (i-128)*100/128;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x08].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0109::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4109";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		
		double i = t_iVal;

		i = (i-128)*100/128;


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x09].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0103::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string m_sFilter = "4103";

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


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x03].push_back(CSensorData(str));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_010D::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "410D";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

		unsigned int t_iMIL = 128;

	//	string val;
	//	if(t_iVal & t_iMILL) 
	//		val = "MIL:ON;"
	//	else
	//		val = "MIL:OFF;";


		t_iVal = t_iVal;

	//	val = "TCD个数："+MyUtility::CBaseEncode::UIntToString(t_iVal);

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x0D].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_010E::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "410E";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		double i = t_iVal;

		i= (i-128)/2;

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x0E].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_010F::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "410F";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		unsigned int i= t_iVal -40;

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x0F].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0110::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4110";

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
		
		double i=0.01 * (double)t_iVal;

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x10].push_back(CSensorData(i));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0111::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);
		
		double i=(100.00 * (double)t_iVal)/255;

		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(i));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0112::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4112";

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

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x12].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_0113::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "4113";

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

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x13].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_011C::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "411C";

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


		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x1C].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_011D::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "411D";

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
				aa+ " ";
			}
		}

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x1D].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_011E::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "411E";

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

		g_objCECUSensorDataVectorMap[t_iEcuNo++][0x1E].push_back(CSensorData(aa));

		pos += m_sFilter.size()+2;

		
	}


	return t_iRetcd;
}
int COBDIIFormat_011F::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int t_iVal = strtoul(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);
	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(t_iVal));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}


int COBDIIFormat_014F::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

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
	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0150::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		unsigned int gs = 10 * strtoul(s_Mid.substr(pos+m_sFilter.size(),2).c_str(),NULL,16);

	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(gs));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0151::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

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

	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(aa));

		pos += m_sFilter.size()+m_iLen;

		
	}


	return t_iRetcd;
}

int COBDIIFormat_0132::DoTranslate(const string &in_sReq, string &out_sRes)
{
	int t_iRetcd =0;

	string s_Mid;
	t_iRetcd = COBDIIFormat::DoTranslate(in_sReq,s_Mid);


	string::size_type pos = 0;

	int t_iEcuNo = 1;

	string m_sFilter = "41"+m_sPID;

	while((pos = s_Mid.find(m_sFilter,pos)) != string::npos)
	{
		int t_iVal = strtol(s_Mid.substr(pos+m_sFilter.size(),4).c_str(),NULL,16);

		double a = 0.25 * (double) t_iVal;
	
		g_objCECUSensorDataVectorMap[t_iEcuNo++][strtoul(m_sPID.c_str(),NULL,16)].push_back(CSensorData(a));

		pos += m_sFilter.size()+4;

		
	}


	return t_iRetcd;
}

CBaseFormatFactory<COBDIIFormat> t_Factory_COBDIIFormat("COBDIIFormat");


CBaseFormatFactory<COBDIIFormat_0100> t_Factory_COBDIIFormat_0100("COBDIIFormat_0100");
CBaseFormatFactory<COBDIIFormat_0120> t_Factory_COBDIIFormat_0120("COBDIIFormat_0120");
CBaseFormatFactory<COBDIIFormat_0140> t_Factory_COBDIIFormat_0140("COBDIIFormat_0140");
CBaseFormatFactory<COBDIIFormat_0160> t_Factory_COBDIIFormat_0160("COBDIIFormat_0160");
CBaseFormatFactory<COBDIIFormat_0180> t_Factory_COBDIIFormat_0180("COBDIIFormat_0180");
CBaseFormatFactory<COBDIIFormat_01A0> t_Factory_COBDIIFormat_01A0("COBDIIFormat_01A0");
CBaseFormatFactory<COBDIIFormat_01C0> t_Factory_COBDIIFormat_01C0("COBDIIFormat_01C0");
CBaseFormatFactory<COBDIIFormat_01E0> t_Factory_COBDIIFormat_01E0("COBDIIFormat_01E0");

CBaseFormatFactory<COBDIIFormat_0101> t_Factory_COBDIIFormat_0101("COBDIIFormat_0101");
CBaseFormatFactory<COBDIIFormat_0102> t_Factory_COBDIIFormat_0102("COBDIIFormat_0102");
CBaseFormatFactory<COBDIIFormat_0103> t_Factory_COBDIIFormat_0103("COBDIIFormat_0103");
CBaseFormatFactory<COBDIIFormat_0104> t_Factory_COBDIIFormat_0104("COBDIIFormat_0104");
CBaseFormatFactory<COBDIIFormat_0105> t_Factory_COBDIIFormat_0105("COBDIIFormat_0105");
CBaseFormatFactory<COBDIIFormat_0146> t_Factory_COBDIIFormat_0146("COBDIIFormat_0146");

CBaseFormatFactory<COBDIIFormat_0106> t_Factory_COBDIIFormat_0106("COBDIIFormat_0106");
CBaseFormatFactory<COBDIIFormat_0107> t_Factory_COBDIIFormat_0107("COBDIIFormat_0107");
CBaseFormatFactory<COBDIIFormat_0108> t_Factory_COBDIIFormat_0108("COBDIIFormat_0108");
CBaseFormatFactory<COBDIIFormat_0109> t_Factory_COBDIIFormat_0109("COBDIIFormat_0109");


CBaseFormatFactory<COBDIIFormat_010A> t_Factory_COBDIIFormat_010A("COBDIIFormat_010A");
CBaseFormatFactory<COBDIIFormat_010B> t_Factory_COBDIIFormat_010B("COBDIIFormat_010B");
CBaseFormatFactory<COBDIIFormat_010C> t_Factory_COBDIIFormat_010C("COBDIIFormat_010C");
CBaseFormatFactory<COBDIIFormat_010D> t_Factory_COBDIIFormat_010D("COBDIIFormat_010D");
CBaseFormatFactory<COBDIIFormat_010E> t_Factory_COBDIIFormat_010E("COBDIIFormat_010E");
CBaseFormatFactory<COBDIIFormat_010F> t_Factory_COBDIIFormat_010F("COBDIIFormat_010F");
CBaseFormatFactory<COBDIIFormat_0110> t_Factory_COBDIIFormat_0110("COBDIIFormat_0110");
CBaseFormatFactory<COBDIIFormat_0111> t_Factory_COBDIIFormat_0111("COBDIIFormat_0111");
CBaseFormatFactory<COBDIIFormat_0145> t_Factory_COBDIIFormat_0145("COBDIIFormat_0145");

CBaseFormatFactory<COBDIIFormat_0147> t_Factory_COBDIIFormat_0147("COBDIIFormat_0147");
CBaseFormatFactory<COBDIIFormat_0148> t_Factory_COBDIIFormat_0148("COBDIIFormat_0148");
CBaseFormatFactory<COBDIIFormat_0149> t_Factory_COBDIIFormat_0149("COBDIIFormat_0149");
CBaseFormatFactory<COBDIIFormat_014A> t_Factory_COBDIIFormat_014A("COBDIIFormat_014A");
CBaseFormatFactory<COBDIIFormat_014B> t_Factory_COBDIIFormat_014B("COBDIIFormat_014B");
CBaseFormatFactory<COBDIIFormat_014C> t_Factory_COBDIIFormat_014C("COBDIIFormat_014C");
CBaseFormatFactory<COBDIIFormat_0151> t_Factory_COBDIIFormat_0151("COBDIIFormat_0151");
CBaseFormatFactory<COBDIIFormat_0152> t_Factory_COBDIIFormat_0152("COBDIIFormat_0152");
CBaseFormatFactory<COBDIIFormat_015A> t_Factory_COBDIIFormat_015A("COBDIIFormat_015A");


CBaseFormatFactory<COBDIIFormat_0112> t_Factory_COBDIIFormat_0112("COBDIIFormat_0112");
CBaseFormatFactory<COBDIIFormat_0113> t_Factory_COBDIIFormat_0113("COBDIIFormat_0113");
CBaseFormatFactory<COBDIIFormat_011C> t_Factory_COBDIIFormat_011C("COBDIIFormat_011C");
CBaseFormatFactory<COBDIIFormat_011D> t_Factory_COBDIIFormat_011D("COBDIIFormat_011D");
CBaseFormatFactory<COBDIIFormat_011E> t_Factory_COBDIIFormat_011E("COBDIIFormat_011E");
CBaseFormatFactory<COBDIIFormat_011F> t_Factory_COBDIIFormat_011F("COBDIIFormat_011F");
CBaseFormatFactory<COBDIIFormat_0131> t_Factory_COBDIIFormat_0131("COBDIIFormat_0131");
CBaseFormatFactory<COBDIIFormat_0132> t_Factory_COBDIIFormat_0132("COBDIIFormat_0132");
CBaseFormatFactory<COBDIIFormat_014D> t_Factory_COBDIIFormat_014D("COBDIIFormat_014D");
CBaseFormatFactory<COBDIIFormat_014E> t_Factory_COBDIIFormat_014E("COBDIIFormat_014E");
CBaseFormatFactory<COBDIIFormat_014F> t_Factory_COBDIIFormat_014F("COBDIIFormat_014F");

CBaseFormatFactory<COBDIIFormat_012C> t_Factory_COBDIIFormat_012C("COBDIIFormat_012C");
CBaseFormatFactory<COBDIIFormat_012D> t_Factory_COBDIIFormat_012D("COBDIIFormat_012D");
CBaseFormatFactory<COBDIIFormat_012E> t_Factory_COBDIIFormat_012E("COBDIIFormat_012E");
CBaseFormatFactory<COBDIIFormat_012F> t_Factory_COBDIIFormat_012F("COBDIIFormat_012F");

CBaseFormatFactory<COBDIIFormat_03> t_Factory_COBDIIFormat_03("COBDIIFormat_03");
CBaseFormatFactory<COBDIIFormat_04> t_Factory_COBDIIFormat_04("COBDIIFormat_04");
CBaseFormatFactory<COBDIIFormat_07> t_Factory_COBDIIFormat_07("COBDIIFormat_07");
//static MyUtility::CFactory <CBaseFormat,COBDIIFormat> t_CBaseFormat_COBDIIFormat("CBaseFormat","COBDIIFormat");