// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef CSTRINGMAP_H_HEADER_INCLUDED_B3FA04FE
#define CSTRINGMAP_H_HEADER_INCLUDED_B3FA04FE

#include "mysoft_utility.h"
#include "CStdMapString.h"

namespace MyUtility {

typedef std::string FILTER (const std::string &);
// �ɽ��ַ��������ض��ķָ������Բ�֣��γ����飻�����γɵ������е�ÿ��ֵ���ж��β�֣��γ�map��ͬ��ֵֻ����һ��
//##ModelId=4BFF287E02AD
class CStringMap : public CStdMapString
{
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
    //##ModelId=4C032D85028A
    CStringMap& Split(
        // ����ֵ��ַ���
        const std::string  &inStr, 
        // Ԫ�طָ���
        const std::string &inEleSep="&", 
        // ����ֵ�ָ���
        const std::string & inNVSep="=", 
        // ��ֵ�Ƿ���ӽ�MAP
        bool inFlg = true,
        FILTER * filter=NULL);

    // ��ϳ�һ���ִ�,inflg 0 raw   1 url����, 
    //##ModelId=4C032D8502C8
    std::string Join(const char *inEleSep="&", const char *inNVSeq="=",FILTER* filter=NULL) const;
	std::string Join(const std::string & inEleSep, const std::string &  inNVSeq,FILTER* filter=NULL) const;

    //##ModelId=4C0332AC01D3
    CStringMap();

    //##ModelId=4C0332AC0202
    virtual ~CStringMap();

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
    //##ModelId=4C05C91F00F8
    CStringMap& Split(
        // ����ֵ��ַ���
        const char *inStr, 
        // Ԫ�طָ���
        const char *inEleSep="&", 
        // ����ֵ�ָ���
        const char *inNVSep="=", 
        // ��ֵ�Ƿ���ӽ�MAP
        bool inFlg = true,FILTER* filter=NULL);

};

} // namespace MyUtility



#endif /* CSTRINGMAP_H_HEADER_INCLUDED_B3FA04FE */
