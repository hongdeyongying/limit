// ***********************************************
// 
// �������ڣ� 2009-11-18
// 
// ��    �ߣ� gaoyong
// 
// �����ʼ��� gaoyong@my-soft.net.cn
// 
// ��Ҫ���ܣ� ʵ�ֶ�html�ļ��ĸ�ʽ��������Լ�����
// 
//            BPEL�����̿��ơ�
// 
// ***********************************************

#ifndef MYFLOW_EVARTYPE_H_HEADER_INCLUDED_B4F4790A
#define MYFLOW_EVARTYPE_H_HEADER_INCLUDED_B4F4790A

#include "myflow_macro.h"

#include <map>

#include <vector>

#include <string>

using namespace std;

// ö���࣬��ʾ��������
//##ModelId=4B0B5901009A
enum EVarType { VT_INTEGER, //int
	VT_DOUBLE, //double
	VT_STRING, //string

	VT_STRINGVECTOR,
	VT_STRINGVECTORMAP,
	VT_STRINGMAP,

	VT_P_CHTML, //chtml
	VT_P_CELEMENT ,//celement
	VT_P_CNODE ,//cnode
	
	VT_UINTEGER //Uint
	};



#endif /* MYFLOW_EVARTYPE_H_HEADER_INCLUDED_B4F4790A */
