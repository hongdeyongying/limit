// ***********************************************
// �������ڣ� 2009-03-27
// ��    �ߣ� gaussgao
// �����ʼ��� gycommunicate@vip.qq.com
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ķ��������Һ͸�ʽ��
// ***********************************************

#ifndef ETAG_H_HEADER_INCLUDED_B62B6A5E
#define ETAG_H_HEADER_INCLUDED_B62B6A5E

#include "mysoft_html.h"

// ��ǩ���ͣ��������嶨��
// 
// ����	˵��
// 1	����xml�Ľ�����ʽ��������<tag></tag>������Ҳ������<tag .../>
// 2	������</tag>����������html��script
// 3	���ݼ���������������html��p���Ա�����p���ڵĿ�ʼ��ǩ����
// 4	ҶTAG���޽�����������html��br,hr,img
//##ModelId=49D2E574003E
enum ETAG { 
    // ʹ�ñ�׼XML�ı�ǩ�Ľ������ơ����£�
    // 
    // 1.<input .....   />
    // 2.<input ... > </input>
    TAG_FORCE_XML, 
    // ����ʹ�����ܵķ��ŶԽ���TAG
    // 
    // <SCRIPT> ...... </SCRIPT>
    TAG_FORCE_SELF, 
    // ���ֽڵ㣬�޽���������
    // 
    // <br>
    TAG_NONE, 
    // �������ȼ����������Ա��������ȼ��ߵ�TAG������
    TAG_PRIORITY, 
    // �����Ա�����ļ���TAG����
    TAG_SPECIAL };



#endif /* ETAG_H_HEADER_INCLUDED_B62B6A5E */
