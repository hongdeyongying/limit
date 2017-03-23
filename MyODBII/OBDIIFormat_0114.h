// OBDIIFormat_0114.h: interface for the COBDIIFormat_0114 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBDIIFORMAT_0114_H__C0837C6E_2F87_44BA_A96A_29A093C81042__INCLUDED_)
#define AFX_OBDIIFORMAT_0114_H__C0837C6E_2F87_44BA_A96A_29A093C81042__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OBDIIFormat.h"
#include "utility/CBaseEncode.h"

class COBDIIFormat_0114 : public COBDIIFormat  
{
public:
	COBDIIFormat_0114(){m_sPID = "14";};
	virtual ~COBDIIFormat_0114();

	int DoTranslate(const string &in_sReq, string &out_sReq) ;

};
class COBDIIFormat_0115 : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_0115(){m_sPID = "15";};
	//virtual ~COBDIIFormat_0115();


};
class COBDIIFormat_0116 : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_0116(){m_sPID = "16";};
	//virtual ~COBDIIFormat_0116();


};
class COBDIIFormat_0117 : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_0117(){m_sPID = "17";};
	//virtual ~COBDIIFormat_0117();


};
class COBDIIFormat_0118 : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_0118(){m_sPID = "18";};
	//virtual ~COBDIIFormat_0118();


};
class COBDIIFormat_0119 : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_0119(){m_sPID = "19";};
	//virtual ~COBDIIFormat_0119();


};

class COBDIIFormat_011A : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_011A(){m_sPID = "1A";};
	//virtual ~COBDIIFormat_011A();


};
class COBDIIFormat_011B : public COBDIIFormat_0114  
{
public:
	//string m_sPID;
	COBDIIFormat_011B(){m_sPID = "1B";};
	//virtual ~COBDIIFormat_011B();


};
// 24 - 2B
class COBDIIFormat_0124 : public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_0124(){m_sPID = "24";};
	//virtual ~COBDIIFormat_0124();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};

class COBDIIFormat_0141 : public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_0141(){m_sPID = "41";m_iLen = 8;};
	//virtual ~COBDIIFormat_0124();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};
class COBDIIFormat_0142 : public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_0142(){m_sPID = "42";m_iLen = 4;};
	//virtual ~COBDIIFormat_0124();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};
class COBDIIFormat_0143: public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_0143(){m_sPID = "43";m_iLen = 4;};
	//virtual ~COBDIIFormat_0124();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};
class COBDIIFormat_0144: public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_0144(){m_sPID = "44";m_iLen = 4;};
	//virtual ~COBDIIFormat_0124();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};
class COBDIIFormat_0125 : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_0125(){m_sPID = "25";};
	//virtual ~COBDIIFormat_0125();


};
class COBDIIFormat_0126 : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_0126(){m_sPID = "26";};
	//virtual ~COBDIIFormat_0126();


};
class COBDIIFormat_0127 : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_0127(){m_sPID = "27";};
	//virtual ~COBDIIFormat_0127();


};
class COBDIIFormat_0128 : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_0128(){m_sPID = "28";};
	//virtual ~COBDIIFormat_0128();


};
class COBDIIFormat_0129 : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_0129(){m_sPID = "29";};
	//virtual ~COBDIIFormat_0129();


};

class COBDIIFormat_012A : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_012A(){m_sPID = "2A";};
	//virtual ~COBDIIFormat_012A();


};
class COBDIIFormat_012B : public COBDIIFormat_0124  
{
public:
	//string m_sPID;
	COBDIIFormat_012B(){m_sPID = "2B";};
	//virtual ~COBDIIFormat_012B();


};
// 34 -  3B

class COBDIIFormat_0134 : public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_0134(){m_sPID = "34";};
	//virtual ~COBDIIFormat_0134();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};

class COBDIIFormat_0135 : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_0135(){m_sPID = "35";};
	//virtual ~COBDIIFormat_0135();


};
class COBDIIFormat_0136 : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_0136(){m_sPID = "36";};
	//virtual ~COBDIIFormat_0136();


};
class COBDIIFormat_0137 : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_0137(){m_sPID = "37";};
	//virtual ~COBDIIFormat_0137();


};
class COBDIIFormat_0138 : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_0138(){m_sPID = "38";};
	//virtual ~COBDIIFormat_0138();


};
class COBDIIFormat_0139 : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_0139(){m_sPID = "39";};
	//virtual ~COBDIIFormat_0139();


};

class COBDIIFormat_013A : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_013A(){m_sPID = "3A";};
	//virtual ~COBDIIFormat_013A();


};
class COBDIIFormat_013B : public COBDIIFormat_0134  
{
public:
	//string m_sPID;
	COBDIIFormat_013B(){m_sPID = "3B";};
	//virtual ~COBDIIFormat_013B();


};

//3C - 3F

class COBDIIFormat_013C : public COBDIIFormat  
{
public:
	//string m_sPID;
	COBDIIFormat_013C(){m_sPID = "3C";};
	//virtual ~COBDIIFormat_0134();
	int DoTranslate(const string &in_sReq, string &out_sReq) ;


};
class COBDIIFormat_013D : public COBDIIFormat_013C  
{
public:
	//string m_sPID;
	COBDIIFormat_013D(){m_sPID = "3D";};
	//virtual ~COBDIIFormat_013B();


};

class COBDIIFormat_013E : public COBDIIFormat_013C  
{
public:
	//string m_sPID;
	COBDIIFormat_013E(){m_sPID = "3E";};
	//virtual ~COBDIIFormat_013B();


};

class COBDIIFormat_013F : public COBDIIFormat_013C  
{
public:
	//string m_sPID;
	COBDIIFormat_013F(){m_sPID = "3F";};
	//virtual ~COBDIIFormat_013B();


};


#endif // !defined(AFX_OBDIIFORMAT_0114_H__C0837C6E_2F87_44BA_A96A_29A093C81042__INCLUDED_)
