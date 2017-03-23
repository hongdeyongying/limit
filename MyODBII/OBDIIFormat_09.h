// OBDIIFormat_09.h: interface for the COBDIIFormat_09 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBDIIFORMAT_09_H__7FBC8B48_6C5C_4E55_8751_DE79EEAA2300__INCLUDED_)
#define AFX_OBDIIFORMAT_09_H__7FBC8B48_6C5C_4E55_8751_DE79EEAA2300__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OBDIIFormat.h"

class COBDIIFormat_09 : public COBDIIFormat  
{
public:
	int DoTranslate(const string &in_sReq, string &out_sRes);
	COBDIIFormat_09();
	virtual ~COBDIIFormat_09();

};

class COBDIIFormat_0901 : public COBDIIFormat  
{
public:
	int DoTranslate(const string &in_sReq, string &out_sRes);
	

};
class COBDIIFormat_0902 : public COBDIIFormat  
{
public:
	int DoTranslate(const string &in_sReq, string &out_sRes);
	

};
class COBDIIFormat_0906 : public COBDIIFormat  
{
public:
	int DoTranslate(const string &in_sReq, string &out_sRes);
	

};
class COBDIIFormat_0908 : public COBDIIFormat  
{
public:
	int DoTranslate(const string &in_sReq, string &out_sRes);
	

};
class COBDIIFormat_090A : public COBDIIFormat  
{
public:
	int DoTranslate(const string &in_sReq, string &out_sRes);
	

};
#endif // !defined(AFX_OBDIIFORMAT_09_H__7FBC8B48_6C5C_4E55_8751_DE79EEAA2300__INCLUDED_)
