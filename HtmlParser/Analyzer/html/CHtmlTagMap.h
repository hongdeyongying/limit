// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef CHTMLTAGMAP_H_HEADER_INCLUDED_B62B107F
#define CHTMLTAGMAP_H_HEADER_INCLUDED_B62B107F

#include "mysoft_html.h"
#include "CTagMap.h"

//##ModelId=49D46D1400FA
class CHtmlTagMap : public CTagMap
{
  public:
    //##ModelId=49D46D6A01E4
    static CHtmlTagMap const& GetInstance();

  private:
    //##ModelId=49D46D250399
    CHtmlTagMap();

};



#endif /* CHTMLTAGMAP_H_HEADER_INCLUDED_B62B107F */
