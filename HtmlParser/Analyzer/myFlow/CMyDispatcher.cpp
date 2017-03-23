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
#include "stdafx.h"
#include "CMyDispatcher.h"
#include "../StrArray.h"
#include "httpcall/HttpClient.h"

#include "CMyHtml2XmlWorker.h"

#include "CMyExpression.h"

//##ModelId=4B14894401E3
CMyDispatcher::CMyDispatcher()
{
	InitMyKey();

	m_pMyWorker = new CMyHtml2XmlWorker(&m_mVar);
}


//##ModelId=4B1489440212
CMyDispatcher::~CMyDispatcher()
{
	delete m_pMyWorker;
}

//##ModelId=4B1489650146
int CMyDispatcher::StartWork(const string &flowFile, string &res,const string & inParas)
{
	int result = 0;

	//准备输入参数
	if(inParas.size() >= 3)
	{
		CStrArray arr;

		arr.SetCommaText(inParas,"&");
		
		for(int i =0;i<arr.size();i++)
		{
			if(arr.at(i).size() >= 3)
			{
				CStrArray nv;
				nv.SetCommaText(arr.at(i),"=");
	
				if(nv.size() == 2)
					m_mVar.SetVarValue(nv[0],CMyAny(nv[1]));
			}
		}

	}

	result = m_htmlFlow.ParseFile(flowFile);

	if(result == 0)
	{
		for(int i=0; i < m_htmlFlow.Child().size();i++)
		{
			result = Run(m_htmlFlow.Child(i),res);
			if(result != 0)
				break;
		}
	}

	return result;
}

int CMyDispatcher::Do_KEY_SWITCH(const CNode *pCurNode, string &res)
{
	int result = 0;

	CText *m_pText = NULL;
	CElement *mpElement = NULL;
	CComment *m_pComm = NULL;
	TRACE("%s:%d ",__FILE__,__LINE__);

	m_htmlFlow.AssertValid(pCurNode,m_pText,mpElement,m_pComm);

	//确认节点名
	if( (!mpElement) || ( m_mKey[mpElement->GetTagName()] != KEY_SWITCH )) 
	{
		result = 1;
		return result;
	}

	//取属性参数 id expr
	string expr;
	
	mpElement->GetAttrValue("expr",expr);

	CMyExpression  myexpr;
	//TRACE("%s:%d %s",__FILE__,__LINE__,expr.c_str());

//	AfxMessageBox("1");
//	AfxMessageBox(expr.c_str());
	
	myexpr.Identify(expr);
//	AfxMessageBox("1.1");

	string varExprRes = myexpr.Execute(m_pMyWorker);
//	AfxMessageBox("2");

	string valExprRes = m_pMyWorker->FetchVarValue(varExprRes);
//	AfxMessageBox("3");

//	TRACE("%s:%d %s",__FILE__,__LINE__,valExprRes.c_str());

	//m_mVar.SetVarValue(id,m_pMyWorker->FetchVarValue(a));

	//取子节点 case与default
	CElement *mpElementCASE = NULL; // 符合条件的CASE
	CElement *mpElementDEFAULT = NULL;//DEFAULT
	CElement *mpElementTMP = NULL;
	CElement *mpElementEXEC = NULL;//将执行的分支

	for(int i = 0;i< mpElement->Child().size(); i++)
	{
		CNode * pNode = mpElement->Child(i);

		m_htmlFlow.AssertValid(pNode,m_pText,mpElementTMP,m_pComm);

		if(mpElementTMP)
		{
			switch(m_mKey[mpElementTMP->GetTagName()])
			{
			case KEY_CASE:
				{
					string value;
					mpElementTMP->GetAttrValue("value",value);

					if( valExprRes == value)
					{
						mpElementCASE = mpElementTMP;
						i = mpElement->Child().size();
						break;
					}

				}
				break;
			case KEY_DEFAULT:
				mpElementDEFAULT = mpElementTMP;
				break;
			}
		}
	}

	if(mpElementCASE )
	{
		mpElementEXEC = mpElementCASE;
	}
	else if(mpElementDEFAULT)
	{
		mpElementEXEC = mpElementDEFAULT;
	}

	if(mpElementEXEC)
	{
		for(i=0; i < mpElementEXEC->Child().size();i++)
		{
			result = Run(mpElementEXEC->Child(i),res);
			if(result != 0)
				break;
		}
	
	}

	return result;		

}
//##ModelId=4B1491690175
int CMyDispatcher::Run(const CNode *pCurNode, string &res)
{
	int result = 0;

	CText *m_pText = NULL;
	CElement *mpElement = NULL;
	CComment *m_pComm = NULL;

	m_htmlFlow.AssertValid(pCurNode,m_pText,mpElement,m_pComm);

	if(mpElement)
	{
		//如果不是关键字
		if(m_mKey.find(mpElement->GetTagName()) == m_mKey.end())
		{
			res += mpElement->ToString();
			int j = mpElement->Child().size();

			for(int i = 0 ;i<j;i++)
			{
				CNode *p = mpElement->Child(i);

				result = Run(p,res);
				if(result != 0) return result;
			}

			res += "</";
			res += mpElement->GetTagName();
			res += ">";
		}
		//如果是关键字
		else
		{
			switch(m_mKey[mpElement->GetTagName()])
			{
			case KEY_ASSIGN:
				result = Do_KEY_ASSIGN(mpElement);
				if(result != 0) return result;
				break;
			case KEY_SWITCH:
				result = Do_KEY_SWITCH(mpElement,res);
				if(result != 0) return result;
				break;
			case KEY_ECHO:
				result = Do_KEY_ECHO(mpElement,res);
				if(result != 0) return result;
				break;
			case KEY_FOR:
				result = Do_KEY_FOR(mpElement,res);
				if(result != 0) return result;
				break;
			case KEY_INVOKE:
				result = Do_KEY_INVOKE(mpElement);
				if(result != 0) return result;
				break;

			default:
				break;
			}
		}
		
	}
	else if(m_pText)
	{
		res += pCurNode->ToString();
	}
	else
	{
		;
	}


	return result;
}

