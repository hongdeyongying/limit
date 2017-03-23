// OBDIIFormat_0153.h: interface for the COBDIIFormat_0153 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBDIIFORMAT_0153_H__01409030_2AFB_4B81_953E_821B07A67D94__INCLUDED_)
#define AFX_OBDIIFORMAT_0153_H__01409030_2AFB_4B81_953E_821B07A67D94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OBDIIFormat.h"

class COBDIIFormat_0153 : public COBDIIFormat  
{
public:
	COBDIIFormat_0153(){m_sPID="53";m_iLen=4;};
	virtual ~COBDIIFormat_0153(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0154 : public COBDIIFormat  
{
public:
	COBDIIFormat_0154(){m_sPID="54";m_iLen=4;};
	virtual ~COBDIIFormat_0154(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0155 : public COBDIIFormat  
{
public:
	COBDIIFormat_0155(){m_sPID="55";m_iLen=4;};
	virtual ~COBDIIFormat_0155(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0159 : public COBDIIFormat  
{
public:
	COBDIIFormat_0159(){m_sPID="59";m_iLen=4;};
	virtual ~COBDIIFormat_0159(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0156 : public COBDIIFormat_0155  
{
public:
	COBDIIFormat_0156(){m_sPID="56";m_iLen=4;};
	//virtual ~COBDIIFormat_0155(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0157 : public COBDIIFormat_0155  
{
public:
	COBDIIFormat_0157(){m_sPID="57";m_iLen=4;};
	//virtual ~COBDIIFormat_0155(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0158 : public COBDIIFormat_0155  
{
public:
	COBDIIFormat_0158(){m_sPID="58";m_iLen=4;};
	//virtual ~COBDIIFormat_0155(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
#endif // !defined(AFX_OBDIIFORMAT_0153_H__01409030_2AFB_4B81_953E_821B07A67D94__INCLUDED_)
