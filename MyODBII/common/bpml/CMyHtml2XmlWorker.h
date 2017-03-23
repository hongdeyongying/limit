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
#include "CMyVarSpace.h"

class CMyHtml2XmlWorker : public CMyWorker
{
private:
	typedef struct ST_CSAIR_LOGIN_COOKIE
	{
		char          szChnID[8]; //�������
		char szUin[72];       //�Ƹ�ͨ��½��
		char szIp[16];	//�û�IP
		time_t        tmStamp;    //ʱ����������ֽ���
		char szAlign[4]; //ʹ�ṹ����
	}SUnionLoginCookie;


//{{map function
	string Map_GetValueByKey(vector <string > & para_list);
	string Map_Size(vector <string > & para_list);
	string Map_Split(vector <string > & para_list);
	string Map_At(vector <string > & para_list);
	string Map_Join(vector <string > & para_list);
//}}map function
//{{vector function
	string Vector_At(vector <string > & para_list);
	string Vector_Size(vector <string > & para_list);
	string Vector_Split(vector <string > & para_list);
	string Vector_Join(vector <string > & para_list);
//}}vector function
//{{string function	
	string String_SubStr(vector <string > & para_list);
	string String_Cat(vector <string > & para_list);
	string String_Trim(vector <string > & para_list);
	string String_Has(vector <string > & para_list);

	string String_Match(vector <string > & para_list);
	
	string String_Find(vector <string > & para_list);
	
	string String_ToHex(vector <string > & para_list);
	string String_ToChar(vector <string > & para_list);

	string String_ReadInt(vector <string > & para_list);
	string String_ReadCString(vector <string > & para_list);
	
	string String_XmlDecode(vector <string > & para_list);
	string String_XmlEncode(vector <string > & para_list);
	string String_UrlDecode(vector <string > & para_list);
	string String_UrlEncode(vector <string > & para_list);
	string String_UrlEncode2(vector <string > & para_list);
	
	string String_ToUpper(vector <string > & para_list);
	string String_ToLower(vector <string > & para_list);

//}}string function

//{{HTML �������������
	string Html_Parse(vector <string > & para_list);
	string Html_GetElementByAttrNV(vector <string > & para_list);
	string Html_Count(vector <string > & para_list);
	string Html_GetResult(vector <string > & para_list);
	string Html_GetAttrValue(vector <string > & para_list);
	string Html_GetInnerText(vector <string > & para_list);
	string Html_GetElementByTagName(vector <string > & para_list);
	string Html_Child(vector <string > & para_list);
//}}HTML �������������


//{{�������ʽ:  ����    С��  ����
	string Math_GT(vector <string > & para_list);
	string Math_LT(vector <string > & para_list);
	string Math_EQU(vector <string > & para_list);
	
	string Math_UintAnd(vector <string > & para_list);
	string Math_UintOr(vector <string > & para_list);
	string Math_UintXor(vector <string > & para_list);
	string Math_UintAt(vector <string > & para_list);
	string Math_UintGt(vector <string > & para_list);
	string Math_UintLt(vector <string > & para_list);
	string Math_UintEqu(vector <string > & para_list);
	
	string Math_AND(vector <string > & para_list);
	string Math_OR(vector <string > & para_list);
	
	string Math_Inc(vector <string > & para_list);
	string Math_Sub(vector <string > & para_list);


	//double
	string Math_Double_Add(vector <string > & para_list);
	string Math_Double_Sub(vector <string > & para_list);
	string Math_Double_Mul(vector <string > & para_list);
	string Math_Double_Div(vector <string > & para_list);

	// math
	string Math_Md5(vector <string > & para_list);
	string Math_3Des(vector <string > & para_list);
	string Math_Un3Des(vector <string > & para_list);
	
//}}�������ʽ:  ����    С��  ����


//{{�ļ���������
	string File_Store(vector <string > & para_list);
	string File_Read(vector <string > & para_list);
	string File_Delete(vector <string > & para_list);
	//gen_file_name
	string File_GenCachName(vector <string > & para_list);
	
//}}�ļ���������

//{{ ϵͳ��������
	string Sys_GetHelp(vector <string > & para_list);



//}}ϵͳ��������

  //�����ִ�����
  string String_GetLength(vector <string > & para_list);

  //���ص�ǰ����yyyymmddhhMMss
  string Date_GetDatetime(vector <string > & para_list);

  //ת��GBK/utf-8
  string String_ConvertCode(vector <string > & para_list);

  //��̨����spoa
  string Tool_SpoaCall(vector <string > & para_list);

  

/*
  //���B�˻��̻���¼
  string CheckUnionMchLogin(vector <string > & para_list);
  
  //B�˻��̻���¼cookie
  string WriteUnionMchLoginCookie(vector <string > & para_list);
*/

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
	  void ClearLocalVarSpace();
	  void InitFunctionMap();
	  string GetTmpVarName();

	 void InitFunctionDesc();
    
	  int m_iTmpVar;
    //##ModelId=4B0CB49501BF
    CMyVarSpace *m_gpVar;

    // �ֲ������ռ�
    //##ModelId=4B0CB4B70087
    CMyVarSpace m_mVar;

	map<string,int> m_mFunction;
	MyUtility::CStringMap m_mFunctionDesc;

	//�ӵ�3λ����ı���
	//void parseRequestInfo_1009(vector <string > & para_list, string &strParam);

};



#endif /* MYFLOW_CMYHTML2XMLWORKER_H_HEADER_INCLUDED_B4F34000 */