//##ModelId=4B148C8D028F
//DEL UINT CMyDispatcher::WorkThread(LPVOID data)
//DEL {
//DEL 	CMyDispatcher * pMyDispatcher = (CMyDispatcher *)data;
//DEL 
//DEL 
//DEL 	return 1;
//DEL }

//##ModelId=4B149377008B
//DEL int CMyDispatcher::Run(const string &file_path, string &res)
//DEL {
//DEL 	int result = 0;
//DEL 
//DEL 	return result;
//DEL }

void CMyDispatcher::InitMyKey()
{
	//分支语句
		//<my-soft::switch expr="big(count(tag($htmlSource,a,0)),0)" >
		m_mKey.insert(map<string,EKEY>::value_type("my-soft::switch", KEY_SWITCH));
		//<my-soft::case value="true">
		m_mKey.insert(map<string,EKEY>::value_type("my-soft::case", KEY_CASE));
		//<my-soft::default>
		m_mKey.insert(map<string,EKEY>::value_type("my-soft::default", KEY_DEFAULT));
	//循环语句
		//<my-soft::for condition="small($var,count(tag($htmlSource,a,0)))" recycle="inc($var)" >
		m_mKey.insert(map<string,EKEY>::value_type("my-soft::for", KEY_FOR));
		//<my-soft::continue>
//		m_mKey.insert(map<string,EKEY>::value_type("my-soft::continue", KEY_CONTINUE));
		//<my-soft::break>
//		m_mKey.insert(map<string,EKEY>::value_type("my-soft::break", KEY_BREAK));

	//输出语句<my-soft::echo>expr</my-soft::echo>
	m_mKey.insert(map<string,EKEY>::value_type("my-soft::echo", KEY_ECHO));
	
	//赋值语句 <my-soft::aasign identify="htmlSource" expr="parse_html(0,$response)"  />
	m_mKey.insert(map<string,EKEY>::value_type("my-soft::assign", KEY_ASSIGN));

	//调用外部功能语句
	/*<my-soft::invoke service="httpcall" retvar="response">
		<my-soft::parameter name="" value="" />
		<my-soft::parameter name="" value="" />
		<my-soft::parameter name="" value="" />
		<my-soft::parameter name="" value="" />
	</my-soft::invoke>
	*/

	m_mKey.insert(map<string,EKEY>::value_type("my-soft::invoke", KEY_INVOKE));
	m_mKey.insert(map<string,EKEY>::value_type("my-soft::parameter", KEY_PARAMETER));

	
}

int CMyDispatcher::Do_KEY_ASSIGN(const CNode *pCurNode)
{
	int result = 0;

	CText *m_pText = NULL;
	CElement *mpElement = NULL;
	CComment *m_pComm = NULL;

	m_htmlFlow.AssertValid(pCurNode,m_pText,mpElement,m_pComm);

	//确认节点名
	if( (!mpElement) || ( m_mKey[mpElement->GetTagName()] != KEY_ASSIGN )) 
	{
		result = 1;
		return result;
	}

	//取属性参数 id expr
	string id,expr;
	
	mpElement->GetAttrValue("id",id);
	mpElement->GetAttrValue("expr",expr);

	CMyExpression  myexpr;
	
	myexpr.Identify(expr);

	string a = myexpr.Execute(m_pMyWorker);

	//string b= m_pMyWorker->FetchVarValue(a);

	m_mVar.SetVarValue(id,m_pMyWorker->FetchVarValue(a));


	return result;					
}

