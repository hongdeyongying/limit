// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#include "StdAfx.h"
#include "CAttribute.h"

//##ModelId=49D089B10290
string CAttribute::ToString() const
{
	string res;

	if(m_iType == 2)
		res = m_sName;
	else
		res = m_sName + "=\"" + m_sValue +"\"";
	return res;
}

//##ModelId=49D08E63033C
int CAttribute::Identify(const  char *pszBuf, int size) const
{

	return 0;
}

//##ModelId=49D48B5103B9
int CAttribute::Identify(std::string::const_iterator iter) const
{

	return 0;
}


bool CAttribute::IsEqual(const string &n, const string &v,int mode)
{
	if(mode == 1) 
	{
		return ((n==m_sName) && (v == m_sValue));
	}
	else if(mode == 2)
	{
		return (n==m_sName) ;
	}
	else
	{
		return false;
	}
}
