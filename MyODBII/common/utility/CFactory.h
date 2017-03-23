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
// 一个通用的工厂类，通过std::map管理类创建方法，用std::map管理类singleton实例，并在析构时自动回收

// 全局变量

typedef std::map<std::string,void*(*)()>  CStringMethodMap;
typedef std::map<std::string,void*> CStringInstanceMap;

typedef std::map<std::string,CStringMethodMap> CStringCStringMethodMapMap;
typedef std::map<std::string,CStringInstanceMap> CStringCStringInstanceMapMap;


extern CStringCStringMethodMapMap g_mmMethod;
extern CStringCStringInstanceMapMap g_mmInstance;

//##ModelId=4D6E03D7013A
template <
    // 要通过Factory管理起来的一种基类类名
    typename TBase, 
    // 要通过factory管理起来的一个具体类的类名，需要与TBase有继承关系
    typename TSpecial>
class CFactory
{
  private:
	std::string m_sBaseName;
	std::string m_sSpecialName;
  public:
    // 获取指定基类，指定具体类ID的一个实例。返回的指针需要调用者释放
    //##ModelId=4D6E082D03C6
    TBase *GetInstance(
        // 基类的名称
        const std::string &inBaseName, 
        // 具体类的标志
        const std::string & inId)
{
	TBase * res = NULL;
	
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(inBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 2.1  如果有,寻找有无派生类
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(inId);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 2.1.1 如果有，创建对象
			res = (TBase*)iterSpecial->second();
		}
	}
	
	return res;
};

    // 获取指定基类，指定具体类ID的一个实例。返回的指针调用者不能释放，类厂会自动在析构时释放
    //##ModelId=4D6E093A03C0
    TBase *GetSingletonInstance(
        // 基类的名称
        const std::string &inBaseName, 
        // 具体类的标志
        const std::string & inId)
{
	TBase * res = NULL;
	
	// 查找有无已经生成的实例
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
	// 如果没有创建实例
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(inBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 2.1  如果有,寻找有无派生类
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(inId);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 2.1.1 如果有，创建对象
			res = (TBase*)iterSpecial->second();
			
			g_mmInstance[inBaseName][inId] = res;
		}
	}
	
	return res;
}

    // 安装指定基类，指定构造类的构造方法。
    //##ModelId=4D6E0AC101E8
    CFactory(
        // 基类的名称
        const std::string &inBaseName, 
        // 具体类的标志
        const std::string & inId)
{
	//保存基类、派生类名
	m_sBaseName = inBaseName;
	m_sSpecialName = inId;
	// 1. 寻找有无基类
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(m_sBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 2.1  如果有,寻找有无派生类
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(m_sSpecialName);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 2.1.1 如果有，使用新方法替换
			iterSpecial->second = CFactory<TBase, TSpecial>::Method;
		}
		else
		{
			//2.1.2 如果没有增加派生类生成方法
		//	iterBase->second.insert(CStringMethodMap::value_type(m_sSpecialName,CFactory<TBase, TSpecial>::Method));
			iterBase->second[m_sSpecialName] = CFactory<TBase, TSpecial>::Method;
		}
	}
	else
	{
		// 2.2 如果没有，产生基类、派生类方法
		CStringMethodMap tCStringMethodMap;
		tCStringMethodMap[m_sSpecialName] = CFactory<TBase, TSpecial>::Method;
		
		g_mmMethod.insert(CStringCStringMethodMapMap::value_type(inBaseName,tCStringMethodMap));
	}	
	
};

    //##ModelId=4D6E0CB201ED
    virtual ~CFactory()
{
	//1.撤销掉存在的派生类方法
	// 1.1. 寻找有无基类
	CStringCStringMethodMapMap::iterator iterBase ;
	
	iterBase = g_mmMethod.find(m_sBaseName);
	
	if(iterBase != g_mmMethod.end()) 
	{
		// 1.2.1  如果有,寻找有无派生类
		CStringMethodMap::iterator iterSpecial;
		
		iterSpecial = iterBase->second.find(m_sSpecialName);
		
		if(iterSpecial != iterBase->second.end())
		{
			// 1.2.1.1 如果有，删除
			iterBase->second.erase(iterSpecial);
		}
	}
	//2.清除掉存在的派生类实例(singleton)
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

    // 创建一个对象
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
		// 2.1  如果有,寻找有无派生类
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
