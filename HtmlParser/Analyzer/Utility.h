// Utility.h: interface for the CUtility class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTILITY_H__61542EB6_70CF_45FB_ACFE_AAEFBE4B90A1__INCLUDED_)
#define AFX_UTILITY_H__61542EB6_70CF_45FB_ACFE_AAEFBE4B90A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <string>
#include <iostream>
using namespace std;

class CUtility  
{
public:
	CUtility();
	virtual ~CUtility();

	static int hex_to_num(char c)
	{
		if(c>='0' && c <= '9')
			return c-'0';
		else if(c>='A' && c<= 'F')
			return c-'A' + 10;
		else if(c>='a' && c<= 'f')
			return c-'a' + 10;
		else
			return -1;
	}

	static int hex_to_num(const string & hexstr)
	{
		int tmp, res = 0;
		string::const_iterator iter;
		
		for(iter = hexstr.begin(); iter != hexstr.end(); ++iter) 
		{
			tmp = hex_to_num(*iter);
			if(tmp != -1)
			{
				res = res * 16 + tmp;
			}
			else

				return -1;
		}

		return res;
	}

	static string & TrimLeft(string & src)
	{	
		string::const_iterator iter;
		iter = src.begin();

		while( iter != src.end()) 
		{
			if((*iter)  == ' ')
			{
				src.erase(0,1);
				iter = src.begin();
			}
			else
				break;

		}
		return src;
	}

	static int get_first_http_text(const string &src,string::const_iterator &iter)
	{
		//无正文
		int res = 1;

		//0 1 2
		int state = 0;
		
		for(iter ; iter != src.end(); ++iter) 
		{
			switch(*iter) 
			{
			case '\n':
				state++;
				if(state == 2)
				{
					iter++;
					return 0;
				}
				break;	
			case '\r':
				break;
			default:
				if(state == 1) state=0;
				break;
			}
		}
		return res;

	}

	static string &get_first_line(string::const_iterator &iterBegin,const string::const_iterator &iterEnd,string & val)
	{
		val = "";
		for(iterBegin ; iterBegin != iterEnd; ++iterBegin) 
		{
			switch(*iterBegin) 
			{
			case '\n':
				iterBegin++;
				return val;
				break;
			case '\r':						
				break;				
			default:
				val.append(1, *iterBegin);
				break;
			}
		}
		return val;
	}


	static string &get_first_line(const string & src,string::const_iterator &iter,string & val)
	{
		val = "";
		for(iter ; iter != src.end(); ++iter) 
		{
			switch(*iter) 
			{
			case '\n':
				iter++;
				return val;
				break;
			case '\r':						
				break;				
			default:
				val.append(1, *iter);
				break;
			}
		}
		return val;
	}

	static string& get_first_line(const string & src,string & val)
	{
		val = "";
		string::const_iterator iter;
		
		for(iter = src.begin(); iter != src.end(); ++iter) 
		{
			switch(*iter) 
			{
			case '\n':
				return val;
				break;
			case '\r':				
				break;				
			default:
				val.append(1, *iter);
				break;
			}
		}
		return val;
	}
	
	static string&  replace_all(string&   str,const   string&   old_value,const   string&   new_value)   
	{   
		while(true)   
		{   
			string::size_type   pos(0);   
			if(   (pos=str.find(old_value))!=string::npos   )   
				str.replace(pos,old_value.length(),new_value);   
			else   
				break;   
		}   
		return   str;   
	}   
	
