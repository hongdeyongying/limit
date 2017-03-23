// BaseFormat.h: interface for the CBaseFormat class.
//
//////////////////////////////////////////////////////////////////////
#pragma warning(disable:4786) 
#if !defined(AFX_BASEFORMAT_H__1DC0BACA_8214_4C83_B7B1_B3ED1170E635__INCLUDED_)
#define AFX_BASEFORMAT_H__1DC0BACA_8214_4C83_B7B1_B3ED1170E635__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
#include <string>
using namespace std;

//#include "utility/CFactory.h"



class CBaseFormat  
{
public:
	string m_sPara;
	void SetPara(const string &para){m_sPara = para;};
	CBaseFormat();
	virtual int DoTranslate(const string &in_sReq, string &out_sReq)
	{
		out_sReq = in_sReq;return 0;
	};
	virtual ~CBaseFormat();

};

typedef CBaseFormat*(*CBaseFormatMaker)(const string &)  ;

typedef std::map<std::string,CBaseFormatMaker>  CStringMethodMap;
typedef std::map<std::string,CBaseFormat *>  CStringInstanceMap;

extern CStringMethodMap g_CBaseFormatFactory;
extern CStringInstanceMap g_CStringInstanceMap;

template <typename T>
class CBaseFormatFactory
{
public:
	

	static CBaseFormat *Method(const string &tid)
    {
		g_CStringInstanceMap[tid] = new T;

         return g_CStringInstanceMap[tid];
    }

	CBaseFormatFactory(const string & tid)
	{
		if(g_CBaseFormatFactory.find(tid) == g_CBaseFormatFactory.end())
		{
			g_CBaseFormatFactory[tid] = CBaseFormatFactory<T>::Method;
			g_CStringInstanceMap[tid] =NULL;
		}

	}

	~CBaseFormatFactory()
	{
		//g_CBaseFormatFactory
	}

	CBaseFormat *GetInstance(const string &tid,const string &para)
	{
		T * res = NULL;
	
		if(g_CBaseFormatFactory.find(tid) != g_CBaseFormatFactory.end())
		{
			res = g_CBaseFormatFactory[tid](tid);
		}

		if( NULL != res)
		{
			res->SetPara(para);
		}
				
		return res;
	}

	CBaseFormat *GetSingletonInstance(const string &tid,const string &para)
	{
		
		if (g_CStringInstanceMap[tid] == NULL) 
		{	
			if(g_CBaseFormatFactory.find(tid) != g_CBaseFormatFactory.end())
			{
				g_CStringInstanceMap[tid] = g_CBaseFormatFactory[tid](tid);
			}
		}

		if(g_CStringInstanceMap[tid] != NULL)
		{
			g_CStringInstanceMap[tid]->SetPara(para);
		}
				
		return g_CStringInstanceMap[tid];
	}/**/

};

//template <typename T>  T* CBaseFormatFactory<T>::m_pT = NULL;


extern CBaseFormatFactory<CBaseFormat> g_Factory;

//extern MyUtility::CFactory <CBaseFormat,CBaseFormat> g_CBaseFormatFactory;

#endif // !defined(AFX_BASEFORMAT_H__1DC0BACA_8214_4C83_B7B1_B3ED1170E635__INCLUDED_)
