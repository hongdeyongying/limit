// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef ESYMBOL_H_HEADER_INCLUDED_B62B1551
#define ESYMBOL_H_HEADER_INCLUDED_B62B1551

#include "mysoft_html.h"

// ��������ö��
//##ModelId=49D1D27F0119
enum ESYMBOL { 
    // �հ׷��ţ��ո�TAB�����з���
    SYMBOL_SPACE, 
    // ��ǩ��ʼ���ţ�<
    SYMBOL_TAG_BEGIN, 
    // ��ǩ�������ţ�>
    SYMBOL_TAG_END, 
    // ���Ը�ֵ���ţ�=
    SYMBOL_TAG_ATTR_ASIGN, 
    // �������ţ�',"
    SYMBOL_TAG_ATTR_QUTOE, 
	//a-zA-Z
	SYMBOL_ALPHA, 
	//0-9
	SYMBOL_NUMBER, 
	//!
	SYMBOL_DOCTYPE_HEADER,
	//...
	SYMBOL_UNKNOWN };



#endif /* ESYMBOL_H_HEADER_INCLUDED_B62B1551 */
