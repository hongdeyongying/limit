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

#ifndef MYFLOW_CMYWORKER_H_HEADER_INCLUDED_B4F338D9
#define MYFLOW_CMYWORKER_H_HEADER_INCLUDED_B4F338D9
#pragma warning(disable:4786)
#include "myflow_macro.h"

#include <map>

#include <vector>

#include <string>

#include "CMyAny.h"


using namespace std;
#include "EVarType.h"
//##ModelId=4B0BA6030200
class CMyWorker
{
  public:
    //##ModelId=4B0BAD97007A
    virtual string  Call(
        // ��������
        const string &func_name, 
        // �����б�
        vector <string > &  para_list) = 0;

	// ȡ����ֵ���Ⱦֲ���ȫ��
    // 
    // ���ȡֵ�ɹ��򷵻�0
    // ���򷵻�����ֵ
    // 1 ����������
    //##ModelId=4B0CB6B103A4
    virtual int FetchVarValue(const string &var, 
        // ������ֵ
        CMyAny &val) = 0;

	virtual CMyAny FetchVarValue(const string &var) = 0;
// ȫ�ֱ����ռ䣬���Ի�ȡ��������
};



#endif /* MYFLOW_CMYWORKER_H_HEADER_INCLUDED_B4F338D9 */
