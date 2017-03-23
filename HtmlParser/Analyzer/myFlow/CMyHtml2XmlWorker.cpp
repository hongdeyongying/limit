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
#include "stdafx.h"
#include "CMyHtml2XmlWorker.h"
#include "CMyAny.h"

string CMyHtml2XmlWorker::count(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 1)
		return res;
	
	CMyAny para1;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;

	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML) && (para1.GetType() != VT_P_CNODE) )
		return res;

	//ִ�к���

	CNode * pNode = para1;

	CElement * pElement = dynamic_cast<CElement * > (pNode);

	if(!pElement) return res;

	//������
	CMyAny resVarValue(pElement->GetResult().size());
	string resVarName = "count_" + GetTmpVarName();

	m_mVar.SetVarValue(resVarName,resVarValue);

	res = "$" +resVarName;
	return res;
}
string CMyHtml2XmlWorker::item(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 2)
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;

	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML)  && (para1.GetType() != VT_P_CNODE))
		return res;
	if((para2.GetType() != VT_INTEGER) &&  (para2.GetType() != VT_STRING))
		return res;

	//ִ�к���
	
	CNode * pNode = para1;

	CElement * pElement = dynamic_cast<CElement * > (pNode);

	if(!pElement) return res;

	int idx = para2;

	//������
	if(idx < pElement->GetResult().size())
	{
		CMyAny resVarValue((CElement * )pElement->GetResult(idx));
		string resVarName = "item_" + GetTmpVarName();

		m_mVar.SetVarValue(resVarName,resVarValue);

		res = "$" + resVarName;
	}
	return res;
}
//strstr(str,0,5)
string CMyHtml2XmlWorker::strsub(vector <string > & para_list)
{
	string res("NULL");

	//������
	if((para_list.size() != 2)  && (para_list.size() != 3))
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;


	if((para1.GetType() != VT_STRING))
		return res;
	if((para2.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	string p1 = para1;
	int p2 = para2;

	int p3 = p1.size() - p2;


	//������:����в���3�����ʾָ������idx
	if(para_list.size() ==  3)
	{
		if(FetchVarValue(para_list.at(2),para3) != 0)
			return res;
		if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
			return res;

		p3 = para3;
	}

	res = p1.substr(p2,p3);


	return res;
}
string CMyHtml2XmlWorker::strcat(vector <string > & para_list)
{
	string res("NULL");

	//������
	if((para_list.size() != 2)  && (para_list.size() != 3))
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;


	if((para1.GetType() != VT_STRING))
		return res;
	if((para2.GetType() != VT_STRING) )
		return res;

	//ִ�к���
	string p1 = para1;
	string p2 = para2;

	res = p1+p2;


	return res;
}
//DEL string CMyHtml2XmlWorker::strsplit(vector <string > & para_list)
//DEL {
//DEL 	string res("NULL");
//DEL 
//DEL 	//������
//DEL 	if((para_list.size() != 2)  && (para_list.size() != 3))
//DEL 		return res;
//DEL 	
//DEL 	CMyAny para1,para2,para3;
//DEL 	if(FetchVarValue(para_list.at(0),para1) != 0)
//DEL 		return res;
//DEL 	if(FetchVarValue(para_list.at(1),para2) != 0)
//DEL 		return res;
//DEL 
//DEL 
//DEL 	if((para1.GetType() != VT_STRING))
//DEL 		return res;
//DEL 	if((para2.GetType() != VT_STRING) )
//DEL 		return res;
//DEL 
//DEL 	//ִ�к���
//DEL 	string p1 = para1;
//DEL 	string p2 = para2;
//DEL 
//DEL 	CUtility::
//DEL 
//DEL 
//DEL 	return res;
//DEL }

string CMyHtml2XmlWorker::child(vector <string > & para_list)
{
	string res("NULL");

	//������
	if((para_list.size() != 1) && (para_list.size() != 2))
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;


	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML) && (para1.GetType() != VT_P_CNODE) )
		return res;

	//ִ�к���
	CNode * pNode = para1;

	CElement * pElement = dynamic_cast<CElement * > (pNode);

	if(!pElement) return res;


	if(para_list.size() == 2)
	{
		if(FetchVarValue(para_list.at(1),para2) != 0)
			return res;

		if((para2.GetType() != VT_INTEGER) &&  (para2.GetType() != VT_STRING))
			return res;


		int idx = para2;

		//������
		if(idx < pElement->Child().size())
		{
			CMyAny resVarValue((CNode * )pElement->Child(idx));
			string resVarName = "child_" + GetTmpVarName();

			m_mVar.SetVarValue(resVarName,resVarValue);

			res = "$" + resVarName;
		}
	}
	else
	{
		CMyAny resVarValue(pElement->Child().size());
		string resVarName = "child_" + GetTmpVarName();

		m_mVar.SetVarValue(resVarName,resVarValue);

		res = "$" + resVarName;
	}
	return res;
}
string CMyHtml2XmlWorker::attr(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 2)
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;

	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML) && (para1.GetType() != VT_P_CNODE))
		return res;
	if((para2.GetType() != VT_STRING))
		return res;

	//ִ�к���
	CNode * pNode = para1;

	CElement * pElement = dynamic_cast<CElement * > (pNode);

	if(!pElement) return res;

	string attrVal,attrName = para2;

	//������

	res = pElement->GetAttrValue(attrName,attrVal);

	return res;
}
//��������ѡ��:tag(CElement * p,string tagname,int type mode) 
string CMyHtml2XmlWorker::tag(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 3)
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;
	if(FetchVarValue(para_list.at(2),para3) != 0)
		return res;

	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML) && (para1.GetType() != VT_P_CNODE) )
		return res;
	if((para2.GetType() != VT_STRING))
		return res;
	if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	
	CNode * pNode = para1;

	CElement * pElement = dynamic_cast<CElement * > (pNode);

	if(!pElement) return res;

	string tagName = para2;

	int mode = para3;


	pElement->GetElementByTagName(tagName,mode);

	//������	
	CMyAny resVarValue(pElement);
	string resVarName = "tag_" + GetTmpVarName();

	m_mVar.SetVarValue(resVarName,resVarValue);


	res = "$" +resVarName;
	return res;
}
string CMyHtml2XmlWorker::gt(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 3)
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;
	if(FetchVarValue(para_list.at(2),para3) != 0)
		return res;

	if((para1.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;
	if((para2.GetType() != VT_STRING) && (para2.GetType() != VT_INTEGER))
		return res;
	if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	int mode = para3;

	string sTmp = para2;

	int iTmp = para2;

	if(para1.GetType() == VT_STRING)
		para2 = sTmp;
	else
		para2 = iTmp;




	switch(mode)
	{
	case 0://����ƥ��
		{
			if(para1 > para2)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}
	case 1://���Ե���
		{
			if(para1 >= para2)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}

	}
		

	return res;
}
string CMyHtml2XmlWorker::lt(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 3)
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;
	if(FetchVarValue(para_list.at(2),para3) != 0)
		return res;

	if((para1.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;
	if((para2.GetType() != VT_STRING) && (para2.GetType() != VT_INTEGER))
		return res;
	if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	int mode = para3;

	string sTmp = para2;

	int iTmp = para2;

	if(para1.GetType() == VT_STRING)
		para2 = sTmp;
	else
		para2 = iTmp;


	switch(mode)
	{
	case 0://����ƥ��
		{
			if(para1 < para2)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}
	case 1://���Ե���
		{
			if(para1 <= para2)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}

	}
		

	return res;
}
string CMyHtml2XmlWorker::equ(vector <string > & para_list)

{
	string res("NULL");

	//������
	if(para_list.size() != 2)
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;

	if((para1.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;
	if((para2.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;

	//ִ�к���

	string sTmp = para2;

	int iTmp = para2;

	if(para1.GetType() == VT_STRING)
		para2 = sTmp;
	else
		para2 = iTmp;

	if(para1 == para2)
	{
		res = "true";
	}
	else
	{
		res = "false";
	}
		

	return res;
}


string CMyHtml2XmlWorker::inc(vector <string > & para_list)
{
	string res("NULL");

	//������
	if((para_list.size() != 2)  && (para_list.size() != 3))
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;


	if((para1.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;
	if((para2.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	int p1 = para1;
	int p2 = para2;


	CMyAny resTmp =  p1+p2;

	//������:����в���3�����ʾ�����Ҳ������˱�����
	if(para_list.size() ==  3)
	{
		if(FetchVarValue(para_list.at(2),para3) != 0)
			return res;
		if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
			return res;

		string varname = para3;
		if(m_gpVar)
		{
			m_gpVar->SetVarValue(varname,resTmp);
		}
		else
		{
			m_mVar.SetVarValue(varname,resTmp);
		}
	}

	res = resTmp;

	return res;
}
string CMyHtml2XmlWorker::sub(vector <string > & para_list)
{
	string res("NULL");

	//������
	if((para_list.size() != 2)  && (para_list.size() != 3))
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;


	if((para1.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;
	if((para2.GetType() != VT_STRING) && (para1.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	int p1 = para1;
	int p2 = para2;


	CMyAny resTmp =  p1-p2;

	//������:����в���3�����ʾ�����Ҳ������˱�����
	if(para_list.size() ==  3)
	{
		if(FetchVarValue(para_list.at(2),para3) != 0)
			return res;
		if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
			return res;

		string varname = para3;
		if(m_gpVar)
		{
			m_gpVar->SetVarValue(varname,resTmp);
		}
		else
		{
			m_mVar.SetVarValue(varname,resTmp);
		}
	}

	res = resTmp;

	return res;
}
//bool store(string path,string content)
string CMyHtml2XmlWorker::store(vector <string > & para_list)
{
	string res("false");

	//������
	if(para_list.size() != 2)
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;


	if(para1.GetType() != VT_STRING)
		return res;
	if(para2.GetType() != VT_STRING)
		return res;

	//ִ�к���
	string p1 = para1;
	string p2 = para2;

	FILE *stream;
	if( (stream  = fopen( p1.c_str(), "w" )) != NULL )
	{
		long sz = fwrite(p2.data(),sizeof(char),p2.size(),stream);

		if(sz == p2.size() )
			res = "true";
		/* Close stream */
		fclose( stream ) ;
	}
	

	return res;
}
//bool read(string filepath,string content)
string CMyHtml2XmlWorker::read(vector <string > & para_list)
{
	string res("false");

	//������
	if(para_list.size() != 2)
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;


	if(para1.GetType() != VT_STRING)
		return res;
	if(para2.GetType() != VT_STRING)
		return res;

	//ִ�к���
	string p1 = para1;
	string p2 = para2;

	string cnt;  char c;

	FILE *stream;
	if( (stream  = fopen( p1.c_str(), "r" )) == NULL )
		return res;
	
	fseek(stream,0,SEEK_END);
	
	LONG fLength = ftell(stream);

	fseek(stream,0,SEEK_SET);

	cnt.reserve(fLength);

	int actReadCount = 0;

	for(LONG i=0;i<fLength;i++)
	{
		actReadCount = fread( &c, sizeof( char ), 1, stream );

		if(actReadCount != 1)
			break;

		cnt.append(1,c);
		
	}


	/* Close stream */
	fclose( stream ) ;

	CMyAny resTmp =  cnt;

	//������:
	{
		string varname = p2;
		if(m_gpVar)
		{
			m_gpVar->SetVarValue(varname,resTmp);
		}
		else
		{
			m_mVar.SetVarValue(varname,resTmp);
		}
	}

	res = "true";
	

	return res;
}
//string xmlDecode(stringsrc)
string CMyHtml2XmlWorker::xmlDecode(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 1)
		return res;
	
	CMyAny para1;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;

	if(para1.GetType() != VT_STRING) 
		return res;

	//ִ�к���
	string p1 = para1;
	
	res = CUtility::XmlDecode(p1);
	

	return res;
}
//��������ѡ��:bool has(string src,string tag,int mode) 
string CMyHtml2XmlWorker::has(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 3)
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;
	if(FetchVarValue(para_list.at(2),para3) != 0)
		return res;

	if((para1.GetType() != VT_STRING) )
		return res;
	if((para2.GetType() != VT_STRING))
		return res;
	if((para3.GetType() != VT_STRING) && (para3.GetType() != VT_INTEGER))
		return res;

	//ִ�к���
	string src = para1;

	string tag = para2;

	int mode = para3;


	switch(mode)
	{
	case 0://����ƥ��
		{
			if(src == tag)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}
	case 1://�ײ�ƥ��
		{
			if(src.find(tag) == 0)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}
	case 2://����
		{
			if(src.find(tag) != string::npos)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}
	case 3://��
		{
			if(tag.find(src) != string::npos)
			{
				res = "true";
			}
			else
			{
				res = "false";
			}
			break;
		}


	}
		

	return res;
}
string CMyHtml2XmlWorker::text(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 1)
		return res;
	
	CMyAny para1;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;

	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML) && (para1.GetType() != VT_P_CNODE))
		return res;

	//ִ�к���


	//������
	if(para1.GetType() != VT_P_CNODE)
	{
		CElement * pElement = para1;
		res = pElement->GetInnerText();
	}
	else
	{
		CNode * pNode = para1;

		CElement * pElement = dynamic_cast<CElement * > (pNode);
		if(pElement)
			res = pElement->GetInnerText();
		else
			res = pNode->ToString();
	}

	return res;
}
//��������ѡ��:string nv(CElement * p,string name,string value) 
string CMyHtml2XmlWorker::nv(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 3)
		return res;
	
	CMyAny para1,para2,para3;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;
	if(FetchVarValue(para_list.at(2),para3) != 0)
		return res;

	if((para1.GetType() != VT_P_CELEMENT) && (para1.GetType() != VT_P_CHTML)  && (para1.GetType() != VT_P_CNODE))
		return res;

	if(para2.GetType() != VT_STRING)
		return res;

	if(para3.GetType() != VT_STRING)
		return res;

	//ִ�к���
	
	CNode * pNode = para1;

	CElement * pElement = dynamic_cast<CElement * > (pNode);

	if(!pElement) return res;
	string n = para2;
	string v = para3;

	pElement->GetElementByAttrNV(n,v);

	//������
	CMyAny resVarValue(pElement);
	string resVarName = "nv_" + GetTmpVarName();

	m_mVar.SetVarValue(resVarName,resVarValue);

	res = "$" + resVarName;
	return res;
}
//����html:string parse_html(int type,string cnt)
// type  : 1 file  2 string
// cnt   : filename string
string CMyHtml2XmlWorker::parse_html(vector <string > & para_list)
{
	string res("NULL");

	//������
	if(para_list.size() != 2)
		return res;
	
	CMyAny para1,para2;
	if(FetchVarValue(para_list.at(0),para1) != 0)
		return res;
	if(FetchVarValue(para_list.at(1),para2) != 0)
		return res;

	if((para1.GetType() != VT_INTEGER) && (para1.GetType() != VT_STRING) )
		return res;

	if(para2.GetType() != VT_STRING)
		return res;

	//ִ�к���
	CHtml * pHtml = new CHtml;

	if(1 == para1)
	{
		pHtml->ParseFile(para2);
	}
	else
	{
		pHtml->Parse(para2);
	}

	//������
	CMyAny resVarValue(pHtml);
	string resVarName = "parse_html_" + GetTmpVarName();

	m_mVar.SetVarValue(resVarName,resVarValue);

	res = "$" + resVarName;
	return res;
}
//##ModelId=4B0CB42302E8
string CMyHtml2XmlWorker::Call(const string &func_name, vector <string > & para_list)
{
	CMyAny tmp;

	string res("NULL"),func;
	if(FetchVarValue(func_name,tmp) != 0)
		return res;

	func = tmp;

	switch(m_mFunction[func])
	{
	case 1://parse_html
		res = parse_html(para_list);
		break;
	case 2://nv
		res = nv(para_list);
		break;
	case 3://item
		res = item(para_list);
		break;
	case 4://count
		res = count(para_list);
		break;
	case 5://attr
		res = attr(para_list);
		break;
	case 6://text
		res = text(para_list);
		break;
	case 7://tag
		res = tag(para_list);
		break;
	case 8://tag
		res = has(para_list);
		break;
	case 9://tag
		res = gt(para_list);
		break;
	case 10://tag
		res = lt(para_list);
		break;
	case 11://tag
		res = equ(para_list);
		break;
	case 12://tag
		res = inc(para_list);
		break;
	case 13://tag
		res = sub(para_list);
		break;
	case 14://store
		res = store(para_list);
		break;
	case 15://xmlDecode
		res = xmlDecode(para_list);
		break;
	case 16://child
		res = child(para_list);
		break;
	case 17://read
		res = read(para_list);
		break;
	case 18://read
		res = strcat(para_list);
		break;
	case 19://read
		res = strsub(para_list);
		break;
	default:
		break;
	}

	return res;

	
}

//##ModelId=4B0CB4D80048
CMyHtml2XmlWorker::CMyHtml2XmlWorker():m_gpVar(NULL)
{
	InitFunctionMap();
}
CMyHtml2XmlWorker::CMyHtml2XmlWorker(CMyVarSpace * global_var_space):m_gpVar(global_var_space)
{
	InitFunctionMap();
}

//##ModelId=4B0CB4D80087
CMyHtml2XmlWorker::~CMyHtml2XmlWorker()
{
}

//##ModelId=4B0CB6B103A4
CMyAny CMyHtml2XmlWorker::FetchVarValue(const string &var)
{
	CMyAny val;

	if( 0 == FetchVarValue(var,val))
		return val;

	else
		return val;

}
int CMyHtml2XmlWorker::FetchVarValue(const string &var, CMyAny &val)
{
	CMyAny * pTmpAny = NULL;
	int res = 1;

	if(var.empty())
		return 1;
	if(var.at(0) == '$')
	{
		if(var.size() > 1)
		{
			string tmpVar = var.substr(1,var.size()-1);

			if(tmpVar.at(0) == '$')
			{
				res = FetchVarValue(tmpVar,val);
				if(  res != 0) return res;

				if(val.GetType() == VT_STRING)
					tmpVar = val;
			}

			//�ֲ��ռ����
			pTmpAny = m_mVar.GetVarValue(tmpVar);
			
			if(pTmpAny )
			{
				val = *pTmpAny;
				res = 0;
			}
			else
			{
				//ȫ�ֲ���
				if(m_gpVar)
				{
					pTmpAny = m_gpVar->GetVarValue(tmpVar);

					if(pTmpAny )
					{
						val = *pTmpAny;
						res = 0;
					}

				}

			}		
		}		

	}
	else
	{
		val = CUtility::UrlDecode (var);
		res = 0;
	}

	return res;
}




string CMyHtml2XmlWorker::GetTmpVarName()
{
	static int i = 1;

	char szSid[10] = {0};

	sprintf(szSid,"%d",i++);


	return string(szSid);


}

void CMyHtml2XmlWorker::InitFunctionMap()
{

	//����html:string parse_html(int type,string cnt)
	m_mFunction["parse_html"] = 1;

	//��������ѡ��:string nv(CElement * p,string name,string value) 
	m_mFunction["nv"] = 2;

	//��������ѡ��:item(CElement * p,int idx) 
	m_mFunction["item"] = 3;

	//��������ѡ��:count(CElement * p) 
	m_mFunction["count"] = 4;

	//��������ѡ��:attr(CElement * p,string name) 
	m_mFunction["attr"] = 5;

	//��������ѡ��:text(CElement * p) 
	m_mFunction["text"] = 6;

	//��������ѡ��:tag(CElement * p,string tagname,int type mode) 
	m_mFunction["tag"] = 7;



	//�߼��Ƚ�:bool has(string src,string tagname,int type mode) 
	m_mFunction["has"] = 8;
	//�߼��Ƚ�:bool gt(string src,string tagname,int type mode) 
	m_mFunction["gt"] = 9;
	//�߼��Ƚ�:bool lt(string src,string tagname,int type mode) 
	m_mFunction["lt"] = 10;
	//�߼��Ƚ�:bool equ(string src,string tagname,int type mode) 
	m_mFunction["equ"] = 11;


	//��������:bool inc(string src,string tag) 
	m_mFunction["inc"] = 12;
	//��������:bool sub(string src,string tag) 
	m_mFunction["sub"] = 13;


	//д�ļ�:int store(string path,string content)
	m_mFunction["store"] = 14;

	//д�ļ�:string xmlDecode(string src)
	m_mFunction["xmlDecode"] = 15;

	//ѡ���ӽڵ�:CNode* child(CElement* p,int i)
	m_mFunction["child"] = 16;
	m_mFunction["read"] = 17;

	m_mFunction["strcat"] = 18;
	m_mFunction["strsub"] = 19;
}
