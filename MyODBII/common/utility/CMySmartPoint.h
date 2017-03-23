// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef CMYSMARTPOINT_H_HEADER_INCLUDED_B3F31045
#define CMYSMARTPOINT_H_HEADER_INCLUDED_B3F31045

#include "mysoft_utility.h"

namespace MyUtility {

// ����ָ�룬��������ָ�룬���Զ��ͷ��ڴ档
// 
// �������0�������캯��
// 
//##ModelId=4C0C804402F8
template <class T>
class CMySmartPoint
{
  public:
    //##ModelId=4C0C80E0004E
    CMySmartPoint()
    { m_pT = new T; }

    CMySmartPoint(T * inPoint)
    { if(inPoint == NULL) m_pT = new T; else m_pT = inPoint; }

    //##ModelId=4C0C80EC0187
    virtual ~CMySmartPoint()
    {delete m_pT;}


    //##ModelId=4C0C80FD0206
    T *operator ->()
    {return m_pT;}


  private:
    //##ModelId=4C0C80C6031B
    T *m_pT;

};

} // namespace MyUtility



#endif /* CMYSMARTPOINT_H_HEADER_INCLUDED_B3F31045 */
