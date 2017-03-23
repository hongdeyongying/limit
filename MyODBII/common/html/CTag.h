// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef CTAG_H_HEADER_INCLUDED_B62B77F0
#define CTAG_H_HEADER_INCLUDED_B62B77F0

#include "mysoft_html.h"

class CStrVector  : public vector<string>
{
public:
	CStrVector();
	virtual ~CStrVector();

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

class CStrSet  : public set<string>
{
public:

	void SetCommaText(const string & value, const string &sep,int flag = 0 )
	{
		SetCommaText(value.c_str(),sep.c_str(),flag);
	}

	void SetCommaText(const char* value, const char *sep,int flag = 0 )
	{
		clear();

		if(strlen(value) == 0) return;

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
                                insert(tmp);

                                p++;
                                s = p;
                        }
                }
                else
                {
                        if (!strlen(s) && flag)
                        {
                                string tmp = "";
                                insert(tmp);
                        }
                        else if(strlen(s))
                        {
                                string tmp(s);
                                insert(tmp);
                        }
                }
        } while (p);
	}
      

}; 
//##ModelId=49D2E786008C
class CTag
{
  public:
    //##ModelId=49D47D45029F
    CTag(const char * name, enum ETAG endstyle, int priority, 
        // �Զ��ŷָ�
        const char * endtags);

	string ToLower(const string & str) const
	{
		string res;
		string::const_iterator iter;

		for(iter = str.begin();iter != str.end();iter++)
			res += tolower(*iter);

		return res;
	}

	bool CanEndTHisTag(const string &str) const
	{

		bool res = m_vEndTag.find(ToLower(str)) != m_vEndTag.end();

	//	res = res || (m_sName == str.substr(1,str.size()-1));

		return res;
	}

	bool SingleTag() const
	{
		return m_eEndStyle == TAG_NONE;
	}

  private:
    // TAG������
    //##ModelId=49D2E79201A5
    std::string m_sName;

    // ��TAG�Ľ�������
    //##ModelId=49D2E7980271
    enum ETAG m_eEndStyle;

    // ���Խ�����TAG��TAG����
    //##ModelId=49D2E7AE00AB
    CStrSet m_vEndTag;

    // ���ȼ�
    //##ModelId=49D2EECB00AB
    int m_iPriority;

};



#endif /* CTAG_H_HEADER_INCLUDED_B62B77F0 */
