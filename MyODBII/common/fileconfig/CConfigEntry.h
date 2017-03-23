// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��xml-like�����ļ��Ķ�ȡ��  
// *************************************************

#ifndef CCONFIGENTRY_H_HEADER_INCLUDED_B3F0FFFF
#define CCONFIGENTRY_H_HEADER_INCLUDED_B3F0FFFF

#include "mysoft_config.h"
#include "CConfigElement.h"
#include "CConfigElementMap.h"
#include "CService.h"
#include "CServiceMap.h"

#include "CMyException.h"

#include "CStringVector.h"

namespace MyConfig {

//##ModelId=4C0C681C0130
class CConfigEntry
{
  public:
    void Clear();
    //##ModelId=4C0C685B02F7
    CConfigEntry();

    //##ModelId=4C0C685B0335
    virtual ~CConfigEntry();

    // ����Element�����ļ�
    //##ModelId=4C0C6AB702A4
    CConfigElementMap& LoadElement(const std::string &inFileName);

    //##ModelId=4C0C6B3102F5
    CServiceMap& LoadService(const std::string & inFileName);
	
    //##ModelId=4C0C6B3102F5
    int LoadInclude(const std::string & inFileName);

    //�������������ļ�
    int LoadConfig(const std::string & inFileName);

    //##ModelId=4C0C6BB300C5
    CConfigElementMap const& GetElementMap() const;

    //##ModelId=4C0C6BB30161
    CServiceMap const& GetServiceMap() const;

    //##ModelId=4C0F3C1A01BE
    bool IsExistService(const std::string &inServiceName);

    //##ModelId=4C0F3C440123
    bool IsExistElement(const std::string &inServiceName);

    //##ModelId=4C0F3C7603B5
    const CService &GetService(const std::string &inServiceName) throw(MyUtility::CMyException);

    //##ModelId=4C0F3C7603E4
    const CConfigElement &GetElement(const std::string &inServiceName) throw(MyUtility::CMyException);

  private:
    //##ModelId=4C0C6A440225
    CServiceMap service;

    //##ModelId=4C0C6A810275
    CConfigElementMap element;


    //namespace default is ""
    //std::string m_sNameSpace;
    MyUtility::CStringVector m_vNamespace;

};

} // namespace MyConfig



#endif /* CCONFIGENTRY_H_HEADER_INCLUDED_B3F0FFFF */
