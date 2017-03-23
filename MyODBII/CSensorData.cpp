#include "CSensorData.h"

#include <time.h>

#include "utility/CBaseEncode.h"

CTCDSet g_objCTCDSet;

//##ModelId=4E3F2A9B031C
CSensorData::CSensorData(unsigned int tm,const string &val)
{
	m_uTime = tm;
	m_sValue = val;
}
CSensorData::CSensorData(unsigned int val)
{
	SetValue(val);
}
CSensorData::CSensorData(int val)
{
	SetValue(val);
}

CSensorData::CSensorData(double val)
{
	SetValue(val);
}
CSensorData::CSensorData(const string &val)
{
	SetValue(val);
}

//##ModelId=4E3F2A9B034B
CSensorData::~CSensorData()
{
}


void CSensorData::SetValue(unsigned int val)
{
	SetValue(MyUtility::CBaseEncode::UIntToString(val));
}
void CSensorData::SetValue(int val)
{
	SetValue(MyUtility::CBaseEncode::IntToString(val));
}

void CSensorData::SetValue(double val)
{
	SetValue(MyUtility::CBaseEncode::DoubleToString(val));
}

void CSensorData::SetValue(const string &val)
{
	m_sValue = val;
	m_uTime = time(NULL);
}
