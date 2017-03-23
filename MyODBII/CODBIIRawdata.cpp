#include "stdafx.h"
#include "CODBIIRawdata.h"



//##ModelId=4E3B31FA00F8
CODBIIRawdata::CODBIIRawdata()
{
	Clear();
}


//##ModelId=4E3B31FA0107
CODBIIRawdata::~CODBIIRawdata()
{
}


void CODBIIRawdata::Clear()
{
	m_iStatus = -1;
	m_sRes = "";
	m_sReq = "";
	m_uID = 0;
	m_uReqTime = 0;
	m_uSpendTime = 0;
}