	static string&   replace_all_distinct(string&   str,const   string&   old_value,const   string&   new_value)   
	{   
		for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())   {   
			if(   (pos=str.find(old_value,pos))!=string::npos   )   
				str.replace(pos,old_value.length(),new_value);   
			else   break;   
		}   
		return   str;   
	}   
	
	static string charToHex(char c)
	{
		std::string result;
		char first, second;
		
		first = (c & 0xF0) / 16;
		first += first > 9 ? 'A' - 10 : '0';
		second = c & 0x0F;
		second += second > 9 ? 'A' - 10 : '0';
		
		result.append(1, first);
		result.append(1, second);
		
		return result;
	}
	static char  hexToChar(char first,char second)
	{
		int digit;
		
		digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
		digit *= 16;
		digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
		return static_cast<char>(digit);
	}
	/*
	&lt; < 小于 
&gt; > 大于 
&amp; & 和号 
&apos; ' 省略号 
&quot; " 引号 

	*/
	static string XmlEncode(const std::string& src)
	{
		string result;
		string::const_iterator iter;
		
		for(iter = src.begin(); iter != src.end(); ++iter) 
		{
			switch(*iter) 
			{
			case '<':
				result.append("&lt;");
				break;		
			case '>':
				result.append("&gt;");
				break;	
			case '&':
				result.append("&amp;");
				break;	
				break;	
			case '\'':
				result.append("&apos;");
				break;	
			case '"':
				result.append("&quot;");
				break;	
			default:
				result.append(1, *iter);
				break;
			}
		}
		
		return result;
	}
	static string XmlDecode(const std::string& src)
	{
		string result;
		string::const_iterator iter;
		
		for(iter = src.begin(); iter != src.end(); ++iter) 
		{
			switch(*iter) 
			{
			case '&':
				{
					string entity;
					do
					{
						if(*iter == ';')
						{
							entity.append(1,*iter);
							break;
						}
						else
							entity.append(1,*iter++);
					}while(iter != src.end());

					if(entity == "&lt;")
						result.append(1, '<');
					else if(entity == "&gt;")
						result.append(1, '>');
					else if(entity == "&amp;")
						result.append(1, '&');
					else if(entity == "&apos;")
						result.append(1, '\'');
					else if(entity == "&quot;")
						result.append(1, '"');
				}
				break;				
			default:
				result.append(1, *iter);
				break;
			}
		}
		
		return result;
	}
	static string UrlDecode(const std::string& src)
	{
		string result;
		string::const_iterator iter;
		char c;
		
		for(iter = src.begin(); iter != src.end(); ++iter) {
			switch(*iter) {
			case '+':
				result.append(1, ' ');
				break;
			case '%':
				// Don't assume well-formed input
				if(distance(iter, src.end()) >= 2
					&& isxdigit(*(iter + 1)) && isxdigit(*(iter + 2))) {
					c = *++iter;
					result.append(1, hexToChar(c, *++iter));
				}
				// Just pass the % through untouched
				else {
					result.append(1, '%');
				}
				break;
				
			default:
				result.append(1, *iter);
				break;
			}
		}
		
		return result;
	}
	static string GetSiteFromUrl(const string &url)
	{
		string result;
		
		string::size_type   pos(0);   

		if(url.substr(0,7) == string("http://"))
			result = url.substr(7);
		else if(url.substr(0,8) == string("https://"))
			result = url.substr(8);


		if(((pos = result.find("/")) != string::npos))
		{
			result = result.substr(0,pos);
		}

		return result;

	}
	static string UrlEncode(const string& src)
	{
		string result;
		string::const_iterator iter;
		
		for(iter = src.begin(); iter != src.end(); ++iter) 
		{
			switch(*iter) 
			{
			case ' ':
				result.append(1, '+');
				break;
				// alnum
			case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
			case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
			case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
			case 'V': case 'W': case 'X': case 'Y': case 'Z':
			case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
			case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
			case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
			case 'v': case 'w': case 'x': case 'y': case 'z':
			case '0': case '1': case '2': case '3': case '4': case '5': case '6':
			case '7': case '8': case '9':
				// mark
			case '-': case '_': case '.': case '!': case '~': case '*': case '\'': 
			case '(': case ')':
			//http://hnair.travelsky.com/huet/ 的cookie中有:号，编码后失效。
			case ':':
				result.append(1, *iter);
				break;
				// escape
			default:
			//	if((unsigned char)(*iter) > 127)
			//	{
			//		result.append(1, *iter);
			//	}
			//	else
				{
					result.append(1, '%');
					result.append(charToHex(*iter));
				}
				break;
			}
		}
		
		return result;
	}
	

	static string IntegerToString(int i)
	{
		char szBuf[100] = {0};

		sprintf(szBuf,"%d",i);

		return string(szBuf);
	}
	static int StringToInteger(string & str)
	{
		int i = 0;

		sscanf(str.c_str(),"%d",&i);

		return i;
	}

};



#endif // !defined(AFX_UTILITY_H__61542EB6_70CF_45FB_ACFE_AAEFBE4B90A1__INCLUDED_)
