// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef ESTATE_H_HEADER_INCLUDED_B62B75EF
#define ESTATE_H_HEADER_INCLUDED_B62B75EF

#include "mysoft_html.h"

// ״̬ö��
//##ModelId=49D1B5F902EE
enum ESTATE { 
    // ��ǰ����Ϊ��δ֪״̬
    // 
    // 
    //  
    STATE_UNKNOWN, 
    // ��ǰ����Ϊ���ı��ڵ�״̬
    STATE_TEXT, 
    // ��ǰ����״̬Ϊ��ELEMENT��ȡ״̬
    STATE_ELEMENT, 
    // ��ǰ����״̬Ϊ��ATTR_NAME��ȡ״̬
    STATE_ELEMENT_ATTR_NAME, 
    // ��ǰ����״̬Ϊ��ATTR_VALUE��ȡ״̬
    STATE_ELEMENT_ATTR_VALUE, 
    // ��ǰ����״̬Ϊ��ATTR_QUOTE��ȡ״̬
    STATE_ELEMENT_ATTR_NAME_QUOTE, 
	STATE_ELEMENT_ATTR_VALUE_QUOTE, 
	// ע��״̬
	STATE_COMMENT,
	// <![CDATA[    ......     ]]>
	STATE_CDATA,
	// 
	STATE_MAYBE_ELEMENT, 
	//
	STATE_MAYBE_ELEMENT_ATTR_VALUE };



#endif /* ESTATE_H_HEADER_INCLUDED_B62B75EF */
