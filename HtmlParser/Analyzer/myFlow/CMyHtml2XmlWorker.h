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

#ifndef MYFLOW_CMYHTML2XMLWORKER_H_HEADER_INCLUDED_B4F34000
#define MYFLOW_CMYHTML2XMLWORKER_H_HEADER_INCLUDED_B4F34000

#include "myflow_macro.h"

#include <map>

#include <vector>

#include <string>
#include "CMyVarSpace.h"
#include "CMyWorker.h"
class CMyAny;

using namespace std;

// ��Htmlת��Ϊxml�Ĺ�����
// 
// ѡ������ 
// 		�����ڵ�
// 			���սڵ�������
// 				tag(para_tag_name)
// 			�������Լ���	
// 				id(para_id_value)
// 				name(para_name_value)
// 				nv(para_attr_name_name,attr_name_value)
// 		�����ڵ�ֵ
// 			count
// 			
// 		�����ڵ�	
// 			����������ż���
// 				item(index)
// 	
// 		����ֵ
// 			ȡ�ڵ���Ӧ���Ե�ֵ
// 				attr(para_attr_name_name)
// 			ȡ�ڵ��м��ı�
// 				text 
// 				
// 	
// 	������
// 		left�Ƿ����right
// 			bool has(left,right)  
// 			bool head_has(left,right)  
// 			bool tail_has(left,right)  			
// 		left�Ƿ����right
// 			bool equ(left,right)
// 		left�Ƿ����right
// 			bool big(left,rigth)
// 		left�Ƿ�С��right
// 			bool little(left,right)
// 		left��ȥright
// 			int minus(left,right)
// 		left����right
// 			int add(left,right)
// 
// 
// �����
// 		echo
// 	��ֵ��
// 		assign
// 		����ı���������������$identify����
// 		
// 		���ͣ�integer,string
//##ModelId=4B0CB36B00B6
#include "EVarType.h"


class CMyHtml2XmlWorker : public CMyWorker
{
	string parse_html(vector <string > & para_list);
	string nv(vector <string > & para_list);
	string count(vector <string > & para_list);
	string item(vector <string > & para_list);
	string attr(vector <string > & para_list);
	string text(vector <string > & para_list);


	string tag(vector <string > & para_list);



	string has(vector <string > & para_list);
	string gt(vector <string > & para_list);
	string lt(vector <string > & para_list);
	string equ(vector <string > & para_list);


	string inc(vector <string > & para_list);
	string sub(vector <string > & para_list);


	string store(vector <string > & para_list);
	string read(vector <string > & para_list);

	string xmlDecode(vector <string > & para_list);

	string child(vector <string > & para_list);

	string strsub(vector <string > & para_list);
	string strcat(vector <string > & para_list);


  public:
    //##ModelId=4B0CB42302E8
    string Call(
        // ��������
        const string &func_name, 
        // �����б�
        vector <string > & para_list);

    // ȡ����ֵ���Ⱦֲ���ȫ��
    // 
    // ���ȡֵ�ɹ��򷵻�0
    // ���򷵻�����ֵ
    // 1 ����������
    //##ModelId=4B0CB6B103A4
    int FetchVarValue(const string &var, 
        // ������ֵ
        CMyAny &val);
    CMyAny FetchVarValue(const string &var);
    //##ModelId=4B0CB4D80048
    CMyHtml2XmlWorker();
    CMyHtml2XmlWorker(CMyVarSpace * global_var_space);

    //##ModelId=4B0CB4D80087
    virtual ~CMyHtml2XmlWorker();

  private:
	  void InitFunctionMap();
	  string GetTmpVarName();

    // ȫ�ֱ����ռ䣬���Ի�ȡ��������
    //##ModelId=4B0CB49501BF
    CMyVarSpace *m_gpVar;

    // �ֲ������ռ�
    //##ModelId=4B0CB4B70087
    CMyVarSpace m_mVar;

	map<string,int> m_mFunction;

};



#endif /* MYFLOW_CMYHTML2XMLWORKER_H_HEADER_INCLUDED_B4F34000 */
