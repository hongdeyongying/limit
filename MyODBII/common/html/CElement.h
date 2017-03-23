// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef CELEMENT_H_HEADER_INCLUDED_B62B2467
#define CELEMENT_H_HEADER_INCLUDED_B62B2467

#include "mysoft_html.h"
#include "CNode.h"
#include "CAttribute.h"

//##ModelId=49CC7C000138
class CElement : public CNode
{
  public:
	CElement(CNode*parent,string &cont,int depth):CNode(parent,depth),m_sName(cont){cont = "";};
	CElement(CNode*parent,string &cont):CNode(parent),m_sName(cont){cont = "";};
	CElement(CNode*parent):CNode(parent),m_sName(""){};
	CElement():CNode(NULL),m_sName(""){};
	
	void AppendAttr(string & str)
	{
		if(str.size() == 0)
			return ;

		CAttribute * p = new CAttribute(str);

		str = "";
		m_vpAttr.push_back(p);
	}

	void SetAttrValue( string & val)
	{
		CAttribute * p = m_vpAttr.at(m_vpAttr.size()-1);


		p->AddValue(val);
		val ="";
	}
	string& GetAttrValue(const string &name, string & val) const
	{
		val = "";
		std::vector<CAttribute *>::const_iterator cur = m_vpAttr.begin();

		while(cur!= m_vpAttr.end())
		{
			if((*cur)->GetName() == name)
			{
				val = (*cur)->GetValue();
				break;
			}
			cur++;
		}
		return val;
	}

	string& NameAppend(string & s)
	{
		string res;
		string::const_iterator iter;

		for(iter = s.begin();iter !=s.end();iter++)
			res += tolower(*iter);

		m_sName.append(res);
		s="";
		return m_sName;
	}
	string NameAppend(char const & c)
	{
#ifdef 	WIN32
		m_sName.append(1,tolower(c));
#else
//gcc 3.x �汾��֧��append(int,char) ����		
		char lc[2]={0};
		lc[0] = tolower(c);
		m_sName.append(lc);
#endif		
		return m_sName;
	}
	  void AppendTextChild(CNode *pnode);
	  void AppendElementChild(CNode *pnode,CElement* &pCur);

	  static void Del(CBase * itm);
    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D0891503A9
    int GetElementByID(
        // ָ����ID��
        const std::string &id);
    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D08925007D
    int GetElementByID(
        // ָ����ID��
        const char *id);
    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D0891503A9
    int GetElementByAttrNV(
        // ָ����ID��
        const std::string &n,const std::string &v);
    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D08925007D
    int GetElementByAttrNV(
        // ָ����ID��
        const char *n,const char *v);

    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D0891503D8
	// mode = 0 ��ȷƥ��,tagname ==
	// mode = 1 �ײ�ƥ��,tagname 
	// mode = 2 ����
	// mode = 3 ������
    int GetElementByTagName(
        // ָ����TAG����
        const std::string &tagname,int mode=0);
    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D08925009C
    int GetElementByTagName(
        // ָ����TAG����
        const char *tagname,int mode=0);

    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D0891503D8
	int GetElementByName(const std::string &name);
    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D08925009C
    int GetElementByName(
        // ָ����TAG����
        const char *tagname);

    //##ModelId=49D08916000F
    const std::vector<CNode *>& GetResult() const
	{
		return m_vResult;
	}

    const CNode * GetResult(int i) const
	{
		return m_vResult[i];
	}


    // ����ֵ�����������Ľڵ�����
    //##ModelId=49D0894802EE
    string GetInnerText() const;
	string GetInnerHTML() const;

    // ������ת��Ϊstring
    //##ModelId=49D089C8001F
    virtual string ToString() const;

    //##ModelId=49D08EA30399
    //virtual CNode *Identify(const string &src, string::const_iterator &pos,enum ESTATE &state);

    // ���ӵ��µĽ�������ʱ�������µ������建��
    //##ModelId=49D488CE00DA
    virtual int Clear();


    //##ModelId=49D48A760119
    virtual ~CElement();    

	std::vector<CNode *> Child() const
	{
		return m_vpChild;
	}

	
	CNode * Child(int i) const
	{
		return m_vpChild.at(i);
	}
	string GetTagName() const
	{
		return m_sName;
	}
	string GetTagName() 
	{
		return m_sName;
	}

	bool IsExistThisAttr(const string & name,const string &value,int mode=1);
	int GetElementByName(const std::string &name,CElement *resEle) const;
	int GetElementByTagName(const std::string &tagname,CElement * resEle,int mode=0) const;
	int GetElementByID(const std::string &id,CElement * resEle);
	int GetElementByAttrNV(const std::string &n,const std::string &v,CElement * resEle);

  private:
    // TAG����
    //##ModelId=49CC7CE60203
    std::string m_sName;
	
    // �ӽڵ�����
    //##ModelId=49CC7D07034B
    std::vector<CNode *> m_vpChild;

	
    // ��������
    // 
    // 1. �Զ�������¼���������ȷ�����߷������ù���
    // 2. ǿ�ƽ�����¼�봮����ϵͳ����
    //##ModelId=49CC7DD7009C
    int m_iEndType;

    //##ModelId=49D0641D031C
    std::vector<CAttribute *> m_vpAttr;

    //##ModelId=49D474970186
    std::vector<CNode *> m_vResult;

};



#endif /* CELEMENT_H_HEADER_INCLUDED_B62B2467 */