int CMyDispatcher::Do_KEY_INVOKE(const CNode *pCurNode)
{
	int result = 0;

	CText *m_pText = NULL;
	CElement *mpElement = NULL;
	CComment *m_pComm = NULL;

	m_htmlFlow.AssertValid(pCurNode,m_pText,mpElement,m_pComm);

	//确认节点名
	if( (!mpElement) || ( m_mKey[mpElement->GetTagName()] != KEY_INVOKE )) 
	{
		result = 1;
		return result;
	}

	//取属性参数 service retvar
	string service,retvar,type,filepath;
	//服务名
	mpElement->GetAttrValue("service",service);
	//返回值，变量名
	mpElement->GetAttrValue("retvar",retvar);
	//服务类型
	mpElement->GetAttrValue("type",type);
	//文件路径:配置文件
	mpElement->GetAttrValue("filepath",filepath);

	//取invoke相应的请求参数
	CStrMap invokeParaMap;

	CElement *mpElementTMP = NULL;

	for(int i = 0;i< mpElement->Child().size(); i++)
	{
		CNode * pNode = mpElement->Child(i);

		m_htmlFlow.AssertValid(pNode,m_pText,mpElementTMP,m_pComm);

		if(mpElementTMP)
		{
			switch(m_mKey[mpElementTMP->GetTagName()])
			{
			case KEY_PARAMETER:
				{
					string name,value,type;
					mpElementTMP->GetAttrValue("name",name);
					mpElementTMP->GetAttrValue("value",value);
					mpElementTMP->GetAttrValue("type",type);

	

					if(type == "var")
					{
						invokeParaMap[name] = m_pMyWorker->FetchVarValue(value);
					}
					else if(type == "expr")
					{
						CMyExpression  myexpr;
						
						myexpr.Identify(value);

						string a = myexpr.Execute(m_pMyWorker);

						invokeParaMap[name] =  m_pMyWorker->FetchVarValue(a);
					}
					else if(type == "const")
					{
						invokeParaMap[name] = value;
					}
					else 
						invokeParaMap[name] = value;

				}
				break;
			}
		}
	}

	//执行invoke，目前只支持httpcall
	string invokeRes("NULL");

	if(type == "httpcall")
	{
		CHttpClient http;

		http.LoadConfig(filepath,service);

		http.LoadInput(invokeParaMap);

		http.LoadSession();

		http.SendAndRecv();

		if(( http.m_sRetCode == string("200")  ) &&
			(http.m_iStatus == 0))
		{

			http.StoreSession();

			invokeRes = http.m_sResBody;
		}
	}
	else if(type== "flowcall")
	{
		CMyDispatcher disp;

		string inParas;

		string res;
		
		disp.StartWork(filepath,res,invokeParaMap.GenString(inParas));		

		invokeRes = res;

	}


	// 返回结果
	m_mVar.SetVarValue(retvar,(CMyAny)invokeRes);


	return result;					
}

int CMyDispatcher::Do_KEY_ECHO(const CNode *pCurNode,string &res)
{
	int result = 0;

	CText *m_pText = NULL;
	CElement *mpElement = NULL;
	CComment *m_pComm = NULL;

	m_htmlFlow.AssertValid(pCurNode,m_pText,mpElement,m_pComm);

	//确认节点名
	if( (!mpElement) || ( m_mKey[mpElement->GetTagName()] != KEY_ECHO )) 
	{
		result = 1;
		return result;
	}

	//取属性参数 id expr
	string type,value;
	
	mpElement->GetAttrValue("type",type);
	mpElement->GetAttrValue("value",value);


	if(type == "var")
	{
		res += m_pMyWorker->FetchVarValue(value);
	}
	else if(type == "const")
	{
		res += value;
	}
	else if(type == "expr")
	{
		CMyExpression  myexpr;
		
		myexpr.Identify(value);

		string a = myexpr.Execute(m_pMyWorker);

		res +=  m_pMyWorker->FetchVarValue(a);
	}
	



	return result;					
}
int CMyDispatcher::Do_KEY_FOR(const CNode *pCurNode,string &res)
{
	int result = 0;

	CText *m_pText = NULL;
	CElement *mpElement = NULL;
	CComment *m_pComm = NULL;

	m_htmlFlow.AssertValid(pCurNode,m_pText,mpElement,m_pComm);

	//确认节点名
	if( (!mpElement) || ( m_mKey[mpElement->GetTagName()] != KEY_FOR )) 
	{
		result = 1;
		return result;
	}

	//取属性参数 id expr
	string condition,recycle;
	
	mpElement->GetAttrValue("condition",condition);
	mpElement->GetAttrValue("recycle",recycle);

	//
	CMyExpression  exprCondition(condition,NULL);
	CMyExpression  exprRecycle(recycle,NULL);
	
	//exprCondition.Identify(condition);
	//exprRecycle.Identify(recycle);

	while(1)
	{
		//执行条件表达式
		string exprCondRes =  exprCondition.Execute(m_pMyWorker);
		if(exprCondRes == "NULL")
		{
			result = 1;
			break;
		}

		string sCondRes = m_pMyWorker->FetchVarValue(exprCondRes);


		if(sCondRes == "true")
		{
			for(int i=0; i < mpElement->Child().size();i++)
			{
				result = Run(mpElement->Child(i),res);
				if(result != 0)
					break;
			}
		}
		else
		{			
			break;
		}

		exprRecycle.Execute(m_pMyWorker);


	}

	return result;
}