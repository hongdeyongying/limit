// OBDIIFormat_0130.h: interface for the COBDIIFormat_0130 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBDIIFORMAT_0130_H__53C2151C_0050_436B_B13D_D51712253BC7__INCLUDED_)
#define AFX_OBDIIFORMAT_0130_H__53C2151C_0050_436B_B13D_D51712253BC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OBDIIFormat.h"

class COBDIIFormat_0130 : public COBDIIFormat  
{
public:
	COBDIIFormat_0130(){m_sPID="30";};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;
};

class COBDIIFormat_0133: public COBDIIFormat_0130  
{
public:
	COBDIIFormat_0133(){m_sPID="33";};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;
};

#endif // !defined(AFX_OBDIIFORMAT_0130_H__53C2151C_0050_436B_B13D_D51712253BC7__INCLUDED_)
