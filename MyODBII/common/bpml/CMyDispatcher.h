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

#ifndef MYFLOW_CMYDISPATCHER_H_HEADER_INCLUDED_B4EB099C
#define MYFLOW_CMYDISPATCHER_H_HEADER_INCLUDED_B4EB099C

#include "myflow_macro.h"

#include <map>

#include <vector>

#include <string>

using namespace std;


#include "CHtml.h"


#include "CMyWorker.h"
#include "CMyAnyMap.h"
#include "CMyVarSpace.h"

// ӵ�ж��������ֿռ䣬��֧�ֲ��кʹ���ģʽ
// 
// �ɽ���flow.xml�ļ�����������ִ��
//##ModelId=4B039295005F
class CMyDispatcher
{
	// �ؼ��ֵĶ���
    //##ModelId=4B04DBE3018E
    enum EKEY { 
		KEY_ASSIGN, 

		KEY_SWITCH,
		KEY_CASE,
		KEY_DEFAULT,

		KEY_ECHO,

		KEY_FOR,
	//	KEY_BREAK,
	//	KEY_CONTINUE,

		KEY_INVOKE,
		KEY_PARAMETER,

		KEY_UNKNOWN };
    // ��������
    //##ModelId=4B1491690175
    int Run(
        // ��ǰ�ڵ�
        const CNode *pCurNode, 
        // ���������������ȱ���
        // 
        // ֻ���ۼ�
        string &res);
    // ����������Run
    //##ModelId=4B1491690175
    int Do_KEY_SWITCH(
        // ��ǰ�ڵ�
        const CNode *pCurNode, 
        // ���������������ȱ���
        // 
        // ֻ���ۼ�
        string &res);
	//##ModelId=4B149377008B
  public:
    //##ModelId=4B14894401E3
    CMyDispatcher();

    //##ModelId=4B1489440212
    virtual ~CMyDispatcher();

    // ������һ�����̶����ļ�
    // �����һ���ַ���
    // 
    // ����ֵ��һ�����������Ա�ǳɹ�����ʧ�� 
    // 
    // 0 �ɹ�
    // * ʧ��
    // 
    // GetLastError���Ի�ȡ������Ϣ
    //##ModelId=4B1489650146
    int StartWork(
        // ���̶����ļ����ַ���
        const string &flowFile, 
        // �������
        string &res,
		const string & inParas="",int parse=1,int mode=0);
    int StartWork(
        // ���̶����ļ�
        const string &flowFile, 
        // �������
        string &res,
		const CStringMap & inParas,int mode=0);
    int StartWork(
        // ���̶����ļ�
        const string &flowFile, 
        // �������
        string &res,
		const CStringVector & inParas,int mode=0);
    int StartWork(
        // ���̶����ļ�
        const string &flowFile, 
        // �������
        string &res,
		const CStringVectorMap & inParas,int mode=0);

  private:
	  string GetExprResult(const string & expr);
	  void InitSysVar();
	  int Do_KEY_ASSIGN(const CNode * pCurNode);
	  int Do_KEY_INVOKE(const CNode * pCurNode);
	  int Do_KEY_ECHO(const CNode * pCurNode,string & res);
	  int Do_KEY_FOR(const CNode * pCurNode,string & res);
	  void InitMyKey();


	  void InitParameters(const std::string & inPara,int parse = 1);
	  void InitParameters(const CStringVectorMap & inPara);
	  void InitParameters(const CStringVector & inPara);
	  void InitParameters(const CStringMap & inPara);
    //##ModelId=4B148C8D028F

    // ���̶������
    //##ModelId=4B03940700A2
    CHtml m_htmlFlow;

	CMyWorker * m_pMyWorker;

	CMyVarSpace m_mVar;

	
	map<string,EKEY> m_mKey;

};



#endif /* MYFLOW_CMYDISPATCHER_H_HEADER_INCLUDED_B4EB099C */
