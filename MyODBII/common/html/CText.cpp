// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************
 
#include "CText.h"

//##ModelId=49D08994000F
string CText::ToString() const
{
	return m_sContent;
}

//##ModelId=49D4883B01B5
int CText::Clear()
{
	m_sContent ="";
	return 0;
}

//##ModelId=49D48B5C00EA
//DEL CNode * CText::Identify(const string &src, string::const_iterator &pos,enum ESTATE &state)
//DEL {
//DEL 	CNode *pResult = m_pParent;
//DEL 
//DEL 	
//DEL 
//DEL 	return pResult;
//DEL }

