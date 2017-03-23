// HttpClient.cpp: implementation of the CHttpClient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HttpClient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "../../ModulePath.h"

#include "Connection.h"

#include "../../XML/tinyxml.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHttpClient::CHttpClient()
{

}

CHttpClient::~CHttpClient()
{

}

int CHttpClient::SendAndRecv()
{
	m_iStatus = -1;
	CConnection conn;

	//LoadSession();


	string sHead,sPara;

	string sCont;

	sHead = m_sMethod;
	if(m_sMethod == "POST")
	{
		sHead += " ";
		sHead += m_sLocation;
		sHead += " ";
		sHead += m_sReqProtocol;
		sHead += "\r\n";

		string hh;

		m_mFixPara.GenString(sPara) += "&";

		m_mInpPara.GenString(sPara);

		m_mReqHead["Content-Length"] = CUtility::IntegerToString(sPara.size());
		
		sHead += m_mReqHead.GenString(hh,"\r\n",":",1);


		sHead += "\r\n\r\n";

		sCont = sHead + sPara;

	}
	else if(m_sMethod == "GET")
	{	

		string hh;

		m_mFixPara.GenString(sPara);
		if(!sPara.empty())
			sPara+="&";

		m_mInpPara.GenString(sPara);

		sHead += " ";
		sHead += m_sLocation;

		if(!sPara.empty())
			sHead +=  "?" + sPara;
		sHead += " ";
		sHead += m_sReqProtocol;
		sHead += "\r\n";

		sHead += m_mReqHead.GenString(hh,"\r\n",":",1);


		sHead += "\r\n";
		sHead += "\r\n";

		sCont = sHead ;

		
	}

	conn.Open(m_sHost.c_str(),CUtility::StringToInteger(m_sPort));
	
	int sz = conn.Send(sCont.c_str(),sCont.size());



	//tracer.Out("111111");
	tracer.Out("%s",sCont.c_str());

	char szResponse[2048]={0};

	sz = 0;		
	
	do
	{			
		memset(szResponse,0,sizeof(szResponse));
		sz = conn.Read(szResponse,sizeof(szResponse));	
	

		m_sResBody.append(szResponse,sz);

		tracer.Out("%s",szResponse);

	}while(sz > 0);

	
	m_iStatus = Analysis();

	/*

	//日交易量
	string sDat ;

	if(!m_mInpPara["TextBoxBeginDate"].empty())   //基本信息
	{
		sDat = CModulePath::GetInstance()->m_sDatDir + "\\"+m_mInpPara["TextBoxBeginDate"]+".html" ;
	}
	else if(!m_mInpPara["TX_QQID"].empty())   //基本信息
	{
		sDat = CModulePath::GetInstance()->m_sDatDir + "\\"+m_mInpPara["TX_QQID"]+".html" ;
	}
	else
	{
		
		sDat = CModulePath::GetInstance()->m_sTmpDir + "\\tmp"+m_mInpPara["pnr"]+".html" ;
	//	return 0;
	}

	CFile file1;
	file1.Open(sDat.c_str(),CFile::modeCreate|CFile::modeWrite|CFile::shareDenyWrite  );


	file1.Write(m_sResBody.data(),m_sResBody.size());
	file1.Close();
	*/

	
	return 0;
}
int CHttpClient::LoadSession()
{
	string fses = CModulePath::GetInstance()->m_sSesDir + "\\" + CUtility::TrimLeft(m_mReqHead["Host"])+".ses.xml";
	
	TiXmlDocument doc(fses.c_str());
	
	bool loadOkay = doc.LoadFile();
	if ( !loadOkay )
	{
		return -1;
	}

	TiXmlNode* nodeRoot = 0;
	TiXmlNode* nodeUrl=0;
	TiXmlNode* nodeCookie=0;
	nodeRoot = doc.FirstChild( "root" );
	if(nodeRoot)
	{
		nodeUrl=nodeRoot->FirstChild( "url" );
		nodeCookie=nodeRoot->FirstChild( "cookie" );
	}

	string url,cookie;
	if(nodeCookie && nodeUrl)
	{
		url = CUtility::UrlDecode(nodeUrl->ToElement()->GetText());
		cookie = CUtility::UrlDecode(nodeCookie->ToElement()->GetText());
	}
	
	m_mReqHead["Cookie"] = cookie;


	return 0;
}
int CHttpClient::LoadConfig(const string & fname,const string & servid)
{
	string err_msg;

	TiXmlNode* nodeHead,*nodeServices,*nodeService,*node,*nodePara,* nodePortProtocol,* nodePort,*nodeResponse;

	TiXmlDocument doc(fname.c_str());

	bool loadOkay = doc.LoadFile();
	if ( !loadOkay )	
	{
		err_msg = "读取配置文件【";
		err_msg+= fname;
		err_msg+= "】失败！";
		goto LoadConfig_ERR;
	}

	nodeServices = doc.FirstChild( "services" );

	nodeService = 0;
	
	node = nodeServices->FirstChild( "service" );

	

	while(node)
	{
		TiXmlElement * ele = 0;
		ele = node->ToElement();
		if(ele->Attribute("id") == servid)
		{
			nodeService = node;
			break;
		}
		node = node->NextSibling();
	}

	if(nodeService == 0)
	{
		err_msg = "配置文件【";
		err_msg+= fname;
		err_msg+= "】没有【";
		err_msg+= servid;
		err_msg+= "】的配置！";
		goto LoadConfig_ERR;
	}
//读取porttype
	nodePort = nodeService->FirstChild( "porttype" );

	if(!nodePort)
	{
		err_msg = "配置文件【";
		err_msg+= fname;
		err_msg+= "】的【";
		err_msg+= servid;
		err_msg+= "】的无porttype信息！";
		goto LoadConfig_ERR;
	}

	{
		TiXmlElement * elePort = 0;
		elePort = nodePort->ToElement();
		m_sMethod	= elePort->Attribute("method");
		m_sLocation = elePort->Attribute("url");

		m_sReqProtocol = elePort->Attribute("name");
		m_sReqProtocol += "/";
		m_sReqProtocol += elePort->Attribute("version");
		
		m_sHost = elePort->Attribute("host");
		m_sPort = elePort->Attribute("port");
	}
	nodePortProtocol = nodePort->FirstChild( "protocol" );
	if(!nodePortProtocol)
	{
		m_iType = HTTP;
	}
	else
	{
		string tmp = nodePortProtocol->ToElement()->Attribute("ssl");
		if(tmp == "none")m_iType = HTTP;
		else if(tmp == "serv")m_iType = HTTPS_SERVER_VALID;
		else if(tmp == "clnt")m_iType = HTTPS_NO_VALID;
		else if(tmp == "both")m_iType = HTTPS_BOTH_VALID;
		else
		{
			err_msg = "不支持的协议【";
			err_msg+= tmp;
			err_msg+= "】";
			goto LoadConfig_ERR;
		}	
	}

	if(m_iType != HTTP)
	{
		TiXmlNode* nodePortCerts = nodePort->FirstChild( "certs" );
		TiXmlNode* nodePortCert = nodePortCerts->FirstChild( "cert" );
		while(nodePortCert)
		{
			TiXmlElement * ele = 0;
			ele = nodePortCert->ToElement();
			if(ele->Attribute("name") == "private" )
				m_sClientCert = ele->Attribute("path");
			else if(ele->Attribute("name") == "trust" )
				m_sRootCert = ele->Attribute("path");
			else
			{
				err_msg = "不支持的证书类型【";
				err_msg+= ele->Attribute("name");
				err_msg+= "】";
				goto LoadConfig_ERR;
			}

		}
	}

//读取headers
	nodeHead = node->FirstChild( "headers" );
	nodeHead = nodeHead->FirstChild( "header" );

	while(nodeHead)
	{
		TiXmlElement * ele = 0;
		ele = nodeHead->ToElement();

		m_mReqHead.insert(map<string,string>::value_type(ele->Attribute("name"),ele->Attribute("value")));
		
	
		nodeHead = nodeHead->NextSibling();
	}

	
//读取parameters
	//
	nodePara = node->FirstChild( "parameters" );
	nodePara = nodePara->FirstChild( "parameter" );

	while(nodePara)
	{
		TiXmlElement * ele = 0;
		ele = nodePara->ToElement();
		
		if(ele->Attribute("type") == string("fix"))
			m_mFixPara.insert(map<string,string>::value_type(ele->Attribute("name"),ele->Attribute("value")));
		else if(ele->Attribute("type") == string("inp"))
			m_mInpPara.insert(map<string,string>::value_type(ele->Attribute("name"),ele->Attribute("value")));
		else
		{
			err_msg = "不支持的参数类型【";
			err_msg+= ele->Attribute("name");
			err_msg+= "】";
			goto LoadConfig_ERR;
		}
		nodePara = nodePara->NextSibling();
	}


//读取responses
	nodeResponse = node->FirstChild( "response" );


	return 0;



LoadConfig_ERR:
	AfxMessageBox(err_msg.c_str());
	return -1;



}

