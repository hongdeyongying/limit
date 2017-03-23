// OBDIIFormat_0121.h: interface for the COBDIIFormat_0121 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBDIIFORMAT_0121_H__550AF91B_CDAD_4439_A63D_9968CE13EA99__INCLUDED_)
#define AFX_OBDIIFORMAT_0121_H__550AF91B_CDAD_4439_A63D_9968CE13EA99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OBDIIFormat_0114.h"

class COBDIIFormat_0121 : public COBDIIFormat_0114  
{
public:
	COBDIIFormat_0121(){m_sPID="21";};
	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0122 : public COBDIIFormat_0114  
{
public:
	COBDIIFormat_0122(){m_sPID="22";};
	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0123 : public COBDIIFormat_0114  
{
public:
	COBDIIFormat_0123(){m_sPID="23";};
	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

#endif // !defined(AFX_OBDIIFORMAT_0121_H__550AF91B_CDAD_4439_A63D_9968CE13EA99__INCLUDED_)
