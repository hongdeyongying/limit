// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef CMYEXCEPTION_H_HEADER_INCLUDED_B3F0B521
#define CMYEXCEPTION_H_HEADER_INCLUDED_B3F0B521

#include "mysoft_utility.h"

namespace MyUtility {

//##ModelId=4C0F3CCC0212
class CMyException
{
  public:
    //##ModelId=4C0F3EAF03B1
    CMyException();

    //##ModelId=4C0F3EB00008
    virtual ~CMyException();

    //##ModelId=4C0F3EB6020B
    CMyException(const std::string  &inUserMsg, long inErrcd = 0, const std::string  &inReason = "", const std::string  &inDebug = "");

    // �����쳣��Ϣת��Ϊ�ɴ�ӡ�ַ���
    //##ModelId=4C0F46E1032D
    std::string ToString() const ;

    //##ModelId=4C0F47220006
    long const& GetErrcode() const;

    //##ModelId=4C0F47220054
    std::string const& GetDebug() const;

    //##ModelId=4C0F472200A2
    std::string const& GetReason() const;

    //##ModelId=4C0F47220100
    std::string const& GetUserMsg() const;

  private:
    // �쳣ԭ��,������Ա�����˽�ģ�����
    //##ModelId=4C0F3D630253
    std::string m_sReason;

    // �������:ͳһ�����
    //##ModelId=4C0F3DA301D7
    long m_iErrcd;

    // �쳣ʱչ�ָ��ͻ�����Ӧ��Ϣ
    //##ModelId=4C0F3DC00264
    std::string m_sUserMsg;

    // ���ڿ�����Ա�����õ���Ϣ
    //##ModelId=4C0F3DF502B4
    std::string m_sDebug;

};

} // namespace MyUtility



#endif /* CMYEXCEPTION_H_HEADER_INCLUDED_B3F0B521 */