/*
  0 成功
  1 失败，无状态行
  2 失败，无正文
  3 chunk Error
  */
int CHttpClient::Analysis()
{
	string curLine;

	string curText;

	string::const_iterator iter = m_sResBody.begin();
	string::const_iterator iterText=m_sResBody.begin();


reget_state:
	//取第一行数据 : HTTP/1.1 100 Continue
	CUtility::get_first_line(m_sResBody,iter,curLine);

	CStrArray curArr;

	curArr.SetCommaText(curLine," ");

	if(curArr.size() != 3) return 1;

	m_sResProtocol = curArr[0];
	m_sRetCode = curArr[1];
	m_sRetDes = curArr[2];

	//取正文，假设没有1**
	if(CUtility::get_first_http_text(m_sResBody,iterText)!=0)
		return 2;

	//读出所有的头
	/*
		Server: Microsoft-IIS/5.0
		Date: Wed, 22 Apr 2009 03:37:32 GMT
		X-Powered-By: ASP.NET
	*/

	while(iter < iterText)
	{
		CUtility::get_first_line(iter,iterText,curLine);
		
		curArr.SetCommaText(curLine,":");

		if(curArr.size() >= 2)
		{
			string tmp = curLine.substr(curArr[0].size()+1/*,curLine.size()-curArr[0].size()*/);
			CUtility::TrimLeft(tmp);
			if((curArr[0] != string("Set-Cookie")) && 
				(curArr[0] != string("Set-cookie"))&& 
				(curArr[0] != string("set-cookie"))
				)
			{
				m_mResHead[curArr[0]] = tmp;
			}
			else
			{
				m_aResCookie.push_back(CCookie(tmp));
			}
		}

	}

	//如果标记行为 100，则从iterText开始取标记行
	if(m_sRetCode == string("100"))
	{
		iter = iterText;
		goto reget_state;
	}

	m_sResBody.erase(0,iterText-m_sResBody.begin());
	


	//分析内容，如果是chunk的，解析之  Transfer-Encoding: chunked

	string sTmp;

	if(CUtility::TrimLeft(m_mResHead["Transfer-Encoding"]) == string("chunked"))
	{
		string::const_iterator iterTagBegin = m_sResBody.begin();
		string::const_iterator iterTagCur = iterTagBegin;
		int block_size = 0;

		do
		{
				//iter = m_sResBody.begin();

				CUtility::get_first_line(m_sResBody,iterTagCur,curLine);

				if(curLine.empty()) 
				{
					if(iterTagCur != m_sResBody.end())
						continue;
				}
				
				block_size = CUtility::hex_to_num(curLine);

				if(block_size < 0) return 3;

				if(block_size > 0)
				{
					//m_sResBody.erase(0,iterTagCur-iterTagBegin);
					sTmp.append(iterTagCur,block_size);
					iterTagCur += block_size;
					iterTagBegin = iterTagCur;

				}

		}while((block_size > 0) && (iterTagCur != m_sResBody.end()));


		m_sResBody= sTmp;

	}




	return 0;
}


int CHttpClient::StoreSession()
{
	CStrMap mCookie;

	//
	string sReqCookie = m_mReqHead["Cookie"];

	mCookie.SnapElement(sReqCookie,"; ");


	if(m_aResCookie.size() == 0)
		return 0;

	for(int i=0;i<m_aResCookie.size();i++)
	{
		mCookie[m_aResCookie[i].m_sName] = m_aResCookie[i].m_sValue; 
	}

	string sCookie ;

	mCookie.GenString(sCookie,"; ");

	string sContent = "<?xml version=\"1.0\" ?>\r\n";
	sContent+= " <root>\r\n";
	sContent+= " <cookie>" + CUtility::UrlEncode(sCookie) + "</cookie>\r\n";
	sContent+= " <url>" + CUtility::UrlEncode(m_sHost) + "</url>\r\n";
	sContent+= " </root>\r\n";

	string fses = CModulePath::GetInstance()->m_sSesDir + "\\" + m_sHost+".ses.xml";


	CFile file1;
	file1.Open(fses.c_str(),CFile::modeCreate|CFile::modeWrite|CFile::shareDenyWrite  );


	file1.Write(sContent.data(),sContent.size());
	file1.Close();


	return 0;
}
