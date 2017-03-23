// author      :  gaussgao
// create date :  2011-03-02
// modify date :  2011-03-02
// descriptor  :  qzone feeds format dll  

#ifndef CFACTORY_H_HEADER_INCLUDED_B291F56F
#define CFACTORY_H_HEADER_INCLUDED_B291F56F


#include "mysoft_utility.h"

//stl
#include <string>
#include <map>
#include <vector>

namespace MyUtility {
// һ��ͨ�õĹ����࣬ͨ��std::map�����ഴ����������std::map������singletonʵ������������ʱ�Զ�����

// ȫ�ֱ���

typedef std::map<std::string,void*(*)()>  CStringMethodMap;
typedef std::map<std::string,void*> CStringInstanceMap;

typedef std::map<std::string,CStringMethodMap> CStringCStringMethodMapMap;
typedef std::map<std::string,CStringInstanceMap> CStringCStringInstanceMapMap;


extern CStringCStringMethodMapMap g_mmMethod;
extern CStringCStringInstanceMapMap g_mmInstance;

//##ModelId=4D6E03D7013A
template <
    // Ҫͨ��Factory����������һ�ֻ�������
    typename TBase, 
    // Ҫͨ��factory����������һ�����������������Ҫ��TBase�м̳й�ϵ
    typename TSpecial>
class CFactory
{
  private:
	std::string m_sBaseName;
	std::string m_sSpecialName;
  public:
    // ��ȡָ�����ָ࣬��������ID��һ��ʵ�������ص�ָ����Ҫ�������ͷ�
    //##ModelId=4D6E082D03C6
    TBase *GetInstance(
        // ���������
        const std::string &inBaseName, 
        // ������ı�־
        const std::string & inId)
{
	TBase * res = NULL;
	
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(inBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 2.1  �����,Ѱ������������
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(inId);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 2.1.1 ����У���������
			res = (TBase*)iterSpecial->second();
		}
	}
	
	return res;
};

    // ��ȡָ�����ָ࣬��������ID��һ��ʵ�������ص�ָ������߲����ͷţ��೧���Զ�������ʱ�ͷ�
    //##ModelId=4D6E093A03C0
    TBase *GetSingletonInstance(
        // ���������
        const std::string &inBaseName, 
        // ������ı�־
        const std::string & inId)
{
	TBase * res = NULL;
	
	// ���������Ѿ����ɵ�ʵ��
	CStringCStringInstanceMapMap::iterator iterInstBase ;
	
	iterInstBase = g_mmInstance.find(inBaseName);
	
	if(iterInstBase != g_mmInstance.end())
	{
		CStringInstanceMap::iterator iterInstSpecial;
		
		iterInstSpecial = iterInstBase->second.find(inId);
		
		if(iterInstSpecial != iterInstBase->second.end())
		{
			res = (TBase*)iterInstSpecial->second;
			
			return res ;
		}
	}
	// ���û�д���ʵ��
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(inBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 2.1  �����,Ѱ������������
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(inId);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 2.1.1 ����У���������
			res = (TBase*)iterSpecial->second();
			
			g_mmInstance[inBaseName][inId] = res;
		}
	}
	
	return res;
}

    // ��װָ�����ָ࣬��������Ĺ��췽����
    //##ModelId=4D6E0AC101E8
    CFactory(
        // ���������
        const std::string &inBaseName, 
        // ������ı�־
        const std::string & inId)
{
	//������ࡢ��������
	m_sBaseName = inBaseName;
	m_sSpecialName = inId;
	// 1. Ѱ�����޻���
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(m_sBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 2.1  �����,Ѱ������������
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(m_sSpecialName);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 2.1.1 ����У�ʹ���·����滻
			iterSpecial->second = CFactory<TBase, TSpecial>::Method;
		}
		else
		{
			//2.1.2 ���û���������������ɷ���
		//	iterBase->second.insert(CStringMethodMap::value_type(m_sSpecialName,CFactory<TBase, TSpecial>::Method));
			iterBase->second[m_sSpecialName] = CFactory<TBase, TSpecial>::Method;
		}
	}
	else
	{
		// 2.2 ���û�У��������ࡢ�����෽��
		CStringMethodMap tCStringMethodMap;
		tCStringMethodMap[m_sSpecialName] = CFactory<TBase, TSpecial>::Method;
		
		g_mmMethod.insert(CStringCStringMethodMapMap::value_type(inBaseName,tCStringMethodMap));
	}	
	
};

    //##ModelId=4D6E0CB201ED
    virtual ~CFactory()
{
	//1.���������ڵ������෽��
	// 1.1. Ѱ�����޻���
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(m_sBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 1.2.1  �����,Ѱ������������
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(m_sSpecialName);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 1.2.1.1 ����У�ɾ��
			iterBase->second.erase(iterSpecial);
		}
	}
	//2.��������ڵ�������ʵ��(singleton)
	CStringCStringInstanceMapMap::iterator iterInstBase ;
	
	iterInstBase = g_mmInstance.find(m_sBaseName);
	
	if(iterInstBase != g_mmInstance.end())
	{
		CStringInstanceMap::iterator iterInstSpecial;
		
		iterInstSpecial = iterInstBase->second.find(m_sSpecialName);
		
		if(iterInstSpecial != iterInstBase->second.end())
		{
			TBase * tTBase = (TBase*)iterInstSpecial->second;
			
			iterInstBase->second.erase(iterInstSpecial);
			
			delete tTBase;
		}
	}
	
	
};

    // ����һ������
    //##ModelId=4D6E0CDB01E0
    static void *Method()
    {
            return (void *)(new TSpecial);
    }

    void Dump(std::string & ostr)
{
	CStringCStringMethodMapMap::iterator iterBase ;

	ostr += "\r\nbase and derive class table list :\r\n";

	for(iterBase = g_mmMethod.begin(); iterBase != g_mmMethod.end();iterBase++)
	{	
		// 2.1  �����,Ѱ������������
		CStringMethodMap::iterator iterSpecial;

		ostr += iterBase->first +":\r\n";
		
		for(iterSpecial = iterBase->second.begin(); iterSpecial != iterBase->second.end();iterSpecial++)
		{			
			ostr += "\t"+ iterSpecial->first +"\r\n";
		}
	}
};


};

};//namespace MyUtility 


#endif /* CFACTORY_H_HEADER_INCLUDED_B291F56F */
