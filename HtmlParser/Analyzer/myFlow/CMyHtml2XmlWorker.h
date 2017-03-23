// ***********************************************
// 
// 创建日期： 2009-11-18
// 
// 作    者： gaoyong
// 
// 电子邮件： gaoyong@my-soft.net.cn
// 
// 主要功能： 实现对html文件的格式化输出，以及类似
// 
//            BPEL的流程控制。
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

// 将Html转化为xml的工作者
// 
// 选择器： 
// 		批量节点
// 			按照节点名检索
// 				tag(para_tag_name)
// 			按照属性检索	
// 				id(para_id_value)
// 				name(para_name_value)
// 				nv(para_attr_name_name,attr_name_value)
// 		批量节点值
// 			count
// 			
// 		单个节点	
// 			按照数组序号检索
// 				item(index)
// 	
// 		单个值
// 			取节点相应属性的值
// 				attr(para_attr_name_name)
// 			取节点中间文本
// 				text 
// 				
// 	
// 	运算器
// 		left是否包含right
// 			bool has(left,right)  
// 			bool head_has(left,right)  
// 			bool tail_has(left,right)  			
// 		left是否等于right
// 			bool equ(left,right)
// 		left是否大于right
// 			bool big(left,rigth)
// 		left是否小于right
// 			bool little(left,right)
// 		left减去right
// 			int minus(left,right)
// 		left加上right
// 			int add(left,right)
// 
// 
// 输出器
// 		echo
// 	赋值器
// 		assign
// 		定义的变量可以在下面用$identify引用
// 		
// 		类型：integer,string
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
        // 函数名称
        const string &func_name, 
        // 参数列表
        vector <string > & para_list);

    // 取变量值，先局部后全局
    // 
    // 如果取值成功则返回0
    // 否则返回其他值
    // 1 变量不存在
    //##ModelId=4B0CB6B103A4
    int FetchVarValue(const string &var, 
        // 变量的值
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

    // 全局变量空间，用以获取输入和输出
    //##ModelId=4B0CB49501BF
    CMyVarSpace *m_gpVar;

    // 局部变量空间
    //##ModelId=4B0CB4B70087
    CMyVarSpace m_mVar;

	map<string,int> m_mFunction;

};



#endif /* MYFLOW_CMYHTML2XMLWORKER_H_HEADER_INCLUDED_B4F34000 */
