// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef CHTML_H_HEADER_INCLUDED_B62B0BD7
#define CHTML_H_HEADER_INCLUDED_B62B0BD7

#include "mysoft_html.h"
#include "CElement.h"
#include "CNode.h"
#include "CElement.h"
#include "CText.h"

//##ModelId=49D06BA3032C
class CHtml : public CElement
{
  private:
	  void EnClosed();
	  void Init();
    //##ModelId=49D17813002E
    CElement* m_pCurNode;
	CNode* m_pTmpNode;

    //##ModelId=49D476080157
    const char *m_szVersion;

    //##ModelId=49D4801401B5
    std::string m_sTmp;

	//' or "
	char m_cQuote;

    //##ModelId=49D4804B02FD
    enum ESTATE m_eCurState;


	void IdentifyUnkwown(const string  & src,string::const_iterator & pos);
	void IdentifyMayBeElement(const string  & src,string::const_iterator & pos);
	void IdentifyText(const string  & src,string::const_iterator & pos);
	void IdentifyElement(const string  & src,string::const_iterator & pos);

	void IdentifyComment(const string  & src,string::const_iterator & pos);
	void IdentifyElementAttrNameQuote(const string  & src,string::const_iterator & pos);
	void IdentifyElementAttrValueQuote(const string  & src,string::const_iterator & pos);
	void IdentifyCDATA(const string  & src,string::const_iterator & pos);

	void IdentifyElementAttrName(const string  & src,string::const_iterator & pos);
	void IdentifyElementAttrValue(const string  & src,string::const_iterator & pos);

	void IdentifyElementAttrMayBeValue(const string  & src,string::const_iterator & pos);
  public:
    //##ModelId=49D481490232
    CHtml():m_pCurNode(NULL),m_pTmpNode(NULL),m_szVersion("0.0.1"),m_sTmp(""),m_eCurState(STATE_UNKNOWN){};
	
	  void AssertValid(const CNode *pnode,CText *&pText,CElement *&pEle,CComment * & pComment);
    // ������
    //##ModelId=49D486860222
    enum ECONTEXT {CONTEXT_FIRST,CONTEXT_MIDDLE,CONTEXT_LAST,CONTEXT_WHOLE};

	
    // ����ֵ��
    // 0 �ɹ�ʶ��
    // 1 ��ʶ��
    //##ModelId=49D06D01002E
    int Parse(
        // ���������ַ���
        const std::string &cont, 
        // 0  cont�������Ĵ�������
        // 1  cont�ǲ��ֵĴ����������Ҵ˲���Ϊ��ʼ����
        // 2  cont�ǲ��ֵĴ����������Ҵ˲���Ϊ�м䲿��
        // 3  cont�ǲ��ֵĴ����������Ҵ˲���Ϊ��������
        int mode = CONTEXT_WHOLE);

    // ���ļ�����������
    //##ModelId=49D06E560109
    int ParseFile(const std::string &fname);

    //##ModelId=49D4770F0167
    const char *GetVer() const;


	~CHtml()
	{
		CElement::Clear();
	}
    //##ModelId=49D4838A00CB
    enum ESYMBOL GetSymbolType(char const &c);

    //##ModelId=49D483D701C5
    enum ESYMBOL GetSymbolType(const char *p);

    //##ModelId=49D48403034B
    enum ESYMBOL GetSymbolType(std::string::const_iterator &iter);

};



#endif /* CHTML_H_HEADER_INCLUDED_B62B0BD7 */
