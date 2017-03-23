// StrArray.h: interface for the CStrArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRARRAY_H__62AE6981_C8B3_4C4F_B74D_D0CFD6643390__INCLUDED_)
#define AFX_STRARRAY_H__62AE6981_C8B3_4C4F_B74D_D0CFD6643390__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Utility.h"

typedef std::map<std::string,std::string> CStr2Map;
typedef std::vector<std::string> CStrVector;


class CStrArray  : public vector<string>
{
public:
	CStrArray();
	virtual ~CStrArray();

	void SetCommaText(const string & value, const string &sep,int flag = 0 )
	{
		SetCommaText(value.c_str(),sep.c_str(),flag);
	}

	void SetCommaText(const char* value, const char *sep,int flag = 0 )
	{
		erase(begin(), end());

        char* p;
        const char* s = value;
        do
        {
                p = strpbrk(s, sep);
                if (p)
                {
                        if (p == s)
                        {
                                p++;
                                s++;
                        }
                        else
                        {
                                string tmp(s, p - s);
                                push_back(tmp);

                                p++;
                                s = p;
                        }
                }
                else
                {
                        if (!strlen(s) && flag)
                        {
                                string tmp = "";
                                push_back(tmp);
                        }
                        else if(strlen(s))
                        {
                                string tmp(s);
                                push_back(tmp);
                        }
                }
        } while (p);
	}
      

};


enum ENUM_RETCODE_CStringMap
{
  SUC = 0,
  NOE = 1, //none element
  INV = 2, //invalid name  value pair
};

class CStrMap : public map<string,string>
{
public:
	CStrMap(){};
	CStrMap(string paras)
	{
		SnapElement(paras);
	}
	virtual ~CStrMap(){};
    //##ModelId=44E298120261
	int SnapElement(
		// 原始报文
		string sDigram, 
		// 字段分隔符
		string sEleSep = "&", 
		// 名字值分隔符
		string sNvSep = "=" ,
		int flag = 0
		)
	{
		CStrArray vEle,vNv;
		
		int iRetcd = SUC;
		
		clear();
		
		vEle.SetCommaText(sDigram,sEleSep);
		
		for(int i = 0; i< vEle.size();i++)
		{
			vNv.SetCommaText(vEle[i],sNvSep,flag);
			if(vNv.size() < 2)
			{
				iRetcd |= INV;
			}
			else
			{
				insert(value_type(vNv[0],CUtility::UrlDecode(vEle[i].substr(vNv[0].length()+1))));
			}
		}
		
		if(size() == 0)
			iRetcd |= NOE;
		
		return iRetcd;
	};
	
	
    // 从MAP还原报文，可以指定分隔符
    //##ModelId=44E298EB0222
    /*
	string & GenString(
        // 原始报文
        string &sDigram, 
        // 字段分隔符
        string sEleSep = "&", 
        // 名字值分隔符
        string sNvSep = "=")
	{		
		iterator mapPos;
		
		mapPos = begin();
		if(mapPos == end())
		{
			return sDigram;
		}
		
		sDigram += mapPos->first + sNvSep + CUtility::UrlEncode(mapPos->second);
		
		for(++mapPos;mapPos != end();mapPos++)
		{
			sDigram += sEleSep + mapPos->first + sNvSep + CUtility::UrlEncode(mapPos->second);
		}
		
		return sDigram;
		
	};*/
	string & GenString(
        // 原始报文
        string &sDigram, 
        // 字段分隔符
        string sEleSep = "&", 
        // 名字值分隔符
        string sNvSep = "=",
		int mode=0)
	{		
		iterator mapPos;
		
		mapPos = begin();
		if(mapPos == end())
		{
			return sDigram;
		}
		if(mode == 0)
			sDigram += mapPos->first + sNvSep + CUtility::UrlEncode(mapPos->second);
		else
			sDigram += mapPos->first + sNvSep + mapPos->second;
		for(++mapPos;mapPos != end();mapPos++)
		{
			if(mode == 0)
				sDigram += sEleSep + mapPos->first + sNvSep + CUtility::UrlEncode(mapPos->second);
			else
				sDigram += sEleSep + mapPos->first + sNvSep + mapPos->second;
		}
		
		return sDigram;
		
	};
	
};

#endif // !defined(AFX_STRARRAY_H__62AE6981_C8B3_4C4F_B74D_D0CFD6643390__INCLUDED_)
