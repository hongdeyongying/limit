// OBDIIFormat.h: interface for the COBDIIFormat class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBDIIFORMAT_H__106A23A7_4F17_4EF6_8386_4B63FAC7AE03__INCLUDED_)
#define AFX_OBDIIFORMAT_H__106A23A7_4F17_4EF6_8386_4B63FAC7AE03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseFormat.h"

#include "global_var.h"

#include "utility/CBaseEncode.h"

class COBDIIFormat : public CBaseFormat  
{	
public:
	int m_iLen;
	string m_sPID;

	COBDIIFormat(const string &para){m_sPara = para;};
	COBDIIFormat(){m_sPID = "";};
	virtual ~COBDIIFormat();

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0100 : public COBDIIFormat  
{
public:
	int m_iPidFrom;

	string m_sFilter;

	COBDIIFormat_0100(){m_iPidFrom = 0;m_sFilter = "4100";};
	virtual ~COBDIIFormat_0100(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0120 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_0120(){};
	virtual ~COBDIIFormat_0120(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0140 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_0140(){};
	virtual ~COBDIIFormat_0140(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0160 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_0160(){};
	virtual ~COBDIIFormat_0160(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0180 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_0180(){};
	virtual ~COBDIIFormat_0180(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_01A0 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_01A0(){};
	virtual ~COBDIIFormat_01A0(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_01C0 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_01C0(){};
	virtual ~COBDIIFormat_01C0(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_010A : public COBDIIFormat
{
public:
	COBDIIFormat_010A(){};
	virtual ~COBDIIFormat_010A(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_010B : public COBDIIFormat
{
public:
	COBDIIFormat_010B(){};
	virtual ~COBDIIFormat_010B(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_010D : public COBDIIFormat
{
public:
	COBDIIFormat_010D(){};
	virtual ~COBDIIFormat_010D(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_010E : public COBDIIFormat
{
public:
	COBDIIFormat_010E(){};
	virtual ~COBDIIFormat_010E(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_010F : public COBDIIFormat
{
public:
	COBDIIFormat_010F(){};
	virtual ~COBDIIFormat_010F(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0110 : public COBDIIFormat
{
public:
	COBDIIFormat_0110(){};
	virtual ~COBDIIFormat_0110(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0111 : public COBDIIFormat
{
public:
	COBDIIFormat_0111(){m_sPID="11";};
	virtual ~COBDIIFormat_0111(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_012C : public COBDIIFormat_0111
{
public:
	COBDIIFormat_012C(){m_sPID="2C";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_015A : public COBDIIFormat_0111
{
public:
	COBDIIFormat_015A(){m_sPID="5A";m_iLen = 2;};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0145 : public COBDIIFormat_0111
{
public:
	COBDIIFormat_0145(){m_sPID="45";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0147 : public COBDIIFormat_0111
{
public:
	COBDIIFormat_0147(){m_sPID="47";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0148 : public COBDIIFormat_0111
{
public:
	COBDIIFormat_0148(){m_sPID="48";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0149 : public COBDIIFormat_0111
{
public:
	COBDIIFormat_0149(){m_sPID="49";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_014A : public COBDIIFormat_0111
{
public:
	COBDIIFormat_014A(){m_sPID="4A";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_014B : public COBDIIFormat_0111
{
public:
	COBDIIFormat_014B(){m_sPID="4B";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_014C : public COBDIIFormat_0111
{
public:
	COBDIIFormat_014C(){m_sPID="4C";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0152 : public COBDIIFormat_0111
{
public:
	COBDIIFormat_0152(){m_sPID="52";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_012E : public COBDIIFormat_0111
{
public:
	COBDIIFormat_012E(){m_sPID="2E";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_012F : public COBDIIFormat_0111
{
public:
	COBDIIFormat_012F(){m_sPID="2F";};

//	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0112 : public COBDIIFormat
{
public:
	COBDIIFormat_0112(){};
	virtual ~COBDIIFormat_0112(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0113 : public COBDIIFormat
{
public:
	COBDIIFormat_0113(){};
	virtual ~COBDIIFormat_0113(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_011C : public COBDIIFormat
{
public:
	COBDIIFormat_011C(){};
	virtual ~COBDIIFormat_011C(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_011D : public COBDIIFormat
{
public:
	COBDIIFormat_011D(){};
	virtual ~COBDIIFormat_011D(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_011E : public COBDIIFormat
{
public:
	COBDIIFormat_011E(){};
	virtual ~COBDIIFormat_011E(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_011F : public COBDIIFormat
{
public:
	COBDIIFormat_011F(){m_sPID="1F";};
	virtual ~COBDIIFormat_011F(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_014F : public COBDIIFormat
{
public:
	COBDIIFormat_014F(){m_sPID="4F";m_iLen = 8;};
	virtual ~COBDIIFormat_014F(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0150 : public COBDIIFormat
{
public:
	COBDIIFormat_0150(){m_sPID="50";m_iLen = 8;};
	//virtual ~COBDIIFormat_014F(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0151 : public COBDIIFormat
{
public:
	COBDIIFormat_0151(){m_sPID="51";m_iLen = 2;};
	//virtual ~COBDIIFormat_014F(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0131 : public COBDIIFormat_011F
{
public:
	COBDIIFormat_0131(){m_sPID="31";};
	//virtual ~COBDIIFormat_011F(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_014D : public COBDIIFormat_011F
{
public:
	COBDIIFormat_014D(){m_sPID="4D";};
	//virtual ~COBDIIFormat_011F(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_014E : public COBDIIFormat_011F
{
public:
	COBDIIFormat_014E(){m_sPID="4E";};
	//virtual ~COBDIIFormat_011F(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0132 : public COBDIIFormat
{
public:
	COBDIIFormat_0132(){m_sPID="32";};
//	virtual ~COBDIIFormat_011F(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_01E0 : public COBDIIFormat_0100  
{
public:
	COBDIIFormat_01E0(){};
	virtual ~COBDIIFormat_01E0(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0101 : public COBDIIFormat  
{
public:
	COBDIIFormat_0101(){};
	virtual ~COBDIIFormat_0101(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0102 : public COBDIIFormat  
{
public:
	COBDIIFormat_0102(){};
	virtual ~COBDIIFormat_0102(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_03 : public COBDIIFormat  
{
public:
	COBDIIFormat_03(){};
	virtual ~COBDIIFormat_03(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_04 : public COBDIIFormat  
{
public:
	COBDIIFormat_04(){};
	virtual ~COBDIIFormat_04(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_07 : public COBDIIFormat  
{
public:
	COBDIIFormat_07(){};
	virtual ~COBDIIFormat_07(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};

class COBDIIFormat_0103 : public COBDIIFormat  
{
public:
	COBDIIFormat_0103(){};
	virtual ~COBDIIFormat_0103(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0104 : public COBDIIFormat  
{
public:
	COBDIIFormat_0104(){};
	virtual ~COBDIIFormat_0104(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0105 : public COBDIIFormat  
{
public:
	COBDIIFormat_0105(){m_sPID = "05";};
	virtual ~COBDIIFormat_0105(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0146 : public COBDIIFormat  
{
public:
	COBDIIFormat_0146(){m_sPID = "46";};
	//virtual ~COBDIIFormat_0105(){};

	//int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0106 : public COBDIIFormat  
{
public:
	COBDIIFormat_0106(){m_sPID="06";};
	virtual ~COBDIIFormat_0106(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_012D : public COBDIIFormat_0106  
{
public:
	COBDIIFormat_012D(){m_sPID="2D";};
	


};
class COBDIIFormat_0107 : public COBDIIFormat  
{
public:
	COBDIIFormat_0107(){};
	virtual ~COBDIIFormat_0107(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0108 : public COBDIIFormat  
{
public:
	COBDIIFormat_0108(){};
	virtual ~COBDIIFormat_0108(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0109 : public COBDIIFormat  
{
public:
	COBDIIFormat_0109(){};
	virtual ~COBDIIFormat_0109(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_010C : public COBDIIFormat  
{
public:
	COBDIIFormat_010C(){};
	virtual ~COBDIIFormat_010C(){};

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
#endif // !defined(AFX_OBDIIFORMAT_H__106A23A7_4F17_4EF6_8386_4B63FAC7AE03__INCLUDED_)
