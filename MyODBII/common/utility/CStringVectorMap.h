// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef CSTRINGVECTORMAP_H_HEADER_INCLUDED_B3FA21CE
#define CSTRINGVECTORMAP_H_HEADER_INCLUDED_B3FA21CE

#include "mysoft_utility.h"
#include "CStdMapCStringVector.h"
#include "CStringMap.h"

namespace MyUtility {

//##ModelId=4C05C83E001A
class CStringVectorMap : public CStdMapCStringVector
{
  private:
	CStringVectorMap& AddElement(const std::string & key,const std::string & val);
  public:
    // ���������
    //     inStr ����ֵ��ַ���
    //     inEleSep Ԫ�طָ����ַ���
    //     inNVSep  Ԫ����ֵ�ָ����ַ���
    //     inFlg �ָ�ģʽ���������ݳ���Ϊ�գ��Ƿ���ΪҪ��֮һ��Ĭ���Ƿ�
    // 
    // ���ز�����
    //     CStringVector &
    // 
    // ʾ����Split("123",2) = > [1,3]
    //##ModelId=4C05C99A005D
    CStringVectorMap& Split(
        // ����ֵ��ַ���
        const std::string  &inStr, 
        // Ԫ�طָ���
        const std::string &inEleSep="&", 
        // ����ֵ�ָ���
        const std::string & inNVSep="=", 
        // ��ֵ�Ƿ���ӽ�MAP
        bool inFlg = true,
        FILTER * filter=NULL);

    // ��ϳ�һ���ִ�
    //##ModelId=4C05C99A007C
    std::string Join(const char *inEleSep, const char *inNVSeq,FILTER * filter=NULL) const;
    std::string Join(const std::string & inEleSep, const std::string & inNVSeq,FILTER * filter=NULL) const;

    // ���������
    //     inStr ����ֵ��ַ���
    //     inEleSep Ԫ�طָ����ַ���
    //     inNVSep  Ԫ����ֵ�ָ����ַ���
    //     inFlg �ָ�ģʽ���������ݳ���Ϊ�գ��Ƿ���ΪҪ��֮һ��Ĭ���Ƿ�
    // 
    // ���ز�����
    //     CStringVector &
    // 
    // ʾ����Split("123",2) = > [1,3]
    //##ModelId=4C05C99A008C
    CStringVectorMap& Split(
        // ����ֵ��ַ���
        const char *inStr, 
        // Ԫ�طָ���
        const char *inEleSep="&", 
        // ����ֵ�ָ���
        const char *inNVSep="=", 
        // ��ֵ�Ƿ���ӽ�MAP
        bool inFlg = true,
        FILTER * filter=NULL);

    //##ModelId=4C05C9BF01B5
    CStringVectorMap();

    //##ModelId=4C05C9BF01E4
    virtual ~CStringVectorMap();

    //##ModelId=4C05C9BF0222
    std::string GetFirst(const std::string &inKey);
    std::string GetFirst(const char *inKey);
    std::string GetFirst(const std::string &inKey)const ;
    std::string GetFirst(const char *inKey)const ;

};

} // namespace MyUtility



#endif /* CSTRINGVECTORMAP_H_HEADER_INCLUDED_B3FA21CE */
