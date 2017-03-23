// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef CNODE_H_HEADER_INCLUDED_B62B42AB
#define CNODE_H_HEADER_INCLUDED_B62B42AB

#include "mysoft_html.h"
#include "CBase.h"

//##ModelId=49CC7BF003C8
class CNode : public CBase
{
  public:

	CNode(CNode*parent,CNode*next,CNode*prev,int depth):m_pParent(parent),m_pNext(next),m_pPrev(prev),m_iDepth(depth){};
	CNode(CNode*parent,int depth):m_pParent(parent),m_pNext(NULL),m_pPrev(NULL),m_iDepth(depth){};
	CNode(CNode*parent):m_pParent(parent),m_pNext(NULL),m_pPrev(NULL),m_iDepth(0){};
	CNode():m_pParent(NULL),m_pNext(NULL),m_pPrev(NULL),m_iDepth(0){};
    // ������ת��Ϊstring
    //##ModelId=49D089BC0251
    virtual string ToString() const = 0;

    // ���ӵ��µĽ�������ʱ�������µ������建��
    //##ModelId=49D4881503D8
    virtual int Clear() = 0;

	virtual string Append(string & str){return str;}
	
	virtual CNode * GetParent()
	{
		return m_pParent;
	}

  protected:
    //##ModelId=49CC7C39001F
    CNode* m_pParent;

    //##ModelId=49D063E40109
    CNode* m_pNext;

    //##ModelId=49D063E801E4
    CNode* m_pPrev;

    // ��ȣ���0��ʼ
    //##ModelId=49D06893006D
    int m_iDepth;

};



#endif /* CNODE_H_HEADER_INCLUDED_B62B42AB */
