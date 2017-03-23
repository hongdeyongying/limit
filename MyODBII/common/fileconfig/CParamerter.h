// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��xml-like�����ļ��Ķ�ȡ��  
// *************************************************

#ifndef CPARAMERTER_H_HEADER_INCLUDED_B3F08018
#define CPARAMERTER_H_HEADER_INCLUDED_B3F08018

#include "mysoft_config.h"

namespace MyConfig {

//##ModelId=4BF665B10399
class CParameter
{
  public:
    //##ModelId=4C0F12090000
    CParameter();

    //##ModelId=4C0F1209003F
    virtual ~CParameter();
	CParameter& operator=(const CParameter& right)
	{
		m_sName = right.m_sName;
		m_sDesc = right.m_sDesc;
		m_sDefault = right.m_sDefault;
		m_sInExistMode= right.m_sInExistMode;
		m_sOutExistMode= right.m_sOutExistMode;
		
		return *this;
	};

    //##ModelId=4C0F1EA802F9
    CParameter(const std::string &inName, const std::string &inInMode = "O", const std::string &inOutMode = "O", const std::string &inDefault = "", const std::string &inDesc = "");

    //##ModelId=4C0F39A10244
    std::string const& GetDefault() const;

    //##ModelId=4C0F39A10292
    std::string const& GetDesc() const;

    //##ModelId=4C0F39A102F0
    std::string const& GetInExistMode() const;

    //##ModelId=4C0F39A1033E
    std::string  const& GetName() const;

    //##ModelId=4C0F39A1039B
    std::string const& GetOutExistMode() const;

    //##ModelId=4C0F39C1039C
    void SetDefault(std::string& left);

    //##ModelId=4C0F39C20080
    void SetDesc(std::string& left);

    //##ModelId=4C0F39C2016A
    void SetInExistMode(std::string& left);

    //##ModelId=4C0F39C20245
    void SetName(std::string &left);

    //##ModelId=4C0F39C2031F
    void SetOutExistMode(std::string& left);

    // ��������һ��ҵ����Ψһ
    //##ModelId=4C0C5D8A003D
    std::string m_sName;

    // �����ԣ�M ���O ��ѡ��B �ؿ�
    //##ModelId=4C0C5D8C0260
    std::string m_sInExistMode;

    // �����ԣ�M ���O ��ѡ��B �ؿ�
    //##ModelId=4C0C5DAB02EE
    std::string m_sOutExistMode;

    // Ĭ��ֵ
    //##ModelId=4C0F0EDC0043
    std::string m_sDefault;

    // ��������
    //##ModelId=4C0C5DB8004F
    std::string m_sDesc;

};

} // namespace MyConfig



#endif /* CPARAMERTER_H_HEADER_INCLUDED_B3F08018 */
