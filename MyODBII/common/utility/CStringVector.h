// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef CSTRINGVECTOR_H_HEADER_INCLUDED_B3FA62D9
#define CSTRINGVECTOR_H_HEADER_INCLUDED_B3FA62D9

#include "mysoft_utility.h"
#include "CStdVectorString.h"

namespace MyUtility {

typedef std::string FILTER (const std::string &);

// �ɽ��ַ��������ض��ķָ������Բ�֣��γ�����
//##ModelId=4BFF2857022F
class CStringVector : public CStdVectorString
{
  public:
    // ���������
    //     inStr ����ֵ��ַ���
    //     inSep �ָ����ַ���
    //     inFlg �ָ�ģʽ���������ݳ���Ϊ�գ��Ƿ���ΪҪ��֮һ��Ĭ���Ƿ�
    // 
    // ���ز�����
    //     CStringVector &
    // 
    // ʾ����Split("123",2) = > [1,3]
    //##ModelId=4BFF2CAC000F
    CStringVector& Split(
        // ����ֵ��ַ���
        const std::string  &inStr, 
        // �ָ���
        const std::string &inSep, 
        // ��ֵ�Ƿ���ӽ�����
        bool inFlg = false,
        FILTER *filter=NULL);

    // ���������
    //     inStr ����ֵ��ַ���
    //     inSep �ָ����ַ���
    //     inFlg �ָ�ģʽ���������ݳ���Ϊ�գ��Ƿ���ΪҪ��֮һ��Ĭ���Ƿ�
    // 
    // ���ز�����
    //     CStringVector &
    // 
    // ʾ����Split("123",2) = > [1,3]
    //##ModelId=4BFF2EA60338
    CStringVector& Split(
        // ����ֵ��ַ���
        const char *inStr, 
        // �ָ���
        const char *inSep="=", 
        // ��ֵ�Ƿ���ӽ�����
        bool inFlg = false,
        FILTER *filter=NULL);

    //##ModelId=4C032750028D
    CStringVector();

    //##ModelId=4C03275002BC
    virtual ~CStringVector();

    // ��ϳ�һ���ִ�
    //##ModelId=4C03275A009A
    std::string Join(const char *inSep = "",FILTER *filter=NULL) const;
    std::string Join(const std::string &inSep ,FILTER *filter=NULL) const;

};

} // namespace MyUtility



#endif /* CSTRINGVECTOR_H_HEADER_INCLUDED_B3FA62D9 */

