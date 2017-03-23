// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��xml-like�����ļ��Ķ�ȡ��  
// *************************************************

#ifndef CConfigElement_H_HEADER_INCLUDED_B3F0A54D
#define CConfigElement_H_HEADER_INCLUDED_B3F0A54D

#include "mysoft_config.h"

namespace MyConfig {

//##ModelId=4C0C5D0D0085
class CConfigElement
{
  public:
    //##ModelId=4C0F11E1006C
    CConfigElement();

    //##ModelId=4C0F11E1009B
    virtual ~CConfigElement();

    //##ModelId=4C0F12170178
    CConfigElement(const std::string &inName, const std::string &inFormat = "", const std::string &inChecker = "reg:single", const std::string &inTranslator = "null", const std::string &inDesc = "");

    //##ModelId=4C0F39D10236
    std::string const& GetChecker() const;

    //##ModelId=4C0F39D10284
    void SetChecker(std::string& left);

    //##ModelId=4C0F39D1033F
    std::string const& GetDesc() const;

    //##ModelId=4C0F39D1038D
    void SetDesc(std::string& left);

    //##ModelId=4C0F39D20070
    std::string const& GetFormat() const;

    //##ModelId=4C0F39D200CE
    void SetFormat(std::string& left);

    //##ModelId=4C0F39D201A9
    std::string const& GetName() const;

    //##ModelId=4C0F39D20207
    void SetName(std::string& left);

    //##ModelId=4C0F39D202E1
    std::string const& GetTranslator() const;

    //##ModelId=4C0F39D2034F
    void SetTranslator(std::string& left);

    // Ԫ�ص�����
    //##ModelId=4C0C5D2403C2
    std::string m_sName;

    // ���鹤��һ����
    //##ModelId=4C0C5D310009
    std::string m_sFormat;

    // ������ʽ��飬Ԥ�������¼�����ͣ�
    // 
    // null �����
    // checker:single ��ֵ�������
    // checker:complex ��ֵ���ϼ��
    // 
    // CChecker* pCChecker =
    //      CChecker::CreateHander(checker);
    // 
    // ����ǵ�ֵ
    // pCChecker->DoSingle(value_of_element);
    // ����Ƕ�ֵ
    // pCChecker->DoComplex(
    //   value_of_element,
    //   map_of_parameter);
    // 
    // 
    // �Ѿ�ʵ�ֵľ���һ������������ʽ�ĵ�ֵ���
    // reg:single
    //##ModelId=4C0C5D3902C9
    std::string m_sChecker;

    // Ԥ�����ת������
    // 
    // null ����ת��
    // translator:single ��ֵ���
    // translator:complex ��ֵ���
    // 
    // CTranslator* pCurTranslator =
    //      CTranslator::CreateHander(translator);
    // 
    // ����ǵ�ֵ
    // pCurTranslator->DoSingle(value_of_element);
    // ����Ƕ�ֵ
    // pCurTranslator->DoComplex(
    //   value_of_element,
    //   map_of_parameter);
    //##ModelId=4C0C5D430078
    std::string m_sTranslator;

    // Ԫ�ص�����
    //##ModelId=4C0C5D350038
    std::string m_sDesc;

};

} // namespace MyConfig



#endif /* CConfigElement_H_HEADER_INCLUDED_B3F0A54D */
