// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************



#include "CTag.h"

//##ModelId=49D47D45029F
CTag::CTag(const char * name, enum ETAG endstyle, int priority, const char * endtags)
	:m_sName(name),m_eEndStyle(endstyle),m_iPriority(priority)
{
	m_vEndTag.SetCommaText(endtags,",");
}

